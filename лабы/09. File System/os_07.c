#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>


int main()
{
	char *locale = setlocale(LC_ALL, "");
    char c;
    int out;
    int rowNumber = 1;
    int in = open("./os09.txt",O_RDWR);

    while (read(in,&c,1) == 1)
    {
    read(in,&c,1);
    write(1,&c,1);
    lseek(in, 5, SEEK_CUR);
    read(in,&c,1);
    write(1,&c,1);
    }
    
    return 0;
}