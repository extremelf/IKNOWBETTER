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



