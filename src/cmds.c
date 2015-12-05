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

CMD_SIGN(append) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(bitcount) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(brpop) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(brpoplpush) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(decr) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(decrby) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(del) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(exists) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(get) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(getbit) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(getrange) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(incr) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(incrby) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(keys) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lindex) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(linsert) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(llen) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lpop) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lpush) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lpushx) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lrange) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lrem) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(lset) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(ltrim) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(mget) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(msetnx) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(randomkey) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(rename) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(rpop) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(rpoplpush) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(rpush) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(rpushx) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(set) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(setbit) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(setrange) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(strlen) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}

CMD_SIGN(type) {
    char buff[BUFF_LEN];
    strcpy(buff, "params:");

    list_t *pos = NULL;
    list_for_each(pos, paras) {
        strcat(buff, " ");
        strcat(buff, param_value(pos));
    }
    strcat(buff, "\r\n");

    if (send(conn_fd, buff, strlen(buff), 0) < 0)
        s_err("send");
    return 0;
}
