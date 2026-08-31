#include "agenda.hpp"

namespace agenda {
    bool isSaved = false;
}

std::string getUID(std::size_t len) {
    std::vector<char> x = {'0','1','2','3','4','5','6','7','8','9',
                            'a','b','c','d','e','f'};
    std::string uid(len, '\0');

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, x.size()-1);

    for (char& c : uid) {
        c = x[dis(gen)];
    }
    return uid;
}

agenda::Agenda agenda::createEmptyAgenda(){
    agenda::Agenda agenda;
    std::cout<<"Titre de l'agenda:";
    std::getline(std::cin, agenda.title);
    std::cout<<"Description de l'agenda:";
    std::getline(std::cin, agenda.desc);
    return agenda;
}

std::istream& loadEvent(std::istream &i, agenda::Event &ev) {
    std::string dateTemp; //
    std::getline(i, ev.ID);
    std::getline(i, ev.title);
    std::getline(i, ev.desc);

    std::getline(i, dateTemp, '/');
    ev.begin.d = std::stoul(dateTemp);
    std::getline(i, dateTemp, '/');
    ev.begin.m = std::stoul(dateTemp);
    std::getline(i, dateTemp);
    ev.begin.y = std::stoul(dateTemp);

    std::getline(i,dateTemp,'/');
    ev.end.d = std::stoul(dateTemp);
    std::getline(i, dateTemp, '/');
    ev.end.m = std::stoul(dateTemp);
    std::getline(i, dateTemp);
    ev.end.y = std::stoul(dateTemp);

    return i;
}

agenda::Agenda agenda::loadAgenda() {
    agenda::Agenda agenda;
    std::string fileName;
    size_t numberOfLines = 0;
    size_t numberOfEvents = 0;

    std::cout << "Nom du fichier Agenda a ouvrir (.raccoon) : ";
    std::getline(std::cin, fileName);
    fileName.append(".raccoon");

    std::ifstream agendaFile;
    agendaFile.open(fileName, std::ios::in);
    if (!agendaFile.is_open()) {
        std::cout << "Erreur a l'ouverture du fichier " << fileName << std::endl;
        return agenda;
    }

    std::string dummy;
    while (std::getline(agendaFile, dummy)) { 
        ++numberOfLines;
    }
    numberOfEvents = (numberOfLines - 2) / 5;

    agendaFile.clear(); 
    agendaFile.seekg(0);

   
    std::getline(agendaFile, agenda.title);
    std::getline(agendaFile, agenda.desc);

    for(size_t i = 0;i<numberOfEvents;i++){
        agenda::Event ev;
        loadEvent(agendaFile,ev);
        agenda.event.push_back(ev);

    }

    agenda::isSaved = true;
    return agenda;
}

std::ostream& saveEvent(std::ostream &os,agenda::Event &ev){
    os << ev.ID << std::endl
       << ev.title << std::endl
       << ev.desc << std::endl
       << ev.begin.d << "/" << ev.begin.m << "/" << ev.begin.y << std::endl
       << ev.end.d << "/" << ev.end.m << "/" << ev.end.y << std::endl;
    return os;
}
 void agenda::saveAgenda(const agenda::Agenda &agenda) {
    std::string fileName;
    std::cout << "Nom du fichier Agenda a sauver : ";
    std::getline(std::cin, fileName); 
    fileName.append(".raccoon");

    std::ofstream agendaFile;
    agendaFile.open(fileName, std::ios::out);

    
    agendaFile << agenda.title << std::endl
               << agenda.desc << std::endl;

    for (agenda::Event ev : agenda.event) {
        saveEvent(agendaFile, ev);
    }


    agenda::isSaved = true;
}

void printEvent(const agenda::Event &ev) {
    std::cout << "ID de l'evenement : " << ev.ID << std::endl
               << "Nom de l'evenement : " << ev.title << std::endl
               << "Description de l'evenement : " << ev.desc << std::endl
               << "Date de debut de l'evenement : " << ev.begin.d << "/" << ev.begin.m << "/" << ev.begin.y << std::endl
               << "Date de fin de l'evenement : " << ev.end.d << "/" << ev.end.m << "/" << ev.end.y << std::endl;
}

void agenda::printAgenda(const agenda::Agenda &agenda){
    std::cout<<"Le titre"<<agenda.title<<std::endl
    <<"Description"<<agenda.desc<<std::endl;
    if (agenda.event.empty()) {
        std::cout << "L'agenda est vide." << std::endl;
    } else {
        for (const agenda::Event &ev : agenda.event) {
            printEvent(ev);
            std::cout << std::endl; 
        }
    }    
}
void agenda::printNextTenEvents(const agenda::Agenda &agenda) {
    date::Date userDate;
    std::cout << "Entrez la date souhaitee : " << std::endl;
    date::inputDate(userDate);

    size_t counter = 0;
    for (agenda::Event ev : agenda.event) {
        if (counter > 9 || counter > agenda.event.size())
            break;

        // ETAPE : si date::checkDate(ev.begin, userDate) est vrai,
        //         appelle printEvent(ev) et incremente counter
        if (date::checkDate(ev.begin, userDate)) {
            printEvent(ev);
            counter++;
        }
    }

}

void agenda::addEvent(agenda::Agenda &agenda) {
    agenda::Event ev;
    ev.ID = getUID(10);

    std::cout << "Nom de l'evenement : ";
    std::getline(std::cin, ev.title);

    std::cout << "Description de l'evenement : ";
    std::getline(std::cin, ev.desc);

    std::cout << "Date de debut de l'evenement : " << std::endl;
    date::inputDate(ev.begin);
    std::cout << "Date de fin de l'evenement : " << std::endl;
    date::inputDate(ev.end);

    while (!date::checkDate(ev.end, ev.begin)) {
        std::cout << "La date de fin de l'evenement doit etre la meme ou apres la date de debut." << std::endl;
        std::cout << "Reessayez." << std::endl;
        date::inputDate(ev.end);
    }

    agenda.event.push_back(ev);
    agenda::isSaved = false;
}

void agenda::delEvent(agenda::Agenda &agenda) {
    std::string delID;
    std::cout << "ID de l'evenement a supprimer : ";
    std::getline(std::cin, delID);

    unsigned int counter = 0;
    for (agenda::Event ev : agenda.event) {
        if (ev.ID == delID)
            agenda.event.erase(agenda.event.begin() + counter);
        ++counter;
    }
    agenda::isSaved = false;
}