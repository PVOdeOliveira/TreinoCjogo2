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

int testaCerto(int tentativa, char letrasTentadas[26], char letraCerta){
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

        acertou = testaCerto(tentativa, letrasTentadas, palavra[i]);

        if(acertou==1){
            printf(" %c",palavra[i]);
        }
        else{
            printf(" _");
        }
    }
    printf("\n\n");
}


int main() {

    int venceu=0, enforcou=0;

    sprintf(palavra,"MELANCIA"); //Palavra fixa para testes

    titulo();

    while(venceu==0 && enforcou==0){

        imprimePalavra();

        jogada(letrasTentadas,tentativa);

    }

    return 0;

}
