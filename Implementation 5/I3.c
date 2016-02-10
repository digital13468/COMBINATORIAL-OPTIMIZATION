#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define V 89

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
	int X[V][2]={{0, 7}, {1, 0}, {1, 11}, {1, 19}, {2, 12}, {2, 13}, {3, 13}, {3,
17}, {4, 16}, {4, 18}, {5, 0}, {5, 5}, {5, 8}, {5, 10}, {5, 15}, {6, 1},
{6, 9}, {6, 11}, {7, 4}, {7, 13}, {8, 4}, {8, 14}, {8, 18}, {10, 7},
{11, 2}, {12, 0}, {12, 2}, {12, 3}, {13, 17}, {14, 17}, {15, 7}, {15,
12}, {15, 13}, {15, 15}, {16, 0}, {16, 2}, {16, 6}, {16, 9}, {17, 5},
{17, 17}, {18, 0}, {18, 6}, {18, 17}, {19, 1}, {19, 2}, {21, 9}, {21,
10}, {22, 1}, {22, 5}, {22, 11}, {22, 17}, {22, 18}, {23, 19}, {24, 2},
{24, 3}, {24, 13}, {25, 5}, {25, 11}, {26, 9}, {26, 16}, {27, 4}, {27,
11}, {27, 19}, {28, 0}, {28, 4}, {28, 11}, {29, 19}, {30, 4}, {31, 8},
{31, 10}, {31, 11}, {31, 18}, {32, 1}, {32, 8}, {33, 10}, {33, 14}, {33,
17}, {33, 19}, {34, 4}, {35, 2}, {36, 0}, {36, 6}, {37, 7}, {37, 9},
{38, 13}, {39, 13}, {39, 14}, {39, 15}, {39, 19}};
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
	if((output=fopen("I3output.txt","w"))==NULL)
		printf("\nerror!Fail to open file!");
	else
		printf("\nOpen I3output successfully!\n");
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
	fprintf(output,"%d %d (%d)\n\n",X[0][0],X[0][1],i);
	fprintf(output,"%lf %lf\n",minLength,finalD);
	fclose(output);	
	free(goodT);		
}
