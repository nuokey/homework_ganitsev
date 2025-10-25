#include <iostream>

using std::min;

struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

void init(subvector *qv) {
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
}

bool resize(subvector *qv) {
    // if (new_capacity == 0) {
    //     // Если новая capacity = 0, освобождаем память
    //     delete[] qv->mas;
    //     qv->mas = nullptr;
    //     qv->capacity = 0;
    //     qv->top = 0;
    //     return true;
    // }
    
    // Создаем новый массив
    int *new_mas = new int[qv->capacity*2];
    
    // Копируем существующие элементы
    unsigned int elements_to_copy = min(qv->top, qv->capacity*2);
    for (unsigned int i = 0; i < elements_to_copy; i++) {
        new_mas[i] = qv->mas[i];
    }
    
    // Освобождаем старую память
    delete[] qv->mas;
    
    // Обновляем поля структуры
    qv->mas = new_mas;
    qv->capacity *= 2;
    qv->top = elements_to_copy;
    
    return true;
}

void push_back(subvector *qv, int d) {
    // Если места нет, нужно увеличить capacity
    if (qv->top == qv->capacity) {
        // Если capacity = 0, устанавливаем начальный размер 1
        resize(qv);
    }
    
    qv->mas[qv->top] = d;
    qv->top++;
}

int pop_back(subvector *qv) {
    if (qv->top == 0) {
        return 0;
    }
    
    qv->top--;
    return qv->mas[qv->top];
}



void shrink_to_fit(subvector *qv) {
    if (qv->top == 0) {
        // Если нет элементов, освобождаем всю память
        delete[] qv->mas;
        qv->mas = nullptr;
        qv->capacity = 0;
    } else if (qv->top < qv->capacity) {
        // Создаем новый массив точно под размер данных
        int *new_mas = new int[qv->top];
        
        // Копируем данные
        for (unsigned int i = 0; i < qv->top; i++) {
            new_mas[i] = qv->mas[i];
        }
        
        // Освобождаем старую память и обновляем указатель
        delete[] qv->mas;
        qv->mas = new_mas;
        qv->capacity = qv->top;
    }
}

void clear(subvector *qv) {
    qv->top = 0;
}

void destructor(subvector *qv) {
    delete[] qv->mas;
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
}

// Вспомогательная функция для тестирования
void print_subvector(subvector *qv) {
    std::cout << "Capacity: " << qv->capacity << ", Top: " << qv->top << ", Elements: ";
    for (unsigned int i = 0; i < qv->top; i++) {
        std::cout << qv->mas[i] << " ";
    }
    std::cout << std::endl;
}

// Пример использования
int main() {
    subvector sv;
    
    init(&sv);
    std::cout << "After init: ";
    print_subvector(&sv);
    
    // Добавляем элементы
    for (int i = 1; i <= 5; i++) {
        push_back(&sv, i * 10);
        std::cout << "After push_back(" << i * 10 << "): ";
        print_subvector(&sv);
    }
    
    // Удаляем элементы
    std::cout << "Popped: " << pop_back(&sv) << std::endl;
    print_subvector(&sv);
    
    // Очищаем содержимое
    clear(&sv);
    std::cout << "After clear: ";
    print_subvector(&sv);
    
    // Освобождаем память
    destructor(&sv);
    
    return 0;
}