//valor esperado
//Surpresa
//Entropia
#include <bits/stdc++.h>

using namespace std;

double log2(double val);

//Valor esperado
void fl1() {
  int n; printf("Numero de termos: "); scanf("%d", &n);
  double sum = 0;
  
  for(int i = 0; i < n; i++) {
    double p, f; scanf("%lf %lf", &p, &f);
    sum += p * f;
  }
  
  printf("Valor esperado = %.5lf\n", sum);
}

//Surpresa
void fl2() {
  double p; printf("Probabilidade: "); scanf("%lf", &p);
  
  printf("Surpresa = %.5lf\n", -log2(p));
}

//Entropia
void fl3() {
  int n; printf("Numero de termos: "); scanf("%d", &n);
  double sum = 0;
  
  for(int i = 0; i < n; i++) {
    double p; scanf("%lf", &p);
    sum += p * log2(p);
  }
  
  printf("Entropia = %.5lf\n", -sum);

}

int main() {
  printf("1. Valor esperado\n");
  printf("2. Surpresa\n");
  printf("3. Entropia\n");
  
  int fl; printf("Introduzir opcao: "); scanf("%d", &fl);
  
  if(fl == 1) fl1();
  if(fl == 2) fl2();
  if(fl == 3) fl3();
  
  return 0;
}

double log2(double val) {
  return log(val) / log(2);
}
