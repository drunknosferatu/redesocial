#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int chec(char *chave){
	FILE *usuariosr;
	usuariosr=fopen("usuarios.txt","r");
	int compar;
	char validade[50];
	while(fgets(validade,50,usuariosr)!=NULL){//puxa as strings do arquivo usuario
		compar=strcmp(chave,validade);//compara todas as strings do arquivo com a passada para a função
		if (!compar){
			break;
		}
	}
	return compar;//retorna o estado(0 para strings iguais, !=0 para strings diferentes
}

void get_int(int *num){

    int flag = 0;

    char str[100];

    fgets(str, 100,stdin);

    *num = atoi(str);

    int i = 0;

    while(*num == 0 && str[i] != '\n'){

        if(str[i] < '0' || str[i] > '9'){

            *num = -1;
            break;

        }
        i++;

    }



}

void get_char(int *chr){

    int flag = 0;

    char str[100];

    fgets(str, 100,stdin);

    int i = 0;

    *chr = str[0];
    while(str[i] != '\n'){

        if(str[i] != 's' && str[i] != 'n' || i > 0){

            *chr = 'x';
            break;

        }
        i++;

    }



}
