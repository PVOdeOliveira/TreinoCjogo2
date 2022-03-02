#include <stdio.h>
#include <string.h>

char palavra[20], letrasTentadas[26];
int tentativa=0;

void titulo(){
    printf("|*****************|\n");
    printf("|* Jogo da Forca *|\n");
    printf("|*****************|\n\n");
}

void jogada(){
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c",&letra);

    letrasTentadas[tentativa]=letra;
    tentativa++;
}

int testaCerto(int tentativa, char letrasTentadas[26], char letraCerta){
    int acertou=0, j;

    for(j=0;j<tentativa;j++){
        if(letrasTentadas[j]==letraCerta){
            acertou=1;
        }
    }
    return acertou;
}

int main() {

    int i, acertou, venceu=0, enforcou=0;

    sprintf(palavra,"MELANCIA"); //Palavra fixa para testes

    titulo();

    while(venceu==0 && enforcou==0){
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

        jogada(letrasTentadas,tentativa);

    }

    return 0;

}
