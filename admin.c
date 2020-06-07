#include "gestaoDados.h"


PERGUNTA newQuestion(){
    PERGUNTA aux;
    int tipoPergunta=0;
    printf("Introduza a pergunta:\n");
    scanf(" %300[^\n]s",aux.pergunta);
    do{
        printf("Introduza o tipo de pergunta:\n"
               "1- escolha multipla\n"
               "2- resposta direta\n"
               "3- Verdadeiro ou falso\n");
        scanf("%i",&tipoPergunta);
        switch(tipoPergunta){
            case 1:{
                printf("Introduza a resposta A:\n");
                scanf(" %300[^\n]s",aux.respostas[0]);
                printf("Introduza a resposta B:\n");
                scanf(" %300[^\n]s",aux.respostas[1]);
                printf("Introduza a resposta C:\n");
                scanf(" %300[^\n]s",aux.respostas[2]);
                printf("Introduza a resposta D:\n");
                scanf(" %300[^\n]s",aux.respostas[3]);
                printf("Introduza a opção correta(apenas a letra maiuscula):\n");
                scanf(" %100[^\n]s",aux.correta);
                break;
            }
            case 2:{
                printf("Introduza a resposta direta:\n");
                scanf(" %300[^\n]s",aux.correta);
                break;
            }
            case 3:{
                printf("Resposta V ou F:\n");
                scanf(" %100[^\n]s",aux.correta);
                break;
            }
            default: printf("opcao errada");
        }
    }while(tipoPergunta!=0);

    return aux;
}

//**************************************************
//PAINEL
//**************************************************
void painelAdmin(ELEMENTO *admin,ELEMENTO **iniListaUser,ELEMENTO **fimListaUser,ELEMENTOP **iniListaPerguntas,ELEMENTOP **fimListaPerguntas){
    int opc;
    int indiceRemover=0;
    int indiceAlterar;
    PERGUNTA novaPergunta;

    if(admin->info.isAdmin==1) {
        do {
            printf("1 - Listar perguntas\n");
            printf("2 - Adicionar Perguntas\n");
            printf("3 - Alterar pergunta\n");
            printf("4 - Remover pergunta\n");
            printf("5 - Listar por ordem alfabética\n");
            printf("6 - Listar utilizadores\n");
            printf("0 - SAIR\n");
            scanf("%i", &opc);
            switch (opc) {
                case 1:
                    listarPerguntas(*iniListaPerguntas);
                    break;
                case 2:
                    novaPergunta=newQuestion();
                    inserirFimListaPerguntas(iniListaPerguntas,fimListaPerguntas,novaPergunta);
                    break;
                case 3:
                    printf("Introduza o indice da pergunta a alterar:(999 para cancelar acção)");
                    scanf("%i",&indiceAlterar);
                    if(indiceAlterar==999){
                        printf("\nAção cancelada\n");
                        break;
                    }
                    printf("\n");
                    alteraPergunta(*iniListaPerguntas,indiceAlterar);
                    break;
                case 4:
                    printf("Introduza o indice da pergunta a remover:(999 para cancelar ação)");
                    scanf("%i",&indiceRemover);
                    if(indiceRemover==999){
                        printf("\nAção cancelada\n");
                        break;
                    }
                    printf("\n");
                    removerPergunta(iniListaPerguntas, fimListaPerguntas,indiceRemover);

                    break;
                case 5:
                    bubbleSort(iniListaUser);
                    listarUtilizadores(*iniListaUser);
                    break;
                case 6:
                    listarUtilizadores(*iniListaUser);
                    break;
                case 0:
                    printf("Sair da parte Administrativa");
                    gravarPerguntasFicheiro(*iniListaPerguntas);
                    break;
                default:
                    printf("Escolha uma opção entre 1 e 6\n");
            }
        } while (opc != 0);
    }
    else{
        printf("O utilizador não tem privilégios de administrador\n");
    }
}