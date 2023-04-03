 - Assignment Name: MPI Histogram

 - Assignment Tech Stack: C, MPI

 - Description: 

 - Code Cheatsheet:
 ```
sftp <id>@access1.cims.nyu.edu
put <file>
exit

ssh <id>@access1.cims.nyu.edu
ssh <id>@crunchy1.cims.nyu.edu
module load mpi/openmpi-x86_64

mpicc -Wall -std=c99 -o filename filename.c
mpiexec -n #processes ./filename arguments
 ```