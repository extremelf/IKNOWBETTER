#include "gestaoDados.h"
#define MAXUSERS 2

USER registarUser(){
    USER aux;

    printf("Introduza nome:\n");
    scanf("%100[^\n]s",aux.nome);
    printf("Introduza password:\n");
    scanf("%100[^\n]s",aux.passwd);
    printf("Introduza idade:\n");
    scanf("%100[^\n]s",aux.idade);
    printf("Introduza nacionalidade:\n");
    scanf("%100[^\n]s",aux.nacionalidade);
    aux.dinheiroCaixa=900;

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
    int jogadores=0;
    USER newUser;
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTOP *iniListaPerguntas=NULL, *fimListaPerguntas=NULL;

    iniListaUser=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));
    iniListaPerguntas=(ELEMENTOP *)calloc(1,sizeof(ELEMENTOP));

    opc1=menu_arranque();
    switch(opc1){
        case 1:jogar(users,utotal){
            opc2=menu_user();
            switch (opc2) {
                case 1:{
                    break;
                }
                case 2:{
                    if(jogadores<=2){
                        newUser=registarUser();
                        newUser->admin=0;
                        inserirFimLista(iniListaUser,fimListaUser,newUser);
                        jogadores++;
                    }
                    else{
                        printf("Maximo de jogadores atingido");
                    }
                    break;
                }
            }
        }
        case 2:{
            newUser=registarUser();
            newUser->admin=1;
            inserirFimLista(iniListaUser,fimListaUser,newUser);

        }
    }
    if(jogadores==2){
        //começa jogo
    }


    return 0;
}
