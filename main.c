#include <sys/time.h>
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
    aux.ultima.dia=0;
    aux.ultima.mes=0;
    aux.ultima.ano=0;
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
    printf("******3-JOGAR**********\n");
    printf("******4-RANKNG*********\n");
    printf("******0-SAIR***********\n");
    scanf("%i", &opc);
    return opc;
}



int main() {
    int nPerguntas=0;
    int opc1=0, opc2=0;
    int i=0;
    int pid=0;
    int cont1,cont2;
    struct timeval t;
    gettimeofday(&t, NULL);
    srand(t.tv_usec * t.tv_sec * pid);

    USER newUser;
    ELEMENTO *user[2]={NULL,NULL};
    ELEMENTO *iniListaUser=NULL, *fimListaUser=NULL;
    ELEMENTO *admin=NULL;
    ELEMENTOP *iniListaPerguntas=NULL, *fimListaPerguntas=NULL;
    ELEMENTOP *iniListaPerguntas2=NULL, *fimListaPerguntas2=NULL;
    ELEMENTOR *iniListaRanking=NULL, *fimListaRanking=NULL;

    lerPerguntas(&iniListaPerguntas,&fimListaPerguntas);
    lerUserEmFicheiro(&iniListaUser,&fimListaUser);
    lerRanking(&iniListaRanking,&fimListaRanking);

    removerUltimaPerguntaLida(&iniListaPerguntas,&fimListaPerguntas);
    removerUltimoJogadorLido(&iniListaUser,&fimListaUser);
    removerUltimoRankingLido(&iniListaRanking,&fimListaRanking);


    do{
        opc1=menu_arranque();
        switch(opc1){
            case 1:{
                do{
                    opc2=menu_user();
                    switch (opc2) {
                        case 1:{
                            if(user[0]!=NULL && user[1]!=NULL){
                                printf("Maximo de jogadores em simultâneo\n");
                                break;
                            }
                            do{
                                do{
                                    printf("Jogador %i:\n",i+1);
                                    user[i]=login(iniListaUser);
                                    if(user[i]==NULL){
                                        cont1++;
                                    }
                                }while(user[i]==NULL && cont1!=3);
                                if(cont1==3){
                                    printf("Numero excessivo de tentativas\n");
                                    cont2=3;
                                    cont1=0;
                                    break;
                                }
                                i++;
                                if(user[1]==user[0]){
                                    printf("Utilizador já logado\n");
                                    user[1]=NULL;
                                    i--;
                                }
                            }while(user[0]==NULL || user[1]==NULL);
                            if(user[0]!=NULL && user[1]!=NULL){
                                i=0;
                            }
                            break;
                        }
                        case 2:{
                            newUser=registarUser();
                            inserirFimLista(&iniListaUser,&fimListaUser,newUser);
                            break;
                        }
                        case 3:{
                            if(user[0]==NULL || user[1]==NULL){
                                printf("Sem utilizadores com sessão iniciada\n");
                                break;
                            }
                            else{
                                printf("Introduza a quantidade de perguntas a jogar:\n");
                                scanf("%i",&nPerguntas);
                                printf("\n\t\t\t\t\t\tAtenção\n"
                                       "-Respostas de escolha multipla deve ser introduzida a letra da opção em maiúscula\n"
                                       "-Respostas diretas em caso de nomes deve sempre começar por letra maiúscula\n"
                                       "-Respostas de verdadeiro e falso deve ser introduzida a opção em maiúscula, \"V\" sendo verdadeiro e \"F\" falso\n\n");
                                geradorPerguntas(iniListaPerguntas,&iniListaPerguntas2,&fimListaPerguntas2,nPerguntas);
                                jogada(user,iniListaPerguntas2,fimListaPerguntas2,nPerguntas,iniListaPerguntas,fimListaPerguntas,&iniListaRanking,&fimListaRanking);
                            }
                            break;
                        }
                        case 4:{
                            bubbleSortRankingMes(&iniListaRanking);
                            bubbleSortRankingDia(&iniListaRanking);
                            listarRanking(iniListaRanking);
                            break;
                        }
                        case 0:{
                            break;
                        }
                    }
                }while(opc2!=0);
                break;
            }
            case 2:{
                admin=login(iniListaUser);
                if(admin==NULL){
                    printf("Utilizador errado");
                    break;
                }
                painelAdmin(admin,&iniListaUser,&fimListaUser,&iniListaPerguntas,&fimListaPerguntas);
                break;
            }
            case 0:{
                printf("Saindo...\n");
                gravarRanking(iniListaRanking);
                gravarEmFicheiro(iniListaUser);
                limparLista(&iniListaUser,&iniListaUser);
                limparListaPerguntas(&iniListaPerguntas,&iniListaPerguntas);
                limparListaPerguntas(&iniListaPerguntas2,&iniListaPerguntas2);
                limparListaRanking(&iniListaRanking,&fimListaRanking);
            }
            default:{
                printf("Opção errada\n");
            }
        }
    }while(opc1!=0);

    return 0;
}
