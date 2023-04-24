#include "Data.h"

Data::Data() {
    string jobTitles[] = {"Proger", "Data-scientist", "DevOps", "Povar", "LoL",
                          "Backpack"};
    jobTitle = jobTitles[rand() % 6];
    workingHoursCount = rand() % 13;
    productivityRate = rand() % 11;
}