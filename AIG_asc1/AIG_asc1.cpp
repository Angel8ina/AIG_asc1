// AIG_asc1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");         //2b
    cout << omp_get_num_procs() << "\n";    //2c

    //2d
    const int n = 10e2;
    float* Asgl = new float[n];
    double* Adbl = new double[n];
    for (int i = 0; i < n; ++i) {
        Asgl[i] = rand();
        Adbl[i] = rand();
    }
    float sum1 = 0;
    double sum2 = 0;
    unsigned int t1 = clock();
    unsigned int t2 = clock();

    t1 = clock();
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования массива одинарной точности =" << t2 - t1 << "\n";

    t1 = clock();
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования массива двойной точности =" << t2 - t1 << "\n";

    //2e
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования (reduction) массива одинарной точности =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования (reduction) массива двойной точности =" << t2 - t1 << "\n";

    //2f
    //2 потока суммирование
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(2) reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования одинарной точности,2 потока =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(2) reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования двойной точности,2 потока =" << t2 - t1 << "\n";

    //4 потока суммирование
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(4) reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования одинарной точности,4 потока =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(4) reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования двойной точности,4 потока =" << t2 - t1 << "\n";
    
    //8 потоков суммирование
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(8) reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования одинарной точности,8 потоков =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(8) reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования двойной точности,8 потоков =" << t2 - t1 << "\n";

    //16 потоков суммирование
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(16) reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования одинарной точности,16 потоков =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(16) reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования двойной точности,16 потоков =" << t2 - t1 << "\n";

    //32 потоков суммирование
    sum1 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(32) reduction(+:sum1)
    for (int i = 0; i < n; ++i) sum1 += Asgl[i];
    t2 = clock();
    cout << sum1 << "\n";
    cout << "Время суммирования одинарной точности,32 потоков =" << t2 - t1 << "\n";

    sum2 = 0;
    t1 = clock();
    #pragma omp parallel for num_threads(32) reduction(+:sum2)
    for (int i = 0; i < n; ++i) sum2 += Adbl[i];
    t2 = clock();
    cout << sum2 << "\n";
    cout << "Время суммирования двойной точности,32 потоков =" << t2 - t1 << "\n";

    //3b
    float** Bsgl1 = new float* [n];
    for (int i = 0; i < n; ++i) Bsgl1[i] = new float[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            Bsgl1[i][j] = rand();
    }
    float** Bsgl2 = new float* [n];
    for (int i = 0; i < n; ++i) Bsgl2[i] = new float[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            Bsgl2[i][j] = rand();
    }

    double** Bdbl1 = new double* [n];
    for (int i = 0; i < n; ++i) Bdbl1[i] = new double[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            Bdbl1[i][j] = rand();
    }
    double** Bdbl2 = new double* [n];
    for (int i = 0; i < n; ++i) Bdbl2[i] = new double[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            Bdbl2[i][j] = rand();
    }

    //3d
    float** Csgl = new float* [n];
    for (int i = 0; i < n; ++i) Csgl[i] = new float[n];  //пустая матрица для результата перемножения float

    double** Cdbl = new double* [n];
    for (int i = 0; i < n; ++i) Cdbl[i] = new double[n];  //пустая матрица для результата перемножения double

    t1 = clock();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности(последовательно) =" << t2 - t1 << "\n";

    t1 = clock();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности(последовательно) =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности(параллельно) =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности(параллельно) =" << t2 - t1 << "\n";

    //3e
    t1 = clock();
    #pragma omp parallel for num_threads(2)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности, 2 потока =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(2)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности, 2 потока =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности, 4 потока =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности, 4 потока =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(8)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности, 8 потоков =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(8)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности, 8 потоков =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(16)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности, 16 потоков =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(16)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности, 16 потоков =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Csgl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Csgl[i][j] += Bsgl1[i][k] * Bsgl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц одинарной точности, 32 потоков =" << t2 - t1 << "\n";

    t1 = clock();
    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Cdbl[i][j] = 0;
            for (int k = 0; k < n; ++k)
                Cdbl[i][j] += Bdbl1[i][k] * Bdbl2[k][j];
        }
    t2 = clock();
    cout << "Время перемножения матриц двойной точности, 32 потоков =" << t2 - t1 << "\n";


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
