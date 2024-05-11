#include <iostream>
#include <vector>


/*
Можно сказать классический вариант с быстрой сортировкой, где массив делится на подмассивы, в которых все элементы одного меньше всех другого
до тех пор пока не сузятся до единичных элементов.
Плохо что рекурсивно и в худшем случае (если отсортирован) будет O(n^2), а в среднем O(nlogn). Так же возможно переполнение стэка
*/
void quicksort(std::vector<int>& arr, int left, int right) {
    int left_ptr = left;
    int right_ptr = right;
    int mid_val = arr[(left + right) / 2];
    while (left_ptr <= right_ptr) {
        while (arr[left_ptr] < mid_val) {
            left_ptr++;
        }
        while (arr[right_ptr] > mid_val) {
            right_ptr--;
        }
        if (left_ptr <= right_ptr) {
            std::swap(arr[left_ptr], arr[right_ptr]);
            left_ptr++;
            right_ptr--;
        }
    }
    if (left < right_ptr) {
        quicksort(arr, left, right_ptr);
    }
    if (left_ptr < right) {
        quicksort(arr, left_ptr, right);
    }
}


/*
Ну и вариант сортировки слиянием: делим массив пополам, сортируем их слиянием и соединяем 
Каждый разделённый режем два  до тех пор, пока в каждом не окажется по одному элементу.
Тоже рекурсия, но в худшем случае так же как и в среднем будет O(nlogn)
*/
void mergesort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

/*
быстрее чем за O(nlogn) без начальных условий не представляю как можно отсортировать

Помимо представленных есть еще всякие introsort (с условием по глубине заполнения стека) и timsort (что-то про отсортированные подмассивы, вроде такой в питоне) которые в некоторых условиях быстрее,
но про них ничего не буду говорить, так как не сталкивался
*/