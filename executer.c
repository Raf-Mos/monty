#include"monty.h"

/**
 * executer - executes opcodes
 * @string: contents of file
 * @stack: the list
 * Return: void
 */
 
void executer(char *string[], stack_t *stack)
{
    int line_num, i, j;
    char *cmd;
    
    instruction_t st[] = {
        {"pall", pall},
        {"pint", pint},
        {"add", add},
        {"swap", swap},
        {"null", NULL}
    };
    
    cmd = splitter(string[]);
    for (line_num = 1, i = 0; cmd[i]; i++, line_num++)
    {
        if (_strcmp("push", cmd[i]) == 0)
            push(&stack, line_num, pushint(cmd[i], line_num));
        else if (_strcmp("nop", cmd[i]) == 0)
            ;
        else
        {
            j = 0;
            while (_strcmp(st[j].opcode, "null") != 0)
            {
                if (_strcmp(st[j].opcode, cmd[i]) == 0)
                {
                    st[j].f(&stack, line_num);
                    break;
                }
                j++;
            }
            if (_strcmp(st[j].opcode, "null") == 0 && _strcmp(cmd[i], "\n") != 0)
            {
                fprintf(stderr, "L%d: unknown instruction %s", line_num, cmd[i]);
                if (!num_line_finder(cmd[i]))
                    fprintf(stderr, "\n");
                    exit(EXIT_FAILLURE);
            }
        }
    }
    freed_stack(stack);
}
