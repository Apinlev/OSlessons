1. �������� ���������, ������� �� ��������� ������ �������� ����� ����� N. ��� ��������� ��������� ������ ������� N ������(file_1.txt, �, file_N.txt)
� ������ �� ������� ������� �Hello world I�, ��� �������� I ��������� �� ��������� ������ �����.
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