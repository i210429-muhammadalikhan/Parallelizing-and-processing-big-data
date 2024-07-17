//NAME: Muhammad Ali Khan, Muhammad Waleed, Anas Mohsin
//SECTION: B
//ROLL NO: i210429, i210438, i210609


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Structure to represent a node in the graph
struct Node {
    int dest;
    int cost;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int dest, int cost) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->cost = cost;           // Initializing the cost at the start
    newNode->next = NULL;           //setting the next as NULL at the start
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
// void addEdge(struct Graph* graph, int src, int dest, int cost) {
//     // Add an edge from src to dest
//     struct Node* newNode = createNode(dest, cost);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;
// }


// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int cost) {
    // Check if the cost is unspecified (-1), if so, use default cost of 1
    if (cost == -1) {
        cost = 1;
    }

    // Add an edge from src to dest
    struct Node* newNode = createNode(dest, cost);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}


// Function to find K shortest path lengths
void findKShortest(struct Graph* g, int src, int dest, int k) {
    int n = g->numVertices;

    // Vector to store distances
    int dis[n];
    for (int i = 0; i < n; ++i) {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;

    // Priority queue to store vertices and their distances
    struct Pair {
        int vertex;
        int distance;
    };
    struct Pair pq[n];
    int pqSize = 0;
    pq[pqSize].distance = 0;
    pq[pqSize].vertex = src;
    pqSize++;

    // While priority queue is not empty
    while (pqSize > 0) {
        // Extract minimum distance vertex from priority queue
        int u = pq[0].vertex;
        int d = pq[0].distance;
        for (int i = 1; i < pqSize; ++i) {
            if (pq[i].distance < d) {
                d = pq[i].distance;
                u = pq[i].vertex;
            }
        }
        for (int i = 0; i < pqSize; ++i) {
            if (pq[i].vertex == u) {
                for (int j = i; j < pqSize - 1; ++j) {
                    pq[j] = pq[j + 1];
                }
                break;
            }
        }
        pqSize--;

        // Traverse adjacency list of u
        struct Node* v = g->adjLists[u];
        while (v != NULL) {
            int dest = v->dest;
            int cost = v->cost;

            // Relaxation step
            if (dis[u] != INT_MAX && dis[u] + cost < dis[dest]) {
                dis[dest] = dis[u] + cost;
                
                // Add updated distance to priority queue
                pq[pqSize].distance = dis[dest];
                pq[pqSize].vertex = dest;
                pqSize++;
            }
            v = v->next;
        }
    }

    printf("The K-shortest path found is : ");
    // Print K shortest paths
    for (int i = 0; i < k; i++) {
        printf("%d ", dis[dest]);
    }
    printf("\n");
}

// Function to read input from file and call findKShortest
void readInputAndFindKShortest(char* fileName) {
    clock_t start_time = clock(); // Start the clock
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }

    int N, M, K;
    fscanf(file, "%d %d %d", &N, &M, &K);

    struct Graph* g = createGraph(N + 1);

    int edges[M][3];
    for (int i = 0; i < M; ++i) {
        fscanf(file, "%d %d", &edges[i][0], &edges[i][1]);
        edges[i][2] = -1; // Set default weight to -1 (indicating unspecified)
        addEdge(g, edges[i][0], edges[i][1], 1); // Default cost to 1 if not provided
    }

    fclose(file);

    int src, dest;
    printf("Enter the source node: ");
    scanf("%d", &src);
    printf("Enter the destination node: ");
    scanf("%d", &dest);

    findKShortest(g, src, dest, K);

    clock_t end_time = clock(); // End the clock
    double total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Total execution time: %.6f seconds\n", total_time);
}

// Driver Code
int main() {
    // Input file name
    char* fileName = "graph.txt";
    
    // Function call to read input from file and find K shortest paths
    readInputAndFindKShortest(fileName);

    return 0;
}
