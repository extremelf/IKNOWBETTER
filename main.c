#include "gestaoDados.h"


USER registarUser(){
    USER aux;

    printf("Introduza nome:\n");
    scanf("%100[^\n]s",aux.nome);
    printf("Introduza password:\n");
    scanf("%100[^\n]s",aux.password);

    return aux;
}
int menu_arranque () {
    int opc = 0;
    printf("*************MENU-************\n");
    printf("***********1-JOGAR************\n");
    printf("***********2-ADMINISTRAR******\n");
    printf("***********0-SAIR*************\n");
    scanf("%i", &opc);
    return opc;
}
int menu_user() {
    int opc = 0;
    printf("*******MENU*************\n");
    printf("******1-ACESSAR CONTA***\n");
    printf("******2-REGISTAR*******\n");
    printf("******0-SAIR***********\n");
    scanf("%i", &opc);
    return opc;
}
int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    USER newUser;
    printf("BEM VINDOS AO JOGO I KNOW BETTER");
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;

    iniListaUser=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));

    printf("\n");
    printf("Qual a quantidade de perguntas a jogar:");
    scanf("%i",&nPerguntas);

    opc1=menu_arranque();
    switch(opc1){
        case 1:jogar(users,utotal){
            opc2=menu_user();
            switch (opc2) {
                case 1:{
                    jogar(users,utotal);
                    loginUser (USER users[], int totregistos);
                    break;
                }
                case 2:{
                    newUser=registarUser();
                    inserirFimLista(iniListaUser,fimListaUser,newUser);
                    break;
                }

            }
        }
    }


    return 0;
}
