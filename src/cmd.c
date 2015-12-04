#include "cmd.h"

#include <sys/socket.h>
#include <string.h>
#include <ctype.h>

#include "def.h"
#include "log.h"
#include "list.h"
#include "cmds.h"
#include "param.h"

#define CMD_ADD(name) {#name, cmd_##name}

int cmd_nil(int conn_fd, list_t *para) {
    const char *nil = "illegal command\r\n";
    if (send(conn_fd, nil, strlen(nil), 0) < 0)
        s_err("send");
    return 0;
}

const struct cmd cmd_table[] = {
    CMD_ADD(hello),
    CMD_ADD(bye),
    {NULL, cmd_nil}
};

int s_cmd(int conn_fd, char buff[BUFF_LEN]) {
    char name[BUFF_LEN];
    bzero(name, sizeof(name));
    size_t i = 0;
    for (i = 0; i != BUFF_LEN && isalpha(buff[i]); ++i)
        name[i] = buff[i];
    memmove(buff, buff + i, BUFF_LEN - i);

    const struct cmd *p = cmd_table;
    for (p = cmd_table; p->name; ++p)
        if (strcmp(p->name, name) == 0)
            break;

    LIST_HEAD(params);

    char *token = strtok(buff, " \t\r\n");
    while(token) {
        if (*token)
            param_add(&params, token);
        token = strtok(NULL, " \t\r\n");
    }

    int ret = p->oper(conn_fd, &params);
    param_free(&params);
    return ret;
}
