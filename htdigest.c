#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

	char password_first[1024], password_repeat[1024];
	char *input, *passwordfile, *username, *realm, *encrypted;
	FILE *htpasswd_file;

	if(argc < 4) {

		printf("Usage:\n\n");
		printf("htdigest passwordfile realm username\n");
		printf("htdigest passwordfile realm username password\n\n");
		printf("Creates or updates an Apache/nginx compatible htdigest file\n");

		return 1;

	}
	
	passwordfile = argv[1];
	realm = argv[2];
	username = argv[3];

	if(argc != 5) {
		
		input = getpass("Password: ");
		strcpy(password_first, input);

		input = getpass("Password (again): ");
		strcpy(password_repeat, input);

		memset(input, 0, strlen(input));

		int password_compare = strcmp(password_first, password_repeat);

		if(password_compare != 0) {

			printf("Passwords did not match\n");
			return 2;

		}

	} else {
		strcpy(password_first, argv[4]);
	}

	encrypted = (char *)crypt(password_first, password_first);

	htpasswd_file = fopen(passwordfile, "a");
	fprintf(htpasswd_file, "%s:%s:%s\n", username, realm, encrypted);
	fclose(htpasswd_file);

	return 0;

}
