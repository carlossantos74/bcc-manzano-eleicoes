#include <stdio.h>

/**
Em uma eleição sindical concorreram ao cargo de presidente três candidatos (representados
pelas variáveis A, B e C). Durante a apuração dos votos foram computados votos nulos e em
branco, além dos votos válidos para cada candidato. Deve ser criado um programa de compu-
tador que faça a leitura da quantidade de votos válidos para cada candidato, além de também ler
a quantidade de votos nulos e em branco.
Ao final o programa deve apresentar o número total de eleitores, considerando votos válidos, nulos e em branco;
o percentual correspondente de votos válidos em relação à quantidade de eleitores; ok
o percentual correspondente de votos válidos do candidato A em relação à quantidade de eleitores; ok
o percentual correspondente de votos válidos do candidato B em relação à quantidade de eleitores; ok
o percentual correspondente de votos válidos do candidato C em relação à quantidade de eleitores; ok
o percentual correspondente de votos nulos em relação à quantidade de eleitores ok;
e por último o percentual correspondente de votos em branco em relação à quantidade de eleitores. ok
*/

struct Candidato
{
  char nome[10];

  int votos;
  float percentual_votos;
} typedef TCanditato;

struct Eleicao
{
  TCanditato candidatos[3];

  int votos_nulos;
  int votos_brancos;

  int quantidade_eleitores;
  int quantidade_votos_validos;
  int quantidade_votos_invalidos;

  float percentual_votos_validos;
  float percentual_votos_invalidos;
  float percentual_votos_nulos;
  float percentual_votos_brancos;
} typedef TEleicao;

float getPercentual(int total, int valor)
{
  return valor * 100 / total;
}

void main()
{
  TEleicao eleicao;
  eleicao.quantidade_eleitores = 0;
  eleicao.quantidade_votos_invalidos = 0;
  eleicao.quantidade_votos_validos = 0;

  for (int i = 0; i < 3; i++)
  {
    printf("\n Nome do candidato: ");
    scanf("%s", &eleicao.candidatos[i].nome);
    printf("\n Quantidade de votos: ");
    scanf("%d", &eleicao.candidatos[i].votos);

    eleicao.quantidade_eleitores += eleicao.candidatos[i].votos;
    eleicao.quantidade_votos_validos += eleicao.candidatos[i].votos;
  }

  printf("\n Quantidade de votos nulos: ");
  scanf("%d", &eleicao.votos_nulos);
  eleicao.quantidade_eleitores += eleicao.votos_nulos;
  eleicao.quantidade_votos_invalidos += eleicao.votos_nulos;

  printf("\n Quantidade de votos brancos: ");
  scanf("%d", &eleicao.votos_brancos);
  eleicao.quantidade_eleitores += eleicao.votos_brancos;
  eleicao.quantidade_votos_invalidos += eleicao.votos_brancos;

  eleicao.percentual_votos_nulos = getPercentual(eleicao.quantidade_eleitores, eleicao.votos_nulos);
  eleicao.percentual_votos_brancos = getPercentual(eleicao.quantidade_eleitores, eleicao.votos_brancos);
  eleicao.percentual_votos_validos = getPercentual(eleicao.quantidade_eleitores, eleicao.quantidade_votos_validos);
  eleicao.percentual_votos_invalidos = getPercentual(eleicao.quantidade_eleitores, eleicao.quantidade_votos_invalidos);

  for (int i = 0; i < 3; i++)
  {
    int total_votos = eleicao.quantidade_eleitores;
    int votos = eleicao.candidatos[i].votos;

    eleicao.candidatos[i].percentual_votos = getPercentual(total_votos, votos);
  }

  printf("\n ------------------------------------------------------------ \n");
  for (int i = 0; i < 3; i++)
  {
    TCanditato candidato = eleicao.candidatos[i];

    printf("Nome: %s, Votos: %d, Percentual Votos: %f \n", candidato.nome, candidato.votos, candidato.percentual_votos);
  }

  printf("Quantidade eleitores: %d \n", eleicao.quantidade_eleitores);

  printf("Quantidade votos nulos: %d \n", eleicao.votos_nulos);
  printf("Percentual votos nulos: %f \n", eleicao.percentual_votos_nulos);

  printf("Quantidade votos brancos: %d \n", eleicao.votos_brancos);
  printf("Percentual votos brancos: %f \n", eleicao.percentual_votos_brancos);

  printf("Quantidade votos válidos: %d \n", eleicao.quantidade_votos_validos);
  printf("Percentual votos válidos: %f \n", eleicao.percentual_votos_validos);

  printf("Quantidade votos inválidos: %d \n", eleicao.quantidade_votos_invalidos);
  printf("Percentual votos inválidos: %f \n", eleicao.percentual_votos_invalidos);
}
