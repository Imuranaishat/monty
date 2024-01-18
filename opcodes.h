#ifndef OPCODES_H
#define OPCODES_H

#include "monty.h"

int data_element;
void push(stack_t **topp, unsigned int cmd_line);
void pall(stack_t **topp, unsigned int cmd_line);
void pint(stack_t **topp, unsigned int cmd_line);
void pop(stack_t **topp, unsigned int cmd_line);
void nop(stack_t **topp, unsigned int cmd_line);
#endif
