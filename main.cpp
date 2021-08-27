// Forca em C++.
// Feito por: Jessé Júnior.

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define TAM_ALF 26

void imprimeForca(int tracos) {

    cout << "Gilhotina: " << endl;
    switch (tracos) {
    case 0:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        break;
    case 1:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    O   " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        break;
    case 2:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    0   " << endl;
        cout << "    |   " << endl;
        cout << "    |   " << endl;
        cout << "        " << endl;
        break;
    case 3:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    O   " << endl;
        cout << "    |/  " << endl;
        cout << "    |   " << endl;
        cout << "        " << endl;
        break;
    case 4:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    O   " << endl;
        cout << "   \\|/ " << endl;
        cout << "    |   " << endl;
        cout << "        " << endl;
        break;
    case 5:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    O   " << endl;
        cout << "   \\|/ " << endl;
        cout << "    |   " << endl;
        cout << "     \\ " << endl;
        break;
    case 6:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "    O   " << endl;
        cout << "   \\|/ " << endl;
        cout << "    |   " << endl;
        cout << "   / \\ " << endl;
        break;
    default:
        cout << "|----   " << endl;
        cout << "    |   " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
        cout << "        " << endl;
    }
}

int main() {

    // Inicialização das variáveis
    int tracos = 0, acertos = 0, tamanho, quant, restantes;
    bool contem = false, troca = false;
    string gabarito, letra, sorteio;

    // Seleciona aleatóriamente uma palavra do arquivo .txt
    srand(time(NULL));
    quant = rand() % 40000;
    ifstream arquivo("aurelio40000.txt");
    for (int i = 0; i < quant; i++) {
        getline(arquivo, sorteio);
        gabarito = sorteio;
    }

    // Inicializa a string a ser acertada, além do alfabeto
    tamanho = gabarito.length();
    string palavra(tamanho, '_');
    string alfabeto(25, '_');
    restantes = tamanho;

    // Trata as ocasiões de palavras com hífen "-"
    for (int i = 0; i < tamanho; i++)
        if (gabarito[i] == '-') {
            palavra[i] = gabarito[i];
            restantes--;
        }

    // Loop principal do jogo
    while ((tracos < 7) && (acertos != restantes)) {
        // Variável para avaliar a letra selecionada
        contem = false;

        // Impressão da palavra e da quantidade de letras faltando
        cout << "Palavra: ";
        for (int i = 0; i < tamanho; i++)
            cout << palavra[i];
        cout << " " << acertos << "/" << restantes << "\n\n";

        // Impressão do alfabeto para consulta de letras sobrando
        cout << "Alfabeto: ";
        for (int i = 0; i < TAM_ALF; i++)
            cout << alfabeto[i];
        cout << "\n\n";

        // Chama a função para a impressão do desenho da forca
        imprimeForca(tracos);

        cout << "---------------------------" << endl;

        do {
            cout << "Escolha uma letra: ";
            cin >> letra;

            // Caso o usuário insira mais de duas letras, um caractere inválido ou uma letra já escolhida, insira novamente
            if (letra.length() != 1) {
                cout << "Insira apenas 1 letra! ";
                troca = true;
            } else if ((letra[0] < 97) || ((letra[0] > 122))) {
                cout << "Insira uma letra valida! ";
                troca = true;
            } else {
                troca = false;
            }

            for (int i = 0; i < TAM_ALF; i++) {
                if (letra[0] == alfabeto[i]) {
                    cout << "Letra ja escolhida! ";
                    troca = true;
                }
            }

        } while (troca);

        // Faz com que haja o preenchimento da string responsável pelo alfabeto, selecionando cada letra de acordo com o seu código ASCII
        alfabeto[letra[0] - 97] = letra[0];

        // Verifica se há ou não determinada letra na palavra
        for (int i = 0; i < tamanho; i++) {
            if (letra[0] == gabarito[i]) {
                palavra[i] = gabarito[i];
                acertos++;
                contem = true;
            }
        }

        // Caso não contenha a letra selecionada incrementa a variável tracos
        if (!contem)
            tracos++;
    }

    // Define se o jogador ganhou ou perdeu a partida, informando também qual foi a palavra a ser acertada
    if (acertos == restantes) {
        cout << "\n\nParabens, voce ganhou!!!\n\n";
        cout << "A palavra correta e: " << gabarito << "\n\n";
    } else {
        cout << "\n\nQue pena, voce perdeu!!!\n\n";
        cout << "A palavra correta era: " << gabarito << "\n\n";
    }

    system("pause");

    return 0;
}