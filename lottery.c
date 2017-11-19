#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//variaveis globais para mergeSort calcular o numero de trocas e comparacoes dos vetores
int comp = 0 , swap = 0;

//escolha de 5 numeros do jogador
void numChoice(int *n1, int *n2, int *n3, int *n4, int *n5 , int max)
{
	printf("\nDigite 5 números de 1 a %d\n" , max);

	int invalid = 0;
	do
	{
		if(invalid)
			puts("Número incorreto/repetido");
		printf("  Número 1:\n");
		scanf("%d" , n1);
		invalid = 1;
	}
	while((*n1 < 1)||(*n1 > max));
	puts("");

	invalid = 0;
	do
	{
		if(invalid)
			puts("Número incorreto/repetido");
		printf("  Número 2:\n");
		scanf("%d" , n2);
		invalid = 1;
	}
	while((*n2 < 1)||(*n2 > max)||(*n2 == *n1));
	puts("");

	invalid = 0;
	do
	{
		if(invalid)
			puts("Número incorreto/repetido");
		printf("  Número 3:\n");
		scanf("%d" , n3);
		invalid = 1;
	}
	while((*n3 < 1)||(*n3 > max)||(*n3 == *n1)||(*n3 == *n2));
	puts("");

	invalid = 0;
	do
	{
		if(invalid)
			puts("Número incorreto/repetido");
		printf("  Número 4:\n");
		scanf("%d" , n4);
		invalid = 1;
	}
	while((*n4 < 1)||(*n4 > max)||(*n4 == *n1)||(*n4 == *n2)||(*n4 == *n3));
	puts("");

	invalid = 0;
	do
	{
		if(invalid)
			puts("Número incorreto/repetido");
		printf("  Número 5:\n");
		scanf("%d" , n5);
		invalid = 1;
	}
	while((*n5 < 1)||(*n5 > max)||(*n5 == *n1)||(*n5 == *n2)||(*n5 == *n3)||(*n5 == *n4));
	puts("");
}

void selectionSort(int array[] , int size)
{
	int comp = 0 , swap = 0;
	for(int i = 1 ; i < size ; i++)
	{
		int min = i;
		for(int j = i+1 ; j <= size ; j++)
		{
			if(array[j] < array[min])
				min = j;
			comp++;
		}
		int aux = array[i];
		array[i] = array[min];
		array[min] = aux;
		swap += 3;
	}

	//printando resultados do selectionSort
	puts("Selection Sort:");
	printf("  Número de comparações: %d\n" , comp);
	printf("  Número de troca de elementos: %d\n\n" , swap);
}

void bubbleSort(int array[] , int size)
{
	int comp = 0 , swap = 0;
	for(int i = size ; i >= 2 ; i--)
	{
		for(int j = 1 ; j < i ; j++)
		{
			if(array[j] > array[j+1])
			{
				int aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
				swap += 3;
			}
			comp++;
		}
	}

	//printando resultados do bubbleSort
	puts("Bubble Sort:");
	printf("  Número de comparações: %d\n" , comp);
	printf("  Número de troca de elementos: %d\n\n" , swap);
}

void mergeSort(int array[] , int arrayAux[] , int left , int right)
{
	int i,j,k;
	if(left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(array , arrayAux , left , middle);
		mergeSort(array , arrayAux , middle+1 , right);

		//intercalando
		for(i = middle+1 ; i > left ; i--)
		{
			arrayAux[i-1] = array[i-1];
			swap++;
		}
		for(j = middle ; j < right ; j++)
		{
			arrayAux[right+middle-j] = array[j+1];
			swap++;
		}
		for(k = left ; k <= right ; k++)
		{
			if(arrayAux[i] < arrayAux[j])
				array[k] = arrayAux[i++];
			else
				array[k] = arrayAux[j--];
			comp++;
			swap++;
		}
	}
}

