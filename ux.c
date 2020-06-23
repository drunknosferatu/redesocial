#include<stdio.h>
#include<string.h>
#include "chec.h"
#include<stdlib.h>
#include "apagar.h"
void ux(char *chave){
	int flag=1;//flag de logout
	int k;//variavel auxiliar
	char *post;//os ponteiros abaixo sao para auxiliar em ações do codigo
	char *aux;
	char *info;
	char *auxpost;
	auxpost=(char*) malloc(sizeof(char)*181);//a maior concatenação possivelpara um nome de usuario e um post (129+52)
	if(auxpost==NULL){
		printf("Falha interna. Fechando o programa\n");
		exit(0);
	}
	info=(char*)malloc(sizeof(char)*100);//tamanho das infos
	if(info==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	post=(char*)malloc(sizeof(char)*129);//é declarado com 129 pois o \0 e o\n foram considerados
	if(post==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	aux=(char*)malloc(sizeof(char)*52);//50 chars para o nome do usuario e \0 e \n
	if(aux==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	int i=strlen(chave);//é feita uma manipulaçã de strings devido ao sistema de arquivos do programa
	chave[--i]='1';
	FILE *tlinfo;
	tlinfo=fopen(chave,"a+");//abre o arq de timeline
	if(tlinfo==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i]='4';
	FILE *posts;//abre o arq de posts feitos pelo usuario
	posts=fopen(chave,"a+");	
	if(posts==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i]='3';
	FILE *seguidores;//abre o arq de seguidores
	seguidores=fopen(chave,"a+");	
	if(seguidores==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i]='2';
	FILE *seguidos;//abre o arq de pessoas seguidas 
	seguidos=fopen(chave,"a+");
	if(seguidos==NULL){
		printf("Falha interna. Fechando o programa");
		exit(0);
	}
	chave[i]='\0';//foi estabelecido esse padrao da string chave para todo o código
	while(flag){//loop de funcionamento do código
		int verif;//verificação da ação que será tomada
		printf("Bem-vindo(a)\n");//menu
		printf("Selecione uma opção pelo número de disposição dela\n");
		printf("Menu:\n");
		printf("1.Apresentar minhas informações\n");
		printf("2.Postar\n");
		printf("3.Encontrar amigos para seguir ou deixar de seguir\n");
		printf("4.Ver meus seguidores\n");
		printf("5.Ver pessoas que eu sigo\n");
		printf("6.Ver meus posts(entre aqui para poder apaga-los)\n");
		printf("7.Ver minha timeline\n");
		printf("8.Logout\n");
		get_int(&verif);//função criada devido aos problemas com buffer
		while(verif<1||verif>8){
			printf("Entrada inválida selecione novamente\n");
            get_int(&verif);
		}
		switch(verif){
			case 1 ://printa nome e telefone do usuario, assim como seu numero de seguidores e posts
				fseek(tlinfo,0,SEEK_SET);
				for(i=0;i<2;i++){
					fgets(info,100,tlinfo);
					printf("%s",info);
				}
				k=0;
				printf("Nickname:%s\n",chave);
				fseek(posts,0,SEEK_SET);
				while(fgets(post,129,posts)!=NULL){
						k++;
				}
				k=0;
				printf("Você fez %d posts\n", k);
				fseek(seguidores,0,SEEK_SET);
				while(fgets(aux,52,seguidores)!=NULL){
					k++;
				}
				printf("Você tem %d seguidores\n",k);
				break;
			case 2 ://faz as postagens
				printf("Escreva seu post abaixo\n");
				fgets(post,129,stdin);//pega o post do usuario pelo teclado
				fprintf(posts,"%s",post);//adiciona ao arquivo de postagens feitas por ele
				FILE *adm=fopen("adm","a");//poe o post no arquivo de posts de toda a rede(para administração)
				fprintf(adm,"%s", post);
				fclose(adm);
				fseek(seguidores,0,SEEK_SET);
				while(fgets(aux,52,seguidores)!=NULL){//concatena a string do nome do usuario autor do post ao post para identificação e printa na timeline dos seguidores
					int j=strlen(aux);//variavel para manipulação de strings
					aux[--j]='1';
					FILE *tlseg=fopen(aux,"a");
					if(tlseg==NULL){
						printf("Falha interna. Fechando o programa");
						exit(0);
					}
					strcpy(auxpost,chave);
					j=strlen(auxpost);
					auxpost[j++]=':';//adiciona os dois pontos só para visuais
					auxpost[j]='\0';
					strcat(auxpost,post);
					fprintf(tlseg,"%s",auxpost);
					fclose(tlseg);
				}
				break;
			case 3 ://segue ou deixa de seguir algum usuario
				printf("Digite o nome da pessoa que gostaria de seguir ou deixar de seguir:\n");
				fgets(aux,52,stdin);//pega o nome do usuario que deixará de ser seguido ou será seguido
				FILE *usuarios;
				usuarios=fopen("usuarios.txt","r");//abre a tabela geral de users
				if(usuarios==NULL){
					printf("Falha interna. Fechando o programa");
					exit(0);
				}
				int checa=chec(aux,usuarios);//função para ver se o user existe
				while(checa){
					printf("Este usuario não existe,tente novamente\n");
					fgets(aux,52,stdin);
					checa=chec(aux,usuarios);
				}
				k=strlen(chave);
				fseek(seguidos,0,SEEK_SET);
				checa=chec(aux,seguidos);//ve se o usuario ja é seguido
				if (!checa){
					printf("Você segue esse usuário, gostaria de deixar de segui-lo?[s/n]\n");
					char teste;
					get_char(&teste);//função feita devido a problemas com buffer do getc
					while(teste!='s'&&teste!='n'){
						printf("Entrada inválida, tente novamente\n");
						get_char(&teste);
					}
					if(teste=='s'){//o usuario deixara de seguir
						chave[k++]='2';
						chave[k--]='\0';
						apagar_usuario(seguidos,aux,chave);//função para apagar o seguido da lista de seguidos
						chave[k++]='\n';
						chave[k--]='\0';
						int y=strlen(aux)-1;
						aux[y++]='3';
						aux[y--]='\0';
						FILE *exclude=fopen(aux,"r");
						if(exclude==NULL){
							printf("Falha interna. Saindo do programa");
							exit(0);
						}
						apagar_usuario(exclude,chave,aux);//exclui o usuario da lista de seguidores do alvo
						fclose(exclude);
						chave[k]='\0';
						aux[y++]='\n';
						aux[y]='\0';
						printf("Você deixou de seguir este usuário\n");
					}else{
						break;
					}
				}else{//o usuario atual nao segue o alvo entao entra para seguir
					int manip=strlen(aux)-1;//faz a manipulação de strings
					aux[manip++]='3';//abre o painel de seguidores do alvo
					aux[manip--]='\0';
					FILE *seguir=fopen(aux,"a");
					if(seguir==NULL){
						printf("Falha interna. Fechando o programa\n");
						exit(0);
					}
					chave[k++]='\n';
					chave[k--]='\0';
					fprintf(seguir,"%s",chave);//printa a chave do usuario no painel de seguidores do alvo
					chave[k]='\0';//volta a chave do usuario ao padrão
					fclose(seguir);
					aux[manip++]='\n';
					aux[manip]='\0';
					fprintf(seguidos,"%s",aux);
					fclose(usuarios);
					printf("Você seguiu este usuário\n");
				}
				break;
			case 4 ://printa os seguidores
				printf("Essas são as pessoas que te seguem:\n");
				fseek(seguidores,0,SEEK_SET);
				while(fgets(aux,52,seguidores)!=NULL){
					printf("%s\n",aux);
				}
				break;
			case 5 ://print os seguidos
				printf("Você segue esssas pessoas:\n");
				fseek(seguidos,0,SEEK_SET);
				while(fgets(aux,52,seguidos)!=NULL){
					printf("%s\n", aux);
				}
				break;
			case 6://mostra e apaga os posts
				fseek(posts,0,SEEK_SET);
				int num=1;//numero de posts
				k=0;
				while(fgets(post,129,posts)!=NULL){
					k++;
				}
				int h=1;
				char duvida='s';
				fseek(posts,0,SEEK_SET);
				printf("Esses são seus posts:\n");
				while(duvida=='s'&&num<=k){//printa os posts com um índice
					while(num<=5*h&&fgets(post,129,posts)!=NULL){
						printf("%d: ", num);
						printf("%s", post);
						num++;
					}
					h++;
					printf("Deseja ver mais posts?[s/n]\n");
					get_char(&duvida);
					while(duvida!='s'&&duvida!='n'){
						printf("Entrada inválida. Tente Novamente\n");
						get_char(&duvida);
					}
				}
				if(num==1){//o numero de posts nao foi incrementado logo ele nao tem posts
					printf("Você ainda não tem posts\n");
					break;
				}
				printf("Esses são todos seus posts\n");
				printf("Deseja apagar algum post?[s/n]\n");
				char quest;
				get_char(&quest);//checa se o usuario quer apagar algum post
				while(quest!='s'&&quest!='n'){
					printf("Entrada inválida, tente novamente");
					get_char(&quest);
				}
				if (quest=='s'){
					printf("Digite o número do post que você deseja apagar\n");
					int numexclude;
					get_int(&numexclude);//pega o numero do post a ser apagado pelo indice
					fseek(posts,0,SEEK_SET);
					int z=0;//variavel para achar o post a ser apagado
					while(fgets(post,129,posts)!=NULL){
						z++;
						if(z==numexclude){
							break;//o posto foi encontrado e salvo
						}
					}
					int w=strlen(chave);
					chave[w++]='4';
					chave[w--]='\0';
					apagar_post(posts,post,chave);//apaga o post da interface do usuario
					chave[w]=':';
					fseek(seguidores,0,SEEK_SET);
					strcpy(auxpost,chave);
					strcat(auxpost,post);//concatena a chave ao post para se adequar ao padrao
					chave[w]='\0';//retorna a chave ao padrao
					while(fgets(aux,52,seguidores)!=NULL){//apaga o post da timeline de todos os seguidores
						int w=strlen(aux)-1;
						aux[w++]='1';
						aux[w]='\0';
						FILE *excludepost=fopen(aux,"a+");
						if(excludepost==NULL){
							printf("Falha interna. Fechando o programa");
							exit(0);
						}
						apagar_post(excludepost,auxpost,aux);
						fclose(excludepost);
						printf("Post apagado com sucesso\n");
					}
				}
				break;
			case 7://printa a timeline em ordem cronologica
				k=0;//numero de posts totais da timeline
				int l;//variavel que indica o post a ser postado
				int m=1;//variavel dos posts a serem postados(setado como um devido as propriedades multiplicativas usadas)
				int o=1;//numero de "blocos de 5"
				char perg='s';//verifica a "vontade" do user de postar sua timeline(começa "setado")
				fseek(tlinfo,0,SEEK_SET);
				while(fgets(post,129,tlinfo)!=NULL){//conta o numero de posts
					k++;
				}
				while(perg=='s'&&m<=k-2){//printa os posts de 5 em 5
					while(m<=5*o&&tlinfo!=NULL&&m<=k-2){
						l=0;//vai buscar o post a ser postado do inicio do arquivo
						fseek(tlinfo,0,SEEK_SET);
						while(fgets(post,129,tlinfo)!=NULL&&l<=k-m-1){//busca o post
							l++;
						}
						printf("%s",post);//printa
						m++;//incrementa o numero de posts
					}
					o++;//adiciona um bloco ja postado
					printf("Gostaria de atualizar sua timeline?[s/n]\n");
					get_char(&perg);
					while(perg!='s'&&perg!='n'){
						printf("Entrada inválida. Tente novamente\n");
						get_char(&perg);
					}
				}
				if(m>k){
					printf("Esses é o fim de sua timeline\n");//declara o fim da tl
				}
				break;
			default ://libera as strings, fecha os arquivos e faz logout
				free(chave);
				free(aux);
				free(info);
				free(post);
				fclose(posts);
				fclose(tlinfo);
				fclose(seguidores);
				fclose(seguidos);
				free(auxpost);
				flag=0;
		}
	}
}
