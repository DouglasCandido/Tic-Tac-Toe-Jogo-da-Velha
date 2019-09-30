// Universidade Federal do Rio Grande do Norte (UFRN)
// Aluno: Douglas Mateus Soares Cândido da Silva.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

char tela[3][3];

int i, j, x, y, pl, teste = 1;

void testar(int pl);
void play1(void);
void gerar_numero_aleatorio_preencher_coordenada(int lower, int upper, int *ponteiro);
void play2(void); 
void exibir(void);

int main(void) {

   char auxiliar;

   system("clear");
   printf("\nBem vindo ao Jogo da Velha!\n");
   printf("           ____  \n");
   printf("         /((   ))\n");
   printf("        ( )6  6( )\n");
   printf("        (_)  l (_)\n");
   printf("          \\ <> )\n");
   printf("      _____)  (_____\n");
   printf("     (  \\       /   )\n");
   printf("     )  , \\ | /  `  (\n");
   printf("    / /(    Y     )\\ \\\n");
   printf("   / /   `     ,'   \\ \\\n");
   printf("   \\ \\    )===(    / /\n");
   printf("    \\ \\  ,     `  / /\n");
   printf("     '\\\\/        \\//'\n");
   printf("      '|\\`      '|\\`\n");
   printf("         \\      /\n");
   printf("          \\    /\n");
   printf("          )    (\n");
   printf("         /      \\\n");
   printf("        /        \\ \n");
   printf("       /          \\\n");
   printf("      /            \\ \n");
   printf("     /              \\\n");
   printf("    /                \\ \n");
   printf("    `-....,      ,..-'\n");
   printf("           `-..-'\n");
   printf("\n Made by Douglas in 2019.\n");
   printf("\n * Regras:\n");
   printf(" - O Humano precisará digitar as coordenadas referente ao tabuleiro 3x3. O Computador escolherá aleatoriamente as coordenadas.\n");    
   printf(" - O vencedor será aquele que preencher uma linha horizontal, vertical ou diagonal.\n");
   printf(" - O Jogador 1 é o Humano e o Jogador 2 é o Computador.\n");
   printf("\n Pressione qualquer tecla para continuar: ");
   scanf(" %c", &auxiliar);


   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
         tela[i][j] = ' ';
      
   while(teste != 0) {      

      if(teste != 0) {
         
         play1();
         
         while(tela[x][y] != ' ') {
            system("clear");
            printf("\nEssa posição já está sendo utilizada.\n"); 
            printf("\nPressione qualquer tecla para digitar uma nova coordenada: ");
            scanf(" %c", &auxiliar);
            play1(); 
         }

         if(tela[x][y] == ' ') {
            tela[x][y] = 'X';
            testar(pl); 
         }
      
      }

      if(teste != 0) { 

         play2();
         
         while(tela[x][y] != ' ') {
            play2(); 
         }

         if(tela[x][y] == ' ') {
            tela[x][y] = 'O';
            testar(pl);   
         }
      
      }

   }

}

void testar(int pl) {
  
   if(x == 0)
   if((tela[0][0] == tela[0][1]) && (tela[0][1] == tela[0][2])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }
   
   if(x == 1)
   if((tela[1][0] == tela[1][1]) && (tela[1][1] == tela[1][2])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }

   if(x == 2)
   if((tela[2][0] == tela[2][1]) && (tela[2][1] == tela[2][2])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }
   
   if(y == 0)
   if((tela[0][0] == tela[1][0]) && (tela[1][0] == tela[2][0])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }
   
   if(y == 1)
   if((tela[0][1] == tela[1][1]) && (tela[1][1] == tela[2][1])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }

   if(y == 2)
   if((tela[0][2] == tela[1][2]) && (tela[1][2] == tela[2][2])) {
      exibir();
      printf("\nJogador **%i** ganhou!\n", pl);
      teste = 0;
   }
   
   if(((x == 0) && (y == 0)) || ((x == 1) && (y == 1)) || ((x == 2) && (y == 2))) {
      if((tela[0][0] == tela[1][1]) && (tela[0][0] == tela[2][2])) {
         exibir();
         printf("\nJogador **%i** ganhou!\n", pl);
         teste = 0;
      }
   }
   
   if(((x == 0) && (y == 2)) || ((x == 1) && (y == 1)) || ((x == 2) && (y == 0))) {
      if((tela[0][2] == tela[1][1]) && (tela[0][2] == tela[2][0])) {
         exibir();
         printf("\nJogador **%i** ganhou!\n", pl);
         teste = 0;
      }
   }

}

void play1(void) {
   exibir();
   printf("\nJogador 1: Digite a coordenada **X**: ");
   scanf("%i", &x);
   printf("\nJogador 1: Digite a coordenada **Y**: ");
   scanf("%i", &y);
   pl = 1;
   x--;
   y--;
}

void gerar_numero_aleatorio_preencher_coordenada(int lower, int upper, int *ponteiro) {
   int i; 
   int n = (rand() % (upper - lower + 1)) + lower; 
   *ponteiro = n;
}

void play2(void) {
   int lower = 1, upper = 3;
   srand(time(0)); 
   exibir();      
   gerar_numero_aleatorio_preencher_coordenada(lower, upper, &x);
   gerar_numero_aleatorio_preencher_coordenada(lower, upper, &y);
   pl = 2;
   x--;
   y--;
}

void exibir(void) {
   system("clear");
   printf("   1   2   3  (Y)\n");
   printf(" 1 %c | %c | %c \n", tela[0][0], tela[0][1], tela[0][2]);
   printf("  ---|---|--- \n ");
   printf("2 %c | %c | %c \n", tela[1][0], tela[1][1], tela[1][2]);
   printf("  ---|---|--- \n ");
   printf("3 %c | %c | %c \n", tela[2][0], tela[2][1], tela[2][2]);
   printf("(X)\n");
}
