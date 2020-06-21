#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	void apagar_post(FILE *fp, int linha, int num, char *arquivo) {

char **copia;
copia=(char **)malloc(sizeof(char *) * (num-1)/*numero de posts da rede*/);
for(int i=0; i<num-1; i++) {
        copia[i]=(char*)malloc(sizeof(char)*128); //numero de caracteres maximo
}
char *aux4=(char*)malloc(sizeof(char)*128);
int cnt=1;
int i=0;
while(fgets(aux4, 128, fp)!=NULL) {
	if(cnt!=linha) {
		strcpy(copia[i++],aux4);
	}
	cnt++;
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
