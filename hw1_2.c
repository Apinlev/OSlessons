/* написать программу, которая рекурсивно обходит данную директорию и печатает содержимое каждого файла с новой строки*/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/dir.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

void printdir(char* dirname)
{
  DIR *dirptr = opendir(dirname);
  if (dirptr == NULL)
  {
    return;
  }
  struct dirent *entry = readdir(dirptr);
  char path[256];
  while (entry != NULL)
  {
    
    if(entry->d_type == DT_DIR)
    {
      if(strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
      {
        snprintf(path, 256, "%s/%s", dirname, entry->d_name);
        printdir(path);
      }
     
    }
    else
    {
      snprintf(path, 256, "%s/%s", dirname, entry->d_name);
      FILE *f;
      char c;
      f=fopen(path,"r");
      while((c=fgetc(f))!=EOF){
        printf("%c",c);
      }
    fclose(f);
    }
    entry = readdir(dirptr);
  }
  closedir(dirptr);
}
int main(void) {
  printdir("test");
}