#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "chec.h"
#include "registro.h"
#include "ux.h"
int main(int argc, char *argv[]){
	int compar;
	while(1){//loop de funcionamento do programa
		printf("Gostaria de iniciar uma sessão[s/n]?\n");
		char verif=getc(stdin);
		while(verif!='s'&&verif!='n'){//garante entrada válida para a resposta
			printf("Opção invalida, tente novamente\n");
			setbuf(stdin,NULL);
			verif=getc(stdin);
		}
		getchar();//"pega" o \n do getc que fica sobrando
		if (verif=='n'){
			exit(0);
		}
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
			char *chave=malloc(50*sizeof(char));
			fgets(chave,50, stdin);//pega a chave de acesso
			compar=chec(chave);//checa se a chave é valida ou não
			if (compar){
				printf("Chave inválida\n");
			}
			if (!compar){//inicio da parte de usuario
				ux(chave);
			}
		}
		if (verif1=='n'){
			printf("Gostaria de se registrar?[s/n]\n");
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
		}
	}
}
	
