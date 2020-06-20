#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apagar_usuario (FILE *fp, char nome[100],int  num, char *arquivo) {
fseek(fp,0,SEEK_SET);
char **copia;
copia=(char**)malloc(sizeof(char *) * (num-1)/*numero de usuarios da rede*/);
for(int i=0; i<num-1; i++) {
	copia[i]=(char*)malloc(sizeof(char)*50); //numero de caracteres maximo
}
char *aux3;
aux3=(char*)malloc(sizeof(char)*50);
while(fgets(aux3, 128, fp)!=NULL) {
	for(int i=0; i<num-1; i++) {
		if(strcmp(aux3,nome)!=0) {
			strcpy(copia[i], aux3);
		}
	}
}
//apos copiar os usuarios menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen(arquivo, "w+");
for(int i=0; i<num-1; i++) {
	printf("%s\n", copia[i]);
	fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<num-1; i++){
	free(copia[i]);
}
free(copia);
free(aux3);
}
