CC= gcc-5
CFLAGS= -std=c99

all: server

#server
server: srv log session cmd
	$(CC) $(CFLAGS) -o scar-srv $(SRVOBJS)

SRVOBJS= obj/server.o obj/log.o obj/session.o obj/cmd.o obj/cmds.o obj/list.o

srv:
	$(CC) $(CFLAGS) -o obj/server.o -c src/server.c

session: log cmd
	$(CC) $(CFLAGS) -o obj/session.o -c src/session.c

cmd: cmds
	$(CC) $(CFLAGS) -o obj/cmd.o -c src/cmd.c

cmds: list
	$(CC) $(CFLAGS) -o obj/cmds.o -c src/cmds.c

#utils
log:
	$(CC) $(CFLAGS) -o obj/log.o -c src/log.c

#data structures
list:
	$(CC) $(CFLAGS) -o obj/list.o -c src/list.c

sds:
	$(CC) $(CFLAGS) -o obj/sds.o -c src/sds.c

#cleanup
clean:
	rm obj/* src/*~ scar-srv
