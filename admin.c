//
// Created by maria on 05/05/2020.
//
#include "gestaoDados.h"


void painelAdmin(USER users[], int totregistos){ //usuariostotal
    int opc;
    ELEMENTO *inilista=NULL, *fimlista=NULL;
    USER infos;
    //int perG=0;
    //perG=lerperguntas
    if(checkAdmin(users,totregistos)==1) {
        do {
            printf("1 - Listar perguntas\n");
            printf("2 - Adicionar Perguntas\n");
            printf("3 - Alterar pergunta\n");
            printf("4 - Remover pergunta\n");
            printf("0 - SAIR\n");
            scanf("%i", &opc);
            switch (opc) {
                case 1:
                    listarlistaP(inilista);
                    break;
                case 2:
                   // printf("Nova Pergunta: %s\n");
                   // LUIS!
                    break;
                case 3:
                    alterarlista(iniLista);
                    break;
                case 4:
                    remover(&inilista, &fimlista,);
                    break;
                case 0:
                    escreverPerg(inilista, fimlista);
                    limparLista(&inilista, &fimlista);
                    break;
                default:
                    printf("Escolha uma opção entre 1 e 4\n");
            }
        } while (opc != 0);
    } else {
        printf("Não é o administrador\0");
    }



}