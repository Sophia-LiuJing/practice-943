#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n,x;
	scanf("%d %d",&n,&x);
	int* data=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	int i=0,j=0;
	for(;i<n;i++){
		if(data[i]==x){
			j++;
		}else data[i-j]=data[i];
	}
	for(int m=0;m<n-j;m++){
		printf("%d ",data[m]);
	}
	return 0;
}
