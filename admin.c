//
// Created by maria on 05/05/2020.
//
#include "gestaoDados.h"




//**************************************************
//PAINEL
//**************************************************
void painelAdmin(USER users[], int totregistos){ //usuariostotal
    int opc;
    ELEMENTO *inilista=NULL, *fimlista=NULL;
    INFO infos;
    //int perG=0;
    //perG=lerperguntas
    if(checkAdmin(users,totregistos)==1) {
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
                    listarlistaP(inilista);
                    break;
                case 2:
                 
                    break;
                case 3:
                    alterarlista(iniLista);
                    break;
                case 4:
                    remover(&inilista, &fimlista, totperguntas);

                    removerP (ELEMENTOP **inilista, ELEMENTO **fimlista)
                    break;
                case 5:ordenaPorNome(USER users[], int totregistos, int tam);
                    listUsers(users,utotal)
                    break;
                case 6:
                    listUser(users, totregistos);
                    break;
                case 0:
                    printf("Sair da parte Administrativa")


                    limparLista(&inilista, &fimlista);
                    break;
                default:
                    //libertar memoria!
                    printf("Escolha uma opção entre 1 e 6\n");
            }
        } while (opc != 0);
    }
    }






