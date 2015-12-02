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

int main()
{
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
    char buff[1025];
    for ( ; ; ) {

        s_log("Waiting for connections");

        if ( (conn_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL)) < 0)
            s_errlog("accepting connections");

        s_log("Write into socket");

        snprintf(buff, sizeof(buff), "hello,world\r\n");
        if (write(conn_fd, buff, strlen(buff)) < 0)
            s_errlog("write into socket");

        if (close(conn_fd) < 0)
            s_errlog("closing connection");

        s_log("Session complete");
    }

    exit(EXIT_SUCCESS);
}
