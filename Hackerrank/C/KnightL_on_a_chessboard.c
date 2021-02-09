#include<stdlib.h>
#include<stdio.h>

#define SIZE 3

typedef struct position{
	int a;
	int b;
	int m;
}position;

typedef struct node{
	position pos;
	struct node *n;
}node;

typedef struct queue{
	int count;
	node *front;
	node *rear;
}queue;

void initialize(queue *q){
	q->count=0;
	q->front=NULL;
	q->rear=NULL;
}

int isEmpty(queue *q){
	return (q->front == NULL);
}

void enqueue(queue *q, int a, int b, int m){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->pos.a=a;
	temp->pos.b=b;
	temp->pos.m=m;
	temp->n=NULL;

	if (isEmpty(q) == 1) {
		q->front=temp;
		q->rear=temp;
	} else {
		q->rear->n = temp;
		q->rear = temp;
	}
	q->count+=1;
}

position dequeue(queue *q){
	node *temp;
	position pos_temp = q->front->pos;
	temp = q->front;
	q->front = q->front->n;
	q->count-=1;
	free(temp);
	return pos_temp;
}

void free_double(int **a, int n){
	for (int i = 0; i < n; ++i) {
		free(*(a+i));
	}
	free(a);
}

int moves(int a, int b, int n){
	int reachable=-1;
	queue *q = (queue*) malloc(sizeof(*q));
	position p;
	initialize(q);

	int **visited = (int**) malloc(n*sizeof(int*));

	for (int i = 0; i < n; ++i) {
		visited[i] = (int*)calloc(n,sizeof(int));
	}

	visited[0][0] = 1;

	enqueue(q, 0, 0, 0);
	
	while(!isEmpty(q)){
		p = dequeue(q);	

		if (p.a == n-1 && p.b == n-1) {
			free(q);
			free_double(visited, n);
			return p.m;
		}

		if (p.a + a < n && p.b + b < n && visited[p.a+a][p.b+b] != 1) {
			enqueue(q,p.a+a,p.b+b,p.m+1);
			visited[p.a+a][p.b+b] = 1;
		}
		if (p.a + a < n && p.b - b > -1 && visited[p.a+a][p.b-b] != 1) {
			enqueue(q,p.a+a,p.b-b,p.m+1);
			visited[p.a+a][p.b-b] = 1;
		}
		if (p.a - a > -1 && p.b + b < n && visited[p.a-a][p.b+b] != 1) {
			enqueue(q,p.a-a,p.b+b,p.m+1);
			visited[p.a-a][p.b+b] = 1;
		}
		if (p.a - a > -1 && p.b - b > -1 && visited[p.a-a][p.b-b] != 1) {
			enqueue(q,p.a-a,p.b-b,p.m+1);
			visited[p.a-a][p.b-b] = 1;
		}
		if (a != b) {
			if (p.a + b < n && p.b + a < n && visited[p.a+b][p.b+a] != 1) {
				enqueue(q,p.a+b,p.b+a,p.m+1);
				visited[p.a+b][p.b+a] = 1;
			}
			if (p.a + b < n && p.b - a > -1 && visited[p.a+b][p.b-a] != 1) {
				enqueue(q,p.a+b,p.b-a,p.m+1);
				visited[p.a+b][p.b-a] = 1;
			}
			if (p.a - b > -1 && p.b + a < n && visited[p.a-b][p.b+a] != 1) {
				enqueue(q,p.a-b,p.b+a,p.m+1);
				visited[p.a-b][p.b+a] = 1;
			}
			if (p.a - b > -1 && p.b - a > -1 && visited[p.a-b][p.b-a] != 1) {
				enqueue(q,p.a-b,p.b-a,p.m+1);
				visited[p.a-b][p.b-a] = 1;
			}
		}
	}

	free(q);
	free_double(visited, n);
	return reachable;
}

void print_matrix(int **matrix,int n){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
 	int n;
	char *input;
	char *endptr;

	input = (char*)malloc(3*sizeof(char));
	fgets(input, 3*sizeof(char), stdin);

	for(int i=0; i<3; i++)
	{
		if( input[i]=='\n' )
		{
			input[i] = '\0';
			break;
		}
	}

	n = strtol(input, &endptr, 0);

	if (n > 0) {
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				printf("%d ", moves(i,j,n));
			}
			printf("\n");
		}
	}
	else {
		printf("Negative values not allowed\n");
	}

	free(input);
    return 0;
}
