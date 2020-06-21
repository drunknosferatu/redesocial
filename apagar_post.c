#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	void apagar_post(FILE *fp, char post[181], char *arquivo) {
		fseek(fp,0,SEEK_SET);
char *aux4=(char*)malloc(sizeof(char)*181);
int num=0;
while(fgets(aux4,181,fp)!=NULL){
	num++;
}
char **copia;
copia=(char **)malloc(sizeof(char *) * (num-1)/*numero de posts da rede*/);
for(int i=0; i<num-1; i++) {
        copia[i]=(char*)malloc(sizeof(char)*181); //numero de caracteres maximo
}
fseek(fp,0,SEEK_SET);
int i=0;
int flag=0;
while(fgets(aux4, 181, fp)!=NULL) {
	if(strcmp(post,aux4)!=0) {
		strcpy(copia[i++],aux4);
	}else if(flag){
		strcpy(copia[i++],aux4);
	}
	if(strcmp(post,aux4)==0){
		flag=1;
	}
}
//apos copiar os posts, menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen(arquivo, "w+");

for(int i=0; i<num-1; i++) {
       fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<(num-1); i++){
        free(copia[i]);
}
free(copia);
free(aux4);
}
