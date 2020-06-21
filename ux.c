#include<stdio.h>
#include<string.h>
#include "chec.h"
#include<stdlib.h>
#include "apagar.h"
void ux(char *chave){
	int flag=1;
	int k;
	char *post;
	char *aux;
	char *info;
	info=(char*)malloc(sizeof(char)*100);
	if(info==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	post=(char*)malloc(sizeof(char)*128);	
	if(post==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	aux=(char*)malloc(sizeof(char)*50);
	if(aux==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	int i=strlen(chave);
	chave[--i]='\0';
	FILE *tlinfo;
	tlinfo=fopen(chave,"a+");	
	if(tlinfo==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i++]='4';
	chave[i--]='\0';
	FILE *posts;
	posts=fopen(chave,"a+");	
	if(posts==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i++]='3';
	chave[i--]='\0';
	FILE *seguidores;
	seguidores=fopen(chave,"a+");	
	if(seguidores==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i++]='2';
	chave[i--]='\0';
	FILE *seguidos;
	seguidos=fopen(chave,"a+");
	if(seguidos==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
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
		get_int(&verif);//nova função de pegar novo digito
		//getchar() removido
		while(verif<1||verif>8){
			printf("Entrada inválida selecione novamente\n");
            get_int(&verif);
		}
		switch(verif){
			case 1 :
				fseek(tlinfo,0,SEEK_SET);
				for(i=0;i<3;i++){
					fgets(info,100,tlinfo);
					printf("%s",info);
				}
				break;
			case 2 :
				printf("Escreva seu post abaixo\n");
				fgets(post,128,stdin);
				fprintf(posts,"%s",post);
				FILE *adm=fopen("adm","a");
				fprintf(adm,"%s", post);
				fclose(adm);
				fseek(seguidores,0,SEEK_SET);
				while(fgets(aux,50,seguidores)!=NULL){
					int j=strlen(aux);
					aux[--j]='\0';
					FILE *tlseg=fopen(aux,"a");
					if(tlseg==NULL){
						printf("Falha interna. Fechando o programa");
						exit(0);
					}
					fprintf(tlseg,"%s",post);
					fprintf(tlseg,"%s:\n",chave);
					fclose(tlseg);
				}
				break;
			case 3 :
				printf("Digite o nome da pessoa que gostaria de seguir ou deixar de seguir:\n");
				fgets(aux,50,stdin);
				FILE *usuarios;
				usuarios=fopen("usuarios.txt","r");
				if(usuarios==NULL){
					printf("Falha interna. Fechando o programa");
					exit(0);
				}
				int checa=chec(aux,usuarios);
				while(checa){
					printf("Este usuario não existe,tente novamente\n");
					fgets(aux,50,stdin);
					checa=chec(aux,usuarios);
				}
				k=strlen(chave);
				fseek(seguidos,0,SEEK_SET);
				checa=chec(aux,seguidos);
				if (!checa){
					printf("Você segue esse usuário, gostaria de deixar de segui-lo?[s/n]\n");
					char teste;
					get_char(&teste);
					while(teste!='s'&&teste!='n'){
						printf("Entrada inválida, tente novamente\n");
						get_char(&teste);
					}
					if(teste=='s'){
						char *aux2;
						aux2=(char*) malloc(sizeof(char)*50);
						if (aux2==NULL){
							printf("Falha interna. Fechando o programa\n");
							exit(0);
						}
						int z=0;
						fseek(seguidos,0,SEEK_SET);
						while(fgets(aux2,50,seguidos)!=NULL){
							z++;
						}
						chave[k++]='2';
						chave[k--]='\0';
						apagar_usuario(seguidos,aux,z,chave);
						chave[k++]='\n';
						chave[k--]='\0';
						int y=strlen(aux)-1;
						aux[y++]='3';
						aux[y--]='\0';
						FILE *exclude=fopen(aux,"r");
						z=0;
						while(fgets(aux2,50,exclude)!=NULL){
							z++;
						}
						apagar_usuario(exclude,chave,z,aux);
						fclose(exclude);
						free(aux2);
						chave[k]='\0';
						aux[y++]='\n';
						aux[y]='\0';
					}else{
						break;
					}
				}else{
					int manip=strlen(aux)-1;
					aux[manip++]='3';
					aux[manip--]='\0';
					FILE *seguir=fopen(aux,"a");
					if(seguir==NULL){
						printf("Falha interna. Fechando o programa");
						exit(0);
					}
					chave[k++]='\n';
					chave[k--]='\0';
					fprintf(seguir,"%s",chave);
					chave[k]='\0';
					fclose(seguir);
					aux[manip++]='\n';
					aux[manip]='\0';
					fprintf(seguidos,"%s",aux);
					fclose(usuarios);
				}
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
				fseek(posts,0,SEEK_SET);
				int num=1;
				while(fgets(aux,128,posts)!=NULL){
					printf("%d: ", num);
					printf("%s", aux);
					num++;
				}
				printf("Deseja apagar algum post?[s/n]\n");
				char quest;
				get_char(&quest);
				while(quest!='s'&&quest!='n'){
					printf("Entrada inválida, tente novamente");
					get_char(&quest);
				}
				if (quest=='s'){
					apagar_post(
				break;
			case 7:
				k=0;
				int l=0;
				int m=1;
				int o=1;
				char perg='s';
				int tamanho=0;
				int tamultimos=0;
				fseek(tlinfo,0,SEEK_SET);
				while(fgets(aux,128,tlinfo)!=NULL){
					k++;
				}
				while(perg=='s'&&m<=k){
					while(m<=10*o&&tlinfo!=NULL&&m<=k){
						l=0;
						fseek(tlinfo,0,SEEK_SET);
						while(fgets(aux,128,tlinfo)!=NULL&&l<=k-m-1){
							l++;
						}
						printf("%s",aux);
						m++;
					}
					o++;
					printf("Gostaria de atualizar sua timeline?[s/n]\n");
					get_char(&perg);
				}
				if(m>k){
					printf("Esses é o fim de sua timeline\n");
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

