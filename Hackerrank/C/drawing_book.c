#include<stdlib.h>
#include<stdio.h>

int main(int argc, char **argv){
	int n, p;
	int start, end;

	scanf("%d", &n);
	scanf("%d", &p);

	start = p/2;
	if (n%2 == 0) {
		end = abs(p-n-1)/2;
	} else {
		end = abs(p-n) / 2;
	}

	printf("start: %d end: %d\n", start, end);

	if (start < end) {
		printf("%d\n", start);
	} else {
		printf("%d\n", end);
	}
    return 0;
}
