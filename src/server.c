#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define SCAR_PORT 6379

const char *welcome =
"Scarletis\n"
"Port: %d\n"
"\n";

time_t g_ticks;

void s_log(const char *s) {
    g_ticks = time(NULL);
    fprintf(stdout, "%.24s * %s\n", ctime(&g_ticks), s);
}

void s_errlog(const char *s) {
    g_ticks = time(NULL);
    fprintf(stderr, "%.24s # ", ctime(&g_ticks));
    perror(s);
    exit(EXIT_FAILURE);
}

int session(int conn_fd, struct sockaddr_in *cli_addr) {
    char buff[1025];
    size_t length = 0;
    uint32_t addr = ntohs(cli_addr->sin_addr.s_addr);
    in_port_t port = ntohs(cli_addr->sin_port);

    for ( ; ; ) {
        bzero(buff, sizeof(buff));
        snprintf(buff, sizeof(buff), ">>> ");
        if (send(conn_fd, buff, strlen(buff), 0) < 0)
            s_errlog("print prompt");

        bzero(buff, sizeof(buff));
        if ( (length = recv(conn_fd, buff, sizeof(buff), 0)) < 0)
            s_errlog("recv data");

        g_ticks = time(NULL);
        fprintf(stdout, "%.24s message from %d:%d\n\t%s", ctime(&g_ticks), addr, port, buff);

        if (send(conn_fd, buff, strlen(buff), 0) < 0)
            s_errlog("echo");
    }

    return 0;
}

int main() {

    fprintf(stdout, welcome, SCAR_PORT);

    int listen_fd;
    if ( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        s_errlog("retrieve socket");

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SCAR_PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        s_errlog("bind address");

    if (listen(listen_fd, 16) < 0)
        s_errlog("listening");

    int conn_fd;
    struct sockaddr_in cli_addr;
    socklen_t length = 0;
    for ( ; ; ) {
        s_log("Waiting for connections");

        length = sizeof(cli_addr);
        if ( (conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &length)) < 0)
            s_errlog("accepting connections");

        if (session(conn_fd, &cli_addr) < 0)
            s_errlog("client session");

        if (close(conn_fd) < 0)
            s_errlog("closing connection");

        s_log("Session complete");
    }

    exit(EXIT_SUCCESS);
}
