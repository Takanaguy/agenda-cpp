#include <iostream>
#include "menu.hpp"

int main(int argc, char const *argv[]) {
    agenda::Agenda agenda;
    menu::launch(agenda);
    return EXIT_SUCCESS;
}