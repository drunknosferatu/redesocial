#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "chec.h"
void registro(){
	FILE *usuarios;
	usuarios=fopen("usuarios.txt","a+");
	setbuf(stdin,NULL);
	printf("Insira sua nova chave de acesso (as chaves podem ter até 50 caracteres):\n");
	char novachave[50];
	fgets(novachave,50,stdin);
	int compar=chec(novachave,usuarios);//checa se ja existe uma chave com esse nome
	while(!compar){
		printf("Chave indisponivel, tente novamente\n");
		fgets(novachave,50,stdin);
		compar=1;
		compar=chec(novachave,usuarios);
	}
	fprintf(usuarios,"%s",novachave);//ao chegar aqui a chave inserida é valida
	int i=strlen(novachave);
	novachave[--i]='\0';//tira o \n da string pra facilitar a manipulação do arquivo por nome
	FILE *novousuario4;//para abrir o arq. dos seus posts
	FILE *novousuario2;//para abrir o arq. de seguidores
	FILE *novousuario3;// para abrir o arq. de seguidos
	FILE *novousuario;//para abrir o arq. de timeline
	novousuario=fopen(novachave, "w");//faz os registros necessarios(deve ser alterado para tratar entradas)
	printf("Adicione algumas informações importantes:\n");
	printf("Nome:\n");
	char nome[100];
	fgets(nome,100,stdin);
	fprintf(novousuario, "%s",nome);
	printf("Data de nascimento, separada por barras(EX:03/08/2002):\n");
	char nasc[12];
	fgets(nasc,11,stdin);
	fprintf(novousuario, "%s", nasc);
	printf("Número de telefone(sem traços e pontos,Ex:19989301761):\n");
	char telefone[13];
	fgets(telefone,12,stdin);
	fprintf(novousuario, "%s", telefone);
	fclose(usuarios);
	fclose(novousuario);
	novachave[i++]='2';
	novachave[i--]='\0';
	novousuario2= fopen(novachave, "w");//cria o arq. de seguidores
	novachave[i++]='3';
	novachave[i--]='\0';
	novousuario3= fopen(novachave,"w");//cria o arq de seguidos
	novachave[i++]='4';
	novachave[i]='\0';
	novousuario4=fopen(novachave, "w");//cria o arq dos seus posts
	fclose(novousuario2);
	fclose(novousuario3);
	fclose(novousuario4);
}
