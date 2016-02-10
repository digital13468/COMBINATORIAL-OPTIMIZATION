#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define V 8

double maxFlow=0.0;
double Edge[V][V]={0.0};
int Resource=0;
int Sink=V-1;
int Path[V];
int nextVertex(int u, int* Path);
int* Augmentation();
void cutSet(int u, int* cutSet, double* edge, double* cedge);
int cutSetSize=0;                        
main(){
	Edge[0][1]=6.0;	Edge[0][2]=3.0;	Edge[0][3]=1.0;	Edge[1][4]=3.0;	Edge[1][5]=2.0;	Edge[2][4]=3.0;	Edge[2][5]=4.0;	Edge[2][6]=1.0;	Edge[3][5]=3.0;	Edge[3][6]=7.0;	Edge[4][7]=9.0;	Edge[5][7]=6.0;	Edge[6][7]=10.0;
	int i,j;
	//int cut[V]={0};	
	double temp=100000.0;
	double cEdge[V][V]={0.0};
	double* cedge=&cEdge[0][0];
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			cEdge[i][j]=Edge[i][j];
	int* rsPath = Augmentation();	

//   	printf("\n\n");
//      	for(i=0;i<V;i++)
//    		printf("%d\t",*(rsPath+i));
	

	for(i=0;i<V-1;i++){
		if(*(rsPath+i+1)!=-1 && temp>Edge[*(rsPath+i)][*(rsPath+i+1)])
			temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
		else if(*(rsPath+1)==-1){
			printf("No Initial Solution Found! Program Stops!\n");
			exit(1);
		}
		//printf("%d\n",temp);
	}	
	maxFlow+=temp;



	while(*(rsPath+1)!=-1){
		for(i=0;i<V-1;i++){
 		
 			if(*(rsPath+i+1)!=-1){
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
			if(*(rsPath+i+1)!=-1&&temp>Edge[*(rsPath+i)][*(rsPath+i+1)]){
				temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
				//printf("%d temp=%d\n",i,temp);
			}
		if(*(rsPath+1)>0)
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
 	}
	return ptrPath;
}

int nextVertex(int u, int* Path){
	int i,j,k,jump;
	int y=0;
	
	//printf("This is node %d\n",u);
	for(i=0;i<V;i++){
		jump=0;
		for(k=0;k<V;k++)
			if(*(Path+k)==i){
				jump=1;
				break;
			}
		if(jump==1)
			continue;
				//jump=1;
		if(Edge[u][i]>0){
			printf("Edge[%d][%d] is selected.\n",u,i);
			for(j=0;j<V;j++)
				if(*(Path+j)==u){
					*(Path+j+1)=i;
					printf("%d is added.\n",i);
					break;
				
				}
			if(i!=Sink){
				y=nextVertex(i,Path);	
				if(y==1)
					break;
			}
			else{
				y=1;
				break;	
			}
		}
		else if(i==V-1)
			for(j=0;j<V;j++)
				if(*(Path+j)==u){
					*(Path+j)=-1;
					printf("%d is deleted.\n",u);
				}
		
	}
	return y;		

}
