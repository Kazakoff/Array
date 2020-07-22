#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int load2DArray(const char* file, int**& m, int& rCnt, int& cCnt)
{
    string line;
    rCnt = 0;
    cCnt = 0;
    std::ifstream in(file); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
            rCnt++;
        istringstream lineReader(line);
        while (!lineReader.eof())
        {
            int tm;
            lineReader >> tm;
            cCnt++;
        }

        //rCnt--; cCnt--;
        m = new int* [rCnt];	   // Захват памяти для массива указателей
        for (int i = 0; i < rCnt; i++)	   // Захват памяти для элементов 
            *(m + i) = new int[cCnt];

        in.close();
        in.open(file);
        int i = 0;
        int  j = 0;
        while (getline(in, line))
        {
            istringstream lineReader(line);
            while (!lineReader.eof())
            {
                int n;
                lineReader >> n;
                m[i][j++] = n;
            }
            i++; j = 0;
        }
        return 1;
    }
    return 0;
}
int print_arr(int* X, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", X[i]);
    return 0;
}
// вывод двумерного массива
int print_arr(int** X, int n, int m)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        print_arr(X[i], m);
    return 0;
}