#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define NMAX 6

int main(int argc, char **argv){
	int n,k,i=0,charge;
	char *input=NULL;
	char *temp=NULL;
	char *endptr=NULL;
	int *items;
	int total=0;

	scanf("%d %d\n", &n, &k);

	input = (char*)malloc((n-1)*NMAX*sizeof(char));
	items = (int*)malloc((n-1)*NMAX*sizeof(int));

    fgets(input, (n-1)*NMAX*sizeof(char), stdin);

    for (temp = strtok(input, " "); temp; temp = strtok(NULL, " ")) {
        items[i] = strtol(temp, &endptr, 0);
        ++i;
    }

	scanf("%d\n", &charge);

	for (i = 0; i < n; ++i) {
		if(i != k){
			total+=items[i];
		}
	}

	if ((int)total/2 == charge) {
		printf("%s\n", "Bon Appetit");
	}
	else{
		printf("%d\n", charge - (int)total/2);
	}

	free(input);
	free(items);

    return 0;
}
