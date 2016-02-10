int * MaximumMatching(int * W){
	int i,j,k;	
	int R[w]={0};
	int T[w]={0};
	int numR=0;
// 	for(i=0;i<w;i++){
// 		for(j=0;j<w;j++)
// 			printf("%d ",*(W+i*w+j));
// 		printf("\n");
// 	}
	//printf("%d",w);
	int unweighted[w][w] = {0};
	for(i=0;i<w;i++)
		for(j=0;j<w;j++)
			if(*(W+i*w+j)==0&&T[j]==0){
				unweighted[i][j]=1;
				R[i]=1;
				T[j]=1;
				numR++;
				break;
			}/*
	for(i=0;i<w;i++){
		for(j=0;j<w;j++)
			printf("%d ",unweighted[i][j]);
		printf("\n");
	}*/
	int visitR[w]={0};
	int visitT[w]={0};
	int exploredR[w]={0};
	int exploredT[w]={0};
	int parentR[w];
	int parentT[w];
//	int Q[2*w];
//	int * ptrQ=&Q[0];
	int * Q = malloc(3*w*sizeof(int));
	for(i=0;i<w;i++){
		parentR[i]=-1;
		parentT[i]=-1;
		//printf("%d ",R[i]);
		if(R[i]==0)
			visitR[i]=1;
	}
	//printf("\n%d\n",numR);
	int visit, numQ, matching, temp;
	int Augmentation;
	do{
		visit=0;
		Augmentation=-1;
		for(i=0;i<w;i++){
			if(visitR[i]==1&&exploredR[i]==0){
				exploredR[i]=1;
				//printf("node %d goes ",i);
				for(j=0;j<w;j++)
					if(*(W+i*w+j)==0&&exploredT[j]==0){
						exploredT[j]=1;
						parentT[j]=i;
						//printf("to node %d ",j);
						Augmentation=j;
						for(k=0;k<w;k++)
							if(unweighted[k][j]==1&&exploredR[k]==0){
								parentR[k]=j;
								//exploredR[w]=1;
								visitR[k]=1;
								visit=1;
								Augmentation=-1;
								//printf("to node %d\n",k);
								//printf("%d %d %d\n",i,j,k);
							}
						if(Augmentation!=-1)
							break;
					}
			}
			if(Augmentation!=-1)
				break;
		}
		//printf("\nStarting from %d",Augmentation);
		//printf("\n%d",parentT[Augmentation]);
		if(visit==0&&Augmentation==-1){
			numQ=0;
			matching=0;
			//int * Q = malloc(2*w*sizeof(int));
			printf("\nNodes in set of R: ");
			for(i=0;i<w;i++){
				
				if(exploredR[i]==0){
					numQ++;
					*(Q+i)=1;
					printf("%d ",i);
				}
				else
					*(Q+i)=0;
			}
			printf("\nNodes in set of T: ");
			for(i=0;i<w;i++){
				
				if(exploredT[i]==1){
					numQ++;
					*(Q+i+w)=1;
					printf("%d ",i);
				}
				else
					*(Q+i+w)=0;
			}
			for(i=0;i<w;i++)
				for(j=0;j<w;j++)
					if(unweighted[i][j]==1)
						matching++;
			//printf("\n%d %d\n",numQ,matching);
			if(numQ!=matching){
				printf("\nerror!\n%d %d\n",numQ,matching);
				exit(1);
			}
			//free(Q);
			for(i=0;i<w;i++)
				for(j=0;j<w;j++)
					if(unweighted[i][j]==1)
						*(Q+i+2*w)=j;
		}
		//printf("\n%d",Augmentation);
		else if(Augmentation!=-1){
			unweighted[parentT[Augmentation]][Augmentation]=1;
			//unweighted[][]=0;
			//printf("\n%d",unweighted[parentT[Augmentation]][Augmentation]);
			Augmentation=parentT[Augmentation];
			//Augmentation=temp;
			//printf("\n%d",parentT[Augmentation]);
			while(parentR[Augmentation]!=-1){
				unweighted[Augmentation][parentR[Augmentation]]=0;
				//printf("\n%d, %d",Augmentation,parentR[Augmentation]);
				unweighted[parentT[parentR[Augmentation]]][parentR[Augmentation]]=1;
				//printf("\n%d, %d",parentT[parentR[Augmentation]],parentR[Augmentation]);
				Augmentation=parentT[parentR[Augmentation]];
				//printf("\nStarting from %d\n",Augmentation);
			}
			for(i=0;i<w;i++){
				visitR[i]=0;
				for(j=0;j<w;j++)
					if(unweighted[i][j]==0)
						visitR[i]=1;
					else{
						visitR[i]=0;
						break;
					}
				exploredR[i]=0;
				exploredT[i]=0;
				parentT[i]=-1;
				parentR[i]=-1;
			}/*
			for(i=0;i<w;i++){
				for(j=0;j<w;j++)
					printf("%d ",unweighted[i][j]);
				printf("\n");
			}*/
		}
	}while(visit==1||Augmentation!=-1);		
	printf("\nNodes in set of R: ");
	for(i=0;i<w;i++){

		if(*(Q+i)==1){
			//numQ++;
			//Q[i]=1;
			printf("%d ",i);
		}

	}
	printf("\nNodes in set of T: ");
	for(i=w;i<2*w;i++){
				
		if(*(Q+i)==1){
			//numQ++;
			//Q[i+w]=1;
			printf("%d ",i-w);
		}

	}/*
	for(i=0;i<2*w;i++)
		printf("%d ",*(Q+i));*/
	return Q;
} 
