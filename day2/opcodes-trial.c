#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_ops(char opstring[], int opcodes[]);
int execute_opcode(int position, int ops[]);
int execute_addition(int position, int ops[]);
int execute_multiplication(int position, int ops[]);

int main(int argc, char* argv[]) {
    char* nounc;
    char* verbc;
    char* opstring;
    int noun;
    int verb;
    int position = 0;
    int* opcodes = NULL;
    int len = 0;

    nounc = argv[1];
    verbc = argv[2];
    opstring = argv[3];
    noun = atoi(nounc);
    verb = atoi(verbc);
    len = strlen(opstring);
    opcodes = (int*)malloc(len * sizeof(int));
    parse_ops(opstring, opcodes);
    opcodes[1] = noun;
    opcodes[2] = verb;
    while ((position = execute_opcode(position, opcodes)) != -1);
    printf("%d\n", opcodes[0]);
    free(opcodes);
}

int parse_ops(char opstring[], int opcodes[]) {
    char* str = NULL;
    char* delim = ",";
    int position = 0;
    int opcode = 0;

    while ((str = strtok(opstring, delim)) != NULL) {
        opstring = NULL; /* Subsequent calls should be NULL */
        opcode = atoi(str);
        opcodes[position] = opcode;
        position++;
    }
    return position;
}

int execute_opcode(int position, int ops[]) {
    int opcode = -1;
    
    opcode = ops[position];
    switch (opcode) {
        case 1:
            return execute_addition(position, ops);
        case 2:
            return execute_multiplication(position, ops);
        case 99:
            return -1;
        default:
            exit(1);
    }
}

int execute_addition(int position, int ops[]) {
    int first = 0;
    int second = 0;
    int sum_position = 0;
    int sum = 0;
    
    first = ops[ops[position + 1]];
    second = ops[ops[position + 2]];
    sum_position = ops[position + 3];
    sum = first + second;
    ops[sum_position] = sum;
    return position + 4;
}

int execute_multiplication(int position, int ops[]) {
    int first = 0;
    int second = 0;
    int prod_position = 0;
    int product = 0;
    
    first = ops[ops[position + 1]];
    second = ops[ops[position + 2]];
    prod_position = ops[position + 3];
    product = first * second;
    ops[prod_position] = product;
    return position + 4;
}
