// ponteiro
#include <iostream>

void converte_tempo(int segundos, int *hor, int *min, int *seg)
{
    if(segundos >= 60){
        *min = segundos/60;
        segundos = segundos - (*min*60);
        *seg = segundos;
    }else{
        *min = 0;
        *hor = 0;
    }
    if(*min >= 60){
        *hor = *min/60;
        *min = *min - (*hor*60);
    }else{
        *hor = 0;
    }
}

int main()
{
   int tempo, h, m, s;
   std::cin >> tempo;
   
   converte_tempo(tempo, &h, &m, &s);

   std::cout << h << ":" << m << ":" << s;
   
   return 0;
}