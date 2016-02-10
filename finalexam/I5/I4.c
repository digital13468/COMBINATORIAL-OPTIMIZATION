#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define V 50

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
	int X[V][2]= {{3, 80}, {25, 73}, {7, 50}, {9, 56}, {43, 5}, {1, 34}, {12, 78}, {2, 55}, {40, 40}, {17, 60}, {90, 1}, {6, 77}, {19, 51}, {61, 38}, {8, 54}, {18, 28}, {52, 47}, {3, 47}, {3, 64}, {9, 16}, {5, 67}, {60, 39}, {30, 13}, {47, 7}, {30, 48}, {135, 60}, {52, 11}, {82, 46}, {31, 45}, {7, 3}, {151, 53}, {66, 77}, {63, 59}, {55, 66}, {25, 43}, {49, 67}, {159, 60}, {36, 5}, {0, 25}, {92, 19}, {103, 13}, {24, 1}, {1, 22}, {33, 24}, {0, 8}, {2, 7}, {137, 2}, {8, 61}, {136, 8}, {17, 78}};
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
		//fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[i][0],X[i][1],i,X[*(goodT+i)][0],X[*(goodT+i)][1],*(goodT+i),distance[i][*(goodT+i)]);
		fprintf(output,"(%d, %d)",X[i][0],X[i][1]);
		i=*(goodT+i);
	}
	while(i!=0);
	fprintf(output,"(%d, %d)\n",X[0][0],X[0][1],i);
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
	double ID;
	int z;
	int x=0;
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
			fprintf(output,"\n\n#Improve Tour %d\n",++x);
			z=0;
			do{
				//fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[z][0],X[z][1],i,X[*(goodT+z)][0],X[*(goodT+z)][1],*(goodT+z),distance[z][*(goodT+z)]);
				fprintf(output,"(%d, %d)",X[z][0],X[z][1]);
				z=*(goodT+z);
			}
			while(z!=0);
			fprintf(output,"(%d, %d)\n",X[0][0],X[0][1],z);
			fprintf(output,"%lf\n",minLength);
		}
	}
	double finalD=0.0;
	fprintf(output,"\n\n#Improved Tour\n");
	i=0;
	do{
		//fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[i][0],X[i][1],i,X[*(goodT+i)][0],X[*(goodT+i)][1],*(goodT+i),distance[i][*(goodT+i)]);
		fprintf(output,"(%d, %d)",X[i][0],X[i][1]);
		i=*(goodT+i);
		finalD+=distance[i][*(goodT+i)];
	}
	while(i!=0);
	fprintf(output,"(%d, %d)\n\n\n",X[0][0],X[0][1],i);
	fprintf(output,"%lf %lf\n",minLength,finalD);
	fclose(output);	
	free(goodT);		
}