#include "gestaoDados.h"


USER registarUser(){
    USER aux;

    printf("Introduza nome:\n");
    scanf(" %100[^\n]s",aux.nome);
    printf("Introduza um username:\n");
    scanf(" %100[^\n]s",aux.username);
    printf("Introduza password:\n");
    scanf(" %100[^\n]s",aux.passwd);
    printf("Introduza a idade atual:\n");
    scanf("%i",&aux.idade);
    printf("Introduza a sua nacionalidade:\n");
    scanf(" %100[^\n]s",aux.nacionalidade);
    aux.isAdmin=0;
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

void jogada(int *user[],int *perguntasJogo[]){
    int i;

    printf("%s\n%s\t%s\n%s\t%s")


}
int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    USER newUser;
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTO *user[2];

    int i;

    iniListaUser=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));

    printf("\n");
    printf("Qual a quantidade de perguntas a jogar:");
    scanf("%i",&nPerguntas);

    ELEMENTO perguntasJogo[nPerguntas];

    opc1=menu_arranque();
    switch(opc1){
        case 1:jogar(users,utotal){
            opc2=menu_user();
            switch (opc2) {
                case 1:{
                    do{
                        do{
                            user[i]=login(iniListaUser,fimListaUser);
                        }while(user[i]==NULL);
                        i++;
                    }while(i!=2 && user[1]==NULL && user[2]==NULL);

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
