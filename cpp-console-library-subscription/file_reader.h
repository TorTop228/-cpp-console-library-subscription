#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "marathon_results.h"

bool readMarathonData(const char* filename, MarathonResult* records, int& count);

#endif