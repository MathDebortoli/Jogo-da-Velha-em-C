///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// Para usar esse codigo tem que comentar o outro por completo e rodar
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

char **criarMtx(char **v) {
  int i;
  v = (char **)malloc(3 * sizeof(char *));
  for (i = 0; i < 3; i++) {
    v[i] = (char *)malloc(3 * sizeof(char));
  }
  return v;
}

void tabuleiro(char **casas2) {
  system("cls");
  printf("\n\tJOGO DA VELHA\n\n");
  printf("\t  | 1 | 2 | 3 |");
  printf("\n\t  -------------\n");
  printf("\t1 | %c | %c | %c |\n", casas2[0][0], casas2[0][1], casas2[0][2]);
  printf("\t  -------------\n");
  printf("\t2 | %c | %c | %c |\n", casas2[1][0], casas2[1][1], casas2[1][2]);
  printf("\t  -------------\n");
  printf("\t3 | %c | %c | %c |\n", casas2[2][0], casas2[2][1], casas2[2][2]);
  printf("\t  -------------\n\n");
}

int compararJogadas(char **casas, int cont) {
  int contJ = cont;
  // CONFERE AS LINHAS HORIZONTAIS DO x
  if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') {
    contJ = 12;
  } else if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') {
    contJ = 12;
  } else if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') {
    contJ = 12;
  }
  // COMFERE AS LINHAS VERTICAIS DO x
  if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') {
    contJ = 12;
  } else if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') {
    contJ = 12;
  } else if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') {
    contJ = 12;
  }
  // CONFERES AS DIAGONAIS DO x
  if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') {
    contJ = 12;
  } else if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X') {
    contJ = 12;
  }

  // CONFERE AS LINHAS HORIZONTAIS DO O
  if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') {
    contJ = 13;
  } else if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') {
    contJ = 13;
  } else if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') {
    contJ = 13;
  }
  // COMFERE AS LINHAS VERTICAIS DO O
  if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') {
    contJ = 13;
  } else if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') {
    contJ = 13;
  } else if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') {
    contJ = 13;
  }
  // CONFERES AS DIAGONAIS DO O
  if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') {
    contJ = 13;
  } else if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O') {
    contJ = 13;
  }

  return contJ;
}

int SeViranos30(char **matriz) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (matriz[i][j] == ' ') {
        matriz[i][j] = 'O';
        return 0;
      }
    }
  }
  return 0;
}


// Função que leia a vertical com base no local que foi jogado, não é necessário
// partir do ultimo ponto que foi jogado, apenas fazer uma leitura da linha ou
// coluna ou diagonal.

int LerVertical(char **Matriz, int coluna) {
  coluna = coluna - 1;
  int i, cont = 0, p_vitoria = 0;
  int marcador = -1;
  for (i = 0; i < 3; i++) {
    if (Matriz[i][coluna] == 'X')
      cont++;
    if (Matriz[i][coluna] == 'O')
      p_vitoria++;
    if (Matriz[i][coluna] == ' ')
      marcador = i;
  }

  if ((p_vitoria == 2) && (marcador != -1)) {
    Matriz[marcador][coluna] = 'O';
    return 1; // caso ele retorne 1, é pq o programa ganhou
  }

  else if ((cont == 2) && (marcador != -1)) {
    Matriz[marcador][coluna] = 'O';
    return 1; // retorna -1 pq ninguem ganhou ainda
  }
  return -1;
}

int LerHorizontal(char **Matriz, int linha) {
  linha = linha - 1;
  int i, cont = 0, p_vitoria = 0;
  int marcador = -1;
  for (i = 0; i < 3; i++) {
    if (Matriz[linha][i] == 'X') {
      cont++;
    } else if (Matriz[linha][i] == 'O')
      p_vitoria++;
    else if (Matriz[linha][i] == ' ')
      marcador = i;
  }

  if ((p_vitoria == 2) &&
      (marcador != -1)) { // Se houver 2 '0' e um espaço vazio, colocar o ultimo
                          // '0' para acabar o jogo
    Matriz[linha][marcador] = 'O';
    return 1; // retornou pq ganhou
  } else if ((cont == 2) &&
             (marcador !=
              -1)) { // Se houver 2 'X' e possuir um espaço vazio, colocar o '0'
    Matriz[linha][marcador] = 'O';
    return 1; // ninguem ganhou ainda
  }
  return -1;
}

