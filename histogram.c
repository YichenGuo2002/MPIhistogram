#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main (int argc, char **argv)
{
    /*Part 1, open the file*/
    int rank, totalProcesses, i = 0, totalBins = 0, totalInts;
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcesses);
    FILE *fptr;

    if(argc != 3 ){
    printf("Program receives two inputs: number of bins and a filename.\n");
    exit(1);
    }

    if((fptr = fopen(argv[2], "r")) == NULL )
    {
	printf("Cannot read the file %s\n", argv[2]);
	exit(1);
    }

    totalBins = atoi(argv[1]);
    fscanf(fptr, "%d,", &totalInts);
    int* myArray = (int*)malloc(totalInts * sizeof(int));
    while(!feof(fptr)){
        fscanf(fptr, "%d,", &myArray[i] );
        i++;
    }
    /*for (i = 0; i < totalBins; i++){
        printf("Number is: %d\n\n", myArray[i] );
    }*/
    fclose(fptr);
    int bin[totalBins], result[totalBins];
    for(i = 0; i < totalBins; i++){
        bin[i] = 0;
    }
    /*Part 1 ends*/

    /*Part 2, create bin and assign*/
    int element = totalInts / totalProcesses;
    int bar = 100 / totalBins;
    if(rank <  totalProcesses - 1){
        for(i = rank * element; i < (rank + 1) * element; i++){
            bin[myArray[i] / bar] ++;
        }
    }else{
        for(i = rank * element; i < totalInts; i++){
            bin[myArray[i] / bar] ++;
        }
    }
    /*Part 2 ends*/

    /*Part 3, combine*/
    MPI_Reduce(&bin, &result, totalBins, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0){
        for(i = 0; i < totalBins; i++){
        printf("bin[%d] = %d\n", i, result[i]);
        }
    }
    MPI_Finalize ();
    /*Part 3 ends*/
    return 0;
}