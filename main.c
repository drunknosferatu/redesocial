#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "chec.h"
#include "registro.h"
int main(int argc, char *argv[]){
	int compar;
	int flagvolta=1;//flag para controle de volta para o primeiro print
	while(flagvolta){//loop de funcionamento do programa
		printf("Você ja possui uma chave de acesso?[s/n]\n");
		char verif1=getc(stdin);
		while(verif1!='s'&&verif1!='n'){//garante entrada válida para a resposta
			printf("Opção invalida, tente novamente\n");
			setbuf(stdin,NULL);
			verif1=getc(stdin);
		}
		getchar();//"pega" o \n do getc que fica sobrando
		if (verif1=='s'){
			printf("Insira sua chave de acesso:\n");
			char chave[50];
			fgets(chave,50, stdin);//pega a chave de acesso
			compar=chec(chave);//checa se a chave é valida ou não
			if (compar){
				printf("Chave inválida\n");
			}
			if (!compar){//inicio da parte de usuario
				flagvolta=0;
				printf("BEM-VINDO");
				printf("Menu:");
			}
		}
		if (verif1=='n'){
			printf("Gostaria de se registrar?[s/n]\n");
			setbuf(stdin,NULL);
			char verif2=getc(stdin);
			while(verif2!='s'&&verif2!='n'){//garante a validade da segunda verificação
				printf("Opção invalida, tente novamente\n");
				setbuf(stdin,NULL);
				scanf("%c", &verif2);
			}
			getchar();//pega o \n do getc
			if (verif2=='s'){
				registro();//registra o usuario
			}
			if (verif2=='n'){//sai do programa mas será alterado
				exit(0);
			}
		}
	}
}
	
