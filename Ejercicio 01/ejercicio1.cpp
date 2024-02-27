#include <iostream>
#include <vector>
#include <omp.h>
#include <fstream> //para guardar en txt el resultado
#include <chrono>

using namespace std;
using namespace std::chrono;
using clk = chrono::high_resolution_clock;

int main() {
	// preparamos para guardar resultados:
	std::ofstream file("resultadosEjercicio1.txt", std::ios::app); // abrir archivo en modo de append
	if (!file)
	{
		std::cerr << "No se pudo abrir el archivo" << std::endl;
		return -1;
	}
	unsigned int N;
	cout << "introduce el tamaño del vector" << endl;
	cin >> N;
	double timeIni, timeFin; vector<int> x(N), y(N);

	cout << " INICIO ****************************************************************** " << endl;
	file << " INICIO ****************************************************************** " << endl;
	cout << "Para tamaño de vector de " << N << " elementos:";
	file << "Para tamaño de vector de " << N << " elementos:";
	//Secuencial
	auto secuencial_t1 = clk::now(); //primera marca secuencial
	for (int i = 1; i < N; i++) {
		x[i] = y[i - 1] * 2; y[i] = y[i] + i;
	}
	auto secuencial_t2 = clk::now(); //segunda marca paralelo
	auto diffsecuencial = duration_cast<microseconds>(secuencial_t2 - secuencial_t1);
	cout << "SECUENCIAL:Tiempo transcurrido " << diffsecuencial.count() << "micro segundos" << endl;
	file << "SECUENCIAL:Tiempo transcurrido " << diffsecuencial.count() << "micro segundos" << endl;

	//Parallel
	auto paralelo_t1 = clk::now(); //primera marca paralelo


#pragma omp parallel  for  //private(i) realmente i es privada por defecto ya
	for (int i = 1; i < N; i++) {
		x[i] = y[i - 1] * 2; y[i] = y[i] + i;
	}


	auto paralelo_t2 = clk::now(); //segunda marca paralelo
	auto diffparalelo = duration_cast<microseconds>(paralelo_t2 - paralelo_t1);

	cout << "PARALELO: Tiempo transcurrido " << diffparalelo.count() << "micro segundos" << endl;
	file << "PARALELO: Tiempo transcurrido " << diffparalelo.count() << "micro segundos" << endl;



	//Imprimimos los vectores (si es menor de 20, si no no lo mostramos)
	if (N < 20) {
		cout << "Vector x: " << endl;
		for (int i = 0; i < N; i++) {
			cout << x[i] << " ";
		}
		cout << endl;
		cout << "Vector y: " << endl;
		for (int i = 0; i < N; i++) {
			cout << y[i] << " ";
		}
	}


	cout << " *********** CONCLUSIONES ***********************" << endl;
	file << " *********** CONCLUSIONES ***********************" << endl;

	int paralelo = diffparalelo.count();
	int secuencial = diffsecuencial.count();
	if (diffparalelo < diffsecuencial) {
		cout << "PARALELO: se obtiene mejor rendimiento con un tiempo de " << paralelo << "micro segundos frente a " << secuencial << "micro segundos" << endl;
		file << "PARALELO: se obtiene mejor rendimiento con un tiempo de " << paralelo << "micro segundos frente a " << secuencial << "micro segundos" << endl;
	}
	else {
		cout << "SECUENCIAL: se obtiene mejor rendimiento con un tiempo de " << secuencial << "micro segundos frente a " << paralelo << "micro segundos" << endl;
		file << "SECUENCIAL: se obtiene mejor rendimiento con un tiempo de " << secuencial << "micro segundos frente a " << paralelo << "micro segundos" << endl;
	}

	//Apartado 2
	int hilosMax = 24;
	vector<double> incrementoTiempos(hilosMax); //Aqui guardaré los incrementos
	vector<double> incrementoTiemposBarrera(hilosMax); //Aqui guardaré los incrementos
	vector<double> incrementoTiemposSeccionCritica(hilosMax); //Aqui guardaré los incrementos
	int NHilo;
	for (int numeroThreads = 1; numeroThreads <= hilosMax; numeroThreads++) {
		auto crearRegionT1 = clk::now();
#pragma omp parallel num_threads(20) private(NHilo)
		{
			NHilo = omp_get_thread_num();

			//apartado c: coste de poner una barrera
			auto crearBarreraT1 = clk::now();
#pragma opm barrier
			auto crearBarreraT2 = clk::now();
			auto incrementoDetiempoCreacionBarrera = duration_cast<microseconds>(crearBarreraT2 - crearBarreraT1);
			int incrementoTiempoBarrera = incrementoDetiempoCreacionBarrera.count();
			incrementoTiemposBarrera[numeroThreads - 1] = incrementoDetiempoCreacionBarrera.count();
			cout << "Soy el hilo" << NHilo << "pasando la barrera" << endl;
			file << "Soy el hilo" << NHilo << "pasando la barrera" << endl;




			//apartado d: coste de poner una seccion critica
			auto crearSeccionCriticaT1 = clk::now();
#pragma opm critical 
			{
				auto crearSeccionCriticaT2 = clk::now();
				auto incrementoDetiempoSeccionCritica = duration_cast<microseconds>(crearSeccionCriticaT2 - crearSeccionCriticaT1);
				int incrementoTiempoSeccionCritica = incrementoDetiempoSeccionCritica.count();
				incrementoTiemposSeccionCritica[numeroThreads - 1] = incrementoDetiempoSeccionCritica.count();
				cout << "Soy el hilo" << NHilo << "pasando una seccion critica" << endl;
				file << "Soy el hilo" << NHilo << "pasando una seccion critica" << endl;

			}






		}
		auto crearRegionT2 = clk::now();
		auto incrementoDetiempoCreacionRegion = duration_cast<microseconds>(crearRegionT2 - crearRegionT1);
		int incrementoTiempo = incrementoDetiempoCreacionRegion.count();
		incrementoTiempos[numeroThreads - 1] = incrementoDetiempoCreacionRegion.count();
	}
	for (int numeroThreads = 0; numeroThreads < hilosMax; numeroThreads++) {
		cout << "Con un numero de hilos = " << numeroThreads + 1 << " el incremento de tiempo de crear la región paralela es " << incrementoTiempos[numeroThreads] << " micro segundos" << endl;
		file << "Con un numero de hilos = " << numeroThreads + 1 << " eel incremento de tiempo de crear la región paralela es " << incrementoTiempos[numeroThreads] << " micro segundos" << endl;

		cout << "Con un numero de hilos = " << numeroThreads + 1 << " el incremento de tiempo de poner una barrera es " << incrementoTiemposBarrera[numeroThreads] << " micro segundos" << endl;
		file << "Con un numero de hilos = " << numeroThreads + 1 << " el incremento de tiempo de poner una barrera es " << incrementoTiemposBarrera[numeroThreads] << " micro segundos" << endl;

		cout << "Con un numero de hilos = " << numeroThreads + 1 << " el incremento de tiempo de entrar en una seccion critica es " << incrementoTiemposSeccionCritica[numeroThreads] << " micro segundos" << endl;
		file << "Con un numero de hilos = " << numeroThreads + 1 << " el incremento de tiempo de entrar en una seccion critica es " << incrementoTiemposSeccionCritica[numeroThreads] << " micro segundos" << endl;



	}






	return 0;
}

