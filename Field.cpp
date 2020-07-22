// Field.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Arrays.h"

int main()
{ 
    int** m = NULL;
    int rCnt, cCnt;
    load2DArray("fld.txt", m, rCnt, cCnt);
   print_arr(m, rCnt, cCnt);
   return 0;
}


