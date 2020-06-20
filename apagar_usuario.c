#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apagar_usuario (FILE *fp, char nome[100],int  num) {

char **copia;
copia=(char**)malloc(sizeof(char *) * (num-1)/*numero de usuarios da rede*/);
int n = num; //provisorio
for(int i=0; i<n; i++) {
	copia[i]=(char*)malloc(sizeof(char)*50); //numero de caracteres maximo
}
char *aux;
aux=(char*)malloc(sizeof(char)*50);
while(fgets(aux, 128, fp)!=NULL) {
	for(int i=0; i<num; i++) {
		if(strcmp(aux,nome)!=0) {
			strcpy(copia[i], aux);
		}
	}
}
//apos copiar os usuarios menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen("usuarios.txt", "w");
for(int i=0; i<num; i++) {
	fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<(num-1); i++){
	free(copia[i]);
	}
free(copia);

free(aux);
}
