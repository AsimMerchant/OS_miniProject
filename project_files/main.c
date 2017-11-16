#include "head.h"
#include "files_dec.h"
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

	  int ch;
	  while(1)
		{
	printf("1 for details\n2 Enter a string and file name to get occurrence of string in file\n3 find duplicate files\n4 del duplicate\n5 To display the contents of log file\n");
	  scanf("%d",&ch);
	  switch(ch)
  {
  case 1:
    getchar();
	details();
  break;

  case 2:
	search();
      break;

    case 3:
    dupli();
    break;

    case 4:
    deldupli();
    break;


    case 5:
    display();
	break;

	default:
	printf("Invalid choice");
	break ;
	}
}
return 0;
}
