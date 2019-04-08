 /* Universidade de Brasília - Faculdade do Gama
 * Estruturas de Dados 1 - 193704 TURMA: B
 * Professor: Mateus Mendelson
 * Nomes: Bruno Carmo Nunes 18/0117548
 *        Guilherme 1       xx/XXXXXXX
 *        Guilherme 2       xx/XXXXXXX
 * Comando compilação(Linux): gcc p3.c -Wall -o p3
 * Programa para resolver a Torre de Hanói usando recursividade
*/
#include <stdio.h>

void torre_hanoi(int a,int b,int c,int d);

int main(){
	
		int discos;
		
		printf("Todos os movimentos dos discos representados nesse programa são dos discos de cima,\n");
		printf("onde na regra um disco maior nunca pode ficar em cima de um disco menor\n");
		printf("Para a solução da Torre de Hanói, digite o número de discos utilizados: ");
		scanf("%d",&discos);
		
		torre_hanoi(discos,1,2,3);
		
		return 0;
	
}

//int a = numero de discos, int b,c,d = torre 1, torre 2, torre 3;
void torre_hanoi(int a,int b,int c,int d){
	
	if (a==1) printf("Mova o disco da torre %d para torre %d\n",b,d);
	else {
		torre_hanoi(a-1, b, d, c);
		printf("Mova o disco da torre %d para torre %d\n",b,d);
		torre_hanoi(a-1, c,b,d);
	}
	
}