#ifndef MERGESORT_H_
#define MERGESORT_H_



#include <vector>
#include <list>

template <class T>
class Sort {

    private: 

    void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);

    public: 

    std::vector<T> mergeSort(const std::vector<T>&);


};

template <class T>
void Sort<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}


template <class T>
void Sort<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {

	int i_ordenado = low;
	int i_izquierda = low;
	int i_derecha = mid + 1;

	//Ciclo para ordenar en B, la parte izquierda de A con respecto a la parte derecha de A
	while (i_izquierda <= mid && i_derecha <= high) {
		if (A[i_izquierda] < A[i_derecha]) {
			B[i_ordenado] = A[i_izquierda];
			i_izquierda++;
		} else {
			B[i_ordenado] = A[i_derecha];
			i_derecha++;
		}
		i_ordenado++;
	}

	//Ciclo para terminar de rellenar B, con lo que queda de la parte izquierda A
	while(i_izquierda <= mid) {
		B[i_ordenado] = A[i_izquierda];
		i_izquierda++;
			i_ordenado++;
	}

	//Ciclo para terminar de rellenar B, con lo que queda de la parte derecha de A
	while(i_derecha <= high) {
		B[i_ordenado] = A[i_derecha];
		i_derecha++;
		i_ordenado++;
	}

	//Copiar B en A
	copyArray(A, B, low, high);
}


template <class T>
void Sort<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {

	//Condición de paro (caso base)
	if (low < high) {
		
		//Calcular la mitad del vector
		int mitad = (low + high) / 2;
		
		//Ordenar la parte izquierda
		mergeSplit(A, B, low, mitad);
	
		//Ordenar la parte derecha
		mergeSplit(A, B, mitad + 1, high);
	
		//Juntar ambas partes ordenadas
		mergeArray(A, B, low, mitad, high);
	}
}


template <class T>
std::vector<T> Sort<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	
	return v;
}



#endif /* MERGESORT_H_ */
