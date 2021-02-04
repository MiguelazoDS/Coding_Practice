#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char **argv){
	int steps, count=0, enter=0, valleys=0;
	char *input=NULL;

	scanf("%d\n", &steps);

	input = (char*)malloc((steps+1)*sizeof(char));

	fgets(input, (steps+1)*sizeof(char), stdin);	

	for (int i = 0; i < steps; ++i) {
		if (input[i] == 'U') {
			++count;
		} else{
			--count;
		}
		if (count < 0) {
			enter = 1;
		} else if (count == 0 && enter){
			++valleys;
			enter = 0;
		}
	}

	printf("%d\n", valleys);

	free(input);
    return 0;
}
