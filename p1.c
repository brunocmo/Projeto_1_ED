/* Universidade de Brasília - Faculdade do Gama
 * Estruturas de Dados 1 - 193704 TURMA: B
 * Professor: Mateus Mendelson
 * Nomes: Bruno Carmo Nunes 18/0117548
 *        Guilherme 1       xx/XXXXXXX
 *        Guilherme 2       xx/XXXXXXX
 * Comando compilação(Linux): gcc p1.c -Wall -o p1
*/
#include <stdio.h>

//Pré inicializacao das funções
int *fneuronio(float* a,float* b, float c,int d);
float sum(float* a,float* b,int i);

int main() {

    float x[10]; //Armazenamento da Entrada
    float w[10]; //Armazenamento do Peso
    float t;     //Armazenamento do limiar T
    int z = 10;  //Numero maximo de elementos da entrada
    int i = 0;   //Entrada para o Laco
    int *resp;   //Ponteiro para a resposta dos neuronios

    printf("Digite o valor real para ENTRADA e PESO Ex: \"4.4 6.7\" \n");

    //Laço para entrada dos valores dos vetores x e w
    while (i <= 9){
        printf("Coluna %d: ",i+1);
        scanf("%f %f", &x[i], &w[i]);
        i++;
    }

    printf("Digite um valor real para o limiar T: ");
    scanf("%f", &t);

    resp = fneuronio(x,w,t,z);
    //Condição para saber se o neurônio esta ou ativado ou inibido
    if(*resp == 1) printf("Neurônio ativado!\n");
    else                        printf("Neurôno inibido!\n");

    return 0;
}

//Função neurônio que com base no limitador T(float c) retorna o estado do neurônio
int *fneuronio(float* a,float* b, float c, int d){
    int *resp;
    if(sum(a,b,d) < c) *resp = 0;
    else               *(resp) = 1;
    return resp;
}

//Função que faz a somas das multiplicações de vetores, onde o inteiro i é o número de repeticoes
float sum(float *a, float *b, int i){
    if(i == 1) return (*a)*(*b);
    else return (*a)*(*b)+(sum((++a),(++b),(i-1)));
}
