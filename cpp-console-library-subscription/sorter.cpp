#include "sorter.h"
#include <string>

// ========== Bubble Sort ==========
void bubbleSort(MarathonResult* array[], int size, int (*compare)(MarathonResult*, MarathonResult*)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(array[j], array[j + 1]) > 0) {
                MarathonResult* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// ========== Quick Sort ==========
void quickSortRecursive(MarathonResult* array[], int left, int right, int (*compare)(MarathonResult*, MarathonResult*)) {
    if (left >= right) return;

    int i = left, j = right;
    MarathonResult* pivot = array[(left + right) / 2];

    while (i <= j) {
        while (compare(array[i], pivot) < 0) i++;
        while (compare(array[j], pivot) > 0) j--;

        if (i <= j) {
            MarathonResult* temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSortRecursive(array, left, j, compare);
    if (i < right) quickSortRecursive(array, i, right, compare);
}

void quickSort(MarathonResult* array[], int size, int (*compare)(MarathonResult*, MarathonResult*)) {
    quickSortRecursive(array, 0, size - 1, compare);
}

// ========== Функции сравнения ==========

// 1. По времени забега (по возрастанию)
int compareByRaceTime(MarathonResult* a, MarathonResult* b) {
    int timeA = a->getRaceTimeInSeconds();
    int timeB = b->getRaceTimeInSeconds();
    return timeA - timeB; // если < 0, то a лучше (быстрее)
}

// 2. По названию клуба, а затем по фамилии (по возрастанию)
int compareByClubAndLastName(MarathonResult* a, MarathonResult* b) {
    // Сравниваем клубы
    int clubCompare = a->club.compare(b->club);
    if (clubCompare != 0) {
        return clubCompare;
    }
    // Если клубы одинаковые, сравниваем фамилии
    return a->lastName.compare(b->lastName);
}