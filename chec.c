#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int chec(char *chave,FILE *arq){
	fseek(arq,0,SEEK_SET);
	int compar=1;
	char validade[50];
	while(fgets(validade,50,arq)!=NULL){//puxa as strings do arquivo usuario
		compar=strcmp(chave,validade);//compara todas as strings do arquivo com a passada para a função
		if (!compar){
			break;
		}
	}
	return compar;//retorna o estado(0 para strings iguais, !=0 para strings diferentes
}

void get_int(int *num){//filtra as entradas para nao haver problemas com buffer

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

void get_char(int *chr){//filtra as entradas para nao haver problemas com buffer

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
