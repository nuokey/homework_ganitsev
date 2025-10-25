#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//1.1
void bin_signed(int *n){
    int size = 32;
    cout << "Signed bin: " << endl;
    for(int i = size-1; i >= 0; --i)
        cout << ((*n >> i) & 1);
    cout << endl << endl;
};
// двоичное представление знакового 32-битного целого числа
// Выводит число int со старшего бита до младшего

//1.2
void bin_unsigned(unsigned *n){
    int size = 32;
    cout << "Unsigned bin: " << endl;
    for(int i = size-1; i >= 0; --i)
        cout << ((*n >> i) & 1);
    cout << endl << endl;
};

//1.3
void opaopa(){
    int x = __INT_MAX__;
    cout << "__INT_MAX__ + 1" << endl;
    cout << __INT_MAX__ + 1 << endl;

    int size = 32;
    cout << "Выводим __INT_MAX__ побитово:" << endl;
    for(int i = size-1; i >= 0; --i)
        cout << ((x >> i) & 1);
    cout << endl << "Так как первый бит в int отвечает за знак, при попытке прибавить к числу единицу, мы получаем число 10000...0" << endl
    << "И это число соответствует наименьшему числу из представимых int-" << endl << endl;



    cout << "Проведем похожий тест, но с unsigned int" << endl << endl;
    unsigned x1 = __UINT32_MAX__;
    unsigned zero = 0;
    cout << "Выведем 0-1:" << endl;
    cout << zero - 1 << endl;
    cout << "Теперь __UINT32_MAX__+1" << endl;
    cout << __UINT32_MAX__+1 << endl;
    cout << "__UINT32_MAX__ побитово:" << endl;
    for(int i = size-1; i >= 0; --i)
        cout << ((x1 >> i) & 1);
    cout << endl << "Здесь все просто: __UINT32_MAX__ представляет собой 111...1 => если прибавить к нему еще единицу, число станет равным 1000...0" << endl
    << "А так как эта единица не уместится в памяти, число обнулится" << endl;
};


int main(){
    int num;
    cout << "Signed int: ";
    cin >> num;

    bin_signed(&num);

    unsigned num1;
    cout << "Unsigned int: ";
    cin >> num1;

    bin_unsigned(&num1);

    cin >> num1;

    opaopa();

    return 0;
}