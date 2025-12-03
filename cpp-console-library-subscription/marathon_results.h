#pragma once
#ifndef MARATHON_RESULTS_H
#define MARATHON_RESULTS_H

#include <iostream>
#include <string>

struct MarathonResult {
    int number;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string startTime;
    std::string finishTime;
    std::string club;

    int getRaceTimeInSeconds() const;
    void print() const;
};

#endif