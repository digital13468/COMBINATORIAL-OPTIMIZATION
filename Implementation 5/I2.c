#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define V 55

int* initial(double* ptrD,int iniV){
	int *t=malloc(sizeof(int)*V);
	//int *ptrT=&t[0];
	int *visited=malloc(sizeof(int)*V);
	int i,j;
	double shortest;
	int temp;
	int allV=0;
	int currentV=iniV;
	
	for(i=0;i<V;i++)
		*(visited+i)=0;

	*(visited+iniV)=1;
	while(allV==0){	
		temp=-1;
		shortest=100000000;
		for(i=0;i<V;i++)
			if(i!=currentV&&*(visited+i)==0&&*(ptrD+currentV*V+i)<shortest){
				shortest=*(ptrD+currentV*V+i);
				temp=i;
				//printf("%d to %d with distance %lf\n",currentV,i,*(ptrD+currentV*V+i));
			}
		
		
		if(temp==-1){
			//printf("%d is the last.",temp);
			*(t+currentV)=iniV;
			allV=1;
		}
		else{
			*(visited+currentV)=1;
			*(t+currentV)=temp;
			currentV=temp;
		}
		/*for(i=0;i<V;i++)
			if(*(visited+i)==0){
				allV=0;
				break;
			}
			else{
				allV=1;
				*(t+currentV)=iniV;
				printf("%d\n",iniV);
			}*/
	}
	free(visited);
	//for(i=0;i<V;i++)
		//printf("%d to %d\n",i,*(t+i));
	return t;
}

main(){
	int X[V][2]={{0, 8}, {1, 1}, {1, 4}, {1, 5}, {2, 0}, {2, 1}, {2, 3}, {2, 9}, {3,2}, {3, 9}, {4, 2}, {4, 4}, {4, 6}, {4, 8}, {4, 9}, {5, 3}, {5, 4}, {5,5}, {5, 7}, {5, 8}, {6, 0}, {6, 4}, {6, 8}, {7, 3}, {7, 6}, {8, 1}, {8,5}, {8, 6}, {9, 4}, {10, 3}, {10, 5}, {11, 5}, {11, 6}, {12, 2}, {12,7}, {12, 8}, {13, 0}, {13, 3}, {13, 4}, {14, 1}, {14, 4}, {14, 6}, {14,8}, {15, 4}, {15, 6}, {15, 8}, {15, 9}, {16, 2}, {16, 5}, {16, 8}, {17,8}, {17, 9}, {18, 5}, {18, 7}, {19, 1}};
	int i,j;
	
	double distance[V][V]={0.0};
	double* ptrD=&distance[0][0];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++){
			//printf("%d to %d is %lf\n",i,j,distance[i][j]);
			distance[i][j]=sqrt(pow(X[i][0]-X[j][0],2)+pow(X[i][1]-X[j][1],2));
			printf("%d to %d is %lf\n",i,j,distance[i][j]);	
		}

	int start=-1;
	double tourLength;
	double minLength=1000000.0;
	int* goodT=malloc(sizeof(int)*V);
	for(i=0;i<V;i++){
		tourLength=0.0;
		int* tour=malloc(sizeof(int)*V);
		tour=initial(ptrD,i);
		for(j=0;j<V;j++)
			tourLength+=distance[j][*(tour+j)];
		printf("Starting from vertex %d, the tour length is %lf\n",i,tourLength);
		if(tourLength<minLength){
			minLength=tourLength;
			goodT=initial(ptrD,i);
			start=i;
		}
		free(tour);
	}
	printf("it starts from node %d\n",start);

	FILE* output;
	if((output=fopen("I2output.txt","w"))==NULL)
		printf("\nerror!Fail to open file!");
	else
		printf("\nOpen I2output successfully!\n");
	fprintf(output,"##This is the output of I1\n\n#Coordinates\n");
	for(i=0;i<V;i++)
		fprintf(output,"%d %d %d\n",i,X[i][0],X[i][1]);
	fprintf(output,"\n\n#Tour\n");
	i=0;
	do{
		fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[i][0],X[i][1],i,X[*(goodT+i)][0],X[*(goodT+i)][1],*(goodT+i),distance[i][*(goodT+i)]);
		i=*(goodT+i);
	}
	while(i!=0);
	fprintf(output,"%d %d (%d)\n",X[0][0],X[0][1],i);
	fprintf(output,"%lf\n",minLength);
	//double originalLength=minLength;
	double updatedLength=minLength;
	int k,l;
	int moving;
	int stop;
	int first;
	int second;
	int update=1;
	int totalNodes;
	
	while(update==1){
		update=0;
		for(i=0;i<V;i++)
			for(j=0;j<V;j++)
				if(i!=j&&j!=*(goodT+i)&&*(goodT+j)!=i&&j!=*(goodT+*(goodT+i))){
					if(updatedLength>minLength-distance[i][*(goodT+i)]-distance[j][*(goodT+j)]+distance[*(goodT+i)][*(goodT+j)]+distance[i][j]){
						updatedLength=minLength-distance[i][*(goodT+i)]-distance[j][*(goodT+j)]+distance[*(goodT+i)][*(goodT+j)]+distance[i][j];
						moving=*(goodT+i);
						stop=j;
						first=i;
						second=j;
						update=1;
						l=*(goodT+second);
						printf("better tour is found (i=%d j=%d new length=%lf).\n",i,j,updatedLength);
					}	

				}
		printf("%d connects to %d\n",second,*(goodT+second));
		if(update==1){
			totalNodes=1;
			k=moving;
			while(k!=stop){
				totalNodes++;
				k=*(goodT+k);//printf("moving=%d stop=%d first=%d second=%d\n",moving,stop,first,second);
			}
			//printf("k = %d\n",totalNodes);
			int* segement=malloc(sizeof(int)*totalNodes);
			for(k=0;k<totalNodes;k++){
				*(segement+k)=moving;
				moving=*(goodT+moving);
			}//printf("test\n");
			for(k=totalNodes;k>1;k--)	
				*(goodT+*(segement+k-1))=*(segement+k-2);
			free(segement);
// 				if(*(goodT+k)==moving){
 					
// 					*(goodT+moving)=k;
// 					moving=k;
// 					break;
// 				}
			minLength=updatedLength;
			*(goodT+*(goodT+first))=l;
			//printf("%d connects to %d\n",second,*(goodT+second));
			*(goodT+first)=second;
			//printf("update soluting...\n");
		}
	}
	double finalD=0.0;
	fprintf(output,"\n\n#Improved Tour\n");
	i=0;
	do{
		fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[i][0],X[i][1],i,X[*(goodT+i)][0],X[*(goodT+i)][1],*(goodT+i),distance[i][*(goodT+i)]);
		i=*(goodT+i);
		finalD+=distance[i][*(goodT+i)];
	}
	while(i!=0);
	fprintf(output,"%d %d (%d)\n",X[0][0],X[0][1],i);
	fprintf(output,"%lf %lf\n",minLength,finalD);
	fclose(output);	
	free(goodT);		
}
