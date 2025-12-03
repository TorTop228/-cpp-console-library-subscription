#include <iostream>
#include "marathon_results.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sorter.h"

using namespace std;

const int LOCAL_MAX_RECORDS = 100; 

void printMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Show all records\n";
    cout << "2. Filter: Show only Spartak club members\n";
    cout << "3. Filter: Show results better than 2:50:00\n";
    cout << "4. Sort records\n";
    cout << "5. Exit\n";
    cout << "Choice: ";
}

void printSortMenu() {
    cout << "\n=== Sorting ===\n";
    cout << "Select sorting method:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Choice: ";
}

void printCompareMenu() {
    cout << "\nSelect sorting criteria:\n";
    cout << "1. By race time (ascending)\n";
    cout << "2. By club and last name (ascending)\n";
    cout << "Choice: ";
}

int main()
{
    cout << "========================================\n";
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #1. Marathon Results\n";
    cout << "Author: Artem Razumov\n";
    cout << "Group: P3210\n";
    cout << "========================================\n\n";

    // Чтение данных
    MarathonResult records[LOCAL_MAX_RECORDS];  
    int count = 0;

    if (!readMarathonData("data.txt", records, count)) {
        cout << "Error reading file!\n";
        return 1;
    }

    cout << "Successfully read " << count << " records.\n";

    // Создаём массив указателей для операций
    MarathonResult* recordPointers[LOCAL_MAX_RECORDS];  
    for (int i = 0; i < count; i++) {
        recordPointers[i] = &records[i];
    }

    // Массивы указателей на функции
    void (*sortFunctions[])(MarathonResult * [], int, int (*)(MarathonResult*, MarathonResult*)) = {
        bubbleSort,
        quickSort
    };

    int (*compareFunctions[])(MarathonResult*, MarathonResult*) = {
        compareByRaceTime,
        compareByClubAndLastName
    };

    // Главное меню
    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Все записи
            cout << "\nAll records (" << count << "):\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < count; i++) {
                records[i].print();
            }
            break;

        case 2: // Фильтр Spartak
        {
            int filteredCount;
            MarathonResult** filtered = filterMarathonResults(
                recordPointers, count, isFromClubSpartak, filteredCount
            );

            cout << "\nSpartak club members (" << filteredCount << "):\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < filteredCount; i++) {
                filtered[i]->print();
            }

            delete[] filtered;
        }
        break;

        case 3: // Фильтр по времени
        {
            int filteredCount;
            MarathonResult** filtered = filterMarathonResults(
                recordPointers, count, hasResultBetterThanThreshold, filteredCount
            );

            cout << "\nResults better than " << THRESHOLD_TIME << " (" << filteredCount << "):\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < filteredCount; i++) {
                filtered[i]->print();
            }

            delete[] filtered;
        }
        break;

        case 4: // Сортировка
        {
            int sortChoice, compareChoice;

            printSortMenu();
            cin >> sortChoice;

            printCompareMenu();
            cin >> compareChoice;

            if (sortChoice < 1 || sortChoice > 2 || compareChoice < 1 || compareChoice > 2) {
                cout << "Invalid choice!\n";
                break;
            }

            // Создаём копию массива указателей для сортировки
            MarathonResult* sortArray[LOCAL_MAX_RECORDS]; 
            for (int i = 0; i < count; i++) {
                sortArray[i] = recordPointers[i];
            }

            // Вызываем выбранную функцию сортировки с выбранной функцией сравнения
            sortFunctions[sortChoice - 1](sortArray, count, compareFunctions[compareChoice - 1]);

            cout << "\nSorted records (" << count << "):\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < count; i++) {
                sortArray[i]->print();
            }
        }
        break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}