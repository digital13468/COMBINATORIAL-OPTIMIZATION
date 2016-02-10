#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define V 40
int y=0;
double maxFlow=0.0;
double Edge[V][V]={0.0};
int Resource=5;
int Sink=37;
int Path[V];
int nextVertex(int u, int* Path, int* Explored);
int* Augmentation();
void cutSet(int u, int* cutSet, double* edge, double* cedge);
int cutSetSize=0;                        
main(){
Edge[0][11] = 2.966262;
Edge[0][15] = 4.444494;
Edge[0][26] = 3.615404;
Edge[0][39] = 2.794066;
Edge[1][3] = 1.636765;
Edge[1][10] = 2.087716;
Edge[1][13] = 1.896815;
Edge[1][22] = 1.899453;
Edge[1][23] = 1.467378;
Edge[1][25] = 2.031631;
Edge[1][26] = 2.948041;
Edge[2][30] = 2.214267;
Edge[2][36] = 2.707585;
Edge[3][17] = 0.306621;
Edge[3][20] = 0.568265;
Edge[3][23] = 0.139800;
Edge[3][32] = 0.882612;
Edge[3][38] = 0.122505;
Edge[4][19] = 5.911453;
Edge[4][27] = 5.184406;
Edge[4][31] = 5.424907;
Edge[4][33] = 5.950664;
Edge[5][7] = 8.982081;
Edge[5][29] = 9.230861;
Edge[5][34] = 7.923999;
Edge[6][1] = 4.074619;
Edge[7][6] = 6.572648;
Edge[7][34] = 7.181918;
Edge[8][18] = 7.883084;
Edge[8][35] = 7.490705;
Edge[9][2] = 0.612271;
Edge[9][20] = 0.440851;
Edge[9][24] = 1.280333;
Edge[9][30] = 1.317580;
Edge[10][3] = 0.480539;
Edge[10][13] = 0.740589;
Edge[10][17] = 0.144330;
Edge[10][20] = 0.117313;
Edge[10][22] = 0.743228;
Edge[10][23] = 0.311152;
Edge[10][25] = 0.875405;
Edge[10][32] = 0.431661;
Edge[10][38] = 0.328447;
Edge[11][2] = 0.077551;
Edge[11][9] = 0.819136;
Edge[11][10] = 1.142673;
Edge[11][39] = 1.181660;
Edge[12][0] = 4.676361;
Edge[12][11] = 3.063955;
Edge[12][15] = 4.542187;
Edge[12][26] = 3.713097;
Edge[12][39] = 2.891759;
Edge[13][3] = 0.289637;
Edge[13][17] = 0.046571;
Edge[13][20] = 0.308215;
Edge[13][23] = 0.120250;
Edge[13][32] = 0.622562;
Edge[13][38] = 0.137545;
Edge[14][19] = 6.678991;
Edge[14][21] = 7.315271;
Edge[14][28] = 7.861029;
Edge[14][33] = 6.718202;
Edge[15][11] = 2.832088;
Edge[15][26] = 3.481231;
Edge[15][39] = 2.659892;
Edge[16][14] = 5.221690;
Edge[16][31] = 4.977122;
Edge[17][16] = 2.324598;
Edge[17][20] = 0.904474;
Edge[17][32] = 1.218821;
Edge[18][0] = 5.971853;
Edge[18][12] = 6.069546;
Edge[18][15] = 5.837680;
Edge[18][35] = 6.972659;
Edge[19][21] = 7.557249;
Edge[19][33] = 6.960180;
Edge[19][37] = 8.450701;
Edge[20][24] = 2.005600;
Edge[20][30] = 2.042846;
Edge[20][32] = 1.480464;
Edge[20][36] = 2.536164;
Edge[21][28] = 8.739286;
Edge[22][3] = 0.292276;
Edge[22][13] = 0.552326;
Edge[22][17] = 0.043933;
Edge[22][20] = 0.305576;
Edge[22][23] = 0.122889;
Edge[22][32] = 0.619923;
Edge[22][38] = 0.140184;
Edge[23][16] = 2.157776;
Edge[23][17] = 0.476008;
Edge[23][20] = 0.737652;
Edge[23][32] = 1.051999;
Edge[24][4] = 3.873510;
Edge[24][27] = 4.155979;
Edge[24][30] = 2.882329;
Edge[24][36] = 3.375647;
Edge[25][3] = 0.424454;
Edge[25][13] = 0.684504;
Edge[25][17] = 0.088245;
Edge[25][20] = 0.173399;
Edge[25][22] = 0.687142;
Edge[25][23] = 0.255067;
Edge[25][32] = 0.487746;
Edge[25][38] = 0.272361;
Edge[26][9] = 1.468278;
Edge[26][10] = 1.791816;
Edge[26][11] = 2.002999;
Edge[26][13] = 1.600914;
Edge[26][22] = 1.603553;
Edge[26][39] = 1.830802;
Edge[27][19] = 6.193922;
Edge[27][31] = 5.707377;
Edge[27][33] = 6.233133;
Edge[29][6] = 6.821427;
Edge[29][7] = 8.488779;
Edge[29][34] = 7.430697;
Edge[30][4] = 3.910756;
Edge[30][27] = 4.193225;
Edge[30][36] = 3.412893;
Edge[31][14] = 6.192446;
Edge[31][19] = 6.434424;
Edge[31][21] = 7.070704;
Edge[31][28] = 7.616461;
Edge[31][33] = 6.473634;
Edge[32][16] = 2.900589;
Edge[32][24] = 2.319947;
Edge[32][30] = 2.357193;
Edge[32][36] = 2.850512;
Edge[33][21] = 7.596460;
Edge[33][37] = 8.489912;
Edge[34][1] = 4.683889;
Edge[34][6] = 5.514566;
Edge[35][0] = 5.579474;
Edge[35][12] = 5.677167;
Edge[35][15] = 5.445300;
Edge[36][4] = 4.404074;
Edge[36][19] = 5.413590;
Edge[36][27] = 4.686543;
Edge[36][31] = 4.927045;
Edge[36][33] = 5.452801;
Edge[38][16] = 2.140481;
Edge[38][17] = 0.458714;
Edge[38][20] = 0.720357;
Edge[38][23] = 0.291892;
Edge[38][32] = 1.034704;
Edge[39][2] = 0.249747;
Edge[39][9] = 0.646940;
Edge[39][10] = 0.970477;
Edge[39][20] = 0.078327;
Edge[39][30] = 0.955056;





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
int z=0;
printf("%d. The max flow value is %lf with %lf added flow\n",++z,maxFlow,temp);

	while(*(rsPath+1)!=-1){
		for(i=0;i<V-1;i++){
 		//*(rsPath+i)!=-1&&
 			if(*(rsPath+i+1)!=-1){
 				Edge[*(rsPath+i)][*(rsPath+i+1)]=Edge[*(rsPath+i)][*(rsPath+i+1)]-temp;
 				Edge[*(rsPath+i+1)][*(rsPath+i)]=Edge[*(rsPath+i+1)][*(rsPath+i)]+temp;
 				//printf("Edge[%d][%d]=%d\n",i,j,Edge[i][j]);
			}
		}
		
//    		for(i=0;i<V;i++)
// // 			//printf("\n");
//   			printf("%d\t",*(rsPath+i));
//  			//printf("\n");
//  		}
		
		rsPath=NULL;
		rsPath=Augmentation();
		temp=100000.0;
		for(i=0;i<V-1;i++)//*(rsPath+i)!=-1&&
			if(*(rsPath+i+1)!=-1&&temp>Edge[*(rsPath+i)][*(rsPath+i+1)]){
				temp=Edge[*(rsPath+i)][*(rsPath+i+1)];
				//printf("%d temp=%d\n",i,temp);
			}
		if(*(rsPath+1)!=-1)
			maxFlow+=temp;printf("%d. The max flow value is %lf with %lf added flow\n",++z,maxFlow,temp);
		//printf("\nadded flow value: %lf\n",temp);
// 		else
// 			for(i=0;i<V;i++)
// 				for(j=;j<V;j++)
// 					if()
	}
//	int rCut=0;
	//printf("The max flow value is %lf\n",maxFlow);
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
// 	//int finalCut=0;
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
	    if(Edge[*(initialCut+j)][*(rBar+i)]==0&&Edge[*(rBar+i)][*(initialCut+j)]==Edge[*(rBar+i)][*(initialCut+j)]&&cEdge[*(initialCut+j)][*(rBar+i)]>0){
	      minCutValur+=Edge[*(rBar+i)][*(initialCut+j)];
	      printf("\nThe minimum cut value is %lf\n",minCutValur);
	    }
	free(initialCut);
	free(rBar);
}
void cutSet(int u, int * initialCut, double* edge, double* cedge){
	int i,j,k;
	int currentSetSize;
	//printf("BEFORE %d\n",u);
	for(i=0;i<V;i++){
		currentSetSize=cutSetSize;
		if(*(edge+u*V+i)>0){
			//printf("New Cut Might be Found!\n");
			
			int skipFlag=0;
			//int * existingCut=malloc(cutSetSize-1*sizeof(int));
			//int * newCut=malloc(cutSetSize*sizeof(int));
			//*(newNode+0)=i;
			//memcpy(existingCut,initialCut,sizeof(initialCut));
			//increaseSize=1;
			for(k=0;k<currentSetSize;k++){
			  //printf("current set size %d\n",currentSetSize);
			  //printf("%d ",*(initialCut+k));//increaseSize=1;

			    if(*(initialCut+k)==i){
			      skipFlag=1;
			      //printf("Node %d exists already!\n",i);
			     }
			}
			//printf("\n");
			if(skipFlag==0){
			    cutSetSize++;
			    //printf("new cut size %d\n",cutSetSize);
			    initialCut = realloc(initialCut,cutSetSize*sizeof(int));
			    if(!initialCut){
			      printf("error!\n");
			      exit(1);
			    }
			    *(initialCut+cutSetSize-1)=i;
			    //printf("Node %d is added!\n",i);
			    //printf("The new set includes now:\n");
			    for(j=0;j<cutSetSize;j++)
			      printf("%d ",*(initialCut+j));
			    printf("\n");
			    cutSet(i,initialCut,edge,cedge);
			    printf("return to %d",u);
			    for(j=0;j<cutSetSize;j++){
			      printf("%d ",*(initialCut+j));
			      if(!initialCut){
				printf("error!\n");
				exit(1);
			      }
			    }
			}
// 			else
// 			  printf("Node(s) already exists!\n");
			//memcpy(initialCut,exisitingCut,sizeof(newNode));

			//if(increaseSize==1)
			  
			//free(newCut);
		}
	//printf("AFTER %d\n",cutSetSize);
 		else if(i==V-1){
			    printf("No new Nodes Found(%d)!\nThe set is still:(%d,%d)\n",u,currentSetSize,cutSetSize);
			    for(j=0;j<cutSetSize;j++)
			      printf("%d ",*(initialCut+j));
			    printf("\n");
		}
	}
// 			printf("%d %d\n",*(edge+u*V+i),*(cedge+u*V+i));
	//return increaseSize;
}
int * Augmentation(){
	//int Pre[V]={-1};
	int i=0;
	int counter=0;
	int* Explored = malloc(V*sizeof(int));
	for(i=0;i<V;i++){
	  Path[i]=-1;
	  *(Explored+i)=-1;
	}
	int* ptrPath;
	ptrPath=&Path[0];
//  	for(i=0;i<V;i++)
//   		printf("%d\t",*(ptrPath+i));
 	printf("%d. ",++y);
	Path[0]=Resource;
	nextVertex(Resource,ptrPath,Explored);
	
 	for(i=0;i<V;i++){
		if(*(ptrPath+i)!=-1)
			printf("%d->",*(ptrPath+i));
 		if(*(ptrPath+i)==Sink)
 			counter++;
 	}
 	if(counter==0){
 		printf("No Path Found!\n");
 		for(i=0;i<V;i++)
		  *(ptrPath+i)=-1;
 	}
 	else if(!ptrPath){
	   printf("error!");
	   exit(1);
	}
	return ptrPath;
}

