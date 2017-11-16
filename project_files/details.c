#include "head.h"
#define MAX 128

void details(void)
{
char choice;
  int ch;



    system("echo \" \" >> log.txt");
    system("date >> log.txt"); //LOG entry
    system("echo \"Basic details were accessed in $PWD\" >> log.txt");
    printf("Directories are \n" );
    system("ls -d */");
    printf("Files are \n" );
    system("ls -l | grep ^-");
    printf("Sizes of files and directores are \n" );
    system("du -sh *");
    printf("Would you like to see all the directores and sub directories in pwd? y or n\n");
    scanf("%c",&choice);
    if(choice=='y')
    {
      system("find * -type d");
      system("echo \"Recursive directores info were accessed in $PWD\" >> log.txt");//LOG entry
      printf("Would you like to see all the files present y/n\n" );
      getchar();
      scanf("%c",&choice);
      if(choice=='y')
      {
        system("find * -type f");
        system("echo \"All files were displayed recursively in $PWD\" >> log.txt");//LOG entry
      }
    }
}
