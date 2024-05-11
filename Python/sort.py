# В целом все аналогично CPP варианту

# Быстрая сортировка
def quicksort(arr, left, right):
    left_ptr = left
    right_ptr = right
    mid_val = arr[(left + right) // 2]
    while left_ptr <= right_ptr:
        while arr[left_ptr] < mid_val:
            left_ptr += 1
        while arr[right_ptr] > mid_val:
            right_ptr -= 1
        if left_ptr <= right_ptr:
            arr[left_ptr], arr[right_ptr] = arr[right_ptr], arr[left_ptr]
            left_ptr += 1
            right_ptr -= 1
    if left < right_ptr:
        quicksort(arr, left, right_ptr)
    if left_ptr < right:
        quicksort(arr, left_ptr, right)

# Сортировка слиянием
def mergesort(arr, left, right):
    if left >= right:
        return
    mid = (left + right) // 2
    mergesort(arr, left, mid)
    mergesort(arr, mid + 1, right)
    merge(arr, left, mid, right)

def merge(arr, left, mid, right):
    temp = [0] * (right - left + 1)
    i = left
    j = mid + 1
    k = 0
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1
    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1
    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1
    for i in range(left, right + 1):
        arr[i] = temp[i - left]
