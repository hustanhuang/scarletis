#include "cmds.h"

#include <sys/socket.h>
#include <string.h>
#include <ctype.h>

#include "def.h"
#include "log.h"

int cmd_hello(int conn_fd, const char *para) {
    char buff[BUFF_LEN];
    strcpy(buff, "hello,world ");
    strcat(buff, para);

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

int cmd_set(int conn_fd, const char *para) {
    char buff[BUFF_LEN];
    strcpy(buff, para);

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

int cmd_get(int conn_fd, const char *para) {
    char buff[BUFF_LEN];
    strcpy(buff, para);

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}
