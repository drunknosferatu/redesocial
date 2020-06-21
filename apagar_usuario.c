#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apagar_usuario (FILE *fp, char nome[52],char *arquivo) {
fseek(fp,0,SEEK_SET);
char *aux3;
aux3=(char*)malloc(sizeof(char)*50);
int num=0;
while(fgets(aux3,52,fp)!=NULL){
	num++;
}
char **copia;
copia=(char**)malloc(sizeof(char *) * (num-1)/*numero de usuarios da rede*/);
for(int i=0; i<num-1; i++) {
	copia[i]=(char*)malloc(sizeof(char)*52); //numero de caracteres maximo
}
int i=0;
fseek(fp,0,SEEK_SET);
while(fgets(aux3, 50, fp)!=NULL) {
	if(strcmp(aux3,nome)!=0) {
		strcpy(copia[i++], aux3);
	}
}
//apos copiar os usuarios menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen(arquivo, "w+");
for(int i=0; i<num-1; i++) {
	fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<num-1; i++){
	free(copia[i]);
}
free(copia);
free(aux3);
}
