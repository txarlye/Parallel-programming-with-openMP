// ordenacion paralelizada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <fstream> // para guardar en txt el resultado

using namespace std;
 

void ordenacionPorSeleccionSecuencial(int arr[], int n) {
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) { 
        //guardamos el elemento más pequeño encontrado en cada iteración i
        minIndex = i; 
        for (j = i + 1; j < n; j++) {
            //comparamos el elemento del array con el mínimo
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        tmp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = tmp;
    }
}

void ordenacionPorSeleccionParalelo(int arr[], int n) {
    int i, j, minIndex, tmp; 
        for (i = 0; i < n - 1; i++) {
            //guardamos el elemento más pequeño encontrado en cada iteración i
            minIndex = i;
            for (j = i + 1; j < n; j++) {
                //comparamos el elemento del array con el mínimo
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            tmp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = tmp;
        }  
}

int* crearArrayAleatorio(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    std::ofstream file("resultadosEjercicio4.txt", std::ios::app); // abrir archivo en modo de append
    if (!file)
    {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return -1;
    }
    
    int size = 10; // Tamaño del array inicial
    cout << " *************************************************************************** " << endl;
    cout << " *************************************************************************** " << endl;
    file << " *************************************************************************** " << endl;
    file << " *************************************************************************** " << endl;

    cout << " - SECUENCIAL - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    file << " - SECUENCIAL - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    
  
    for (int i = 0; i < 5; i++) {
        double start_time_Secuential = omp_get_wtime();
        int* arr = crearArrayAleatorio(size); 
        ordenacionPorSeleccionSecuencial(arr, size); 
        double end_time_Secuential = omp_get_wtime();
        double run_time_Secuential = end_time_Secuential - start_time_Secuential;
         
        cout << "para tamanio de Array: " << size << " - tiempo de ejecucion: " << run_time_Secuential << "  segundos" << endl;
        file << "para tamanio de Array: " << size << " - tiempo de ejecucion: " << run_time_Secuential << "  segundos" << endl;
        size *= 10;
        delete[] arr;
    }
     
    cout << " - - PARALELO - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    file << " - - PARALELO - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl; 
    
    int sizep = 10;
    
#pragma omp parallel 
    { 
        //int numero_threads = omp_get_num_threads();
        //cout << "Un total de " << numero_threads << " hilos " << endl;
        //file << "Un total de " << numero_threads << " hilos " << endl;
        for (int ip = 0; ip < 5; ip++) {
            double start_time_Paralel = omp_get_wtime();
            int* arrp = crearArrayAleatorio(sizep); 
             ordenacionPorSeleccionParalelo(arrp, sizep); 
            double end_time_Paralel = omp_get_wtime();
            double run_time_Paralel = end_time_Paralel - start_time_Paralel;
              
            cout << "para tamanio de Array: " << sizep << " - tiempo de ejecucion: " << run_time_Paralel << "  segundos" << endl;
            file << "para tamanio de Array: " << sizep << " - tiempo de ejecucion: " << run_time_Paralel << "  segundos" << endl;
            sizep *= 10;
            delete[] arrp;
        }
    }
    
    cout << " - - - - - - - - - - - - - - - -F I N - - - - - - - - - - - - - - - - - - " << endl;
    file << " - - - - - - - - - - - - - - - -F I N - - - - - - - - - - - - - - - - - - " << endl;
     
    return 0;
}
