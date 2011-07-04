all:
	mkdir -p build
	gcc htpasswd.c -o build/htpasswd
	gcc htdigest.c -o build/htdigest

clean:
	rm -rf build
