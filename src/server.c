#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define SCAR_PORT 6379

const char *welcome =
"Scarletis\n"
"Port: %d\n";

int main()
{
    fprintf(stdout, welcome, SCAR_PORT);

    int listen_fd;
    if ( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("retrieve socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SCAR_PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind address");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, 16) < 0) {
        perror("listening");
        exit(EXIT_FAILURE);
    }

    int conn_fd;
    char buff[1025];
    for ( ; ; ) {
        if ( (conn_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL)) < 0) {
            perror("accepting connections");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i != 10; ++i) {
            snprintf(buff, sizeof(buff), "\b\b\b\b\b\bandyroiiid");
            if (write(conn_fd, buff, strlen(buff)) < 0) {
                perror("write into socket");
                exit(EXIT_FAILURE);
            }
            sleep(1);
        }

        if (close(conn_fd) < 0) {
            perror("closing connection");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
