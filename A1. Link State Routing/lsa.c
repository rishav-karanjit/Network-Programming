#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 999
#define MAX 100

int cost[MAX][MAX]; // cost matrix
int distance[MAX]; // distance from source
int visited[MAX] = {0};
int parent[MAX];
int source;
int n; // number of nodes

void initialize()
{
    int i;
    visited[source] = 1;
    parent[source] = source;

    for(i=0; i<n; i++)
    {
        distance[i] = cost[source][i];
        if( cost[source][i] != INFINITY )
        {
            parent[i] = source;
        }
    }
}

/* Get minimum distant node not already in network */
int GetMin()
{
    int minIdx = -1;
    int minDist = INFINITY;

    int i;
    for(i=0; i<n; i++)
    {
        if( !visited[i] && minDist >= distance[i] )
        {
                minIdx = i;
                minDist = distance[i];
        }
    }
    return minIdx;
}

/* update distance for adjacent nodes */
void updateTable(int node)
{
    int i;
    for(i=0; i<n; i++)
    {
        if( cost[node][i] != INFINITY && distance[i] > distance[node]+cost[node][i] )
        {
            distance[i] = distance[node] + cost[node][i];
            parent[i] = node;
        }
    }
}

void display()
{
    int i;
    int node;

    printf("\nNode \t Distance from source \t Path \n");
    for(i=0; i<n; i++)
    {
        printf("%d \t\t %d \t\t", i, distance[i]);

        // node <- parent[node] <- parent[parent[node]] <- ... <- source
        node = i;
        printf("%d", node);
        while( node != source)
        {
            printf(" <- %d", parent[node]);
            node = parent[node];
        }
        printf("\n");
    }
}

int main()
{
    int i, j, node;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the source node    : ");
    scanf("%d", &source);

    printf("\nEnter the cost matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    initialize();

    for(i=0; i<n-1; i++) // for all remaining vertices(since source is already visited)
    {
        node = GetMin();
        visited[node] = 1;
        updateTable(node);
    }
    display();
    return 0;
}