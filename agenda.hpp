#include <iostream>
#include <vector>
#include <fstream>
#include "date.hpp"
#include <random>


namespace agenda{
    struct Event
    {
        std::string ID,title,desc;
        date::Date begin,end;
    };
    
    struct Agenda{
        std::string title,desc;
        std::vector <Event> event;
    };
    extern bool isSaved;

    Agenda createEmptyAgenda();
    Agenda loadAgenda();
    void saveAgenda(const Agenda &agenda);
    void printAgenda(const Agenda &agenda);
    void printNextTenEvents(const Agenda &agenda);
    void addEvent(Agenda &agenda);
    void delEvent(Agenda &agenda);
}


