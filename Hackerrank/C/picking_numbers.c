
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define ELEM_MAX 3

void sorting(int *a, int n){
    int temp;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(int argc, char **argv){
    int n, i, temp_count=0,count=0;
    char *input=NULL;
    char *temp, *endptr=NULL;
    int *array=NULL;

    scanf("%d\n", &n);

    input = (char*)malloc(ELEM_MAX*n*(n-1)*sizeof(char));

    array = (int*)malloc(ELEM_MAX*n*(n-1)*sizeof(int));

    fgets(input, ELEM_MAX*n*(n-1)*sizeof(char), stdin);

    i = 0;

    for (temp = strtok(input, " "); temp; temp = strtok(NULL, " ")) {
        array[i] = strtol(temp, &endptr, 0);
        ++i;
    }

    sorting(&array[0], n);

    for (i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(array[i] == array[j] || abs(array[i] - array[j]) == 1){
                ++temp_count;
            } else{
                if (temp_count > count) {
                    count = temp_count;
                    temp_count = 0;
                }
            }
        }
		if (temp_count > count) {
			count = temp_count;
		}
        temp_count = 0;
    }

    printf("%d\n", count+1);

    free(input);
    free(array);
    return 0;
}
