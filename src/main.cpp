#include "Simulation.h"
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Simulation sim;
    sim.run(15); 
    return 0;
}