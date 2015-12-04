#ifndef SESSION_H
#define SESSION_H

#include <arpa/inet.h>

int session(int conn_fd, struct sockaddr_in *cli_addr);

#endif
