// Autores: RAFAEL SCHMIDT, VINICIUS GERMANN, BRUNO SCHMIDT E JÕAO. V DE PAULA.
// TRABALHO SUDOKU - ALGORITMOS 1

#include <cstdlib>
#include <ctime> // para utilizar a função de números aleatórios
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;
#define TAM 9

int main() {
  int inicio, escolhademat;    // variavel do switch para "jogar", e variavel para o sorteio da Matriz.
  int linha, coluna, valor, tentativa = 0;
  bool FIM = true;
  int contador = 0, Mjogo[TAM][TAM] = {};
  int Mtemporario[TAM][TAM] = {},
      mat[TAM][TAM] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
      };

  int Mgabarito[TAM][TAM] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9},
      };





  do {
    srand(time(NULL));
    escolhademat = rand() % 4 + 1;

    cout << "================" << endl
         << "SUDOKU" << endl
         << "================" << endl;

    cout << endl << "1: Jogar.\n2: Sobre.\n3: Sair.\n"; // menu do jogo
    cout << endl << "(Digite a opção): ";
    cin >> inicio;

    switch (inicio) { // usado para fazer o sistema de escolha
    case 1:           // primeira escolha: jogar
      cout << "\nESSA É A SUA MATRIZ PRINCIPAL!\n" << endl;

      cout << "\nOperação: " << escolhademat << endl;
      int aux;

      if (escolhademat == 1) {
        system("cls");

        for (int i = 0; i < TAM; i++) {          // MATRIZ SEM MODIFICAÇÃO
          for (int j = 0; j < TAM; j++) {
            Mtemporario[i][j] = Mgabarito[i][j];
          }
        }
      }

      if (escolhademat == 2) {
        system("cls");

        for (int i = 0; i < TAM; i++) {
          for (int j = i + 1; j < TAM; j++) {         // OPERAÇÃO MATRIZ TRANSPOSTA
            aux = Mgabarito[i][j];
            Mgabarito[i][j] = Mgabarito[j][i];
            Mgabarito[j][i] = aux;
          }
        }
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            Mtemporario[i][j] = Mgabarito[i][j];
          }
        }
      }

      if (escolhademat == 3) {
        system("cls");

        for (int i = 0; i < TAM / 2; i++) {
          for (int j = 0; j < TAM; j++) {              // OPERAÇÃO COM LINHA INVERTIDA
            aux = Mgabarito[i][j];
            Mgabarito[i][j] = Mgabarito[TAM - i - 1][j];
            Mgabarito[TAM - i - 1][j] = aux;
          }
        }
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            Mtemporario[i][j] = Mgabarito[i][j];
          }
        }
      }

      if (escolhademat == 4) {
        system("cls");

        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM / 2; j++) {           // OPERAÇÃO MATRIZ COM COLUNA INVERTIDA
            aux = Mgabarito[i][j];
            Mgabarito[i][j] = Mgabarito[i][TAM - j - 1];
            Mgabarito[i][TAM - j - 1] = aux;
          }
        }
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            Mtemporario[i][j] = Mgabarito[i][j];
          }
        }
      }

      while (contador <= 79) {
        int i = rand() % TAM;
        int j = rand() % TAM;
        if (Mtemporario[i][j] != 0) {     //Estrutura para jogar 41 numeros random da matriz randomizada para a matriz jogo.
          Mjogo[i][j] = Mtemporario[i][j];
          Mtemporario[i][j] = 0;
          contador++;
        }
      }

      cout << "\n";
      for (int i = 0; i < TAM; i++) {     // Imprimir linha horizontal
        if (i % 3 == 0 && i != 0) {
          cout << "---------------------" << endl;
        }
        for (int j = 0; j < TAM; j++) {   // Imprimir linha vertical
          if (j % 3 == 0 && j != 0) {
            cout << "| ";
          }
          cout << Mjogo[i][j] << " ";
        }
        cout << endl;
      }

      do {                          //ESTRUTURA "DO WHILE" PARA O INICIO DO JOGO EM SI.
        cout << endl;
        cout << "Digite a linha (0-8): ";
        cin >> linha;
        cout << "Digite a coluna (0-8): ";
        cin >> coluna;
        cout << "Digite o valor (1-9): ";
        cin >> valor;
        cout << endl;

        if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {       // IF PARA O JOGADOR COLOCAR O VALOR CORRETO DAS COORDENADAS.
          if (Mjogo[linha][coluna] == 0) {                                 // IF PRA QUE ELES SOMENTE PREENCHAM AS POSIÇOES "VAZIAS".
            if (valor != Mgabarito[linha][coluna]) {                          // IF PARA AVALIAR O VALOR PREENCHIDO, E VERIFICAR SE É VERDADEIRO OU NÃO.
              tentativa++;
              cout << "O Valor está INCORRETO! Tente outra vez." << endl;

            } else {
              tentativa++;
              cout << "O Valor está CORRETO!\nAperte Enter para verificar e continuar." << endl;
              Mjogo[linha][coluna] = valor;

            }
            system("pause");
          } else {
            cout << "Essa coordenada já foi preenchida. Tente outra vez." << endl;
            system("pause");
          }
        } else {
          cout << "As coordenadas são inválidas. Tente outra vez." << endl;
          system("pause");
        }

        system("cls");

        // Imprimir a matriz atualizada
        for (int i = 0; i < TAM; i++) {
          if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
          }
          for (int j = 0; j < TAM; j++) {
            if (j % 3 == 0 && j != 0) {
              cout << "| ";
            }
            cout << Mjogo[i][j] << " ";
          }
          cout << endl;
        }

        cout << "TENTATIVAS: " << tentativa << endl;


        FIM = true;
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            if (Mjogo[i][j] == 0) {            //ESTRUTURA PARA O TERMINO DO JOGO (DO WHILE)
              FIM = false;                     // ENQUANTO FIM = FALSE, O JOGO CONTINUA
              break;
            }
          }

        }

      } while (FIM == false);
        system("cls");
        cout << "PARABÉNS, VOCÊ CONSEGUIU COMPLETAR A MATRIZ EM " << tentativa << " jogadas!\n" << endl;

        // Imprimir a matriz final
        for (int i = 0; i < TAM; i++) {
            if (i % 3 == 0 && i != 0) {
              cout << "---------------------" << endl;
            }
            for (int j = 0; j < TAM; j++) {
              if (j % 3 == 0 && j != 0) {
                cout << "| ";
              }
              cout << Mgabarito[i][j] << " ";
            }
            cout << endl;
          }
            system("pause");
           system("cls");

      for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            Mgabarito[i][j] = 0;
          }
        }
      for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            Mtemporario[i][j] = 0;
          }
        }

      break;

    case 2:            // segunda escolha: sobre
      system("cls"); // deixa só as informações essenciais
      cout << endl
           << "Trabalho 3(SUDOKU) Algoritmos e Programação.\n\n Feito por: "
              "Vinicius Germann\n\n João V. de Paula\n\n Bruno Schmidt Dal "
              "Paz\n\n Rafael Schmidt Dal Paz\n\n Data: 07/06/2023.\n\n "
              "Professor: Rafael Ballottin Martins\n";
      cout << "\nDigite qualquer tecla para voltar ao menu.\n\n"; // Pede um
                                                                  // comando
                                                                  // para voltar
     system("pause"); // pausa e reinicia o comando
      system("cls");      // deixa só as informações essencias
      break;                // quebra de linha para a próxima escolha

    case 3: // terceira escolha: sair
      system("cls");
      cout << "Você saiu do jogo." << endl;

      break; // quebra de linha para a proxima escolha

      // condicao caso nao seja antendida nenhuma das anteriores
      system("cls"); // deixa só as informações essencias
      cout << "\nOpção inválida.\n";
    }

  } while (inicio != 3); // Enquanto a opção escolhida não for 3
  return 0;
}
