#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Brincando com C, usando um pouco de cada coisa desde printf até ponteiros.
//feito por: Daniel O. 10/04/2025

char palavra[] = "peralta";
int chances = 3;
char inputs[26];
int tentativa = 0;

void welcome()
{
        printf("========= - Jogo da Forca\n");
        printf("  +---+  \n");
        printf("  |   |  \n");
        printf("  O   |  \n");
        printf(" /|\\  |  \n");
        printf(" / \\  |  \n");
        printf("      |  \n");
        printf("=========\n\n");
        char a;
        printf("Utilize apenas letras! Aperte ENTER para começar.\n");
        scanf("%c", &a);
        
        
}

int verifyletters(char letra)
{
    for (int j = 0; j < strlen(inputs); j++)
    {
        if (inputs[j] == letra)
        {
            return 1;
        }
    }
    return 0;
}

void tilesandletters()
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        int find = verifyletters(palavra[i]);
        if (find)
        {
            printf("%c ", palavra[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

int acertos = 0;
int win(int *definemsg)
{
    acertos = 0;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (verifyletters(palavra[i]))
        {
            acertos++;
        }
        if (acertos == strlen(palavra))
        {
            *definemsg = 1;
            return 1;
        }
    }
    return 0;
}

int erros = 0;
int lose(int *definemsg)
{
    int find = 0;
    for(int i=0;i<strlen(palavra);i++){
        if(inputs[tentativa-1] == palavra[i]){
            find++;   
        }
    }
    if (!find){
        erros++;    
    }
    
    if (erros == chances)
    {
        *definemsg = 0;
        return 1;
    }
    return 0;
}

void status(){
    printf("Tentativa %d, Erros %d/%d", tentativa, erros, chances);
}

void sendinput()
{
    printf("Mande uma letra para verificar: ");
    scanf(" %c", &inputs[tentativa]);
    tentativa++;
}

int main()
{
    int msg;
    welcome();

    do
    {
        tilesandletters();
        printf(" - ");
        status();
        printf("\n");
        sendinput();
    } while (!win(&msg) && !lose(&msg));

    tilesandletters();
    printf(" - ");
    status();
    printf("\n\n");

    if (msg)
    {
        printf("Parabéns, você ganhou!");
    }
    else
    {
        printf("Noob, você perdeu.");
    }
}
