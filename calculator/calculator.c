#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../linkstack/linkstack.h"
#define MAX_EXP_LEN 1000
#define MAX_NUM_STR_LEN 100
#define PRIORITY_ADD 1
#define PRIORITY_SUBTRACT 1
#define PRIORITY_MULTIPLY 2
#define PRIORITY_DIVIDE 2
#define PRIORITY_POWER 3
#define OPERATION_ADD '+'
#define OPERATION_SUBTRACT '-'
#define OPERATION_MULTIPLY '*'
#define OPERATION_DIVIDE '/'
#define OPERATION_POWER '^'
#define OPEN_PARENTHESIS '('
#define CLOUSE_PARENTHESIS ')'

typedef enum TokenType
{
    FINAL,
    OPERATION,
    NUMBER,
} TokenType;

union TokenValue
{
    char operation;
    double number;
};

typedef struct Token
{
    union TokenValue token_value;
    TokenType type;
} Token;

char *s_gets(char *s, int n);
void split_token(Token *token_middle[], const char *str);
double parse_number(const char *str);
void middle2before(Token *token_middle[], Token *token_before[]);
void middle2after(Token *token_middle[], Token *token_after[]);
double calculate_before(Token *token_before[]);
double calculate_after(Token *token_before[]);
void show_tokens(Token *token_list[]);
void trim(const char *str, char *trimed_s);
bool is_operation(char ch);
void free_tokens(Token *token_middle[]);
int get_priority_of_operation(char op);

int main(int argc, char const *argv[])
{
    char exp[MAX_EXP_LEN];
    s_gets(exp, MAX_EXP_LEN);
    Token *token_middle[MAX_EXP_LEN];
    Token *token_before[MAX_EXP_LEN];
    Token *token_after[MAX_EXP_LEN];
    split_token(token_middle, exp);
    printf("middle: ");
    show_tokens(token_middle);
    printf("\n");
    // TODO
    middle2after(token_middle, token_after);
    printf("after: ");
    show_tokens(token_after);
    printf("\n");

    printf("value: %.2lf\n",
           calculate_after(token_after));

    free_tokens(token_middle);
    return 0;
}

