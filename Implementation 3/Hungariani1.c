#include <stdio.h>
#include <stdlib.h>
//#define w 10
#define w 10
#include "AugmentingPath.h"

main(){
// 	int W[w][w] = { 
// 	{  1 ,  0 ,  7 ,  4 ,  9 ,  6 ,  3 ,  9 ,  4 ,  0 },
// 	{  6 ,  4 ,  7 ,  1 ,  6 ,  7 ,  7 ,  6 ,  7 ,  5 },
// 	{  2 ,  7 ,  6 ,  9 ,  6 ,  1 ,  2 ,  2 ,  0 ,  2 },
// 	{  9 ,  0 ,  7 ,  1 ,  5 ,  0 ,  7 ,  4 ,  8 ,  4 },
// 	{  4 ,  1 ,  9 ,  2 ,  0 ,  8 ,  8 ,  8 ,  2 ,  9 },
// 	{  1 ,  4 ,  3 ,  3 ,  3 ,  4 ,  0 ,  3 ,  5 ,  9 },
// 	{  2 ,  6 ,  7 ,  7 ,  0 ,  6 ,  7 ,  8 ,  1 ,  9 },
// 	{  9 ,  2 ,  6 ,  8 ,  1 ,  3 ,  2 ,  1 ,  9 ,  4 },
// 	{  1 ,  1 ,  9 ,  1 ,  8 ,  2 ,  8 ,  1 ,  7 ,  8 },
// 	{  9 ,  0 ,  8 ,  2 ,  7 ,  2 ,  4 ,  5 ,  8 ,  0 } 
// 	};
// 	int W[w][w]={
// 	  {5,2,2,7,0},
// 	  {0,0,0,3,0},
// 	  {1,3,8,0,9},
// 	  {0,1,0,6,1},
// 	  {9,1,0,0,6}
// 	};
	int W[w][w]={
{  1 ,  0 ,  7 ,  4 ,  9 ,  6 ,  3 ,  9 ,  4 ,  0 },
{  6 ,  4 ,  7 ,  1 ,  6 ,  7 ,  7 ,  6 ,  7 ,  5 },
{  2 ,  7 ,  6 ,  9 ,  6 ,  1 ,  2 ,  2 ,  0 ,  2 },
{  9 ,  0 ,  7 ,  1 ,  5 ,  0 ,  7 ,  4 ,  8 ,  4 },
{  4 ,  1 ,  9 ,  2 ,  0 ,  8 ,  8 ,  8 ,  2 ,  9 },
{  1 ,  4 ,  3 ,  3 ,  3 ,  4 ,  0 ,  3 ,  5 ,  9 },
{  2 ,  6 ,  7 ,  7 ,  0 ,  6 ,  7 ,  8 ,  1 ,  9 },
{  9 ,  2 ,  6 ,  8 ,  1 ,  3 ,  2 ,  1 ,  9 ,  4 },
{  1 ,  1 ,  9 ,  1 ,  8 ,  2 ,  8 ,  1 ,  7 ,  8 },
{  9 ,  0 ,  8 ,  2 ,  7 ,  2 ,  4 ,  5 ,  8 ,  0 } 
};;
	//int * ptrW=&W[0][0];
	int * ptrW=malloc(w*w*sizeof(int));
	int * Q;
 	int i,j;
	int epsilon;
	int setN;
	int v[w]={0};
	int u[w];
	int U;
	int vertexCover=0;
	int Matching=0;
	for(i=0;i<w;i++){
		u[i]=0;
		for(j=0;j<w;j++){
		//	*(ptrW+i*w+j)=W[i][j];//printf("%d ",W[i][j]);
			if(u[i]<W[i][j])
				u[i]=W[i][j];
		}
		for(j=0;j<w;j++){
			*(ptrW+i*w+j)=u[i]-W[i][j];
			printf("%d ",*(ptrW+i*w+j));
		//	if(u[i]<W[i][j])
		//		u[i]=W[i][j];
		}
		
	}
	do{
		printf("\nu array:\n");
		for(i=0;i<w;i++)
			printf("%d ",u[i]);
		printf("\nv array:\n");
		for(i=0;i<w;i++)
			printf("%d ",v[i]);
		
		Q=MaximumMatching(ptrW);
		setN=0;
		printf("\nNodes in set of R: ");
		for(i=0;i<w;i++){

			if(*(Q+i)==1){
				//numQ++;
				//Q[i]=1;
				printf("%d ",i);
				setN++;
			}

		}
		printf("\nNodes in set of T: ");
		for(i=w;i<2*w;i++){
					
			if(*(Q+i)==1){
				//numQ++;
				//Q[i+w]=1;
				printf("%d ",i-w);
				setN++;
			}

		}
/*		printf("\n");
		for(i=0;i<2*w;i++)
			printf("%d ",*(Q+i));*/		
		if(setN!=w){
			epsilon=9999999;
			for(i=0;i<w;i++)
				for(j=0;j<w;j++)
					if(*(Q+i)==0&&*(Q+j+w)==0)
						if(*(ptrW+i*w+j)<epsilon)
							epsilon=*(ptrW+i*w+j);
			printf("epsilon=%d\n",epsilon);
			for(i=0;i<w;i++){
				for(j=0;j<w;j++)
					if(*(Q+i)==0&&*(Q+j+w)==0)
						*(ptrW+i*w+j)=*(ptrW+i*w+j)-epsilon;
					else if(*(Q+i)==1&&*(Q+j+w)==1)
						*(ptrW+i*w+j)=*(ptrW+i*w+j)+epsilon;
				if(*(Q+i)==0)
					u[i]=u[i]-epsilon;
				if(*(Q+i+w)==1)
					v[i]=v[i]+epsilon;
			}
			printf("vertex cover:\n");
			for(i=0;i<w;i++){
				printf("%d ",u[i]);
				printf("%d ",v[i]);
			}
		}
		else{
			printf("perfect matching found.\n");
			for(i=0;i<w;i++){
				vertexCover=vertexCover+u[i]+v[i];
				Matching=Matching+W[i][*(Q+2*w+i)];
			}
			if(vertexCover!=Matching){
				printf("Vertex cover doesn't match mathching!\n");
;

				exit(1);
			}
			else
				printf("Matching: %d= Vertex Cover: %d\n",Matching, vertexCover);
		}
// 		for(i=0;i<2*w;i++)
// 			printf("%d ",*(Q+i));
		
	}while(setN!=w);
	free(ptrW);
}
