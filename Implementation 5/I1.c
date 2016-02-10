#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#define V 16

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
	for(i=0;i<V;i++)
		printf("%d to %d\n",i,*(t+i));
	return t;
}

main(){
	int X[V][2]={{1, 1},{1, 5},{3, 0},{3, 1},{6, 0},{7, 0},{7, 1},{7, 8},{12, 9},{13, 0},{14, 3},{15, 1},{16, 3},{16, 8},{17, 5},{18, 6}};
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
	if((output=fopen("I1output.txt","w"))==NULL)
		printf("\nerror!Fail to open file!");
	else
		printf("\nOpen I1output successfully!\n");
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
	
	//double originalLength=minLength;
	double updatedLength=minLength;
	int k;
	int moving;
	int stop;
	int first;
	int second;
	int update=1;
	
	while(update==1){
		update=0;
		for(i=0;i<V;i++)
			for(j=0;j<V;j++)
				if(i!=j&&j!=*(goodT+i)&&*(goodT+j)!=i&&j!=*(goodT+*(goodT+i))){
					if(updatedLength>minLength-distance[i][*(goodT+i)]-distance[j][*(goodT+j)]+distance[*(goodT+i)][*(goodT+j)]+distance[i][j]){
						updatedLength=minLength-distance[i][*(goodT+i)]-distance[j][*(goodT+j)]+distance[*(goodT+i)][*(goodT+j)]+distance[i][j];
						moving=j;
						stop=*(goodT+i);
						first=i;
						second=j;
						update=1;

						printf("better tour is found (i=%d j=%d new length=%lf).\n",i,j,updatedLength);
					}	

				}
		if(update==1){
			while(moving!=stop)
				for(k=0;k<V;k++)
					if(*(goodT+k)==moving){
						*(goodT+moving)=k;
						moving=k;
						break;
					}
			minLength=updatedLength;
			*(goodT+*(goodT+first))=*(goodT+second);
			*(goodT+first)=second;
			printf("update soluting...");
		}
	}
	
	fprintf(output,"\n\n#Improved Tour\n");
	i=0;
	do{
		fprintf(output,"%d %d (%d) to %d %d (%d) distance %lf\n",X[i][0],X[i][1],i,X[*(goodT+i)][0],X[*(goodT+i)][1],*(goodT+i),distance[i][*(goodT+i)]);
		i=*(goodT+i);
	}
	while(i!=0);
	fprintf(output,"%d %d (%d)\n",X[0][0],X[0][1],i);
	
	fclose(output);	
	free(goodT);		
}
