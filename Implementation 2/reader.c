#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define n 100



                                  
main(){
       
FILE *infile, *outfile; 
int i,j,k;
char id[5000];
char tempC;

int value;
double fvalue;
size_t loc;
char string[3]="[\\";
//char string1[4]="\] ";
char string2[2]=",";
char string3[3]=",\\";

int u,v;

double capacity[n][n]={0.0};
double cap=0.0;
//float x[100]={0.0};
//float y[250]={0.0};
int index;
if ((infile=fopen("flow3.txt", "r")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");
// if ((outfile=fopen("matrix3.txt", "w")) == NULL)
// 	printf("Fail to open file!");
// else
// 	printf("Open file successfully!\n");

		
	while (fscanf(infile, "%s", &id)!=EOF){
	  //printf("%s\n",id);
		if (strcmp(id,string)==0){
		  //fscanf(infile, "%s", &id);
		 //printf("%s",id);
			//fscanf(infile, "%s ", &id);
			//printf("%s",id);
			do{
			fscanf(infile, "%s", &id);
			fscanf(infile, "%d,", &u);
			fscanf(infile, "%d,%lf)",&v,&cap);
			capacity[u][v]=cap;
			fscanf(infile, "%s", &id);
// 			if(strcmp(id,string1)==0)
// 			  break;
 			}
			while(strcmp(id,string2)==0||strcmp(id,string3)==0);
				
					//fscanf(infile, " ( %d,");
					
					//fscanf(infile, "%lf),");
					//printf("%c",tempC);
// 					if(tempC=='x'){
// 						fscanf(infile, "%d\"", &index);
// 						fscanf(infile, "%s", &id);
// 						fscanf(infile, "%s", &id);
// 						fscanf(infile, " value=\"%lf\"", &fvalue);
// 						x[index]=fvalue;
// 						fscanf(infile, "%s", &id);
// 					}
					//printf("%s",id);
	
					
					//if(strcmp(id,string2)==0)
					  

				                                                     
			                                                     
		}
	
	}


fclose(infile);
for(i=0;i<n;i++)
   for(j=0;j<n;j++)
     if(capacity[i][j]>0)
	printf("c[%d][%d] = %lf\n",i,j,capacity[i][j]);
//fclose(outfile);
/*
printf("Dual solution convertion.\n");
FILE *dualIn, *dualOut;
if ((dualIn=fopen("I4_dual_sol.txt", "r")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");
if ((dualOut=fopen("I4_dual_vector.txt", "w")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");

		
	while (fscanf(dualIn, "%s", &id)!=EOF){
	  printf("%s\n",id);
		if (strcmp(id,string)==0){
			fscanf(dualIn, "%s", &id);
			printf("%s",id);
			while(strcmp(id,string1)!=0){
				while(strcmp(id,string2)==0){
					fscanf(dualIn, " name=\"");
					fscanf(dualIn, "%c", &tempC);
					//printf("%c",tempC);
					if(tempC=='y'){
						fscanf(dualIn, "%d\"", &index);
						fscanf(dualIn, "%s", &id);
						fscanf(dualIn, "%s", &id);
						fscanf(dualIn, " value=\"%lf\"", &fvalue);
						y[index]=fvalue;
						fscanf(dualIn, "%s", &id);
					}
					//printf("%s",id);
	
					fscanf(dualIn, "%s", &id);

				}                                                          
			}                                                            
		}
	
	}


fclose(dualIn);




		
for(i=0;i<250;i++)
  if(y[i]!=0)
	fprintf(dualOut,"y_{%d} = %g, ",i,y[i]);
fclose(dualOut);*/



}

