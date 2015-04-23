//Distribuicao combinada e entropia de uma distribuicao conjunta
//Distribuicoes marginais e entropias
#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

double s[MAX];
double t[MAX];
double cmb[MAX][MAX];

void fl1();
void fl2();
void dis_cmb(int S, int T);
double entropia_cmb(int S, int T);
double log2(double val) {
  return log(val) / log(2);
}
void marginal_S(int S, int T);
void marginal_T(int S, int T);
double entropia_S(int S);
double entropia_T(int T);
double entropia_cnd(double hp, double hc);

int main() {
  printf("1. Distribuicao combinada e entropia\n");
  printf("2. Distribuicoes marginais e entropias\n");
  
  int fl; printf("Introduzir opcao: "); scanf("%d", &fl);
  
  if(fl == 1) fl1();
  if(fl == 2) fl2();
  
  return 0;
}

void fl1() {
  int S, T; printf("Numero de termos de S: "); scanf("%d", &S); printf("Numero de termos de T: "); scanf("%d", &T);
  
  for(int i = 0; i < S; i++) {
    printf("P(S%d): ", i + 1);
    scanf("%lf", &s[i]);
  }
  
  for(int i = 0; i < T; i++) {
    printf("P(T%d): ", i + 1);
    scanf("%lf", &t[i]);
  }
  
  dis_cmb(S, T);
  
  printf("------------------------------------------------\n");
  for(int i = 0; i < S; i++) {
    for(int j = 0; j < T; j++) {
      printf("P(S%d, T%d) = %.5lf\n", i + 1, j + 1, cmb[i][j]);
    }
  }
  
  printf("Entropia da distribuicao de probabilidade conjunta: %.5lf\n", entropia_cmb(S, T));
}

void dis_cmb(int S, int T) {
  for(int i = 0; i < S; i++) {
    for(int j = 0; j < T; j++) {
      cmb[i][j] = s[i] * t[j];
    }
  }
}

double entropia_cmb(int S, int T) {
  double sum = 0;
  for(int i = 0; i < S; i++) {
    for(int j = 0; j < T; j++) {
      sum += cmb[i][j] * log2(cmb[i][j]);
    }
  }
  
  return -sum;
}

void fl2() {
  int S, T; printf("Numero de termos de S: "); scanf("%d", &S); printf("Numero de termos de T: "); scanf("%d", &T);
  for(int i = 0; i < S; i++) {
    for(int j = 0; j < T; j++) {
      printf("P(S%d, T%d) ", i + 1, j + 1);
      scanf("%lf", &cmb[i][j]);
    }
  }
  
  marginal_S(S, T);
  marginal_T(S, T);
  
  printf("------------------------------------------------\n");
  printf("Distribuicao marginal S:\n");
  for(int i = 0; i < S; i++) {
    printf("P(S%d) = %.5lf\n", i + 1, s[i]);
  }
  
  printf("Distribuicao marginal T:\n");
  for(int i = 0; i < T; i++) {
    printf("P(T%d) = %.5lf\n", i + 1, t[i]);
  }

  double entropia_s = entropia_S(S);
  double entropia_t = entropia_T(T);
  double hp = entropia_cmb(S, T);
  
  printf("Entropia conjunta: %.5lf\n", hp);
  printf("Entropia P(S) e entropia P(T): %.5lf %.5lf\n", entropia_s, entropia_t);
  printf("Pelo teorema 1.6, H(P) = H(P_T) + H(P_S|T) = H(P_S) + H(P_T|S)\n");
  printf("Entropias condicionadas P(S|T) e P(T|S): %.5lf %.5lf\n", entropia_cnd(hp, entropia_t), entropia_cnd(hp, entropia_s));
}

void marginal_S(int S, int T) {
  for(int i = 0; i < S; i++) {
    double sum = 0;
    for(int j = 0; j < T; j++) {
      sum += cmb[i][j];
    }
    s[i] = sum;
  }
}

void marginal_T(int S, int T) {
  for(int j = 0; j < T; j++) {
    double sum = 0;
    for(int i = 0; i < S; i++) {
      sum += cmb[i][j];
    }
    t[j] = sum;
  }
}

double entropia_S(int S) {
  double sum = 0;
  for(int i = 0; i < S; i++) {
    sum += s[i] * log2(s[i]);
  }
  
  return -sum;
}

double entropia_T(int T) {
  double sum = 0;
  for(int i = 0; i < T; i++) {
    sum += t[i] * log2(t[i]);
  }
  
  return -sum;
}

double entropia_cnd(double hp, double hc) {
  return hp - hc;
}
