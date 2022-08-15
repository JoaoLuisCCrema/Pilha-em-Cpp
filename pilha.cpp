#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace std::chrono;

typedef duration<long, ratio<1, 1000000000>> t;

void avg(t x[]){
    double soma = 0, media;
    for (int i = 0; i<50; i++){
      soma = soma + x[i].count();
    }
    media = soma/50;
    cout << trunc(media) << " nanossegundos" << endl;
}
int main (){
  
  int k, w, p[1000000];
  t tmps1[50], tmps2[50], tmps3[50];
  double soma;

  for(int j = 0; j<50; j++){
    auto str1 = steady_clock::now();
    for (int i=0; i<1000000; i++){
      p[i] = i+1;
    }
    auto fin1 = steady_clock::now();
    auto tempo1 = fin1 - str1;
    tmps1[j] = tempo1;
  }
  
  // Somas
  for(int j = 0; j<50; j++){
    auto str2 = steady_clock::now();
    for (int i: p){
     soma += i;
    }
    auto fin2 = steady_clock::now();
    auto tempo2 = fin2 - str2;
    tmps2[j] = tempo2;
  }
  
  //RNG
  for(int j = 0; j<50; j++){
    k = 0;
    srand(time(0));
    int r = 1+rand()%1000000;
    auto str3 = steady_clock::now();
    while (p[k] != r){
      k++;
    }
  auto fin3 = steady_clock::now();
  auto tempo3 = fin3 - str3;
  tmps3[j] = tempo3;
  }
  cout << "Tempo para preenchimento da pilha: "; avg(tmps1);
  cout << "Tempo para realizar a soma da pilha: "; avg(tmps2);
  cout << "Tempo para busca de um numero na pilha: "; avg(tmps3);
}