#include "marathon_results.h"
#include <iomanip>
#include <sstream>

using namespace std;  

// Вычисление времени забега в секундах
int MarathonResult::getRaceTimeInSeconds() const {
    int startHours, startMinutes, startSeconds;
    int finishHours, finishMinutes, finishSeconds;
    char colon;

    stringstream ssStart(startTime);
    ssStart >> startHours >> colon >> startMinutes >> colon >> startSeconds;

    stringstream ssFinish(finishTime);
    ssFinish >> finishHours >> colon >> finishMinutes >> colon >> finishSeconds;

    int startTotal = startHours * 3600 + startMinutes * 60 + startSeconds;
    int finishTotal = finishHours * 3600 + finishMinutes * 60 + finishSeconds;

    return finishTotal - startTotal;
}

// Форматированный вывод
void MarathonResult::print() const {
    cout << setw(3) << number << ". "
        << lastName << " "
        << firstName << " "
        << middleName << ", "
        << "Start: " << startTime << ", "
        << "Finish: " << finishTime << ", "
        << "Club: " << club << endl;
}