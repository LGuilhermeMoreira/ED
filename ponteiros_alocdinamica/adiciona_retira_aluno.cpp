// alocacao dinamica
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct aluno {
   int matricula;
   char nome[50];
   float media;
};

aluno le_aluno()
{
    aluno a;
    cin >> a.matricula;
    cin.ignore(); // lê e descarta o caractere '\n' do buffer 
    cin.get(a.nome, 50);
    cin >> a.media;
    return a;
}

aluno* insere_aluno(aluno *v, int *n, aluno novo)
{
   *n += 1;
   aluno *v2 = new aluno[*n];

   if(v != 0){
      for(int i = 0; i < *n; i++){
         v2[i] = v[i];
      }
      delete v;
      v = nullptr;
   }

   v2[*n-1] = novo;
   return v2;
}


aluno* remove_aluno(aluno *v, int *n, int matricula)
{
   *n -= 1;
   aluno *novo_ = new aluno[*n];

   for(int i = 0; i < *n+1; i++){
      if(v[i].matricula == matricula){
         v[i] = v[*n];
      }
   }

   int j = 0;
   while(j < *n){
      novo_[j] = v[j];
      j++;
   }

   delete v;
   v = nullptr;
   return novo_;
}

int main()
{
   int num_oper = 0, i, n = 0;
   cin >> num_oper;
   aluno *v = 0;

   for (i = 0; i < num_oper; i++) {
      cin.ignore(); // lê e descarta o caractere '\n' do buffer 
      char oper;
      cin >> oper;
      if (oper == 'i') {
         aluno a = le_aluno();
         v = insere_aluno(v, &n, a);
      } else {
         int mat;
         cin >> mat;
         v = remove_aluno(v, &n, mat);
      }
   }

   for (i = 0; i < n; i++) {
      cout << v[i].matricula << "\n" << v[i].nome << "\n" << std::fixed << setprecision(1) << v[i].media << "\n";
   }
   
   delete[] v;
   
   return 0;
}