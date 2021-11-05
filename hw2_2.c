/* написать программу, которая получает 2 файла А и В. далее открывает файл С и копирует содержимое А в С, после чего добавляет содержимое В с конца С (добавляет неизвестные символы?!)*/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/dir.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

void concatenate(const char* A, const char* B) {
	char c;
	char temp1[64] = "";
  char temp2[64] = "";
	int fd = open("C.txt" ,O_WRONLY);
	FILE* first;
	first = fopen(A, "r");
	while ((c = fgetc(first)) != EOF) {
		strncat(temp1, &c, 1);
	}
  write(fd, temp1, 64);
  printf("%s", temp1);
  fclose(first);
	lseek(fd, -1, SEEK_END);
	FILE* second;
  second = fopen(B, "r");
	while ((c = fgetc(second)) != EOF) {
		strncat(temp2, &c, 1);
	}
  write(fd, temp2, 64);
  printf("%s", temp2);
	fclose(second);
	close(fd);
}

int main() {
	concatenate("A.txt", "B.txt");
}