 ///// PARTE DE ADICIONAR PERGUNTAS POR CATEGORIA ////

 typedef struct info {
     char pergunta[100];
     char respostaA[50];
     char respostaB[50];
     char respostaC[50];
     char respostaD[50];
     char respostaCerta;
     char tipo;
     int id;
     int pro,contra;
 } INFO;

 void  inserirPergunta(ELEMENTOP **iniLista, ELEMENTOP **fimLista){
     FILE *fp=NULL;
     PERGUNTA pergunta;

     fp=fopen("perguntas.dat","rb");
     if(fp==NULL){
         printf("Erro a abrir o ficheiro\n");
         return;
     } else {  //
         printf("Qual a categoria que pretende inserir a pergunta: ");
         scanf("%s", &cat); //buscar no ficheiro como tinhas dito, não sei nome
         printf ("Pretende fazer pergunta de VF, escolha multipla ou resposta rápida?:\n");
            scanf("%s", &tipo);
         if (strcmp (pergunta,"VF")==0){
             printf("Insira a pergunta:\n");
             fflush(stdin);
             gets(info.pergunta);
             printf("Insira se a pergunta é verdadeira ou falsa \n");
             fflush(stdin);
             scanf("%c",&infos.respostaCerta);
         } if(strcmp(pergunta, "Escola Multipla")==0){
             printf("Insira a pergunta:\n");
             fflush(stdin);
             gets(infos.pergunta);
             printf("Insira a resposta A:\n");
             fflush(stdin);
             gets(infos.respostaA);
             printf("Insira a resposta B:\n");
             fflush(stdin);
             gets(infos.respostaB);
             printf("Insira a resposta C:\n");
             fflush(stdin);
             gets(infos.respostaC);
             printf("Insira a resposta D:\n");
             fflush(stdin);
             gets(infos.respostaD);
             printf("Insira a alinea da resposta certa:\n");
             fflush(stdin);
             scanf("%c",&infos.respostaCerta);

     } is (strcmp(escolha "Resposta Rapida")==0){
            printf(printf("Insira a pergunta:\n");
             fflush(stdin);
             gets(infos.pergunta);
             printf("Insira a resposta certa:\n");
             fflush(stdin);
             scanf("%c",&infos.respostaCerta);
         }
     }
}

/////////////   PONTUAÇÃO////
void bubblesorteP (USER users, int tam, totPerguntas){
    int i, x;
    USER aux;
    for(x=0;tam==0;x++){
        for(i=0;i<tam-1;i++){
            if(users[i].pergunta<users[i+1].pergunta){
                aux=users[i];
                users[i]=users[i+1];
                users[i+1]=aux;

            }
        }
    }

}

// RECORDE DE PONTUAÇÃO////



void bubblesort  (USER users, int *ponto, char *nome, int tam){

    int i, pAux;
    char nAux;
    int troca;
    do{
        troca = 0;
        for(i=tam;i>0;i--) {

      /* Fazer o fp open do ficheiro
    fp=fopen("perguntas.dat","rb");
    if(fp==NULL){
        printf("Erro a abrir o ficheiro\n");
        return;
    }*/
if (ponto[i]>ponto[i-1]){
    pAux = pontos [i];
    strcpy(nAux, nome[i]);
    ponto[i]= ponto [i-1];
    strcpy(nome[i], nome [i-1]);
    ponto [i-1]=pAux;
    strcpy(nome[i-1],nAux);
    troca = 1;
         }
    }

 } while (troca);


}


void raking(){
    
    char nomes [100];
    int ponto, i;
    int tam = 50 //mostrar  a quatidade de jogadores



    printf("\n******* RAKING DE JOGADORES *******\n");
    printf("        \n");
    printf("NOME - PONTUAÇÃO");
    printf("        \n");

    FILE * pont_arq; //ponteiro para o arquivo
    pont_arquivo = fopen("ponto.txt", "r"); // ALTERAR O PONTO.TXT;

    while(fscanf(ponto/*arquivo do ponto*/, "%s -  %d\n", nome, &ponto)!=EOF){
        strcpy (nomes[tam], nome);
        pontuacoes[tam]=pontuacao;
        tam++;
    }
//ordenar 
bubblesort(ponto, nomes, tamanho);

//imprimir

for (i=0; i<tam;i++){
    printf(" %s - %d", nomes[i], ponto[i]);

}
fclose (ponto_arq)


}