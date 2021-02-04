#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define PMAX 3

char * result(const int * positions){
	char *r=NULL;
	if (abs(positions[0] - positions[2]) < abs(positions[1] - positions[2])) {
		r = "Cat A";	
	} else if (abs(positions[0] - positions[2]) > abs(positions[1] - positions[2])) {
		r = "Cat B";
	} else {
		r = "Mouse C";
	}

	return r;
}

int main(int argc, char **argv){
	int tests, j=0;
	char *input=NULL;
	char *temp=NULL;
	int *positions=NULL;
	char *endptr=NULL;

	scanf("%d\n", &tests);

	input = (char*)malloc(3*PMAX*2*sizeof(char));
	positions = (int*)malloc(3*PMAX*2*sizeof(int));

	for (int i = 0; i < tests; ++i) {
		memset(input, 0, 3*PMAX*2);
		fgets(input, 3*PMAX*2*sizeof(char),stdin);
		
		for (temp = strtok(input, " "); temp; temp = strtok(NULL, " ")) {
			positions[j] = strtol(temp, &endptr, 0);
			++j;
		}
		j=0;
		
		printf("%s\n", result(&positions[0]));
	}

	free(input);
	free(positions);
    return 0;
}
