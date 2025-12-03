#include <iostream>
#include "marathon_results.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{
    cout << "========================================\n";
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #1. Marathon Results\n";
    cout << "Author: Artem Razumov\n";
    cout << "Group: P3210\n";  
    cout << "========================================\n\n";

    MarathonResult records[MAX_RECORDS];
    int count = 0;

    if (readMarathonData("data.txt", records, count)) {
        cout << "Successfully read " << count << " records:\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < count; i++) {
            records[i].print();
        }
        cout << "----------------------------------------\n";
    }
    else {
        cout << "Error reading file!\n";
    }

    return 0;
}