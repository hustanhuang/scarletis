#include "cmds.h"

#include <stdio.h>
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

struct cmd {
    const char *name;
    int (*oper)(int conn_fd, const char *para);
};

struct cmd cmd_table[] = {
    {"hello"    , cmd_hello },
    {"set"      , cmd_set   },
    {"get"      , cmd_get   },
    {NULL       , NULL      }
};

int cmd_nil(int conn_fd) {
    const char *nil = "illegal command\r\n";
    if (send(conn_fd, nil, strlen(nil), 0) < 0)
        s_err("send");
    return 0;
}

int s_cmd(int conn_fd, char buff[BUFF_LEN]) {
    struct cmd *p = cmd_table;

    char name[BUFF_LEN];
    bzero(name, sizeof(name));
    size_t i = 0;
    for (i = 0; i != BUFF_LEN && isalpha(buff[i]); ++i)
        name[i] = buff[i];
    memmove(buff, buff + i, BUFF_LEN - i);

    while (p->name) {
        if (strcmp(p->name, name) == 0) {
            int ret =  p->oper(conn_fd, buff);
            return ret;
        }
        ++p;
    }

    return cmd_nil(conn_fd);
}
