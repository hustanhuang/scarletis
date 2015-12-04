#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "def.h"
#include "log.h"
#include "session.h"

int main() {
    int listen_fd;
    if ( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        s_err("retrieve socket");

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SCAR_PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        s_err("bind address");

    if (listen(listen_fd, 16) < 0)
        s_err("listening");

    fprintf(stdout, welcome, SCAR_PORT);

    int conn_fd;
    struct sockaddr_in cli_addr;
    socklen_t length = 0;
    for (int i = 0; i != 2; ++i) {
        s_log("Waiting for connections");

        length = sizeof(cli_addr);
        if ( (conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &length)) < 0)
            s_err("accepting connections");

        if (session(conn_fd) < 0)
            s_err("client session");

        if (close(conn_fd) < 0)
            s_err("closing connection");

        s_log("Session complete");
    }

    exit(EXIT_SUCCESS);
}
