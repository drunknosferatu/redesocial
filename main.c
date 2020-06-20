#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "chec.h"
#include "registro.h"
#include "ux.h"
#include "adm.h"
int main(int argc, char *argv[]){
	int compar;
	while(1){//loop de funcionamento do programa
		printf("Gostaria de iniciar uma sessão[s/n]?\n");
		char verif;
        get_char(&verif);
		while(verif!='s'&&verif!='n'){//garante entrada válida para a resposta
			printf("Opção invalida, tente novamente\n");
			setbuf(stdin,NULL);
			get_char(&verif);//Nova função para pegar char
		}
		//getchar() removido
		if (verif=='n'){
			exit(0);
		}
		printf("Você ja possui uma chave de acesso?[s/n]\n");
		char verif1;
        get_char(&verif1);
		while(verif1!='s'&&verif1!='n'){//garante entrada válida para a resposta
			printf("Opção invalida, tente novamente\n");
			setbuf(stdin,NULL);
			get_char(&verif1);
		}
		if (verif1=='s'){
			printf("Insira sua chave de acesso:\n");
			char *chave;
			chave=malloc(50*sizeof(char));
			if(chave==NULL){
				printf("Falha interna. Fechando o programa");
				exit(0);
			}
			setbuf(stdin,NULL);
			fgets(chave,50, stdin);//pega a chave de acesso
			if(strcmp(chave,"adm")==0) {
				adm();
			}
			FILE *usuarios;
			usuarios=fopen("usuarios.txt","r");
			compar=chec(chave,usuarios);//checa se a chave é valida ou não
			fclose(usuarios);
			if (compar){
				printf("Chave inválida\n");
				free(chave);
			}
			if (!compar){//inicio da parte de usuario
				ux(chave);
			}
		}
		if (verif1=='n'){
			printf("Gostaria de se registrar?[s/n]\n");
			char verif2;
            get_char(&verif2);
			while(verif2!='s'&&verif2!='n'){//garante a validade da segunda verificação
				printf("Opção invalida, tente novamente\n");
				setbuf(stdin,NULL);
				get_char(&verif2);
			}
			if (verif2=='s'){
				registro();//registra o usuario
			}
		}
	}
}
	
