#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#define MAX 128
/*
•provide statistics on the number of files and directories (can add more relevant
statistics if required)
• given a file name and string, find the occurrence of the string in the file in terms of
count
• to the above feature also add up details on which line numbers the string occurs
• given a string find the occurrence of that string in files
• find duplicate files in the directory
• delete duplicate files in the directory
• create a file to log all the important events happening in the program
*/
int main(int argc, char const *argv[])
 {
	char a[MAX],path[MAX],str[MAX],name[MAX],choice;
  int ch;
  while(1)
{
	printf("1 for details\n2 Enter a string and file name to get occurrence of string in file\n3 find duplicate files\n4 del duplicate\n5 To display the contents of log file\n6 Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
    getchar();
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
  break;

  case 2:
  //grep -I -o "print" */ -r | wc -l
    getchar();
    system("echo \" \" >> log.txt");
    system("date >> log.txt");//LOG entry
    system("echo \"Recursively or non-recursively, files and directrories were displayed to look for specific string in file in $PWD\" >> log.txt");
    printf("Would you like to see all the directores and sub directories in pwd? y or n\n");
    scanf("%c",&choice);
    if(choice=='y')
    {
      system("find * -type d");
      getchar();
      printf("Would you like to see all the files present recursively y/n?\n" );
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
    /*grep -I --include="main.c" printf * -nr*/
    break;

    case 3:
    getchar();
    system("echo \" \" >> log.txt");
    system("date >> log.txt");//LOG entry
    printf("Would you like to see duplicate files recursively y:recursively n:only in pwd\n");
    getchar();
    scanf("%c",&choice);
    if(choice=='y')
    {
      system("echo \"Duplicate files were found Recursively in $PWD\" >> log.txt");
      system("fdupes -r $PWD");
    }
    else
    {
      system("echo \"Duplicate files were found only in $PWD\" >> log.txt");
      system("fdupes $PWD");
    }
    break;

    case 4:
    getchar();
    system("echo \" \" >> log.txt");
    system("date >> log.txt");//LOG entry
    printf("Are you sure you want to delete duplicate files y/n ?\n");
    scanf("%c",&choice);
    if(choice=='y')
    {
      printf("Would you like to see the duplicate files before deleting them y/n ?\n");
      getchar();
      scanf("%c",&choice);
      if(choice=='y')
      {
        printf("Would you like to see duplicate files recursively y:recursively n:only in pwd\n");
        getchar();
        scanf("%c",&choice);
        if(choice=='y')
        {
          system("echo \"Duplicate files were found Recursively in $PWD\" >> log.txt");
          system("fdupes -r $PWD");
          printf("Delete above files y/n?\n");
          getchar();
          scanf("%c\n",&choice);
          if(choice=='y')
          {
            system("fdupes -r -d $PWD");
          }
          else
          break;
        }
        else
        {
          system("echo \"Duplicate files were found only in $PWD\" >> log.txt");
          system("fdupes $PWD");
          printf("Delete above files y/n?\n");
          getchar();
          scanf("%c\n",&choice);
          if(choice=='y')
          {
            system("fdupes -r -d $PWD");
          }
          else
          break;
        }
      }
      else
      break;
    }
    break;


    case 5:
    printf("contents of LOG FILE are\n");
    system("cat log.txt");
    break;

    case 6:
    system("echo \" \" >> log.txt");
    system("echo \"Code exited on\" >> log.txt");
    system("date >> log.txt");
    return 0;
  }
}
return 0;
}
