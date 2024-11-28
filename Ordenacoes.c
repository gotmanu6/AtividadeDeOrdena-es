#include <stdio.h>
#include <stdlib.h>

// Variável global que registra o número de trocas realizadas em cada algoritmo
int trocas = 0;

// Função para exibir os elementos do vetor
void exibirVetor(int vetor[], int tamanho) {
  printf("Vetor: ");
  for (int i = 0; i < tamanho; i++) { // Percorre todos os elementos do vetor
    printf("%d ", vetor[i]); // Imprime cada elemento seguido de um espaço
  }
  printf("\n"); // Quebra de linha após exibir o vetor
}

// Função de ordenação Selection Sort
void selectionSort(int vetor[], int tamanho) {
  trocas = 0; // Inicializa o contador de trocas como 0

  // Itera pelo vetor até o penúltimo elemento
  for (int i = 0; i < tamanho - 1; i++) {
    int indiceMenor = i; // Assume que o menor elemento está na posição atual

    // Busca o menor elemento no subvetor restante
    for (int j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[indiceMenor]) { // Se encontrar um elemento menor
        indiceMenor = j; // Atualiza o índice do menor elemento
      }
    }

    // Troca o menor elemento encontrado com o elemento atual
    if (indiceMenor != i) { 
      int temp = vetor[i];
      vetor[i] = vetor[indiceMenor];
      vetor[indiceMenor] = temp;
      trocas++; // Incrementa o contador de trocas
    }
  }
}

// Função de ordenação Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
  trocas = 0; // Inicializa o contador de trocas como 0

  // Percorre o vetor várias vezes
  for (int i = 0; i < tamanho - 1; i++) {
    // Compara pares de elementos adjacentes
    for (int j = 0; j < tamanho - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) { // Se estiverem fora de ordem
        int temp = vetor[j]; // Troca os elementos
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
        trocas++; // Incrementa o contador de trocas
      }
    }
  }
}

// Função de ordenação Insertion Sort
void insertionSort(int vetor[], int tamanho) {
  trocas = 0; // Inicializa o contador de trocas como 0

  // Começa do segundo elemento e insere no lugar correto
  for (int i = 1; i < tamanho; i++) {
    int chave = vetor[i]; // Elemento atual a ser inserido
    int j = i - 1;

    // Move os elementos maiores que a chave para frente
    while (j >= 0 && vetor[j] > chave) {
      vetor[j + 1] = vetor[j];
      j = j - 1;
      trocas++; // Conta cada movimento como uma troca
    }
    vetor[j + 1] = chave; // Insere a chave na posição correta
  }
}

// Função auxiliar para trocar dois elementos
void troca(int *a, int *b) {
  int temp = *a; // Armazena temporariamente o valor de a
  *a = *b;       // Coloca o valor de b em a
  *b = temp;     // Coloca o valor armazenado em b
}

// Função principal
int main() {
  int opcao, tamanho; // Variáveis para opção do menu e tamanho do vetor
  int *vetor; // Ponteiro para armazenar dinamicamente o vetor

  do {
    // Exibe o menu de opções
    printf("\nOpções:\n");
    printf("1 - Inserir lista\n");
    printf("2 - Selection Sort\n");
    printf("3 - Bubble Sort\n");
    printf("4 - Insertion Sort\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao); // Lê a escolha do usuário

    switch (opcao) {
    case 1: // Caso para inserir uma nova lista
      printf("Digite o tamanho do vetor: ");
      scanf("%d", &tamanho); // Lê o tamanho do vetor
      vetor = (int *)malloc(tamanho * sizeof(int)); // Aloca memória para o vetor

      printf("Digite os elementos do vetor:\n");
      for (int i = 0; i < tamanho; i++) { // Lê os elementos do vetor
        scanf("%d", &vetor[i]);
      }

      exibirVetor(vetor, tamanho); // Exibe o vetor inserido
      break;

    case 2: // Ordenação por Selection Sort
      selectionSort(vetor, tamanho); // Chama a função de ordenação
      exibirVetor(vetor, tamanho); // Exibe o vetor ordenado
      printf("Trocas realizadas: %d\n", trocas); // Exibe o número de trocas realizadas
      break;

    case 3: // Ordenação por Bubble Sort
      bubbleSort(vetor, tamanho); // Chama a função de ordenação
      exibirVetor(vetor, tamanho); // Exibe o vetor ordenado
      printf("Trocas realizadas: %d\n", trocas); // Exibe o número de trocas realizadas
      break;

    case 4: // Ordenação por Insertion Sort
      insertionSort(vetor, tamanho); // Chama a função de ordenação
      exibirVetor(vetor, tamanho); // Exibe o vetor ordenado
      printf("Trocas realizadas: %d\n", trocas); // Exibe o número de trocas realizadas
      break;

    case 0: // Caso de saída
      free(vetor); // Libera a memória alocada para o vetor
      printf("Programa encerrado.\n"); // Mensagem de encerramento
      break;

    default: // Caso de entrada inválida
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (opcao != 0); // Continua até que o usuário escolha sair

  return 0; // Retorna 0 indicando que o programa terminou corretamente
}