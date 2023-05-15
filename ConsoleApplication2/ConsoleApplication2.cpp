#include <iostream>

using namespace std;

void merge(int*, int, int, int);

void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        //разделим массив посередине и отсортируем независимо, используя сортировку слиянием
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //объединим отсортированные массивы
        merge(arr, low, high, mid);
    }
}
// Сортировка слиянием 

void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
// считывание входного массива и вызов mergesort

int main()
{
    setlocale(LC_ALL, "Russian");

    int myarray[30], num;
    int w, sum = 0;
    cout << "Введите количество элементов, которое необходимо сложить: ";
    cin >> w;
    cout << "Вводите элементы: ";

    for (int i = 0; i < w; i++) {
        cin >> myarray[i];
        sum = sum + myarray[i];
    }
    cout << "Сумма: " << sum << endl;

    cout << "Введите число элментов, которые необходимо отсортировать:";
    cin >> num;
    cout << "Введите " << num << " элемента/ов, которые необходимо отсортировать:";

    for (int i = 0; i < num; i++) {
        cin >> myarray[i];
    }

    merge_sort(myarray, 0, num - 1);
    cout << "Отсортированный массив: ";

    for (int i = 0; i < num; i++)
    {
        cout << myarray[i] << "\t";

    }

}