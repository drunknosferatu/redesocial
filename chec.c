#include<stdio.h>
#include<string.h>
int chec(char *chave){
	FILE *usuariosr;
	usuariosr=fopen("usuarios.txt","r");
	int compar;
	char validade[50];		
	while(fgets(validade,50,usuariosr)!=NULL){
		compar=strcmp(chave,validade);
		if (!compar){
			break;
		}
	}
	return compar;
}
