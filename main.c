#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char palavra[] = "peralta";
int chances = 2;
char inputs[26];
int tentativa = 0;

void welcome()
{
    printf("Bem-vindo\n");
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
    printf("\n");
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
    for (int i = 0; i < strlen(palavra); i++)
    {
        //Terminar essa lógica.
    }

    if(find>0){
        erros++;
    }

    if (erros == chances)
    {
        return 1;
        *definemsg = 0;
    }
    return 0;
}

void sendinput()
{
    printf("Ponha a bomba ai da letra: ");
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
        sendinput();
    } while (!win(&msg) && !lose(&msg));

    tilesandletters();

    if (msg)
    {
        printf("Parabéns, você ganhou!");
    }
    else
    {
        printf("Noob");
    }
}
