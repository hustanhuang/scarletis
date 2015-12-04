CC= gcc-5
CFLAGS= -std=c99

all: server

#server
server: srv log session cmds
	$(CC) $(CFLAGS) -o scar-srv $(SRVOBJS)

SRVOBJS= obj/server.o obj/log.o obj/session.o obj/cmds.o

srv:
	$(CC) $(CFLAGS) -o obj/server.o -c src/server.c

session: log cmds
	$(CC) $(CFLAGS) -o obj/session.o -c src/session.c

cmds:
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
