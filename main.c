#include <stdio.h>

int main(void) {
  int total, votosRestantes, candidato;
  int votosMaeli = 0, votosIvan = 0, votosLinda = 0, votosJoao = 0;
  int votosBrancos = 0, votosNulos = 0, votosInvalidos;
  int maiorVoto, menorVoto;
  float porcenMaeli, porcenIvan, porcenLinda, porcenJoao, porcenInvalidos;

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
    }

    votosRestantes -= 1;
    printf("Votos restantes - %d\n\n", votosRestantes);
  }

  votosInvalidos = votosBrancos + votosNulos;

  printf("Total de Eleitores - %d\n", total);
  printf("Votos em Maeli - %d\n", votosMaeli);
  printf("Votos em Ivan - %d\n", votosIvan);
  printf("Votos em Linda - %d\n", votosLinda);
  printf("Votos em Joao - %d\n", votosJoao);
  printf("Votos brancos - %d\n", votosBrancos);
  printf("Votos nulos - %d\n\n", votosNulos);

  /* 
    Verifica quem teve o maior número de votos e assigna um número para quem teve o maior quantidade de votos
    Maeli = 1; Ivan = 2; Linda = 3; Joao = 4
  */
  if (votosMaeli > votosIvan && votosMaeli > votosLinda && votosMaeli > votosJoao) {
    maiorVoto = 1;
  } else if (votosIvan > votosLinda && votosIvan > votosJoao) {
    maiorVoto = 2;
  } else if (votosLinda > votosJoao) {
    maiorVoto = 3;
  } else maiorVoto = 4;

  /* 
    Verifica quem teve o maior número de votos e assigna um número para quem teve o maior quantidade de votos
    Maeli = 1; Ivan = 2; Linda = 3; Joao = 4
  */
  if (votosMaeli < votosIvan && votosMaeli < votosLinda && votosMaeli < votosJoao) {
    menorVoto = 1;
  } else if (votosIvan < votosLinda && votosIvan < votosJoao) {
    menorVoto = 2;
  } else if (votosLinda < votosJoao) {
    menorVoto = 3;
  } else menorVoto = 4;

  printf("Maior voto - %d\nMenor voto - %d\n", maiorVoto, menorVoto);
  
  return 0;
}