int linearSearch(int value , int array[] , int size)
{
	int i , comp = 1;
	array[0] = value;

	for(i = size ; array[i] != value ; i-- , comp++);

	printf("  Número de comparações para o número %d: %d\n" , value,comp);

	return i;
}

int binarySearch(int value , int array[] , int size)
{
	int left = 1 , middle , right = size , comp = 0;

	do
	{
		middle = (left + right)/2;

		if(value > array[middle])
			left = middle + 1;
		else
			right = middle - 1;

		comp += 2;
	}
	while((value != array[middle])&&(left <= right));

	//comparao do proximo if
	comp++;
	printf("  Número de comparações para o número %d: %d\n" , value,comp);

	if(value == array[middle])
		return middle;
	else
		return 0;
}

//funcao para printar o array desejado
void printArray(int array[] , int size)
{
	for(int i=1 , j=1 ; i<=size ; i++ , j++)
	{
		if(j > 20)
		{
			puts("|");
			j = 1;
		}
		printf("| %d " , array[i]);
	}
	puts("|");
}

int main()
{
	char choice;
	do
	{
		system("clear");
		//lendo parametros
		int size , max , invalid = 0;
		do
		{
			if(invalid)
				puts("Tamanho e valor máximo não podem ser menores que 5");
			puts("Digite o tamanho do vetor e o valor máximo:");
			scanf("%d %d" , &size,&max);
			invalid = 1;
		}
		while((size < 5)||(max < 5));

		//criando vetor aleatorio
		int *array;
		array = malloc((size+1)*sizeof(int));
		//sempre que rodar o programa os numeros serao diferentes
		srand(time(NULL));
		for(int i = 1 ; i <= size ; i++)
			array[i] = (rand() % max) + 1;

		//escolha de numeros
		int n1,n2,n3,n4,n5;
		numChoice(&n1,&n2,&n3,&n4,&n5,max);

		puts("Pesquisa Sequencial:");
		linearSearch(n1,array,size);
		linearSearch(n2,array,size);
		linearSearch(n3,array,size);
		linearSearch(n4,array,size);
		linearSearch(n5,array,size);
		puts("");

		//criando vetor copia para manter o vetor original
		int *arrayCopy;
		arrayCopy = malloc((size+1)*sizeof(int));

		//selectionSort
		for(int i = 1 ; i <= size ; i++)
			arrayCopy[i] = array[i];
		selectionSort(arrayCopy,size);

		//bubbleSort
		for(int i = 1 ; i <= size ; i++)
			arrayCopy[i] = array[i];
		bubbleSort(arrayCopy,size);

		//mergeSort
		for(int i = 1 ; i <= size ; i++)
			arrayCopy[i] = array[i];

		//criando vetor auxiliar para mergeSort
		int *arrayAux;
		arrayAux = malloc((size+1)*sizeof(int));

		mergeSort(arrayCopy,arrayAux,1,size);
		printf("Merge Sort: \n");
		printf("  Número de comparações: %d\n" , comp);
		printf("  Número de troca de elementos: %d\n\n" , swap);
		
		//count = contagem de acertos
		int count = 0;
		puts("Pesquisa Binária:");
		//binary search com a copia do vetor original
		if(binarySearch(n1,arrayCopy,size))
			count++;
		if(binarySearch(n2,arrayCopy,size))
			count++;
		if(binarySearch(n3,arrayCopy,size))
			count++;
		if(binarySearch(n4,arrayCopy,size))
			count++;
		if(binarySearch(n5,arrayCopy,size))
			count++;
		puts("");

		//contar comparacoes nas buscas
		printf("Acertou %d dos 5 números\n" , count);

		//printar array
		puts("Printar Vetor Ordenado? (s/n)");
		scanf(" %c" , &choice);
		puts("");
		if(choice == 's')
			printArray(arrayCopy,size);
		puts("");

		puts("Jogar de novo? (s/n)");
		scanf(" %c" , &choice);

		comp = 0;
		swap = 0;
	}
	while((choice == 's')||(choice == 'S'));
}
