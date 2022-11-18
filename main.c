#include <stdio.h>
#include <string.h>

int main(void) {
  //Variáveis de uso geral
  int total, votosRestantes, candidato, flag;
  char vencedor[20];
  //Variáveis contendo os votos
  int votosMaeli = 0, votosIvan = 0, votosLinda = 0, votosJoao = 0;
  int votosBrancos = 0, votosNulos = 0, votosInvalidos, votosValidos;
  int maiorVoto, menorVoto;
  //Variáveis contendo as porcentagens
  float porcenMaeli, porcenIvan, porcenLinda, porcenJoao, porcenInvalidos;
  float porcenHomem, porcenMulher;

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

  votosValidos = votosMaeli + votosIvan + votosLinda + votosJoao;
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

  //Calcula as porcentagens de votos
  //TO-DO - Verificar se quantidade de votos válidos é maior que 0
  // Senão o código vai dar um problemão

  //O (float) é para forçar que o resultado seja decimal, pois no C, divisão de números inteiros sempre dará um inteiro

  porcenMaeli = (float) 100 * votosMaeli / votosValidos;
  porcenIvan = (float) 100 * votosIvan / votosValidos;
  porcenLinda = (float) 100 * votosLinda / votosValidos;
  porcenJoao = (float) 100 * votosJoao / votosValidos;
  porcenInvalidos = (float) 100 * votosInvalidos / votosValidos;
  porcenHomem = (float) 100 * votosIvan + votosJoao / votosValidos;
  porcenMulher = (float) 100 * votosMaeli + votosLinda / votosValidos;

  //O %.2f imprime apenas as duas primeiras casas decimais de números decimais
  printf("%% Maeli - %.2f\n", porcenMaeli);
  printf("%% Ivan - %.2f\n", porcenIvan);
  printf("%% Linda - %.2f\n", porcenLinda);
  printf("%% Ivan - %.2f\n", porcenJoao);
  printf("%% Inválidos - %.2f\n", porcenInvalidos);

  //Verifica se há ganhador no primeiro turno
  //strcpy = string copy, é uma função pronta da biblioteca string.h, que
  // copia uma string (segundo parâmetro) em outra variável (primeiro parametro)
  if (porcenMaeli > 50) strcpy(vencedor, "Sra Maeli Gente Boa");
  else if (porcenIvan > 50) strcpy(vencedor, "Sr Ivan do Brasil");
  else if (porcenLinda > 50) strcpy(vencedor, "Dra Linda Progresso");
  else if (porcenJoao > 50) strcpy(vencedor, "Seu João da Ana");

  //Verifica quem vai pro segundo turno

  if (strlen(vencedor) > 0) printf("Vencedor - %s", vencedor);
  else printf("Haverá segundo turno!");

  return 0;
}