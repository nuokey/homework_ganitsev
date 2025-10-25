#include<iostream>


using std::cout;
using std::cin;
using std::endl;

// 2.1
void bin_float(float *n) {
    int *i = (int*) n;
    cout << "float: ";
    for(int j = 31; j >= 0; --j){
        cout << ((*i >> j) & 1);
        if (j == 31 || j == 23)
            cout << " ";
    }

    cout << endl << endl;
}
// value = (-1)^S × (1 + Mantissa) × 2^(Exp - 127)

// 2.2
void dva_chisla() {
    cout << "Числа, между которыми фатальная ошибка составляет 1.0: " << endl
    << "(1 + 0)*2^23 = " << (2<<23) << " и (1 + 2^-23)*2^23) = "<< ((2<<23)+1) << endl << endl;

    float x = 1.0f;
    while (x != (x+1.0f))
        x++;
    cout << "x0: A x > x0 -> x == x+1: " << static_cast<int>(x) << endl;
}

//ROW
//если бы ряд расходился, цикл был бы бесконечным
void row() {
    cout << endl << "Исследуем ряд:" << endl << endl;
    float sum = 0.0f;
    int n = 1;

    do{
        sum += 1.0f/n;
        ++n;
    } while(sum + (1.0f / n) != sum);
    cout << "Сумма ряда: " << sum << endl;
    cout << "Искомое число (задание - ряд):  " << 1.0f/n << ", c порядковым номером: " << n <<  endl << endl;

    sum = 0.0f;
    for (int i = 1; i <= n + 100; ++i) {
        sum += 1.0f / i;
    }
    cout << "Новая сумма (к+100): " << sum << endl;

    sum = 0.0f;
    for (int i = n + 100; i >= 1; --i) {
        sum += 1.0f / i;
    }
    cout << "Обратная сумма: " << sum << endl;
}

int main()
{
    float num;
    cin >> num;

    bin_float(&num);

    dva_chisla();

    cout << endl << endl;

    // 1.3
    cout << endl << "1.3" << endl << endl;
    cout << static_cast<bool>((0.1f + 0.1f)+0.5f == (0.1f + (0.1f+0.5f))) << endl;
    // Равенство не выполняется, так как 0.1 не может храниться под типом float без потерь точности, 
    // так как это число не представимо в виде степеней двойки
    // 0.1 + 0.1 = 0.200000002980232239, а 0.1 + 0.5 = 0.60000002384185791.
    // 0,100000001490116119+0.60000002384185791 != 0.200000002980232239 + 0.5
    
    row();

    return 0;
}