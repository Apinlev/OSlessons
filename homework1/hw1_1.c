1. Ќаписать программу, котора€ из командной строки получает целое число N.  ак результат программа должен создать N файлов(file_1.txt, Е, file_N.txt)
в каждом из которых написан УHello world IФ, где значение I совпадает со значением номера файла.
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

int main(void) {
  int N;
  scanf("%d", &N);
  while(N != 0)
  {
    char path[16];
    snprintf(path, 16, "file_%d.txt", N);
    creat(path, O_WRONLY);
    int fd = open (path, O_WRONLY);
    char text[16];
    snprintf(text, 16, "Hello world%d", N);
    write(fd, text, 16);
    close(fd);
    N--;
  }
}