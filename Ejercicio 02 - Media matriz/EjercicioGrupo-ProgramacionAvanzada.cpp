// EjercicioGrupo-ProgramacionAvanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <fstream> //para guardar en txt el resultado

using namespace std;
using namespace std::chrono;
using clk = chrono::high_resolution_clock;

int main() {
    int m, n;
    // preparamos para guardar resultados:
    std::ofstream file("resultadosEjercicio2.txt", std::ios::app); // abrir archivo en modo de append
    if (!file)
    {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return -1;
    }
    std::cout << "introduce el tamaño de la Matriz" << endl;
    std::cout << "numero de filas" << endl;
    cin >> m;
    std::cout << "numero de columnas" << endl;
    cin >> n;
    int matriz[100][100];
    std::cout << "Vamos a introducir los valores aleatorios" << endl;
    int num;
    srand(time(NULL)); // para los valores aleatorios
    
    file << " *************************************************************************** " << endl;
    for (int mx = 0; mx < m; mx++) {
        for (int ny = 0; ny < n; ny++) {
            /* podríamos hacerlo manualmente de este modo 
            std::cout << "Introduce el valor del elemento [" << mx << "][" << ny << "]: " << endl;
            cin >> matriz[mx][ny];
            */ 
            matriz[mx][ny] = 1 + rand() % (10 - 1);
        }
    }

    std::cout << "Nuestra matriz es: " <<m<<"*"<<n<< endl;
    file << "Nuestra matriz es: " << m << "*" << n << endl;
    for (int mx = 0; mx < m; mx++) {
        for (int ny = 0; ny < n; ny++) {
            std::cout << matriz[mx][ny]; 
            if (m<10 && n<10) { //para tamaños mayores no guardamos la matriz en el txt que emborrona
                file << matriz[mx][ny];
            }  
        }
        std::cout << "\n" << endl;
        if (m < 10 && n < 10) {
            file << "\n" << endl;
        }
    }

    //Calculando el promedio : secuencial
    cout << "Calculo por proceso SECUENCIAL: " << endl;
    file << "Calculo por proceso SECUENCIAL: " << endl;
    auto secuencial_t1 = clk::now(); //primera marca secuencial
    int totalsec = 0;
    for (int mx = 0; mx < m; mx++) {
      for (int ny = 0; ny < n; ny++) {
        totalsec=totalsec+ matriz[mx][ny];
      }
    }
    int mediatotalsec = totalsec / (m * n);
    std::cout << "SECUENCIAL: El total de la matriz es "<< totalsec <<" y la media es "<< mediatotalsec << endl;
    file << "SECUENCIAL: El total de la matriz es " << totalsec << " y la media es " << mediatotalsec << endl;
    auto secuencial_t2 = clk::now(); //segunda marca paralelo
    auto diffsecuencial = duration_cast<microseconds>(secuencial_t2 - secuencial_t1);
    cout << "SECUENCIAL:Tiempo transcurrido " << diffsecuencial.count() << "micro segundos" << endl;
    file << "SECUENCIAL:Tiempo transcurrido " << diffsecuencial.count() << "micro segundos" << endl;

    cout << " *************************************************************************** " << endl;
    file << " *************************************************************************** " << endl;


    //Calculando el promedio : paralelo
    cout << "Calculo por proceso PARALELO: " << endl;
    file << "Calculo por proceso PARALELO: " << endl;
    //Variables compartidas
    int total = 0;

    int id;
    
    auto paralelo_t1 = clk::now(); //primera marca paralelo
#pragma omp parallel  for reduction(+:total)  
    for (int px = 0; px < m; px++)
    {
        for (int py = 0; py < n; py++)
        {
            /*Cada hilo sumará su valor debido a la clausula for reduction*/
            total += matriz[px][py];
            id = omp_get_thread_num();
            
            if (m < 10 && n < 10) { //no queremos disminuir el rendimiento escribiendo ni dificultar la lectura del txt
                cout << "El hilo [" << id << "] ha introducido el valor de " << matriz[px][py] << " al total " << endl;
                file << "El hilo [" << id << "] ha introducido el valor de " << matriz[px][py] << " al total " << endl;
            } 
        }
        /*Sólo queremos que un hilo nos proporcione esta información que será el hilo que pase por la última iteración*/
        if (px == m-1 ) {
            int numero_threads = omp_get_num_threads();
            cout << "Un total de " << numero_threads << " hilos " << endl;
            file << "Un total de " << numero_threads << " hilos " << endl;
        }
    }


    /*Con barrier indicamos a todos los hilos que esperen a que todos los hilos completen su tarea antes de continuar*/
#pragma omp barrier
    if (omp_get_thread_num() == 0) {
        int mediatotal = total / (m * n);
        std::cout << "El total de la matriz es " << total << " y la media es " << mediatotal << endl;
        file << "PARALELO: El total de la matriz es " << total << " y la media es " << mediatotal << endl;
    }
    auto paralelo_t2 = clk::now(); //segunda marca paralelo
    auto diffparalelo = duration_cast<microseconds>(paralelo_t2 - paralelo_t1);
    cout << "PARALELO: Tiempo transcurrido " << diffparalelo.count() << "micro segundos" << endl;
    file << "PARALELO: Tiempo transcurrido " << diffparalelo.count() << "micro segundos" << endl;

    int paralelo = diffparalelo.count();
    int secuencial = diffsecuencial.count();

    cout << " *********** CONCLUSIONES ***********************" << endl;
    file << " *********** CONCLUSIONES ***********************" << endl;
    if (diffparalelo < diffsecuencial) {
        cout << "PARALELO: se obtiene mejor rendimiento para matriz de [" << m << "][" << n << "] con un tiempo de " << paralelo << "micro segundos frente a " << secuencial << "micro segundos" << endl;
        file << "PARALELO: se obtiene mejor rendimiento para matriz de [" << m << "][" << n << "] con un tiempo de " << paralelo << "micro segundos frente a " << secuencial << "micro segundos" << endl;
    }
    else { 
        cout << "SECUENCIAL: se obtiene mejor rendimiento para matriz de [" << m << "][" << n << "] con un tiempo de " << secuencial << "micro segundos frente a " << paralelo << "micro segundos" << endl;
        file << "SECUENCIAL: se obtiene mejor rendimiento para matriz de [" << m << "][" << n << "] con un tiempo de " << secuencial << "micro segundos frente a " << paralelo << "micro segundos" << endl;
    }

    return 0;
}





