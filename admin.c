//
// Created by maria on 05/05/2020.
//
#include "gestaoDados.h"


//*****************************************************
//LISTAR UTILIZADORES
//*****************************************************
void listUsers(USER users[], int totregistos){
    int i;

    if (totregistos==0) {
        printf("Não ha utilizadores\n");
        return;
    }

    for (i=0;i<totregistos;i++) {
        printf("Nome: %s\n username: %s \n idade: %s \n  nacionalidade: %s \n ",users[i].nome,users[i].username,users[i].idade, users[i].nacionalidade);
        if (users[i].isAdmin==1) {
            printf("E Administrador\n");
        } else {
            printf("E Jogador\n");
        }
    }
}



//********************************************************
// Listar por ordem alfabetica
//********************************************************
void ordenaPorNome(USER users[], int totregistos, int tam){
    int i,j,mudar=1;
    USER aux;
    mudar=0;
    for (x=0;x<tam && mudar=0;x++) {
        mudar=1;
        for (i=0;i<tam-1;i++) {
            if (stricmp(users[i].nome,users[i+1].nome)>0) {
                aux=users[i];
                users[i]=users[i+1];
                users[i+1]=aux;
                mudar=0;
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
                case 5:ordenaPorNome(USER users[], int totregistos, int tam);
                    listUsers(users,utotal)
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