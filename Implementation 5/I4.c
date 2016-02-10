#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define V 206

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
	int X[V][2]= {{0, 12}, {0, 17}, {0, 30}, {1, 1}, {1, 2}, {1, 13}, {2, 42}, {3, 0}, {3, 1}, {3, 12}, {3, 31}, {4, 13}, {4, 26}, {4, 36}, {4, 43}, {5, 6}, {5, 33}, {6, 5}, {6, 11}, {6, 12}, {6, 22}, {7, 6}, {7, 18}, {7, 36}, {7, 37}, {8, 8}, {8, 28}, {8, 40}, {10, 11}, {10, 18}, {10, 35}, {11, 4}, {11, 35}, {11, 38}, {12, 9}, {13, 13}, {13, 14}, {13, 31}, {14, 16}, {14, 17}, {14, 18}, {14, 22}, {14, 30}, {14, 34}, {14, 36}, {15, 24}, {15, 29}, {16, 11}, {16, 18}, {17, 16}, {17, 33}, {18, 0}, {18, 12}, {18, 34}, {18, 43}, {19, 7}, {19, 11}, {20, 5}, {20, 7}, {21, 13}, {21, 37}, {21, 40}, {22, 28}, {22, 44}, {25, 8}, {25, 34}, {25, 43}, {26, 9}, {26, 13}, {26, 14}, {26, 16}, {26, 19}, {26, 20}, {26, 27}, {29, 11}, {29, 19}, {29, 29}, {31, 15}, {31, 20}, {31, 29}, {31, 38}, {31, 44}, {33, 5}, {33, 10}, {33, 32}, {34, 13}, {34, 16}, {34, 37}, {35, 13}, {36, 1}, {36, 4}, {36, 20}, {36, 40}, {36, 44}, {38, 0}, {38, 5}, {38, 10}, {38, 23}, {38, 35}, {38, 36}, {38, 39}, {39, 9}, {39, 24}, {39, 29}, {39, 42}, {40, 12}, {40, 16}, {40, 27}, {40, 31}, {41, 1}, {41, 34}, {42, 14}, {42, 24}, {42, 41}, {44, 7}, {44, 11}, {45, 16}, {46, 22}, {47, 13}, {47, 36}, {47, 43}, {48, 29}, {48, 34}, {49, 1}, {50, 32}, {51, 29}, {51, 37}, {51, 42}, {52, 5}, {52, 27}, {53, 16}, {54, 6}, {54, 39}, {56, 11}, {56, 24}, {56, 44}, {58, 28}, {58, 43}, {61, 5}, {61, 12}, {61, 24}, {62, 9}, {62, 30}, {62, 37}, {63, 12}, {64, 21}, {64, 22}, {64, 24}, {65, 6}, {65, 7}, {66, 5}, {66, 29}, {66, 42}, {66, 44}, {67, 15}, {67, 32}, {68, 16}, {68, 25}, {69, 34}, {70, 0}, {71, 39}, {72, 26}, {73, 31}, {74, 0}, {74, 11}, {74, 23}, {74, 42}, {75, 17}, {75, 24}, {75, 35}, {76, 10}, {76, 27}, {76, 35}, {77, 30}, {78, 11}, {78, 34}, {78, 42}, {79, 14}, {79, 15}, {79, 19}, {79, 20}, {79, 25}, {79, 31}, {80, 1}, {80, 29}, {82, 8}, {82, 9}, {82, 10}, {82, 14}, {82, 26}, {83, 23}, {84, 16}, {84, 29}, {84, 39}, {85, 6}, {86, 2}, {86, 22}, {86, 41}, {88, 35}, {88, 37}, {89, 7}, {89, 9}, {89, 14}, {89, 18}, {89, 33}, {89, 41}};
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
	if((output=fopen("I4output.txt","w"))==NULL)
		printf("\nerror!Fail to open file!");
	else
		printf("\nOpen I4output successfully!\n");
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
	fprintf(output,"%d %d (%d)\n\n\n",X[0][0],X[0][1],i);
	fprintf(output,"%lf %lf\n",minLength,finalD);
	fclose(output);	
	free(goodT);		
}
