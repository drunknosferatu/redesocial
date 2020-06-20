#include <stdio.h>
#include <stdlib.h>
#include "apagar.h"
#include "chec.h"

void adm() {
int logout=1;
while(logout) {
printf("Bem vindo administrador!\n");
printf("Escolha uma das opcoes para iniciar\n");
printf("[1] Gerenciar postagens\n");
printf("[2] Gerenciar usuarios\n");
int verif;
get_int(&verif);

FILE *fp= fopen("adm", "a+");

FILE *fd=fopen("usuarios.txt", "r+");

switch (verif) {

	case 1:{

		char *posts;
		posts= (char*) malloc(sizeof(char)*128);
		char *teste;
        teste= (char*) malloc(sizeof(char)*128);
		int flag=1;
		int linha=0;
		int num=0; //numero de posts
		while(fgets(teste , 128 , fp)==NULL) {
			num++;
		}
		printf("Existem atualmente %d posts na timeline geral\n", num);
		fseek(fp, 0, SEEK_SET);
		while(flag) {
		for(int i=1; i<=5; i++) {
			if(fgets(teste, 128, fp)==NULL) {//alt
				break;
			}
			else {
				linha++;
				for(int j=0; j<128; j++) {
					fgets(posts, 200, fp); //  {
						printf("%d %s\n", linha, posts);
						//}
					}
				}
		}
		printf("\nDeseja excluir o post (i)? Exemplo: 1 [s/n]\n");
                                                int excluir_numero;
                                                char excluir_bin;
                                                get_int(&excluir_numero);
                                                while(excluir_numero<1 ||  excluir_numero>num) {
                                                        printf("Resposta invalida\n");
                                                        get_int(&excluir_numero);
                                                }
                                                get_char( &excluir_bin);
                                                while(excluir_bin =! 's' && excluir_bin!='n' ) {
                                                        printf("Resposta invalida/n");
                                                        get_char( &excluir_bin);
                                                                 }
                                                if(excluir_bin =='s'){
                                                        apagar_post(fp, excluir_numero, num);
                                                }

		printf("Deseja ver mais postagens? [s/n]");
		char resposta;
		get_char(&resposta);
		while(resposta =! 's' && resposta!= 'n') {
			printf("Resposta invalida/n");
			get_char(&resposta);
			}	
		if(resposta=='n'){
			flag=0;
			}
		}
        break;
    }
	case 2:{
	char *aux;
    int	num=0;
        aux= (char*) malloc(sizeof(char)*50);
	while(fgets(aux, 50, fd)!=NULL) {
		printf("%s", aux);
		num++;
	}
	printf("Existem atualmente %d registrados na rede\n", num);
	printf("Deseja excluir algum dos usuários? [s/n]\n");
	char resp;
	get_char(&resp);
	while(resp=! 's' && resp!='n') {
                        printf("Resposta invalida/n");
                        get_char(&resp);
                        }
                if(resp=='s'){
                        printf("Qual deles?\n");
			fgets(aux, 50, stdin);
			while(chec(aux,fd)!=0) {
				printf("Esse usuario nao existe/n");
				fgets(aux, 50, stdin);
                        }

apagar_usuario(fd, aux, num, "usuarios.txt");
                }
	    break;
           }
	case 3:
		logout=0;
        break;
}

fclose(fp);
fclose(fd);
}
}
