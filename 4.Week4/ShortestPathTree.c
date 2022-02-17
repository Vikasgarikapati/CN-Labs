#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
#define MAX 10

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isfull(struct Stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int newitem)
{
    if (isfull(s))
    {
        printf("STACK FULL");
    }
    else
    {
        s->top++;
        s->arr[s->top] = newitem;
    }
}

int pop(struct Stack *s)
{
    int data;
    if (isempty(s))
    {
        printf("\n STACK EMPTY \n");
        return -1;
    }
    else
    {
        data = s->arr[s->top];
        s->top--;
    }

    return data;
}

// Create a new node
struct node *newNode(int d, int p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// To remove the element with highest priority
int extractMin(struct node **head)
{
    if (*head == NULL)

        return -1;

    int data = (*head)->data;
    struct node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
    return data;
}

// To insert an element into priority queue

void enqueue(struct node **head, int d, int p)
{
    struct node *iter = (*head);
    struct node *temp = newNode(d, p);

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    if ((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (iter->next != NULL && iter->next->priority < p)
        {
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;
    }
}

void Dijkstra(int G[MAX][MAX], int n, int start)

{
    struct node *headPQ = NULL;

    int cost[MAX][MAX], i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    int distance[MAX], parent[MAX];
    int S[MAX], u = 0, v = 0;

    distance[start] = 0;
    enqueue(&headPQ, start, 0);
    parent[start] = -1;
    S[start] = 0;

    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            distance[i] = INFINITY;
            parent[i] = -1;

            S[i] = 0;
        }
    }

    while (headPQ != NULL)
    {
        u = extractMin(&headPQ);
        S[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (S[v] != 1)
            {
                if (distance[v] > distance[u] + cost[u][v])
                {
                    distance[v] = distance[u] + cost[u][v];
                    enqueue(&headPQ, v, distance[v]);
                    parent[v] = u;
                }
            }
        }
    }

    struct Stack s;
    initStack(&s);

    printf("\n\n---Dijkstra's Shortest paths---\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Shortest path from %d to %d :\n", start, i);
        printf("Path : ");
        int iter = i;
        while (parent[iter] != -1)
        {
            push(&s, iter);
            iter = parent[iter];
        }

        printf("%d", start);
        while (!isempty(&s))
        {
            printf("->%d", pop(&s));
        }

        printf("\n");
        printf("Cost : %d\n\n", distance[i]);
    }
}

int main()
{
    int G[MAX][MAX];

    int n;
    int i = 0, j = 0;

    printf("@@@@@@@@@@ DIJKSTRA'S ALGORITHM IMPLEMENTATION@@@@@@@@@@\n\n");
    printf("Enter the no. of vertices : ");

    scanf("%d", &n);
    printf("\n");

    printf("Enter the Adjacency Matrix for the Graph :\n\n");

    for (i = 0; i < n; i++)
    {
        printf("Edges coming from vertex %d : \n", i);

        for (j = 0; j < n; j++)
        {
            printf("Weight of edge %d---%d :", i, j);

            scanf("%d", &G[i][j]);
        }

        printf("\n");
    }

    int start;
    printf("Enter the starting vertex : ");
    scanf("%d", &start);

    Dijkstra(G, n, start);

    return 0;
}