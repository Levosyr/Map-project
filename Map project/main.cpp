#include "schedule.h"
#include <iostream>
#include <fstream>

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Print Schedule\n";
    std::cout << "2. Find by Subject\n";
    std::cout << "3. Find by Subject and Catalog\n";
    std::cout << "4. Find by Instructor Last Name\n";
    std::cout << "5. Quit\n";
}

int main() {
    Schedule schedule;

    // Open data file
    std::ifstream file("STEM - Summer 2022 Schedule of Classes as of 05-02-22(1).csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    // Initialize schedule
    schedule.initSchedule(file);
    file.close();

    // Menu loop
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.print();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter subject and catalog: ";
            std::cin >> subject >> catalog;
            schedule.findBySubjectCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter instructor's last name: ";
            std::cin >> lastName;
            schedule.findByInstructor(lastName);
            break;
        }
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
