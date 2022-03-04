#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Forca.h"

char palavra[20], letrasTentadas[26];
int tentativa=0;

void titulo(){ //mostra o titulo
    system("cls");

    printf("   ___                         _        ______                            \n");
    printf("  |_  |                       | |       |  ___|                           \n");
    printf("    | | ___   __ _  ___     __| | __ _  | |_ ___  _ __ ___ __ _           \n");
    printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | |  _/ _ \\| '__/ __/ _` |          \n");
    printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | | || (_) | | | (_| (_| |          \n");
    printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| \\_| \\___/|_|  \\___\\__,_|          \n");
    printf("              __/ |                                                       \n");
    printf("             |___/                                                        \n\n\n");

}

void jogada(){ //recebe a letra jogada em cada rodada e armazena em um array com todas as tentativas
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c",&letra);

    letrasTentadas[tentativa]=letra;
    tentativa++;
}

int testaCerto(char letraCerta){
    //compara a letra da jogada atual, ja armazenada no array de tentativas, com a letra certa da posicao testada

    int acertou=0, j;

    for(j=0;j<tentativa;j++){
        if(letrasTentadas[j]==letraCerta){
            acertou=1;
        }
    }
    return acertou;
}

void imprimePalavra(){//imprime todas as letras descobertas até o momento
    int i, acertou;
    for(i=0;i<strlen(palavra);i++){

        acertou = testaCerto(palavra[i]);

        if(acertou==1){
            printf(" %c",palavra[i]);
        }
        else{
            printf(" _");
        }
    }
    printf("\n\n");
}

void escolhePalavraSecreta(){//escolhe a palavra do arquivo de palavras do jogo
    int i, randomico, qtdDePalavras;

    FILE* f;
    f = fopen("Palavras.txt","r"); //abre o arquivo
    if(f == 0) {//testa falha na leitura do arquivo
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    fscanf(f, "%d", &qtdDePalavras); //primeira linha do arquivo tem a quantidade de palavras

    srand(time(0));
    randomico = (rand()% qtdDePalavras); //gera um num aleatorio de 0 ate a quantidade de palavras

    for(i=0; i<=randomico; i++){
        fscanf(f, "%s", palavra); //passa pela lista de palavras e para quando chega no numero randomico, escolhendo a palavra secreta
    }

    fclose(f); //fecha o arquivo
}

int contaErro(){ //conta quantos erros o jogador cometeu
    int i,j,existe,erros=0;

    for(i=0;i<tentativa;i++){
        existe=0;

        for(j=0;j<strlen(palavra);j++){
            if(letrasTentadas[i]==palavra[j]){
                existe=1;
            }
        }
        if(existe==0){
            erros++;
        }
    }
    return erros;
}

int testaVitoria(){ //testa se o jogador ja acertou todas as letras
    int i;

    for(i=0;i<strlen(palavra);i++){
        if(testaCerto(palavra[i])==0){
            return 0;
        }
    }
    return 1;
}


void adicionaPalavra(){
    char resp, novaPalavra[20];
    int fim=0;
    do{
        printf("Deseja adicionar uma nova palavra ao jogo? (S/N)");
        scanf(" %c",&resp);

        if(resp=='S'){
            printf("\nDigite a nova palavra: ");
            scanf("%s",&novaPalavra);
            fim=1;
        }
        else if(resp=='N'){
            fim=1;
        }
        else{
            printf("Escolha uma opcao valida (S/N) [S para sim][N para nao]\n");
        }
    }while(fim==0);

    int qtd;

    FILE* f;
    f = fopen("Palavras.txt","r+");
    if(f == 0) {//testa falha na leitura do arquivo
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }


    fscanf(f,"%d",&qtd);//le a quantidade na primeira linha
    qtd++;//soma 1 na quantidade

    fseek(f,0,SEEK_SET); //volta para a primeira linha
    fprintf(f,"%d",qtd); //escreve a nova quantidade

    fseek(f,0,SEEK_END); //vai para o fim do arquivo
    fprintf(f,"\n%s",novaPalavra); //escreve a nova palavra

    fclose(f);
}


int main() {

    int venceu=0, erros=0;

    escolhePalavraSecreta();
    titulo();

    while(venceu==0 && erros<6){

        imprimePalavra();

        jogada(letrasTentadas,tentativa);

        erros=contaErro();
        venceu=testaVitoria();

    }

    //adicionaPalavra();

    return 0;

}
