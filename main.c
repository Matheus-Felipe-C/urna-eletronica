#include <stdio.h>

int main(void) {
  int total, votosRestantes, candidato;
  int votosMaeli = 0, votosIvan = 0, votosLinda = 0, votosJoao = 0;
  int votosBrancos = 0, votosNulos = 0, votosInvalidos;

  printf("Olá! por favor, digite o total de eleitores\n");
  scanf("%d", &total);

  votosRestantes = total;

  while (votosRestantes > 0) {
    printf("\nEscolha o seu candidato:\n");
    printf("n 10 - Sra Maeli Gente Boa\n");
    printf("n 47 - Sr Ivan do Brasil\n");
    printf("n 31 - Dra Linda Progresso\n");
    printf("n 38 - Seu João da Ana\n");
    printf("n 0 - Branco\n");

    scanf("%d", &candidato);

    switch(candidato) {
      case 0:
        votosBrancos += 1;
        votosInvalidos += 1;
        break;
      case 10:
        votosMaeli += 1;
        break;
      case 47:
        votosIvan += 1;
        break;
      case 31:
        votosLinda += 1;
        break;
      case 38:
        votosJoao += 1;
        break;
      default:
        votosNulos += 1;
        votosInvalidos += 1;
    }

    votosRestantes -= 1;
    printf("Votos restantes - %d\n\n", votosRestantes);
  }

  printf("Total de Eleitores - %d\n", total);
  printf("Votos em Maeli - %d\n", votosMaeli);
  printf("Votos em Ivan - %d\n", votosIvan);
  printf("Votos em Linda - %d\n", votosLinda);
  printf("Votos em Joao - %d\n", votosJoao);
  printf("Votos brancos/nulos - %d\n\n", votosInvalidos);
  return 0;
}