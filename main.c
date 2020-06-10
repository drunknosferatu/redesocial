#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "chec.h"
#include "registro.h"
int main(int argc, char *argv[]){
	FILE *usuarios;
	int compar;
	usuarios= fopen("usuarios.txt","a");
	printf("Você ja possui uma chave de acesso?[s/n]\n");
	char verif1=getc(stdin);
	while(verif1!='s'&&verif1!='n'){
		printf("Opção invalida, tente novamente\n");
		setbuf(stdin,NULL);
		verif1=getc(stdin);
	}
	getchar();
	if (verif1=='s'){
		printf("Insira sua chave de acesso:\n");
		char chave[50];
		fgets(chave,50, stdin);
		compar=chec(chave);
		if (compar){}//discutir em grupo
		if (!compar){
			printf("BEM-VINDO");
			printf("Menu:");
		}
	}
	if (verif1=='n'){
		printf("Gostaria de se registrar?[s/n]\n");
		setbuf(stdin,NULL);
		char verif2=getc(stdin);
		while(verif2!='s'&&verif2!='n'){
			printf("Opção invalida, tente novamente\n");
			setbuf(stdin,NULL);
			scanf("%c", &verif2);
		}
		getchar();
		if (verif2=='s'){
			registro(usuarios);
		}
		if (verif2=='n'){
			exit(0);
		}
	}
}
	
