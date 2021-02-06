#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SIZE 7
#define ROWS 3

void rotate_matrix(int *matrix){
	int temp_array[9] = {0};
	for (int i = 0; i < 9; ++i) {
		temp_array[(i+2*(i+1))-((i+2*(i+1))/9)*10] = matrix[i];
	}

	for (int i = 0; i < 9; ++i) {
		matrix[i] = temp_array[i];
	}
}

void traspose_matrix(int *matrix){
	int temp;
	for (int i = 0; i < 6; ++i) {
		if (i == 1) {
			temp = matrix[i];
			matrix[i] = matrix[3];
			matrix[3] = temp;
		} 
		if (i == 2) {
			temp = matrix[i];
			matrix[i] = matrix[6];
			matrix[6] = temp;
		}
		if (i == 5) {
			temp = matrix[i];
			matrix[i] = matrix[7];
			matrix[7] = temp;
		}
	}
}

int minimum_cost(int *input_matrix){
	int magic_square[9] = {6,1,8,7,5,3,2,9,4};
	int temp=0;
	int result=1000000;

	for (int i = 0; i < 8; ++i) {
		if (i == 1 || i == 2 || i == 3) {
			rotate_matrix(&magic_square[0]);
		}
		if (i == 4) {
			rotate_matrix(&magic_square[0]);
			traspose_matrix(&magic_square[0]);
		}
		if (i == 5 || i == 6 || i == 7) {
			rotate_matrix(&magic_square[0]);
		}

		for (int j = 0; j < 9; ++j) {
			temp += abs(input_matrix[j]-magic_square[j]);
		}

		if (temp < result) {
			result = temp;
		}
		temp = 0;
	}
	
	return result;
}

int main(int argc, char **argv){
	char *input=NULL;
	char *temp_row = NULL;
	char *endptr=NULL;
	int *input_matrix = NULL;
	int j=0;

	input = (char*)malloc(SIZE*sizeof(char));
	input_matrix = (int*)malloc(3*ROWS*sizeof(int));

	for (int i = 0; i < ROWS; ++i) {
		fgets(input, SIZE*sizeof(char), stdin);
		for (temp_row = strtok(input, " "); temp_row; temp_row = strtok(NULL, " ")) {
			input_matrix[j] = strtol(temp_row, &endptr, 0);
			++j;
		}
	}

	printf("%d\n", minimum_cost(&input_matrix[0]));

	free(input_matrix);
	free(input);
    return 0;
}
