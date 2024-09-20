#include "SelectionSort.h"



void UOrdenamientoSeleccion::SelectionSort(TArray<float>& Array)
{
    float Size = Array.Num();

    for (float i = 0; i < Size - 1; i++)
    {
        float pos_menor = i;

        for (float j = i + 1; j < Size; j++)
        {
            if (Array[j] < Array[pos_menor])
            {
                pos_menor = j;
            }
        }

        if (pos_menor != i)
        {
            Array.Swap(i, pos_menor);  // Función Swap de TArray
        }
    }
}

TArray<float> UOrdenamientoSeleccion::Seleccion(const TArray<float>& InArray)
{
    TArray<float> SortedArray = InArray;

    SelectionSort(SortedArray);

    return SortedArray;
}
