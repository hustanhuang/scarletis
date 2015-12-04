#include "cmds.h"

#include <sys/socket.h>
#include <string.h>
#include <ctype.h>

#include "def.h"
#include "log.h"
#include "param.h"

CMD_SIGN(hello) {
    char buff[BUFF_LEN];
    strcpy(buff, "Greetings");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, ", ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, ".\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(bye) {
    char buff[BUFF_LEN];
    strcpy(buff, "Bye");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, ", ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, ".\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}
