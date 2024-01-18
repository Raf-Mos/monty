#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*opcode_func)(stack_t **, unsigned int);

/*file operations*/
void opener(char *file);
int splitter(char *str, int line_num, int format);
void reader(FILE *);
int length_char(FILE *);
void func_finder(char *opcode, char *value, int line_num, int format);

/*Stack operations*/
stack_t *create_new_node(int n);
void free_nodes(void);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void addtoqueue(stack_t **, unsigned int);

void func_caller(opcode_func, char *, char *, int, int);

void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_top_nodes(stack_t **, unsigned int);
void sub_top_nodes(stack_t **, unsigned int);
void div_top_nodes(stack_t **, unsigned int);
void mul_top_nodes(stack_t **, unsigned int);
void mod_top_nodes(stack_t **, unsigned int);

/*String operations*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err_func1(int err_code, ...);
void err_func2(int err_code, ...);
void string_err_func(int err_code, ...);
void rotr(stack_t **, unsigned int);

#endif
