#include<stdio.h>
#include<string.h>
#include "chec.h"
#include<stdlib.h>
void ux(char *chave){
	int flag=1;
	char *info;
	char *post;
	char *aux;
	info=(char*)malloc(sizeof(char)*100);
	post=(char*)malloc(sizeof(char)*128);
	aux=(char*)malloc(sizeof(char)*50);
	int i=strlen(chave);
	chave[--i]='\0';
	FILE *tlinfo;
	tlinfo=fopen(chave,"a+");
	chave[i++]='4';
	chave[i--]='\0';
	FILE *posts;
	posts=fopen(chave,"a+");
	chave[i++]='3';
	chave[i--]='\0';
	FILE *seguidores;
	seguidores=fopen(chave,"a+");
	chave[i++]='2';
	chave[i--]='\0';
	FILE *seguidos;
	seguidos=fopen(chave,"a+");
	chave[i]='\0';
	while(flag){
		int verif;
		printf("Bem-vindo(a)\n");
		printf("Selecione uma opção pelo número de disposição dela\n");
		printf("Menu:\n");
		printf("1.Apresentar minhas informações\n");
		printf("2.Postar\n");
		printf("3.Encontrar amigos para seguir ou deixar de seguir\n");
		printf("4.Ver meus seguidores\n");
		printf("5.Ver pessoas que eu sigo\n");
		printf("6.Ver meus posts\n");
		printf("7.Ver minha timeline\n");
		printf("8.Logout\n");
		scanf("%d",&verif);
		getchar();
		while(verif<1||verif>8){
			printf("Entrada inválida selecione novamente");
		}
		switch(verif){
			case 1 :
				for(i=0;i<3;i++){
					fgets(info,100,tlinfo);
					printf("%s",info);
				}
				break;
			case 2 :
				printf("Escreva seu post abaixo\n");
				fgets(post,128,stdin);
				fprintf(posts,"%s",post);
				fprintf(tlinfo,"%s",post);
				while(fgets(aux,50,seguidores)!=NULL){
					int j=strlen(aux);
					aux[--j]='\0';
					FILE *tlseg=fopen(aux,"a");
					fprintf(tlseg,"%s",post);
					fclose(tlseg);
				}
				break;
			case 3 :
				printf("Digite o nome da pessoa que gostaria de seguir:\n");
				fgets(aux,50,stdin);
				int checa=chec(aux);
				while(checa){
					printf("Este usuario não existe,tente novamente\n");
					fgets(aux,50,stdin);
					checa=chec(aux);
				}
				int manip=strlen(aux)-1;
				aux[manip++]='3';
				aux[manip--]='\0';
				FILE *seguir=fopen(aux,"a");
				fprintf(seguir,"%s",chave);
				fclose(seguir);
				aux[manip]='\0';
				fprintf(seguidos,"%s",aux);
				break;
			case 4 :
				fseek(seguidores,0,SEEK_SET);
				while(fgets(aux,50,seguidores)!=NULL){
					printf("%s\n",aux);
				}
				break;
			case 5 :
				fseek(seguidos,0,SEEK_SET);
				while(fgets(aux,50,seguidos)!=NULL){
					printf("%s\n", aux);
				}
				break;
			case 6:
				fseek(postsr,0,SEEK_SET);
				while(fgets(aux,128,posts)!=NULL){
					printf("%s\n", aux);
				}
				break;
			case 7:
				fseek(tlinfor,0,SEEK_SET);
				while(fgets(aux,128,tlinfo)){
					printf("%s\n", aux);
				}
				break;
			default :
				free(chave);
				free(aux);
				free(info);
				free(post);
				fclose(posts);
				fclose(tlinfo);
				fclose(seguidores);
				fclose(seguidos);
				flag=0;
		}
	}
}

