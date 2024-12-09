#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <iostream>

class ScheduleItem {
private:
    std::string subject, catalog, section, component, session, instructor;
    int units, totEnrl, capEnrl;

public:
    // Constructor with default parameters
    ScheduleItem(std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string sess = "", int u = 0, int tot = 0,
        int cap = 0, std::string instr = "")
        : subject(subj), catalog(cat), section(sec), component(comp), session(sess),
        units(u), totEnrl(tot), capEnrl(cap), instructor(instr) {}

    // Getters
    std::string getSubject() const { return subject; }
    std::string getCatalog() const { return catalog; }
    std::string getSection() const { return section; }
    std::string getComponent() const { return component; }
    std::string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotEnrl() const { return totEnrl; }
    int getCapEnrl() const { return capEnrl; }
    std::string getInstructor() const { return instructor; }

    // Overload operators
    bool operator==(const ScheduleItem& other) const {
        return (subject == other.subject && catalog == other.catalog && section == other.section);
    }

    bool operator!=(const ScheduleItem& other) const {
        return !(*this == other);
    }

    bool operator>=(const ScheduleItem& other) const {
        return (subject + catalog + section) >= (other.subject + other.catalog + other.section);
    }

    // Print function
    void print() const {
        std::cout << subject << "\t" << catalog << "\t" << section << "\t" << component << "\t"
            << session << "\t" << units << "\t" << totEnrl << "\t" << capEnrl << "\t"
            << instructor << std::endl;
    }
};

#endif
#pragma once