int LerDiagonal(char **Matriz, int linha, int coluna) {
  linha = linha - 1;
  coluna = coluna - 1;
  int i = 0, j = 0;
  int cont = 0;
  int marcador_i = -1, marcador_j = -1, p_vitoria = 0;
  if ((linha == 0 && coluna == 0) ||
      (linha == 2 && coluna == 2)) { // Diagonal ESQUERDA \ <-desenho
    for (i = 0; i < 3; i++) {
      if (Matriz[i][j] == 'X')
        cont++;

      if (Matriz[i][j] == 'O')
        p_vitoria++;

      if (Matriz[i][j] == ' ') {
        marcador_i = i;
        marcador_j = j;
      }

      j++;
    }

    if ((marcador_i == -1) && (marcador_j == -1)) {
      SeViranos30(Matriz);
    } else if ((p_vitoria = 2) && (marcador_i != -1)) {
      Matriz[marcador_i][marcador_j] = 'O';
      return 1;
    } else if ((cont == 2) && (marcador_i != -1)) {
      Matriz[marcador_i][marcador_j] = 'O';
      return 1;
    }
    return -1;

  } else if (!((linha == 1 &&
                coluna == 1))) { // ENTÃO SÓ PODERÁ SER A DIAGONAL DIREITA / <-
                                 // Desenho da diagonal

    for (i = 2; i >= 0;
         i--) { // Agora o 'i' será decrementado, leitura de baixo para cima
      if (Matriz[i][j] == 'X')
        cont++;

      if (Matriz[i][j] == 'O')
        p_vitoria++;

      if (Matriz[i][j] == ' ') {
        marcador_i = i;
        marcador_j = j;
      }
      j++;
    }
    if ((marcador_i == -1) && (marcador_j == -1)) {
      Matriz[1][1] = 'O';
    } else if ((p_vitoria = 2) && (marcador_i != -1)) {
      Matriz[marcador_i][marcador_j] = 'O';
      return 1;
    }

    else if ((cont == 2) && (marcador_i != -1))
      Matriz[marcador_i][marcador_j] = 'O';
    return 1;
  }
  // caso seja o meio, ele executa as duas diagonais.
  else {
    for (i = 0; i < 3; i++) { // execução da primeira diagonal novamente
      if (Matriz[i][j] == 'X')
        cont++;

      if (Matriz[i][j] == 'O')
        p_vitoria++;

      if (Matriz[i][j] == ' ') {
        marcador_i = i;
        marcador_j = j;
      }

      j++;
    }


    } if ((p_vitoria = 2) && (marcador_i != -1)) {
        Matriz[marcador_i][marcador_j] = 'O';
        return 1;
    } else if ((cont == 2) && (marcador_i != -1)) {
        Matriz[marcador_i][marcador_j] = 'O';
        return 1;
    }
    for (i = 2; i >= 0; i--) { // execução da segunda diagonal novamente
      if (Matriz[i][j] == 'X')
        cont++;

      if (Matriz[i][j] == 'O')
        p_vitoria++;

      if (Matriz[i][j] == ' ') {
        marcador_i = i;
        marcador_j = j;
      }
      j++;
    }

     if ((p_vitoria = 2) && (marcador_i != -1)) {
        Matriz[marcador_i][marcador_j] = 'O';
        return 1;
    } else if ((cont == 2) && (marcador_i != -1)) {
        Matriz[marcador_i][marcador_j] = 'O';
        return 1;
    }
  
  return -1;
}

// --------------------------------------------------------------------------
void imprimirVencedor(int contJogadas) {
  if (contJogadas == 11) {
    printf("Velha\n\n");
  } else if (contJogadas == 12) {
    printf("Vencedor X!!!\n\n");
  } else if (contJogadas == 13) {
    printf("Vencedor O!!!\n\n");
  }
}

void fazerJogada(char **casas, int vez, int *p, int *q) {
  int l = 0, c;
  while (l == 0) {
    printf("\n\nJogador X : \n\n");
    printf("Digite a linha: ");
    scanf("%d", &l);
    printf("Digite a coluna: ");
    scanf("%d", &c);
    if (l < 1 || c < 1 || l > 3 || c > 3) {
      l = 0;
      c = 0;
    } else if (casas[l - 1][c - 1] != ' ') {
      printf("\nCasa Ocupada!\nJogue Novamente!\n");
      l = 0;
      c = 0;
    } else {
      *p = l;
      *q = c;
      if (vez % 2 == 0) {
        casas[l - 1][c - 1] = 'X';
      } else {
        casas[l - 1][c - 1] = 'O';
      }
    }
  }
}

