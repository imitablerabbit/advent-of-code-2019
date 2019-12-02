#include <stdio.h>
#include <stdlib.h>

int fuel(int mass);

int main(int argc, char* argv[]) {
    int mass;
    int requiredFuel;
    int totalFuel;
    
    mass = atoi(argv[1]);
    while ((requiredFuel = fuel(mass)) > 0) {
        totalFuel += requiredFuel;
        mass = requiredFuel;
    }
    printf("%d\n", totalFuel);
}

int fuel(int mass) {
    return (mass / 3) - 2;
}
