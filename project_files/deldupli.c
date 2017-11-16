#include "head.h"
#define MAX 128

void deldupli(void)
{


	char choice;
	  


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
        system("fdupes -r $PWD");
      }
      else
      {
        system("fdupes -r -d $PWD");
        system("echo \"Duplicate files were DELETED in $PWD\" >> log.txt");
      }
    }
}
