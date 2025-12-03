#include "marathon_results.h"
#include <iomanip>
#include <sstream>

int MarathonResult::getRaceTimeInSeconds() const {
    int startHours, startMinutes, startSeconds;
    int finishHours, finishMinutes, finishSeconds;
    char colon;

    std::stringstream ssStart(startTime);
    ssStart >> startHours >> colon >> startMinutes >> colon >> startSeconds;

    std::stringstream ssFinish(finishTime);
    ssFinish >> finishHours >> colon >> finishMinutes >> colon >> finishSeconds;

    int startTotal = startHours * 3600 + startMinutes * 60 + startSeconds;
    int finishTotal = finishHours * 3600 + finishMinutes * 60 + finishSeconds;

    return finishTotal - startTotal;
}

void MarathonResult::print() const {
    std::cout << std::setw(3) << number << ". "
        << lastName << " "
        << firstName << " "
        << middleName << ", "
        << "Start: " << startTime << ", "
        << "Finish: " << finishTime << ", "
        << "Club: " << club << std::endl;
}