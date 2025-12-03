#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "marathon_results.h"

// Основная функция фильтрации
MarathonResult** filterMarathonResults(
    MarathonResult* array[],
    int size,
    bool (*check)(MarathonResult* element),
    int& result_size
);

// Функция-предикат 1: проверка клуба "Spartak"
bool isFromClubSpartak(MarathonResult* element);

// Функция-предикат 2: проверка времени лучше 2:50:00
bool hasResultBetterThanThreshold(MarathonResult* element);

#endif