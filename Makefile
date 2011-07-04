UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	LIBS =
else
	LIBS = -lcrypt
endif

all:
	mkdir -p build
	gcc htpasswd.c -o build/htpasswd $(LIBS)
	gcc htdigest.c -o build/htdigest $(LIBS)

clean:
	rm -rf build
