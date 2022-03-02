#include <stdio.h>
#include <string.h>

int main() {
    char palavra[20], letrasTentadas[26], letra;
    int i, j, tentativa=0, acertou, venceu=0, enforcou=0;

    sprintf(palavra,"MELANCIA"); //Palavra fixa para testes

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

        printf("Digite uma letra: ");
        scanf(" %c",&letra);

        letrasTentadas[tentativa]=letra;
        tentativa++;
    }

    return 0;

}
