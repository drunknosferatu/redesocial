#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apagar.h"
#include "chec.h"

void adm() {
int logout=1;
while(logout) {
printf("Bem vindo administrador!\n");
printf("Escolha uma das opcoes para iniciar\n");
printf("[1] Gerenciar postagens\n");
printf("[2] Gerenciar usuarios\n");
printf("[3] Logout\n");
int verif;
get_int(&verif);

char excluir_bin = ' ' ;
int excluir_numero = 0;
FILE *fp;
fp = fopen("adm", "a+");

FILE *fd;
fd = fopen("usuarios.txt", "r+");

if(fd == NULL){
    printf("falha interna\n");
    exit(0);
}

switch (verif) {

	case 1:{

		char *posts;
		posts= (char*) malloc(sizeof(char)*129);
		char *teste;
        teste= (char*) malloc(sizeof(char)*129);
		int flag=1;
		int linha=0;
		int num=0; //numero de posts
		while(fgets(teste , 129 , fp)!=NULL) {
			num++;
		}
		printf("Existem atualmente %d posts na timeline geral\n", num);
		fseek(fp, 0, SEEK_SET);
		    for(int linha=1; linha<=num; linha++) {
			    fgets(posts, 129, fp);
			    printf("%d %s\n", linha, posts);
			}
		    printf("\nDeseja excluir algum post? [s/n]\n");
            get_char(&excluir_bin);
            while(excluir_bin != 's' && excluir_bin!='n' ) {
                printf("Resposta invalida\n");
                get_char(&excluir_bin);
            }
            if(excluir_bin == 's'){
                printf("\nQual post gostaria de escolher escolha um numero de 1 à %d\n",num);
                get_int(&excluir_numero);
                while(excluir_numero<1 ||  excluir_numero>num) {
                    printf("Resposta invalida\n");
                    get_int(&excluir_numero);
                }
                fseek(fp,0,SEEK_SET);
                for(int j = 0; j < excluir_numero;j++){
                    fgets(posts,129,fp);
                }
                apagar_post(fp,posts,"adm");
                fseek(fd,0,SEEK_SET);
                char *aux2 = (char *)malloc(sizeof(char)*50);
                int ctn = 0;
                while(fgets(aux2,50,fd) != NULL){
                    ctn++;
                }
                char **users;
                users = (char **)malloc(sizeof(char*)*ctn);
                for(int j = 0; j < ctn;j++){
                    users[j] = (char *)malloc(sizeof(char)*50);
                }
                fseek(fd,0,SEEK_SET);
                for(int j = 0; j < ctn; j++){
                    fgets(users[j],50,fd);
                }
                for(int j = 0; j < ctn;j++){
                    int len = 0;
                    len = strlen(users[j]);
                    users[j][len-1] = '4';
                }
                for(int j = 1;j < ctn;j++){
                    FILE *fc;
                    fc =  fopen(users[j],"a+");
                    apagar_post(fc,posts,users[j]);
                    fclose(fc);

                }
                for(int j = 0;j < ctn;j++){
                    free(users[j]);
                }
                free(users);
                free(aux2);

             }
		    printf("Deseja ver mais postagens? [s/n]");
		    char resposta;
		    get_char(&resposta);
		    while(resposta != 's' && resposta!= 'n') {
			    printf("Resposta invalida\n");
			    get_char(&resposta);
		    }	
		    if(resposta=='n'){
			    flag=0;
		    }
	
    free(posts);
    free(teste);
    break;
    }

	case 2:{
    fseek(fd,0,SEEK_SET);
	char *aux;
    int	num=0;
        aux= (char*) malloc(sizeof(char)*50);
	while(fgets(aux, 50, fd)!=NULL) {
		printf("%s", aux);
		num++;
	}
	printf("Existem atualmente %d registrados na rede\n", num-1);
	printf("Deseja excluir algum dos usuários? [s/n]\n");
	char resp;
	get_char(&resp);
	while(resp != 's' && resp!='n') {
        printf("Resposta invalida\n");
        get_char(&resp);
     }
    if(resp=='s'){
        printf("Qual deles?\n");
		fgets(aux, 50, stdin);
        int k = strlen(aux);
        aux[k-1] = '\0';
        int flag = 1;
        flag = chec(aux,fd);
		while(flag != 0) {
		    printf("Esse usuario nao existe\n");
            setbuf(stdin,NULL);
			fgets(aux, 50, stdin);
            flag = chec(aux,fd);
     }

        apagar_usuario(fd, aux, "usuarios.txt");
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
