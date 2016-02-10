#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>





                                  
main(){
       
FILE *infile, *outfile; 
int i,j,k;
char id[5000];
char tempC;

int value;
double fvalue;
size_t loc;
char string[12]="<variables>" ;
char string1[13]="</variables>" ;
char string2[9]="<variable";


float x[30]={0.0};
float y[80]={0.0};
int index;
if ((infile=fopen("I4_primal_sol.txt", "r")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");
if ((outfile=fopen("I4_primal_vector.txt", "w")) == NULL)
	printf("Fail to open file!");
else
	printf("Open file successfully!\n");

		
	while (fscanf(infile, "%s", &id)!=EOF){
	  printf("%s\n",id);
		if (strcmp(id,string)==0){
			fscanf(infile, "%s", &id);
			printf("%s",id);
			while(strcmp(id,string1)!=0){
				while(strcmp(id,string2)==0){
					fscanf(infile, " name=\"");
					fscanf(infile, "%c", &tempC);
					//printf("%c",tempC);
					if(tempC=='x'){
						fscanf(infile, "%d\"", &index);
						fscanf(infile, "%s", &id);
						fscanf(infile, "%s", &id);
						fscanf(infile, " value=\"%lf\"", &fvalue);
						x[index]=fvalue;
						fscanf(infile, "%s", &id);
					}
					//printf("%s",id);
	
					fscanf(infile, "%s", &id);

				}                                                          
			}                                                            
		}
	
	}


fclose(infile);
for(i=0;i<30;i++)
  if(x[i]!=0)
	fprintf(outfile,"x_{%d} = %g, ",i,x[i]);
fclose(outfile);

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




		
for(i=0;i<80;i++)
  if(y[i]!=0)
	fprintf(dualOut,"y_{%d} = %g, ",i,y[i]);
fclose(dualOut);



}

