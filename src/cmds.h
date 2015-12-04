#ifndef CMDS_H
#define CMDS_H

int cmd_hello(int conn_fd, const char *para);
int cmd_set(int conn_fd, const char *para);
int cmd_get(int conn_fd, const char *para);

#endif
