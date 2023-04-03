#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main (int argc, char **argv)
{
    /*Part 1, open the file*/
    FILE *fptr;
    int count = 0;

    if(argc != 3 ){
    printf("Program receives two inputs: number of bins and a filename.\n");
    exit(1);
    }

    if((fptr = fopen(argv[2], "r")) == NULL )
    {
	printf("Cannot read the file %s\n", argv[2]);
	exit(1);
    }

    count = atoi(argv[1]);
    int myArray[count];
    int i;
    for (i = 0; i <= count; i++){
        if(i >= 1){
            fscanf(fptr, "%d,", &myArray[i - 1] );
        }else{
            fscanf(fptr, "%d,", &myArray[i] );
        }
    }
    for (i = 0; i < count; i++){
        printf("Number is: %d\n\n", myArray[i] );
    }
    fclose(fptr);
    return 0;
}