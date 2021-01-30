#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define NMAX 3

int main(int argc, char **argv){
    int squares_number;

    scanf("%d\n", &squares_number);

    char *buffer = (char*)malloc(2*NMAX*squares_number*sizeof(*buffer));
    int *squares = (int*) malloc(2*NMAX*squares_number*sizeof(*squares));
    char *temp;

    fgets(buffer, 2*NMAX*squares_number*sizeof(*buffer), stdin);

    char * endptr=NULL;
    int i=0;

    for (temp = strtok(buffer, " "); temp; temp = strtok(NULL, " ")) {
        squares[i] = strtol(temp, &endptr, 0);
        ++i;
    }

    int d,m,count=0,total=0;

    scanf("%d %d", &d, &m);

    if (m == squares_number){
        for (i = 0; i < squares_number; ++i){
            total+=squares[i];
            if(total == d){ ++count; }
        }
    }
    else{
        for (i = 0; i < squares_number-m+1; ++i) {
            for (int j = i; j < m+i; ++j) {
                total+=squares[j];
            }
			if(total == d){ 
					++count;
			}
            total=0;
        }
    }

    printf("%d\n", count);

    free(buffer);
    free(squares);
    return 0;
}
