#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node_t
{
    float data;
    struct node_t *next;
};

struct stack_t
{
    struct node_t *head;
};

void push(struct stack_t *stack, float value)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));
    new_node->data = value;
    new_node->next = stack->head;
    stack->head = new_node;
}

float pop(struct stack_t *stack)
{
    float value = stack->head->data;
    struct node_t *old_head = stack->head;
    stack->head = stack->head->next;
    free(old_head);
    return value;
}

void sum(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a + b;
    push(stack, result);
}

void subtraction(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b - a;
    push(stack, result);
}

void multiply(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a * b;
    push(stack, result);
}

void divide(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b / a;
    push(stack, result);
}

void natural_log(struct stack_t *stack)
{
    float a, result = 0;
    a = (pop(stack));
    result = log(a);
    push(stack, result);
}

void log_base(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = (log(b) / log(a));
    push(stack, result);
}

void pi(struct stack_t *stack)
{
    push(stack, M_PI);
}

void e(struct stack_t *stack)
{
    push(stack, M_E);
}

int main()
{
    return 0;
}