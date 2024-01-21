#ifndef OPCODES_H
#define OPCODES_H

#include "monty.h"

int data_element;
char **command;
int stack_len(stack_t *head);
void push(stack_t **topp, unsigned int cmd_line);
void pall(stack_t **topp, unsigned int cmd_line);
void pint(stack_t **topp, unsigned int cmd_line);
void pop(stack_t **topp, unsigned int cmd_line);
void nop(stack_t **topp, unsigned int cmd_line);
void swap(stack_t **topp, unsigned int cmd_line);
void add(stack_t **topp, unsigned int cmd_line);
void sub(stack_t **topp, unsigned int cmd_line);
void divi(stack_t **topp, unsigned int cmd_line);
void mull(stack_t **topp, unsigned int cmd_line);
void mode(stack_t **topp, unsigned int cmd_line);
#endif
