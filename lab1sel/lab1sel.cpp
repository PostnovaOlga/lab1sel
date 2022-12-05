

#include <iostream>
template <typename T>
T peredv(T* arr, int t, int count) {
    T arr2[9];
    //создаём копию массива
    for (int i = 0; i < 9; i++) {
        arr2[i] = arr[i];
    }
    //числа до этого элемента сдвигаем вправо на 1
    //а сам минимальный элемент ставим вперёд, опираясь на номер шага (count)
    for (int i = count; i <= t; i++) {
        arr[i] = arr2[i - 1];
    }
    arr[count] = arr2[t];
    return *arr;
}


//реализация Selection Sort
template <typename T>
void Select(T array[]) {

    //выбираем наименьший элемент и отправляем в функцию "peredv" 3 параметра: 
    //массив, номер минимального элемента и номер шага, т.е. сколько чисел мы уже поставили на свои места до этого
    //идем ещё раз, пока не доходим до последнего элемента

    for (int t = 0; t < 9; t++) {
        int min = t;
        for (int i = t; i < 9; ++i) {
            if (array[min] >= array[i]) {
                min = i;

            }
        }
        peredv(array, min, t);
        //печать каждого этапа
        for (int i = 0; i < 9; ++i) {
            std::cout << array[i] << " ";

        }
        std::cout << " " << std::endl;
    }
    //печать итога
    for (int i = 0; i < 9; ++i) {
        std::cout << array[i] << " ";
    }
}
int main()
{ //работает и на int и на float
    float arr2[9] = { 6.7, 3.65, 4.0, 6.4, 24.66, 12.34, 3.67, 5.0, 2.3 };
    int arr[9] = { 4,5,3,2,5,1,54,43,12 };
    Select(arr2);
    Select(arr);
}
