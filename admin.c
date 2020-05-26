//
// Created by maria on 05/05/2020.
//
#include "gestaoDados.h"


//*****************************************************
//LISTAR UTILIZADORES
//*****************************************************
void listUsers(USER users[], int totregistos){
    int i=0;
    printf("Listar todos os utilizadores:\n");
    for(i=0;i<totregistos;i++){
        printf("%s - %s %s %.s\n", totregistos[i].nome, totregistos[i].username,
               totregistos[i].idade, totregistos[i].nacionalidade, );
    }
}

//********************************************************
// Listar por ordem alfabetica
//********************************************************
void ordenaPorNome(USER users[], int totregistos){
    int i=0, x=0;
    USER aux;
    for(x=0; x<totregistos;x++){
        for(i=0;i<totregistos-1-x;i++){
            if(strcmp(users[i].nome,users[i+1].nome)>0){
                aux=users[i];
                users[i]= users[i+1];
                users[i+1]=aux;
            }
        }
    }
}
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
                   // printf("Nova Pergunta: %s\n");
                   // LUIS!
                    break;
                case 3:
                    alterarlista(iniLista);
                    break;
                case 4:
                    remover(&inilista, &fimlista);
                    break;
                case 5:ordenaPorNome(USER users[], int totregistos)
                    break;
                case 6:
                    listUser(users, totregistos);
                    break;
                    case 0:
                    escreverPerg(inilista, fimlista);
                    limparLista(&inilista, &fimlista);
                    break;
                default:
                    printf("Escolha uma opção entre 1 e 6\n");
            }
        } while (opc != 0);
    } else {
        printf("Não é o administrador\0");
    }




}