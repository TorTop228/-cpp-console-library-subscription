#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <sstream>

bool readMarathonData(const char* filename, MarathonResult* records, int& count) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    count = 0;
    std::string line;

    while (std::getline(file, line) && count < MAX_RECORDS) {
        std::stringstream ss(line);
        MarathonResult record;

        ss >> record.number
            >> record.lastName
            >> record.firstName
            >> record.middleName
            >> record.startTime
            >> record.finishTime;

        // Читаем клуб (может содержать пробелы)
        std::getline(ss, record.club);
        // Убираем лишний пробел в начале
        if (!record.club.empty() && record.club[0] == ' ') {
            record.club.erase(0, 1);
        }

        records[count] = record;
        count++;
    }

    file.close();
    return true;
}