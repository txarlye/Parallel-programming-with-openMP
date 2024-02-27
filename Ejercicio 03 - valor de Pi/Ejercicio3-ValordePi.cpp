// ProgramacionAvanzadaEjercicio2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <cmath>
#include <omp.h>
#include <fstream> // para guardar en txt el resultado
#include <iomanip> // para imprimir con mayor precisión de decimales

using namespace std;
double f(double x) {
    return 4.0 / (1 + x * x);
}

int main() {
    std::ofstream file("resultadosEjercicio2.txt", std::ios::app); // abrir archivo en modo de append
    if (!file)
    {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return -1;
    }
    for (int inicio = 10; inicio < 10000000000; inicio*=10) {
        //En paralelo
        double start_time_Paralel = omp_get_wtime();
        int N = inicio;
        double a = 0.0;
        double b = 1.0;
        double h = (b - a) / N;
        double sum = 0.5 * (f(a) + f(b));
#pragma omp parallel  for  reduction(+:sum) 
        for (int i = 1; i < N; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        double pi_paralel = h * sum;

        cout << " *************************************************************************** " << endl;
        cout << " *************************************************************************** " << endl;
        file << " *************************************************************************** " << endl;
        file << " *************************************************************************** " << endl;
        cout << " para N = " << N << endl;
        file << " para N = " << N << endl;


        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        file << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        cout << "EJECUTADO EN PARALELO: Aproximacion de pi con regla del trapecio: " << fixed << setprecision(10) << pi_paralel << endl;
        file << "EJECUTADO EN PARALELO: Aproximacion de pi con regla del trapecio: " << fixed << setprecision(10) << pi_paralel << endl;
        double end_time_paralel = omp_get_wtime();
        double run_time_paralel = end_time_paralel - start_time_Paralel;
        cout << "El tiempo de ejecucion fue: " << run_time_paralel << " segundos" << endl;
        file << "El tiempo de ejecucion fue: " << run_time_paralel << " segundos" << endl;


        //secuencial
        double start_time_secuential = omp_get_wtime();
        for (int i = 1; i < N; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        double pi_secuential = h * sum;

        cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        file << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
        cout << "EJECUTADO SECUENCIAL: Aproximacion de pi con regla del trapecio: " << fixed << setprecision(10) << pi_secuential << endl;
        file << "EJECUTADO SECUENCIAL: Aproximacion de pi con regla del trapecio: " << fixed << setprecision(10) << pi_secuential << endl;
        double end_time_secuential = omp_get_wtime();
        double run_time_secuential = end_time_secuential - start_time_secuential;
        cout << "El tiempo de ejecucion fue: " << run_time_secuential << " segundos" << endl; 
        file << "El tiempo de ejecucion fue: " << run_time_secuential << " segundos" << endl;
    }

    


    return 0;
}