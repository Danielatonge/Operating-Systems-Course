#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	int *iarray = (int *)malloc(N*sizeof(int));

	for(int i = 0; i < N; i++){
		*(iarray + i) = i;
	}
	
	printf("[");
	for(int i = 0; i < N; i++){
		printf(" %d ", *(iarray + i));
	}	
	printf("]\n");
	free(iarray);

	return 0;
}
