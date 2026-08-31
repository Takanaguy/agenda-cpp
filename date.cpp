#include "date.hpp"

bool date::isLeap(const date::Date &d){
    if ((d.y%4==0 && d.y%100!=0) || d.y%400==0){
        return true;
    }
    else{
        return false;
    }
}

bool date::checkDate(const date::Date &date){
    if (date.m<1||date.m>12||date.d<1||date.d>31){
        return false;
    }
    if (date.m==2){
        if(isLeap(date)){
            return date.d<=29;
        } else{
            return date.d<=28;
        }
    }
    if(date.m==4||date.m==6 ||date.m==9||date.m==11){
        return date.d<=30;
    }
    else{
        return date.d<=31;
    }
}

bool date::checkDate(const date::Date &date1,const date::Date &date2){
    if (date1.y != date2.y){
        return date1.y > date2.y;
    }
    if (date1.m != date2.m){
        return date1.m > date2.m;
    }
    if (date1.d != date2.d){
        return date1.d > date2.d;
    }
    return true;
}

void date::inputDate(date::Date &date){
    std::cout<<"Donne moi une Date sous la forme jour mois annee (separes par des espaces)"<<std::endl;
    std::cout<<"vas y mon gars :"<<std::endl;
    std::cin>>date.d>>date.m>>date.y;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Entree invalide, tape uniquement des nombres separes par des espaces." << std::endl;
        inputDate(date);
        return;
    }

    std::cout<<"tu as choisi cette date"<<date.d<<"/"<<date.m<<"/"<<date.y<<std::endl;
    if (!checkDate(date)) {
        std::cout << "Date invalide, recommencez." << std::endl;
        inputDate(date);
    }
}
