#include <stdio.h>
#include "apagar.h"

void adm() {
int logout=1;
while(logout) {
printf("Bem vindo administrador!\n");
printf("Escolha uma das opcoes para iniciar\n");
printf("[1] Gerenciar postagens\n");
printf("[2] Gerenciar usuarios\n");
int verif;
scanf("%d", &verif);
switch case (verif) {

	case 1:
		char *posts;
		posts= (char*) malloc(sizeof(char)*128);
		char *teste;
                teste= (char*) malloc(sizeof(char)*128);
		int flag=1;
		int linha=0;
		FILE *fp= fopen(adm, "r+");
		int num=0; //numero de posts
		while(fgets(teste; 128; fp)==NULL) {
			num++;
		}
		printf("Existem atualmente %d posts na timeline geral\n", num);
		fseek(fp, 0, SEEK_SET);

		while(flag) {
		for(int i=1; i<=5; i++) {
			if(fgets(teste; 128; fp)==NULL) {
				break;
			}
			else {
				linha++;
				for(int j=0; j<128; j++) {
					fgets(posts, 200, fp) {
						printf("%d %s\n", linha, posts);
							}
					}
				}
		}
		printf("\nDeseja excluir o post (i)? Exemplo: 1 [s/n]\n");
                                                int excluir_numero;
                                                char exclui_bin;
                                                scanf("%d", &excluir_numero);
                                                scanf("%c", &excluir_bin);
                                                while(excluir_numero<1 ||  excluir_numero>num) {
                                                        printf("Resposta invalida\n");
                                                        scanf("%d", &excluir_numero);
                                                }
                                                while(excluir_bin=!s && excluir_bin!=n) {
                                                        printf("Resposta invalida/n");
                                                        scanf("%d", &excluir_bin);
                                                                 }
                                                if(excluir=='s'){
                                                        apagar_post(&fp, excluir_numero, num);
                                                }

		printf("Deseja ver mais postagens? [s/n]");
		char resposta;
		scanf("%c", &resposta);
		while(resposta=!s && resposta!=n) {
			printf("Resposta invalida/n");
			scanf("%d", &resposta);
			}	
		if(resposta=='n'){
			flag=0;
			}
		}
	case 2:
	FILE *fd=fopen(usuarios.txt, "r+");
	char *aux
	int num=0;
        aux= (char*) malloc(sizeof(char)*50);
	while(fgets(aux, 50, fd)!=NULL) {
		printf("%s", aux);
		num++;
	}
	printf("Existem atualmente %d registrados na rede\n", num);
	printf("Deseja excluir algum dos usuários? [s/n]\n");
	char resp;
	scanf("%c", &resp);
	while(resp=!s && resp!=n) {
                        printf("Resposta invalida/n");
                        scanf("%d", &resp);
                        }
                if(resp=='s'){
                        printf("Qual deles?\n")
			fgets(aux, 50, stdin);
			while(chec(aux)!=0) {
				printf("Esse usuario nao existe/n");
				fgets(aux, 50, stdin);
                        }

			apagar_usuario(&fd, aux, num);
		}
	
	case 3:
		logout=0;
		fclose(fp);
		fclose(fd);
}
