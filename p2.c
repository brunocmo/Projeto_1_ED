/* Universidade de Brasília - Faculdade do Gama
 * Estruturas de Dados 1 - 193704 TURMA: B
 * Professor: Mateus Mendelson
 * Nomes: Bruno Carmo Nunes 18/0117548
 * Comando compilação(Linux): gcc p2.c -Wall -o p2
 Programa para saber quantidade de alunos aprovados e reprovados.
*/
#include <stdio.h>

int *recebe_notas(float *a, int i);
int *conta_notas(int *a, int i);
int percent_aprov(int *aprov, int *repro, int *resp);

int main(){

    float NOTAS[10];
    int b = 10;         //Numero de elementos do vetor
    int i = 0;          //Inteiro para o loop
    int x[2];           //Vetor para armazenar os valores percentuais
    int turma_aprovada; //Inteiro que o valor se mais da metade da turma foi aprovada

    printf("Insira 10 valores reais para as notas dos alunos, entre 0 e 10\n");
    while (i <= 9){
        printf("Nota %d: ",i+1);
        scanf("%f", &NOTAS[i]);
        if( NOTAS[i] >= 0 && NOTAS[i] <= 10) i++;
        else printf("Erro, valor fora do especificado, coloque valores entre 0 e 10\n");
    }

    printf("A quantidade de aprovados foi: %d\n", *conta_notas((recebe_notas(NOTAS,b)),b));
    printf("A quantidade de reprovados foi: %d\n", *(conta_notas(recebe_notas(NOTAS,b),b)+1));

    //Armazenamento dos valores no vetor x[0] e x[1] e tambem dos para turma_aprovada
    turma_aprovada = percent_aprov(conta_notas(recebe_notas(NOTAS,b),b),(conta_notas(recebe_notas(NOTAS,b),b)+1),x);

    printf("O pertcentual de aprovados foi: %d%%\n", x[0]);
    printf("O pertcentual de reprovados foi: %d%%\n", x[1]);
    printf("Mais da metade da turma foi aprovada: ");
    if( turma_aprovada == 1) puts("Sim");
    else                     puts("Nao");

    return 0;
}

int *recebe_notas(float *a,int i) {
    int *APR;
    int x[10] = {0,0,0,0,0,0,0,0,0,0};
    int j;
    APR = x;

    for (j=0; j <= i-1; j++) {
        if (*(a + j) >= 6) *(APR + j) = 1;
        else               *(APR + j) = 0;
    }
    return APR;
}
int *conta_notas(int *a, int i){
    int *ptr;
    int aval[2] = {0,0};
    ptr = aval;
    int j;

    for(j=0;j<=i-1;j++){
        if (*(a + j) == 1) *aval += 1;
        else               *(aval+1) += 1;
    }
    return ptr;
}

int percent_aprov(int *aprov, int *reprov, int *resp){

    int *ptr = aprov;

    *resp = *aprov * 10;
    *(resp +1) = *reprov * 10;
    if( *ptr >= 6 ) return 1;
    else            return 0;
}
