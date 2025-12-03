#pragma once
#ifndef SORTER_H
#define SORTER_H

#include "marathon_results.h"

// Прототипы функций сортировки
void bubbleSort(MarathonResult* array[], int size, int (*compare)(MarathonResult*, MarathonResult*));
void quickSort(MarathonResult* array[], int size, int (*compare)(MarathonResult*, MarathonResult*));

// Прототипы функций сравнения
int compareByRaceTime(MarathonResult* a, MarathonResult* b);
int compareByClubAndLastName(MarathonResult* a, MarathonResult* b);

#endif
