#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define V 500

double maxFlow=0.0;
double Edge[V][V]={0.0};
int Resource=16;
int Sink=8;
int Path[V];
int nextVertex(int u, int* ptrPath);
int* Augmentation();
void cutSet(int u, int* cutSet, double* edge, double* cedge);
int cutSetSize=0;  
	double cEdge[V][V]={0.0};
                                  
main(){
       
FILE *infile, *outfile; 
int i,j,k;
char id[5000];
char tempC;
char coming[20];
int value;
double fvalue;
size_t loc;
char string[10]="Edges";
	double temp=100000.0;

	double* cedge=&cEdge[0][0];
char string2[2]="];";
char string3[8]="pos";
char symbol;
int u,v;
int begin=0;
int end=0;
int arrayEnd;
double cap=0.0;
char * pch=NULL;
int leave=0;
int index;
if ((infile=fopen("flow4.txt", "r")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");
// if ((outfile=fopen("matrix3.txt", "w")) == NULL)
// 	printf("Fail to open file!");
// else
// 	printf("Open file successfully!\n");

		
	//while (fscanf(infile, "%s", &id)!=EOF){
	while(fgets(id, 5000, infile) != NULL){
		printf("%s\n",id);
  		if (strncmp(id,string,5)==0){
			while(fgets(id, 5000, infile) != NULL){
				if(strncmp(id,string2,1)!=0){
					pch = strrchr(id,')');		      
					if(pch==NULL){
						printf("stop 1, %s",id);
						exit(1);
					}
					arrayEnd = pch-id;
					pch=id;
					do{
						pch = strchr(pch,'(');
						if(pch==NULL){
							printf("stop 2");
							exit(1);
						}
						begin = pch-id;
						pch = strchr(pch,')');
						if(pch==NULL){
							printf("stop 3");
							exit(1);
						}
						end = pch-id;
						
						char *destination = malloc((end-begin+2) * sizeof(char));
						memcpy(destination, id+begin , (end-begin+1) * sizeof(char));
						printf("%s\n",destination);
						if(sscanf(destination, "%*[( ]%d%*[, ]%d%*[, ]%lf%*[, )\\]", &u, &v, &cap)==0){
						  printf("stop  4");
						  exit(1);
						}
						free(destination);
						Edge[u][v]=cap;
						//printf("Edge[%d][%d]=%lf\n", u, v, cap);
						
					}
					while(arrayEnd!=end);
				}
				else{
					leave=1;
					break;
			
				}		    
			}
		}
		if(leave==1)
			break;

	}

	printf("Are we here?");
fclose(infile);
for(i=0;i<V;i++)
   for(j=0;j<V;j++)
     if(Edge[i][j]>0)
	printf("Edge[%d][%d] = %lf\n",i,j,Edge[i][j]);

	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			cEdge[i][j]=Edge[i][j];
	int* rsPath = Augmentation();	

//   	printf("\n\n");
//      	for(i=0;i<V;i++)
//    		printf("%d\t",*(rsPath+i));
	

	for(i=0;i<V-1;i++){
		if(*(rsPath+i+1)>-1 && temp>Edge[*(rsPath+i)][*(rsPath+i+1)])
			temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
		else if(*(rsPath+1)<=-1){
			printf("No Initial Solution Found! Program Stops!\n");
			exit(1);
		}
		//printf("%d\n",temp);
	}	
	maxFlow+=temp;



	while(*(rsPath+1)>-1){
		for(i=0;i<V-1;i++){
 		
 			if(*(rsPath+i+1)>-1){
 				Edge[*(rsPath+i)][*(rsPath+i+1)]=Edge[*(rsPath+i)][*(rsPath+i+1)]-temp;
 				Edge[*(rsPath+i+1)][*(rsPath+i)]=Edge[*(rsPath+i+1)][*(rsPath+i)]+temp;
 				//printf("Edge[%d][%d]=%d\n",i,j,Edge[i][j]);
			}
		}
		
   		for(i=0;i<V;i++)
// 			//printf("\n");
  			printf("%d\t",*(rsPath+i));
//  			//printf("\n");
//  		}
		printf("\nadded flow value: %lf\n",temp);
		rsPath=NULL;
		rsPath=Augmentation();
		temp=100000.0;
		for(i=0;i<V-1;i++)
			if(*(rsPath+i+1)>-1&&temp>Edge[*(rsPath+i)][*(rsPath+i+1)]){
				temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
				//printf("%d temp=%d\n",i,temp);
			}
		if(*(rsPath+1)>-1)
			maxFlow+=temp;
// 		else
// 			for(i=0;i<V;i++)
// 				for(j=;j<V;j++)
// 					if()
	}
//	int rCut=0;
	printf("The max flow value is %lf\n",maxFlow);
// 	for(i=1;i<V;i++)
// 		if(Edge[Resource][i]==0&&cEdge[Resource][i]>0)
// 			rCut++;
// 	int * initialCut=malloc(rCut*sizeof(int));
// 	int x=0;
// 	for(i=1;i<V;i++)
// 		if(Edge[Resource][i]==0&&cEdge[Resource][i]>0){
// 			*(initialCut+x)=i;
// 			x++;
// 		}
// 	int* edge=&Edge[0][0];
// 	int* cedge=&cEdge[0][0];
// 	for(i=0;i<x;i++)
// 		cutSet(i,initialCut,edge,cedge,x);
//   	for(i=0;i<V;i++)
//   		for(j=0;j<V;j++)
//   			printf("Edge[%d][%d]=%d\t",i,j,Edge[i][j]); 
	//int* finalCut;
	double* edge=&Edge[0][0];
	cutSetSize=1;
 	int* initialCut=malloc(1*sizeof(int));
 
 	*(initialCut+0)=Resource;
	//int finalCut=0;
	cutSet(Resource,initialCut,edge,cedge);
	printf("cutsize %d\n",cutSetSize);
	printf("The R set includes:\n");
	for(i=0;i<cutSetSize;i++)
		printf("%d ",*(initialCut+i));
	printf("\n");
	int* rBar = malloc((V-cutSetSize)*sizeof(int));
	//printf("%d ",*(rBar+1));
	int rBarIndex=0;
	double minCutValur=0.0;
	for(i=0;i<V;i++)
	  for(j=0;j<cutSetSize;j++)
	    if(*(initialCut+j)!=i){
	      if(j==cutSetSize-1){
		*(rBar+rBarIndex)=i;
		rBarIndex++;
		printf("%d ",*(rBar+rBarIndex-1));
	      }
	    }
	    else
	      break;
	    
	for(i=0;i<V-cutSetSize;i++)
	  for(j=0;j<cutSetSize;j++)
	    if(Edge[*(initialCut+j)][*(rBar+i)]==0&&Edge[*(rBar+i)][*(initialCut+j)]>0&&cEdge[*(initialCut+j)][*(rBar+i)]==Edge[*(rBar+i)][*(initialCut+j)]){
	      minCutValur+=Edge[*(rBar+i)][*(initialCut+j)];
	      printf("\nThe minimum cut value is %lf\n",minCutValur);
	    }
	free(initialCut);
	free(rBar);
}
void cutSet(int u, int * initialCut, double* edge, double* cedge){
	int i,j,k;
	int currentSetSize=cutSetSize;
	//printf("BEFORE %d\n",cutSetSize);
	for(i=0;i<V;i++)
		if(*(edge+u*V+i)>0){
			//printf("New Cut Might be Found!\n");
			
			int skipFlag=0;
			//int * existingCut=malloc(cutSetSize-1*sizeof(int));
			//int * newCut=malloc(cutSetSize*sizeof(int));
			//*(newNode+0)=i;
			//memcpy(existingCut,initialCut,sizeof(initialCut));
			//increaseSize=1;
			for(k=0;k<currentSetSize;k++){
			  printf("%d ",*(initialCut+k));//increaseSize=1;
			    if(*(initialCut+k)==i){
			      skipFlag=1;
			      printf("Node %d exists already!\n",i);
			     }
			}
			printf("\n");
			if(skipFlag==0){
			    cutSetSize++;
			    printf("new cut size %d\n",cutSetSize);
			    initialCut = realloc(initialCut,cutSetSize*sizeof(int));
			    if(!initialCut){
			      printf("error!\n");
			      exit(1);
			    }
			    *(initialCut+cutSetSize-1)=i;
			    printf("Node %d is added!\n",i);
			    printf("The new set includes now:\n");
			    for(j=0;j<cutSetSize;j++)
			      printf("%d ",*(initialCut+j));
			    printf("\n");
			    cutSet(i,initialCut,edge,cedge);
			}
// 			else
// 			  printf("Node(s) already exists!\n");
			//memcpy(initialCut,exisitingCut,sizeof(newNode));

			//if(increaseSize==1)
			  
			//free(newCut);
		}
	//printf("AFTER %d\n",cutSetSize);
//  		else{
// 			    printf("No new Nodes Found!\nThe set is still:\n");
// 			    for(j=0;j<cutSetSize;j++)
// 			      printf("%d ",*(initialCut+j));
// 			    printf("\n");
// 		}
// 			printf("%d %d\n",*(edge+u*V+i),*(cedge+u*V+i));
	//return increaseSize;
}
int * Augmentation(){
	//int Pre[V]={-1};
	int i=0;
	int counter=0;
	for(i=0;i<V;i++)
	  Path[i]=-1;
	int* ptrPath;
	ptrPath=&Path[0];
//  	for(i=0;i<V;i++)
//   		printf("%d\t",*(ptrPath+i));
// 	printf("\n");
	Path[0]=Resource;
	nextVertex(Resource,ptrPath);
	
 	for(i=0;i<V;i++){
 		//printf("%d\t",*(ptrPath+i));
 		if(*(ptrPath+i)==Sink)
 			counter++;
 	}
 	if(counter==0){
 		printf("No Path Found!\n");
 		for(i=0;i<V;i++)
		  *(ptrPath+i)=-1;
 	}
	return ptrPath;
}

int nextVertex(int u, int* ptrPath){
	int i,j,k,jump;
	int y=0;
	
	//printf("This is node %d (V=%d)\n",u,V);
	for(i=0;i<V;i++){
		//printf("i=%d",i);
		jump=0;
		for(k=0;k<V;k++)
			if(*(ptrPath+k)==i){
				jump=1;
				break;
			}
		if(jump==1&&i!=V-1)
			continue;
		else if(jump==1&&i==V-1){
		  for(j=0;j<V;j++)
			if(*(ptrPath+j)==u){
				*(ptrPath+j)=-1;
				break;
					//printf("%d is deleted from position %d.\n",u,j);
			}
		  continue;
		}
				//jump=1;
		if(Edge[u][i]>0){
			//printf("Edge[%d][%d] is selected (%lf).\n",u,i,Edge[u][i]);
			for(j=0;j<V;j++)
				if(*(ptrPath+j)==u){
					*(ptrPath+j+1)=i;
			//		printf("%d is added to posistion %d. (Edge[%d][%d]=%lf)\n",i,j+1,u,i,Edge[u][i]);
					break;
				
				}
			if(i!=Sink){
			//	printf("Search for the next node for %d.\n",i);
				y=nextVertex(i,ptrPath);	
				if(y==1){
			//	  printf("Path has been found. (%d)\n",i);
					break;
				}
			}
			else{
				y=1;
			//	printf("Path has been found. (%d)\n",i);
				break;	
			}
		}
		else if(V-1==i){
			//printf("All other nodes has been reached.\n");
			for(j=0;j<V;j++)
				if(*(ptrPath+j)==u){
					*(ptrPath+j)=-1;
					//printf("%d is deleted from position %d.\n",u,j);
				}
		}
// 		else if(V-1!=i)
// 		  printf("V=%d i=%d",V,i);
		
	}
	return y;		

}


