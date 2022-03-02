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

int main() {

    int i, j, acertou, venceu=0, enforcou=0;

    sprintf(palavra,"MELANCIA"); //Palavra fixa para testes

    titulo();

    while(venceu==0 && enforcou==0){
        for(i=0;i<strlen(palavra);i++){
            acertou=0;

            for(j=0;j<tentativa;j++){
                if(letrasTentadas[j]==palavra[i]){
                    acertou=1;
                }
            }

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
