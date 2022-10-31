#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int* data=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	
	for(int i=0;i<n/2;i++){
		int tmp=data[n-i-1];
		data[n-i-1]=data[i];
		data[i]=tmp;
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",data[i]);
	}
	
	return 0;
}
