// ponteiro
#include <iostream> // std::cout, std::cin, std::fixed
#include <iomanip> // std::setprecision

struct aluno {
   float nota[3];
   float media;
};

void calcula_media(aluno *a)
{
   float soma = 0;
   for(int i = 0; i < 3; i++){
      soma += a->nota[i];
   }
   a->media = soma/3;
}


void calcula_media_turma(aluno turma[], int n)
{
   for(int i = 0; i < n; i++){
      calcula_media(&turma[i]);
   }
}

int main()
{
   int n, i, j;
   
   std::cin >> n; // tamanho do vetor de strutura
   aluno turma[n]; // criando a strutura turma
   
   for (j = 0; j < n; j++)
      for (i = 0; i < 3; i++)
         std::cin >> turma[j].nota[i];
   
   calcula_media_turma(turma, n);
   
   
   for (j = 0; j < n; j++) {
      std::cout << std::fixed;
      std::cout << std::setprecision(1) << turma[j].media << " ";
   }
   
   return 0;
}