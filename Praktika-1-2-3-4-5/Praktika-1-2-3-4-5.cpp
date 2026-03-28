
#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include <locale>

void  GenerateMatrix(vector<vector<double>>& mat, int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = rand() % 19 - 9;
        }
    }
}

void PrintMatrix(const vector<vector<double>>& mat, int N)
{
    cout << "--- Матриця " << N << "x" << N << " ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl << endl;
    }
}


double average(const vector<vector<double>>& mat, int N)
{
    double suma = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (mat[i][j] > 0)
            {
                suma += mat[i][j];
                count++;
            }
        }
    }
    if (count > 0) {
        return suma / count;
    }
    else {
        return 0;
    }
}


double Sector8(vector<vector<double>>& mat, int N, double avg)
{
    double sector3 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (j > i && i + j > N - 1) {
                if (mat[i][j] > 0) {

                    sector3++;
                }
            }
            if (i > j)
            {
                mat[i][j] = avg;
            }
        }
    }
    cout << "Кількість натуральних чисел у Секторі 3 " << sector3 << endl;
    return 0;
}





int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int N;
    cout << "Введіть розмір матриці =)";
    cin >> N;
    vector<vector<double>> matrix(N, vector<double>(N));
    GenerateMatrix(matrix, N);
    PrintMatrix(matrix, N);
    double averige = average(matrix, N);
    cout << "Середнє арифметичне додатних чисел " << averige << endl << endl;

    Sector8(matrix, N, averige);
    cout << "\nМатриця ПІСЛЯ обробки секторів:\n";
    PrintMatrix(matrix, N);
    return 0;
}