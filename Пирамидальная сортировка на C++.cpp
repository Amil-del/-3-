#include <iostream>
#include <vector>
using namespace std;

// Функция для построения max-кучи (heapify)
void heapify(vector<int>& arr, int n, int i) {
    // Инициализация наибольшего элемента как корня текущего поддерева
    int largest = i;   // Индекс текущего узла
    int left = 2 * i + 1;  // Левый дочерний узел
    int right = 2 * i + 2; // Правый дочерний узел

    // Проверяем существует ли левый дочерний элемент и больше ли он текущего корня
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // Проверяем существует ли правый дочерний элемент и больше ли он текущего корня
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент изменился, меняем местами корень и наибольший элемент
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Меняем элементы местами

        // Рекурсивно применяем heapify к затронутому поддереву
        heapify(arr, n, largest);
    }
}

// Основная функция для выполнения пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Строим max-кучу (перестраиваем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);  // Применяем heapify ко всем родительским узлам

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (максимальный элемент) в конец массива
        swap(arr[0], arr[i]);
        
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Вспомогательная функция для вывода отсортированного массива
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    // Пример использования
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Исходный массив: ";
    printArray(arr);

    heapSort(arr);  // Сортируем массив методом пирамидальной сортировки

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}

//Исходный массив: 12 11 13 5 6 7 
//Отсортированный массив: 5 6 7 11 12 13 