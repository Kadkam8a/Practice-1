#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int x0 = 2; // initial value
    int m = 10; // cycles number
    int sum = x0; // variable for the cumultive sum
    int next, prev;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    next = (rank + 1) % size;
    prev = (rank + size - 1) % size;
    int i = 0;
    int error = 0;
    while (i < m && !error) {
        MPI_Request request;
        MPI_Isend(&sum, 1, MPI_INT, next, 0, MPI_COMM_WORLD, &request);
        MPI_Status status;
        MPI_Recv(&sum, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &status);
        int flag;
        MPI_Test(&request, &flag, &status);
        if (!flag) {
            MPI_Abort(MPI_COMM_WORLD, 1);
            error = 1;
        }
        i++;
        sum+=1;
    }
    if (!error) {
        printf("Process %d: cumulative sum = %d\n", rank, sum);
    }
    MPI_Finalize();
    return 0;
}
