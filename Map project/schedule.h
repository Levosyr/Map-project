#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "scheduleItem.h"
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

    // Helper function to generate a unique key for each record
    std::string generateKey(const std::string& subject, const std::string& catalog, const std::string& section) {
        return subject + "_" + catalog + "_" + section;
    }

public:
    // Initialize the schedule by reading the .csv file
    void initSchedule(std::ifstream& file) {
        std::string line;
        std::getline(file, line); // Skip the header line

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string subject, catalog, section, component, session, instructor;
            int units = 0, totEnrl = 0, capEnrl = 0;

            // Parse required fields
            std::getline(ss, subject, ',');
            std::getline(ss, catalog, ',');
            std::getline(ss, section, ',');
            std::getline(ss, component, ',');
            std::getline(ss, session, ',');
            ss >> units;
            ss.ignore(1, ',');
            ss >> totEnrl;
            ss.ignore(1, ',');
            ss >> capEnrl;
            ss.ignore(1, ',');

            // Skip 3 fields after CapEnrl
            std::string temp;
            for (int i = 0; i < 3; ++i) {
                std::getline(ss, temp, ',');
            }

            // Read the Instructor field
            std::getline(ss, instructor, ',');

            // Remove extra quotes from the instructor field if present
            if (!instructor.empty() && instructor.front() == '"' && instructor.back() == '"') {
                instructor = instructor.substr(1, instructor.size() - 2);
            }

            // Debugging output (optional)
            // std::cout << "Instructor: " << instructor << std::endl;

            // Add the parsed data to the map
            ScheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            scheduleMap[generateKey(subject, catalog, section)] = item;
        }
    }

    // Print the entire schedule
    void print() const {
        std::cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor\n";
        for (const auto& [key, item] : scheduleMap) {
            item.print();
        }
    }

    // Find records by subject
    void findBySubject(const std::string& subject) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getSubject() == subject) {
                item.print();
            }
        }
    }

    // Find records by subject and catalog
    void findBySubjectCatalog(const std::string& subject, const std::string& catalog) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getSubject() == subject && item.getCatalog() == catalog) {
                item.print();
            }
        }
    }

    // Find records by instructor's last name
    void findByInstructor(const std::string& lastName) const {
        for (const auto& [key, item] : scheduleMap) {
            if (item.getInstructor().find(lastName) != std::string::npos) {
                item.print();
            }
        }
    }
};

#endif
