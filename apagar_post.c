#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	void apagar_post(FILE *fp, char post[129], char *arquivo) {
fseek(fp,0,SEEK_SET);
char *aux4=(char*)malloc(sizeof(char)*129);
int num=0;
while(fgets(aux4,129,fp)!=NULL){
	num++;
}
char **copia;
copia=(char **)malloc(sizeof(char *) * (num-1)/*numero de posts da rede*/);
for(int i=0; i<num-1; i++) {
        copia[i]=(char*)malloc(sizeof(char)*129); //numero de caracteres maximo
}
fseek(fp,0,SEEK_SET);
int i=0;
while(fgets(aux4, 129, fp)!=NULL) {
	if(strcmp(post,aux4)) {
		strcpy(copia[i++],aux4);
	}
}
//apos copiar os posts, menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen(arquivo, "w+");
for(int i=0; i<num; i++) {
        fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<(num-1); i++){
        free(copia[i]);
}
free(copia);
free(aux4);
}
