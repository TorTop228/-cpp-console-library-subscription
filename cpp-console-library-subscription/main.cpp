#include <iostream>
#include "marathon_results.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

using namespace std;

void printMenu() {
    cout << "\n=== Menu ===\n";
    cout << "1. Show all records\n";
    cout << "2. Filter: Show only Spartak club members\n";
    cout << "3. Filter: Show results better than 2:50:00\n";
    cout << "4. Exit\n";
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
    MarathonResult records[MAX_RECORDS];
    int count = 0;

    if (!readMarathonData("data.txt", records, count)) {
        cout << "Error reading file!\n";
        return 1;
    }

    cout << "Successfully read " << count << " records.\n";

    // Создаём массив указателей для фильтрации
    MarathonResult* recordPointers[MAX_RECORDS];
    for (int i = 0; i < count; i++) {
        recordPointers[i] = &records[i];
    }

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

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}