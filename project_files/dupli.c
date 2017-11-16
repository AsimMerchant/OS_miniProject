#include "head.h"
#define MAX 128

void dupli()
{
    system("echo \" \" >> log.txt");
    system("date >> log.txt");//LOG entry
    system("echo \"Duplicate files were found in $PWD\" >> log.txt");
    system("fdupes -r $PWD");
}
