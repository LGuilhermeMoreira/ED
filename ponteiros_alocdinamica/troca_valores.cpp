// ponteiro
#include <iostream>

void troca(int *a, int *b){
    int z = 0;
    z = *a;
    *a = *b;
    *b = z;
}

int main(){
   int x, y;
   std::cin >> x;
   std::cin >> y;
   
   troca(&x,&y);

   
   std::cout << x << " " << y << std::endl;
   return 0;
}