int analisarPosicaoCantos(char **casas, int i, int j) {
  if ((i + 2 == 3) && (j + 2 == 3)){
    casas[1][1] = 'O';
    return 1;
  }
  else if ((i - 2 == 1) && (j + 2 == 3)){
    casas[1][1] = 'O';
    return 1;
  }
  else if ((i + 2 == 3) && (j - 2 == 1)){
    casas[1][1] = 'O';
    return 1;
  }
  else if ((i - 2 == 1) && (j - 2 == 1)){
    casas[1][1] = 'O';
    return 1;
  }
  return -1;
}

int analisarPosicaoCentro(char **casas, int i, int j) {
  if ((i == 2) && (j == 2)){
    casas[2][0] = 'O';
    return 2;
  }
  return -1;
}

int analisarPosicaoBorda(char **casas, int i, int j) {
  if ((i == 2) && (j == 1)){
    casas[1][1] = 'O';
    return 3;
  }
  else if ((i == 3) && (j == 2)){
    casas[1][1] = 'O';
    return 3;
  }  
  else if ((i == 2) && (j == 3)){
    casas[1][1] = 'O';
    return 3;
  }  
  else if ((i == 1) && (j == 2)){
    casas[1][1] = 'O';
    return 3;
  }
  return -1;
}

void segundaJogadaXCanto(char **casas, int i,
                         int j) { // O QUE FAZER SE O X COMEÇAR NO CANTO
  if ((casas[0][1] = ' '))
    casas[0][1] = 'O';
  else if ((casas[1][0] = ' '))
    casas[1][0] = 'O';
  else if ((casas[1][2] = ' '))
    casas[1][2] = 'O';
  else if ((casas[2][1] = ' '))
    casas[2][1] = 'O';
}

void segundaJogadaXCentro(char **casas, int i, int j) { // X COMEÇANDO NO CENTRO
  int v;
  v = LerVertical(casas, j);
  v = LerHorizontal(casas, i);
  v = LerDiagonal(casas, i, j);
  if(v==-1)
    SeViranos30(casas);
}

void segundaJogadaXBorda(char **casas, int i, int j) { // X COMEÇANDO NO CENTRO
  int v;
  v = LerVertical(casas, j);
  v = LerHorizontal(casas, i);
  v = LerDiagonal(casas, i, j);
  if(v==-1)
    SeViranos30(casas);
}

void jogar(char **casas) {
  char res;
  int contJogadas;
  int l, c, b;
  int vez = 0;
  int i, j;
  int v = -1;

  do {
    contJogadas = 1;
    for (i = 0; i <= 2; i++) {
      for (j = 0; j <= 2; j++) {
        casas[i][j] = ' ';
      }
    }
    do {
      tabuleiro(casas);
      if (vez % 2 == 0) {
        fazerJogada(casas, vez, &l, &c);
        vez++;
        contJogadas++;
      } else {
          printf("Jogador O : \n\n");
          if (vez == 1) {
            b = analisarPosicaoCantos(casas, l, c);
          if (b == -1)
            b = analisarPosicaoCentro(casas, l, c);
          if (b == -1)
            b = analisarPosicaoBorda(casas, l, c);
        }
        else if (vez == 3) {
            if (b==1)
              segundaJogadaXCanto(casas, i, j);
            if (b==3)
              segundaJogadaXBorda(casas, i, j);
            if (b==2)
              segundaJogadaXCentro(casas, i, j);
        } 
        else {
          if (v == -1)
            v = LerHorizontal(casas, l);
          if (v == -1)
            v = LerVertical(casas, c);
          if (v == -1)
            v = LerDiagonal(casas, l, c);
          if(v==-1){
            SeViranos30(casas);
          }
        }
        v = -1;
        vez++;
        contJogadas++;
        system("pause");
      }
      contJogadas = compararJogadas(casas, contJogadas);
    } while (contJogadas <= 9);
    tabuleiro(casas);
    imprimirVencedor(contJogadas);

    // printf("Deseja Jogar novamente [S-N]\n");
    // scanf("%s", &res);
    res = 'n';
  } while (res == 's');
}

int main() {

  char **casas = criarMtx(casas);
  char j;

  printf("\nJOGO DA VELHA\n");
  printf("Deseja jogar [S - N]:");
  scanf("%c", &j);

  if ((j == 's') || (j == 'S')) {
    jogar(casas);
  }

  /*Seria interessante divir em 2 partes, jogada do computador e jogada do
    Giovas porque é possível o computador ganhar do player,
    se não o computador poderá entrar em um loop que tentar trancar o usuário e
    é possível surgir uma nova 'trava' que seria igual aos casos especiais de
    inicio*/
}
