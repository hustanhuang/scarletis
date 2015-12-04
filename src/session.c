#include "session.h"

#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

#include "def.h"
#include "log.h"
#include "cmd.h"

int session(int conn_fd, struct sockaddr_in *cli_addr) {
    const char *prompt = ">>> ";
    const size_t prompt_len = 4;

    char buff[BUFF_LEN];
    size_t length = 0;

    for ( ; ; ) {
        if (send(conn_fd, prompt, prompt_len, 0) < 0)
            s_err("print prompt");

        bzero(buff, sizeof(buff));
        if ( (length = recv(conn_fd, buff, sizeof(buff), 0)) < 0)
            s_err("recv data");

        if (buff[length - 1] == '\n') buff[--length] = '\0';
        if (buff[length - 1] == '\r') buff[--length] = '\0';

        if (strcmp(buff, "quit") == 0) {
            s_log("END");
            break;
        } else {
            s_log("MSG");
            s_prt(buff, length);
            putchar('\n');

            s_cmd(conn_fd, buff);
        }
    }

    return 0;
}
