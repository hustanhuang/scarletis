CC= gcc-5
CFLAGS= -std=c99

all: srv cli

srv: srvobjs
	$(CC) $(CFLAGS) -o scar-srv obj/server.o

srvobjs:
	$(CC) $(CFLAGS) -o obj/server.o -c src/server.c

cli: cliobjs
	$(CC) $(CFLAGS) -o scar-cli obj/client.o

cliobjs:
	$(CC) $(CFLAGS) -o obj/client.o -c src/client.c

clean:
	rm obj/* scar-srv scar-cli
	rm -R *.dSYM
