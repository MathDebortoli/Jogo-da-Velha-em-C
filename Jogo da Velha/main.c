// #include <stdio.h>
// #include <stdlib.h>

// /* ANOTAÇÕES GERAIS 

//   Leitura por locais. Cantos, meios e meio possuem leituras diferentes; 

// */

// // ----------------- ALOCANDO MATRIZ DE INT DINAMICAMENTE ------
// int ** criarMtx(int ** v){
//   int i;
//   v = (int**)malloc(3 * sizeof(int*));
//   for(i=0;i<3;i++){
//     v[i] = (int*)malloc(3 * sizeof(int));
//    }
//   return v;
// }

// //---------------- PREENCHENCO MATRIZ COM '0'--------
// int ** preencherMtx(int ** v){
//   int i,j;
//   for(i=0;i<3;i++){
//     for(j=0;j<3;j++){
//       v[i][j] = 0;
//     }
//   }
//   return v;
// }

// // ----------- EXIBIR TABULEIRO -----------------
// void printarTabuleiro(int **v){
//   int i,j;
//    for(j=0;j<3;j++){
//       printf("----");
//   }
//   printf("\n");
//   for(i=0;i<3;i++){
//     for(j=0;j<3;j++){
//       printf("| %d ",v[i][j]);
//     }
//     printf("|\n");
//     for(j=0;j<3;j++){
//       printf("----");
//     }
//     printf("\n");
//   }
// }
// // ---------------------------------------------

// int lerVitoria(int **v){ // VERIFICA SE HÁ UMA SEQUÊNCIA DE 3 '1'
//   int i,j;
  
//   // LINHAS 
//   for(i=0;i<3;i++){
//     if(((v[i][0]==1) && (v[i][1]==1) && (v[i][2]==1)))
//       return 1;
//   }

//   // COLUNAS
//   for(j=0;j<3;j++){
//     if(((v[0][j]==1) && (v[1][j]==1) && (v[2][j]==1)))
//       return 1;
//   }  
  
//   // DIAGONAIS 
//   if(((v[0][0]==1) && (v[1][1]==1) && (v[2][2]==1)))
//     return 1;

//   if(((v[2][0]==1) && (v[1][1]==1) && (v[0][2]==1)))
//     return 1;
  
//   return 0;
// }

// void lerJogada(int ** v, int *val1, int *val2){
//   int i,j;
//   printf("\nDigite a Linha: ");
//   scanf("%d",&i);
//   printf("Digite a Coluna: ");
//   scanf("%d",&j);

//   *val1 = i; 
//   *val2 = j;

//   v[i][j]=1; //PREENCHE A POSICAO ESCOLHIDA COM 1
// }

// //void verificarDiagonais(int **M){}


// // ------------------ PROGRAMA PRINCIPAL ----------

// int main(void) {
  
//   int i, j,vitoria=0;
//   int ** tabuleiro;
//   tabuleiro = criarMtx(tabuleiro);
//   tabuleiro = preencherMtx(tabuleiro);


//   printf("\n\nJOGO DA VELHA\n\n");

//   while(vitoria==0){ //COMECA UM LOOPING ATE GANHAR
//     lerJogada(tabuleiro, &i, &j);// Passando como referencia a localização, ultimo local marcado pelo jogador; 


    
// // ---------- CONDIÇÕES DE MAPEAMENTO ----------
//   int local; 
//   // Variavel para guardar o local que será analisado 
//   // local = 1 (CANTO)
//   // local = 2 (BORDA)
//   // local = 3 (MEIOZINHO)
    
//     // JOGADA NO EXTREMO
//     if ( ( i == 0 || i == 2 ) && (j == 0 || j== 2)
//     {
//       local = 1;
//     }  
//     else if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 2) || (i == 2 && j == 1) ) 
//     {
//       local = 2;
          
    
//     }else { 
      
//       local = 3;
//     }
// // Neste momento ja sabemos qual é a localização do Gioavanni e iremos percorrer a tabuleiro com base na sua localização
    
//     vitoria = lerVitoria(tabuleiro);
//   }
  
//   printarTabuleiro(tabuleiro);
//   printf("ganhou: %d\n",vitoria);

//   // system("cls");

//   return 0;
// }

