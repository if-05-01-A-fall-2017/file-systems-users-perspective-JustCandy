#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
	char data[4000];
	int toCopy = open(argv[1], O_RDWR);
	int toWrite = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	int n = 0;
	do{
		n = read(toCopy, data, 4000);

		if(n == 0){
			printf("%s\n", "Copy done");
			close(toCopy);
			close(toWrite);
		}
		else {
			write(toWrite, data, n);
		}
	}
	while(n != 0);
	return 0;
}