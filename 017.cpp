#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    // �ڴ˴�������Ĵ���
    int row, col;//�к���
    int** parr;//�洢����
public:
    //��ζ�̬���ٶ�ά����
    Array2(int r, int c)
    {
        row = r;
        col = c;
        parr = new int* [r];
        for (int i = 0; i < r; i++)
        {
            parr[i] = new int[c];
        }
    }
    int* operator[](int i)
    {
        return parr[i];
    }
    int& operator()(int i, int j)
    {
        return parr[i][j];
    }
    Array2()
    {
        row = 0;
        col = 0;
        parr = NULL;
    }
    //���ٿռ�
    ~Array2()
    {
        for (i = 0; i < row; i++)
        {
            delete[]parr[i];
            parr[i] = NULL;
        }
        delete[]parr;
        parr = NULL;
    }
    
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}