int nextVertex(int u, int* ptrPath, int* Explored){
	int i,j,k,jump;
	int y=0;
	int pre;
	
	//printf("This is node %d (V=%d)\n",u,V);
	for(i=0;i<V;i++){
		//if(y==0)
		jump=0;
		pre=0;
		//suc=0;
				//jump=1;
		if(Edge[u][i]>0.00009&&u!=i){		
			for(k=0;k<V;k++){
				if(*(ptrPath+k)==i||*(Explored+k)==i){
					jump=1;
					//break;
					//suc=k;
				}
				if(*(ptrPath+k)==u){
					pre=k;
					//printf("(%d)%d at %d(%d)\n",i,u,pre,k);
				}
			}
			//printf("jump=%d when i=%d\n",jump,i);
			if(jump==1&&i!=V-1)
				continue;
			else if(jump==1&&i==V-1){
//			  for(j=0;j<V;j++)
				*(ptrPath+pre)=-1;
// 				if(*(ptrPath+j)==u){
 					//*(ptrPath+j)=-1;//
					//printf("1. %d is deleted from position %d.\n",u,pre);
// 					break;
// 						
// 				}
			  continue;
			}
			//printf("Edge[%d][%d] is selected (%lf).\n",u,i,Edge[u][i]);
// 			for(j=0;j<V;j++)
// 			  if(*(Explored+j)==i)
			    
				*(ptrPath+(pre+1))=i;
// 				if(*(ptrPath+j)==u){
// 					*(ptrPath+j+1)=i;
 					//printf("%d is added to posistion %d. (Edge[%d][%d]=%lf)\n",i,pre+1,u,i,Edge[u][i]);
// 					break;
// 				
// 				}
			if(i!=Sink){
				//printf("Search for the next node for %d.\n",i);
				y=nextVertex(i,ptrPath,Explored);	
				//printf("stop before hrer");
				if(y==1){
				  //printf("Path has been found. (%d)\n",i);
					break;
				}
				else{
				    if(i==V-1)
				      *(ptrPath+pre)=-1;
				  for(j=0;j<V;j++)
				    if(*(Explored+j)==-1){
				      *(Explored+j)=i;
				      break;
				    }
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
					//printf("2. %d is deleted from position %d.\n",u,j);
				}
		}
//  		else if(V-1!=i)
// 		  printf("V=%d i=%d",V,i);
		
	}
	return y;		

}
