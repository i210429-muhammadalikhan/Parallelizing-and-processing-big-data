MPI and OpenMP K Shortest Paths Algorithm:
This program implements the K shortest paths algorithm using a EnronEmail data with MPI (Message Passing Interface) and OpenMP for parallelization. It reads input from a file, represents the graph, and finds the K shortest paths from a given source node to a destination node.


Compilation Instructions:
To compile the program, ensure that you have MPI and OpenMP installed on your system. Then, follow these steps:

1-Open a terminal.
2-Navigate to the directory containing the source code (k_shortest_paths_mpi_omp.c) and the input file (EnronEmail.txt).
3-Compile the source code using a C compiler with MPI and OpenMP support.
4-mpicc -fopenmp k_shortest_paths_mpi_omp.c -o k_shortest_paths_mpi_omp
5-This command will generate an executable file named k_shortest_paths_mpi_omp.


Execution Instructions:
After compiling the program, you can execute it using MPI. Follow these steps:

1-Ensure that the input file (EnronEmail.txt) is in the same directory as the compiled executable.
2-Open a terminal.
3-Execute the compiled program using mpiexec with the desired number of processes:
bash
4-mpiexec -n <num_processes> ./k_shortest_paths_mpi_omp
5-Replace <num_processes> with the number of MPI processes you want to use for parallel execution for example 4.


Follow the prompts to input the source and destination nodes when prompted.
After providing the necessary inputs, the program will display the K shortest paths from the specified source node to the destination node.
