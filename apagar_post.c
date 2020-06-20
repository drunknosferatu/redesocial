#include <stdio.h>
#include <stdlib.h>

void apagar_post(FILE *fp, int linha, int num) {

char **copia;
copia=(char **)malloc(sizeof(char *) * (num-1)/*numero de usuarios da rede*/);
int n = num; //provisorio
for(int i=0; i<n; i++) {
        copia[i]=(char*)malloc(sizeof(char)*200); //numero de caracteres maximo
}
int cnt=1;
int i = 50; //provisorio provavel numero de posts
while(fgets(copia[i], 200, fp)!=NULL) {
	for(int i=0; i< (num-1); i++) {
		if(cnt!=linha) {
        		fgets(copia[i], 200, fp);
		}
		cnt++;
	}
}
		
//apos copiar os posts, menos o desejado o arquivo deve ser limpo
fclose(fp);
fp=fopen("adm.txt", "w");
for(int i=0; i<num; i++) {
        fprintf(fp, "%s", copia[i]);
}
for(int i=0; i<(num-1); i++){
        free(copia[i]);
        }
free(copia);

//free(aux);
}

