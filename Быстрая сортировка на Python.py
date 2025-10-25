def quick_sort(arr):
    """
    Основная функция быстрой сортировки Quicksort.
    """
    # Проверяем длину массива: если массив пуст или состоит из одного элемента,
    # то он уже отсортирован и возвращается как есть
    if len(arr) <= 1:
        return arr

    # Выбираем опорный элемент ("pivot"). В данном случае берем средний элемент массива
    pivot = arr[len(arr) // 2]

    # Формируем три новых списка:
    # 1. Элементы меньше опорного
    # 2. Элементы равные опорному
    # 3. Элементы больше опорного
    less_than_pivot = [x for x in arr if x < pivot]
    equal_to_pivot = [x for x in arr if x == pivot]
    greater_than_pivot = [x for x in arr if x > pivot]

    # Рекурсивно применяем быструю сортировку к двум частям (меньшим и большим),
    # затем соединяем отсортированные части вместе с элементами, равными опорному
    return quick_sort(less_than_pivot) + equal_to_pivot + quick_sort(greater_than_pivot)

# Пример использования
if __name__ == "__main__":
    unsorted_array = [3, 6, 8, 10, 1, 2, 1]
    print(f'Исходный массив: {unsorted_array}')

    sorted_array = quick_sort(unsorted_array)
    print(f'Отсортированный массив: {sorted_array}')
#Исходный массив: [3, 6, 8, 10, 1, 2, 1]
#Отсортированный массив: [1, 1, 2, 3, 6, 8, 10]