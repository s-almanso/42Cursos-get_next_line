 // #include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd;
	int x;
	char buff[] = "Hello World!";

	if ((fd = open("file.txt", O_WRONLY)) == -1)
	{
		printf("ERROR! FILE OPEN FAILED\n");
	}
	else {
		printf("File Successfully opened\n");
		printf("file descriptor: %d\n", fd);
	}

	x = strlen(buff);

	if (write(fd, buff, x) == -1)
	{
		printf("Error while writing to file\n");
	}
	else {
		printf("wrote %d bytes to fille\n", x);
	}
	return (0);
}
