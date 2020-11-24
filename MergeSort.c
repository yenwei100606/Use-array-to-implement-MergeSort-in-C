#include <stdio.h>
#include <stdlib.h>

void MergeSort(int array[],int front,int end){
	if(front<end){
		int mid = (front+end)/2;
		MergeSort(array,front,mid);
		MergeSort(array,mid+1,end);
		merge(array,front,mid,end);
	}
}

void merge(int array[],int front,int mid,int end){
	int lenL = mid - front + 1;
	int lenR = end - (mid+1) + 1;
	int LeftArr[lenL];
	int RightArr[lenR];
	int max=100000;
	int i,j,k;
	
//	Copy origin array to LeftArr and RightArr
	for(i=0;i<lenL;i++){
		LeftArr[i] = array[front+i];
	} 
	for(j=0;j<lenR;j++){
		RightArr[j] = array[mid+1+j];
	}
	
	LeftArr[i] = max;
	RightArr[j] = max;
	i=0;j=0;
	
//	Check the size of the number and sort from small to large
	for(k=front;k<=end;k++){
		if(LeftArr[i] <= RightArr[j]) array[k]=LeftArr[i++];
		else array[k]=RightArr[j++];
	}
	
	
}

void display(int array[]){
	int i;
	for(i=0;i<5;i++){
		printf("%d\t",array[i]);
	}
	printf("\n");
}


int main(void){
	int array[5]={5,4,3,6,9};
	MergeSort(array,0,4);
	display(array);
}