char *s_gets(char *s, int n)
{
    char *result = fgets(s, n, stdin);
    if (result)
    {
        char *ch;
        if (ch = strchr(s, '\n'))
        {
            *ch = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return result;
}

void trim(const char *str, char *trimed_s)
{
    int count = 0;
    while (*str)
    {
        if (*str != ' ')
        {
            trimed_s[count] = *str;
            count++;
        }
        str++;
    }
    trimed_s[count] = '\0';
}

bool is_operation(char ch)
{
    return (ch == OPERATION_ADD ||
            ch == OPERATION_SUBTRACT ||
            ch == OPERATION_MULTIPLY ||
            ch == OPERATION_DIVIDE ||
            ch == OPERATION_POWER ||
            ch == OPEN_PARENTHESIS ||
            ch == CLOUSE_PARENTHESIS)
               ? true
               : false;
}

int get_priority_of_operation(char op)
{
    int priority;
    switch (op)
    {
    case OPERATION_ADD:
        priority = PRIORITY_ADD;
        break;
    case OPERATION_SUBTRACT:
        priority = PRIORITY_SUBTRACT;
        break;
    case OPERATION_MULTIPLY:
        priority = PRIORITY_MULTIPLY;
        break;
    case OPERATION_DIVIDE:
        priority = PRIORITY_DIVIDE;
        break;
    case OPERATION_POWER:
        priority = PRIORITY_POWER;
        break;

    default:
        exit(EXIT_FAILURE);
        break;
    }
    return priority;
}

void split_token(Token *token_middle[], const char *s)
{
    char *str = (char *)malloc(strlen(s) + 1);
    char *str_origin = str;
    trim(s, str);
    int token_index = 0;
    while (*str)
    {
        Token *token = (Token *)malloc(sizeof(Token));
        // meet operation char
        if (is_operation(*str))
        {
            token->type = OPERATION;
            switch (*str)
            {
            case OPERATION_ADD:
                token->token_value.operation = OPERATION_ADD;
                break;
            case OPERATION_SUBTRACT:
                token->token_value.operation = OPERATION_SUBTRACT;
                break;
            case OPERATION_MULTIPLY:
                token->token_value.operation = OPERATION_MULTIPLY;
                break;
            case OPERATION_DIVIDE:
                token->token_value.operation = OPERATION_DIVIDE;
                break;
            case OPERATION_POWER:
                token->token_value.operation = OPERATION_POWER;
                break;
            case OPEN_PARENTHESIS:
                token->token_value.operation = OPEN_PARENTHESIS;
                break;
            case CLOUSE_PARENTHESIS:
                token->token_value.operation = CLOUSE_PARENTHESIS;
                break;
            }
            str++;
        }
        // meet number char
        else
        {
            int token_len = 0;
            char token_number_s[MAX_NUM_STR_LEN];
            while (!is_operation(*str) && *str)
            {
                token_number_s[token_len] = *str;
                token_len++;
                str++;
                if (token_len > MAX_NUM_STR_LEN - 1)
                {
                    printf("ERROR: value should less than %d char\n", MAX_NUM_STR_LEN);
                    exit(EXIT_FAILURE);
                }
            }
            token_number_s[token_len] = '\0';
            token->type = NUMBER;
            token->token_value.number = parse_number(token_number_s);
        }
        token_middle[token_index] = token;
        token_index++;
    }
    Token *token_final = (Token *)malloc(sizeof(Token));
    token_final->type = FINAL;
    token_middle[token_index] = token_final;
    free(str_origin);
}

double parse_number(const char *str)
{
    double num;
    sscanf(str, "%lf", &num);
    return num;
}

void middle2before(Token *token_middle[], Token *token_before[])
{
}

void middle2after(Token *token_middle[], Token *token_after[])
{
    LinkStack s;
    InitLinkStack(&s);
    int top;
    int middle_count = 0;
    int after_count = 0;
    Token **token_middle_origin = token_middle;
    while ((**token_middle).type != FINAL)
    {
        if ((**token_middle).type == NUMBER)
        {
            token_after[after_count] = *token_middle;
            after_count++;
        }
        else if ((**token_middle).type == OPERATION)
        {
            while (LinkStackLength(s) > 0)
            {
                if (LinkStackPop(&s, &top) == OK &&
                    get_priority_of_operation((*(token_middle_origin[top])).token_value.operation) >=
                        get_priority_of_operation((**token_middle).token_value.operation))
                {
                    token_after[after_count] = token_middle_origin[top];
                    after_count++;
                }
                else
                {
                    LinkStackPush(&s, top);
                    break;
                }
            }
            LinkStackPush(&s, middle_count);
        }
        middle_count++;
        token_middle++;
    }
    while (LinkStackLength(s) > 0)
    {
        LinkStackPop(&s, &top);
        token_after[after_count] = token_middle_origin[top];
        after_count++;
    }
    token_after[after_count] = *token_middle;
}

double calculate_before(Token *token_before[])
{
}

double calculate_after(Token *token_after[])
{
    Token **token_after_origin = token_after;
    LinkStack s;
    InitLinkStack(&s);
    int top;
    int after_count = 0;
    double values[MAX_EXP_LEN];
    int value_count = 0;
    while ((**token_after).type != FINAL)
    {
        if ((**token_after).type == NUMBER)
        {
            values[value_count] = (**token_after).token_value.number;
        }
        value_count++;
        token_after++;
    }
    token_after = token_after_origin;
    while ((**token_after).type != FINAL)
    {
        if ((**token_after).type == NUMBER)
        {
            LinkStackPush(&s, after_count);
        }
        else if ((**token_after).type == OPERATION)
        {
            int a, b;
            switch ((**token_after).token_value.operation)
            {
            case OPERATION_ADD:
                LinkStackPop(&s, &top);
                b = top;
                LinkStackPop(&s, &top);
                a = top;
                values[a] += values[b];
                LinkStackPush(&s, a);
                break;
            case OPERATION_SUBTRACT:
                LinkStackPop(&s, &top);
                b = top;
                LinkStackPop(&s, &top);
                a = top;
                values[a] -= values[b];
                LinkStackPush(&s, a);
                break;
            case OPERATION_MULTIPLY:
                LinkStackPop(&s, &top);
                b = top;
                LinkStackPop(&s, &top);
                a = top;
                values[a] *= values[b];
                LinkStackPush(&s, a);
                break;
            case OPERATION_DIVIDE:
                LinkStackPop(&s, &top);
                b = top;
                LinkStackPop(&s, &top);
                a = top;
                values[a] /= values[b];
                LinkStackPush(&s, a);
                break;
            case OPERATION_POWER:
                LinkStackPop(&s, &top);
                b = top;
                LinkStackPop(&s, &top);
                a = top;
                values[a] = pow(values[a], values[b]);
                LinkStackPush(&s, a);
                break;
            default:
                break;
            }
        }

        token_after++;
        after_count++;
    }
    LinkStackPop(&s, &top);
    return values[top];
}

void show_tokens(Token *token_list[])
{
    int count = 0;
    while ((**token_list).type != FINAL)
    {
        if (count)
            printf(" ");
        if ((**token_list).type == OPERATION)
        {
            printf("%c", (**token_list).token_value.operation);
        }
        else
        {
            printf("%.2lf", (**token_list).token_value.number);
        }
        token_list++;
        count++;
    }
}

void free_tokens(Token *token_list[])
{
    int count = 0;
    while ((**token_list).type != FINAL)
    {
        free(*token_list);
        token_list++;
        count++;
    }

    printf("free %d tokens\n", count);
}
