#ifndef CMDS_H
#define CMDS_H

#include "list.h"

#define CMD_SIGN(name) int cmd_##name(int conn_fd, list_t *paras)

CMD_SIGN(hello);
CMD_SIGN(bye);

#endif
