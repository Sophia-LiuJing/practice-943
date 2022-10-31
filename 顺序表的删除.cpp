#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n==0){
		printf("error\n");
		return 0;
	} 
	int* data=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	int min=data[0],minpos=0;
	for(int i=0;i<n;i++){
		if(data[i]<min){
			min=data[i];
			minpos=i;
		}
	}
	data[minpos]=data[n-1];
	n--;
	for(int i=0;i<n;i++){
		printf("%d ",data[i]);
	}

	return 0;
}
