#include "head.h"
#define MAX 128

void search(void)
{
		char a[MAX],path[MAX],str[MAX],name[MAX],choice;
	  int ch;
    system("echo \" \" >> log.txt");
    system("date >> log.txt");//LOG entry
    system("echo \"Recursively or non-recursively, files and directrories were displayed to look for specific string in file in $PWD\" >> log.txt");
    printf("Would you like to see all the directores and sub directories in pwd? y or n\n");
    scanf("%c",&choice);
    if(choice=='y')
    {
      system("find * -type d");
      getchar();
      printf("Would you like to see all the files present y/n\n" );
      scanf("%c",&choice);
      if(choice=='y')
      {
        system("find * -type f");
      }
    }
    getchar();
    printf("Enter filename\n");
    gets(name);
    printf("Enter string to search in %s\n",name);
    gets(str);
    strcpy(a,"grep -I --include=\"");
    strcat(a,name);
    strcat(a,"\" ");
    strcat(a,str);
    strcat(a," * -nr");
    printf("Below are the line numbers where file occurs\n");
    system(a);
    strcpy(a,"echo \"Filename: ");
    strcat(a,name);
    strcat(a," String to be searched: ");
    strcat(a,str);
    strcat(a,"\" >> log.txt");
    system(a);
    strcpy(a,"grep -o -I --include=\"");
    strcat(a,name);
    strcat(a,"\" ");
    strcat(a,str);
    strcat(a," * -nr");
    strcat(a," | wc -l");
    printf("Occurrence of string in file is\n");
    system(a);
    system("echo \"Occurrence of string in file was found\" >> log.txt");
}
