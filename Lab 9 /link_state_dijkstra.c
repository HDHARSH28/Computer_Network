#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

static void print_path(int parent[], int vertex)
{
    if (parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }

    print_path(parent, parent[vertex]);
    printf(" -> %d", vertex);
}

int main(void)
{
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int distance[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int source;

    printf("Enter number of routers (1-%d): ", MAX_VERTICES);
    if (scanf("%d", &vertices) != 1 || vertices < 1 || vertices > MAX_VERTICES) {
        fprintf(stderr, "Invalid number of routers.\n");
        return 1;
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = (i == j) ? 0 : -1;
        }
    }

    printf("Enter adjacency list for each router.\n");
    printf("For each router, enter: number_of_neighbors neighbor cost ...\n");
    for (int i = 0; i < vertices; i++) {
        int neighbors;

        if (scanf("%d", &neighbors) != 1 || neighbors < 0 || neighbors >= vertices) {
            fprintf(stderr, "Invalid number of neighbors.\n");
            return 1;
        }

        for (int j = 0; j < neighbors; j++) {
            int neighbor;
            int cost;

            if (scanf("%d %d", &neighbor, &cost) != 2 ||
                neighbor < 0 || neighbor >= vertices || neighbor == i || cost < 0) {
                fprintf(stderr, "Invalid neighbor or link cost.\n");
                return 1;
            }

            graph[i][neighbor] = cost;
        }
    }

    printf("Enter source router (0-%d): ", vertices - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= vertices) {
        fprintf(stderr, "Invalid source router.\n");
        return 1;
    }

    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0;

    for (int step = 0; step < vertices; step++) {
        int current = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && distance[i] != INT_MAX &&
                (current == -1 || distance[i] < distance[current])) {
                current = i;
            }
        }

        if (current == -1) {
            break;
        }
        visited[current] = 1;

        for (int neighbor = 0; neighbor < vertices; neighbor++) {
            int cost = graph[current][neighbor];
            if (!visited[neighbor] && cost >= 0 && distance[current] <= INT_MAX - cost &&
                distance[current] + cost < distance[neighbor]) {
                distance[neighbor] = distance[current] + cost;
                parent[neighbor] = current;
            }
        }
    }

    printf("\nLink-state routing table (Dijkstra/OSPF model)\n");
    printf("Destination\tCost\tPath\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t\t", i);
        if (distance[i] == INT_MAX) {
            printf("INF\tUnreachable\n");
        } else {
            printf("%d\t", distance[i]);
            print_path(parent, i);
            putchar('\n');
        }
    }

    return 0;
}
