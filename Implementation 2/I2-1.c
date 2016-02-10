#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define V 24

double maxFlow=0.0;
double Edge[V][V]={0.0};
int Resource=16;
int Sink=8;
int Path[V];
int nextVertex(int u, int* ptrPath);
int* Augmentation();
void cutSet(int u, int* cutSet, double* edge, double* cedge);
int cutSetSize=0;                        
main(){
	Edge[16][20]=25.0;	Edge[20][21]=15.0;	Edge[21][22]=10.0;	Edge[22][23]=5.0;	Edge[23][0]=3.0;	Edge[16][17]=35.0;	Edge[20][12]=16.0;	Edge[21][14]=6.0;	Edge[22][9]=8.0;	Edge[23][2]=3.0;	Edge[0][1]=2.0;		Edge[17][12]=12.0;	
	Edge[12][14]=8.0;	Edge[14][9]=6.0;	Edge[9][2]=7.0;		Edge[2][1]=4.0;		Edge[17][18]=20.0;	Edge[12][15]=10.0;
	Edge[14][10]=4.0;	Edge[9][4]=5.0;		Edge[2][3]=5.0;		Edge[1][7]=9.0;		Edge[18][15]=15.0;	Edge[15][10]=3.0;	Edge[10][4]=7.0;	Edge[4][3]=5.0;		Edge[3][7]=10.0;	Edge[18][19]=4.0;	Edge[15][11]=30.0;	Edge[10][13]=12.0;
	Edge[4][5]=2.0;		Edge[3][6]=12.0;	Edge[7][8]=20.0;	Edge[19][11]=5.0;	Edge[11][13]=10.0;	Edge[13][5]=15.0;
	Edge[5][6]=25.0;	Edge[6][8]=35.0;
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
					//printf("%d is added to posistion %d. (Edge[%d][%d]=%lf)\n",i,j+1,u,i,Edge[u][i]);
					break;
				
				}
			if(i!=Sink){
				//printf("Search for the next node for %d.\n",i);
				y=nextVertex(i,ptrPath);	
				if(y==1){
				  //printf("Path has been found. (%d)\n",i);
					break;
				}
			}
			else{
				y=1;
				//printf("Path has been found. (%d)\n",i);
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
