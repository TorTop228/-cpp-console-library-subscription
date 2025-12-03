#include "filter.h"
#include "constants.h"
#include <iostream>

// Основная функция фильтрации
MarathonResult** filterMarathonResults(
    MarathonResult* array[],
    int size,
    bool (*check)(MarathonResult* element),
    int& result_size
) {
    // Сначала подсчитаем, сколько элементов подходит
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            count++;
        }
    }

    // Создаём массив указателей
    MarathonResult** result = new MarathonResult * [count];

    // Заполняем массив
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            result[index] = array[i];
            index++;
        }
    }

    result_size = count;
    return result;
}

// Проверка: участник из клуба "Spartak"
bool isFromClubSpartak(MarathonResult* element) {
    return element->club == TARGET_CLUB;
}

// Проверка: результат лучше 2:50:00
bool hasResultBetterThanThreshold(MarathonResult* element) {
    int raceTime = element->getRaceTimeInSeconds();

    // Преобразуем пороговое время "02:50:00" в секунды
    int thresholdHours, thresholdMinutes, thresholdSeconds;
    char colon;
    std::stringstream ss(THRESHOLD_TIME);
    ss >> thresholdHours >> colon >> thresholdMinutes >> colon >> thresholdSeconds;
    int thresholdTotal = thresholdHours * 3600 + thresholdMinutes * 60 + thresholdSeconds;

    return raceTime < thresholdTotal;  // лучше = меньше времени
}