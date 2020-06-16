#include<stdio.h>
#include<string.h>
int chec(char *chave,FILE *arq){
	FILE *usuariosr;
	usuariosr=fopen(arq,"r");
	int compar=1;
	char validade[50];
	while(fgets(validade,50,usuariosr)!=NULL){//puxa as strings do arquivo usuario
		compar=strcmp(chave,validade);//compara todas as strings do arquivo com a passada para a função
		if (!compar){
			break;
		}
	}
	return compar;//retorna o estado(0 para strings iguais, !=0 para strings diferentes
}
