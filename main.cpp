#include "Model.h"
#include "UserInterface.h"

int main() {
    Model db;
    UserInterface *UI = new UserInterface(db);
    UI->menu();

    return 0;
}