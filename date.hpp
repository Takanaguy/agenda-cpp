#include <iostream>

namespace date{
    struct Date{
        unsigned int d,m,y;   
    };
    bool isLeap(const Date &d);
    bool checkDate(const Date &date); //verif si la date existe
    bool checkDate(const Date &date1,const Date &date2); //compare 2 dates entre elle
    void inputDate(Date &d);

    
}