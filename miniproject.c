#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
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
	char a[MAX],path[MAX];
	int id;
	/*strcpy(path,"/bin/");
	strcat(path,a);*/

  while(1)
{
	printf("1 for details\n2 Enter a string or file name\n3 find duplicate files\n4 del duplicate\n5 to make data entry\n");
	id=fork();
	if(id==0)
	{
    strcpy(a,"main ");
    printf("Enter full path of the pwd\n");
    gets(path);
    strcat(a,path);
    puts(a);
		//execl("$PATH","main",path,NULL);
    system(a);
	}
	else
	{
	wait(NULL);
	}
}
return 0;
}
