/* написать программу, которая на вход получает подстроку и путь, и рекурсивно обходя все файлы под заданным путем, печатает те строки и намера строк, которые содержат этот шаблон (работает не совсем так как должно, вместо этого печатает весь файл, в котором было найдено совпадение)*/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/dir.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <string.h>

void find(char* dirname, char* substr)
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
        find(path, substr);
      }
     
    }
    else
    {
      snprintf(path, 256, "%s/%s", dirname, entry->d_name);
      FILE *f;
      char c = 's';
      char line[512] = "";
      f=fopen(path,"r");
     while((c=fgetc(f))!=EOF){
       if( strncmp(&c,"\n", 1) != 0)
       {
        strncat(line, &c, 1);
       }
       else
       {
         if(strstr(line, substr))
         {
           printf("%s \n", entry->d_name);
           printf("%s \n", line);
         }
         strcpy(line, "");
       }
      }
    fclose(f);
    
    }
    entry = readdir(dirptr);
  }
  closedir(dirptr);
}
int main(void) {
  char *substr = "dominus";
  char *dirname = "test";
  find(dirname, substr);
}
