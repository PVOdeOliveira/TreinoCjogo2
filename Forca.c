#include <stdio.h>
#include <string.h>

char palavra[20], letrasTentadas[26];
int tentativa=0;

void titulo(){ //mostra um titulo
    printf("|*****************|\n");
    printf("|* Jogo da Forca *|\n");
    printf("|*****************|\n\n");
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

void imprimePalavra(){//imprime todas as letras descobertas at� o momento
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

void escolhePalavraSecreta(){
    sprintf(palavra,"MELANCIA"); //Palavra fixa para testes
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

int testaVitoria(){
    int i;

    for(i=0;i<strlen(palavra);i++){
        if(testaCerto(palavra[i])==0){
            return 0;
        }
    }
    return 1;
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

    return 0;

}
