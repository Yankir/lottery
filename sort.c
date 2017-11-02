#include <stdio.h>
#define size 5 //sem contar elemento [0]

//implementando array global para o mergeSort
int arrayAux[size+1];
int comp = 0 , swap = 0;

void selectionSort(int array[])
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
	printf("Número de comparações: %d\n" , comp);
	printf("Número de troca de elementos: %d\n" , swap);
}

void bubbleSort(int array[])
{
	int comp = 0 , swap = 0;
	for(int i = size ; i >= 2 ; --i)
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
	printf("Número de comparações: %d\n" , comp);
	printf("Número de troca de elementos: %d\n" , swap);
}

void mergeSort(int array[] , int left , int right)
{
	int i,j,k;
	if(right > left)
	{
		int middle = (left + right) / 2;
		mergeSort(array , left , middle);
		mergeSort(array , middle+1 , right);

		//intercalando
		for(i = middle+1 ; i > left ; --i)
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

int main()
{
	int array1[] = {6,5,4,3,2,1} , array2[] = {6,5,4,3,2,1} , array3[] = {6,5,4,3,2,1};

	selectionSort(array1);
	bubbleSort(array2);
	mergeSort(array3,1,5);
	//printando resultados do mergeSort
	printf("Número de comparações: %d\n" , comp);
	printf("Número de troca de elementos: %d\n" , swap);

	for(int i = 1 ; i < size+1 ; i++)
		printf("%d " , array3[i]);
	puts("");
}
