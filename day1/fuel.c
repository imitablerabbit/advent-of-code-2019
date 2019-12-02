#include <stdio.h>
#include <stdlib.h>

int fuel(int mass);

int main(int argc, char* argv[]) {
    int mass;
    int requiredFuel;
    
    mass = atoi(argv[1]);
    requiredFuel = fuel(mass);
    printf("%d\n", requiredFuel);
}

int fuel(int mass) {
    return (mass / 3) - 2;
}
