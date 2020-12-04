// Dan Blanchette
// cs210 
// Dr.Rinker
// 12-3-2020
%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "sym.h"
%}
%{
int yylex(void);
void yyerror(const char *s);
%}
%union {
    double dval;
    struct sym *symptr;
}

%token <symptr> NAME
%token <dval> NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression
%%
statement_list
    : statement '\n'
    | statement_list statement '\n'
    ;

statement
    :
    | NAME '=' expression 
    { 
        char *constSym = $1->name;
    if (strcmp(constSym, "PI") != 0 && strcmp(constSym, "PHI") != 0){        
            $1->value = $3; 
        } else {
            yyerror("assign to const");
        }
    }
    | expression { printf("= %g\n", $1); }
    ;

expression
    : expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { 
        if ($3 == 0) {
            yyerror("divide by zero");
        } else {
            $$ = $1 / $3;
        }
    }
    | '-' expression %prec UMINUS { $$ = -$2; }
    | '(' expression ')' { $$ = $2; }
    | NUMBER
    | NAME { $$ = $1->value; }
    ;

%%

struct sym * sym_lookup(char *s)
{
    if (head == NULL)
    {
        head = (struct sym *)malloc(sizeof(struct sym));
    }

    struct sym *og = head;
    struct sym *sp = head;

    if (sp->name == NULL)
    {
        // dynamically allocate a linked list
        struct sym *dyn =  (struct sym *)malloc(sizeof(struct sym));
        // define PI as the tail entry for the linked list
        dyn->name = "PI";
        dyn->value = 3.14159;
        dyn->next = NULL;
        // PHI is the new head of the linked list
        sp->name = "PHI";
        sp->value = 1.61803;
        sp->next = dyn;
        sp->length = 2;
    }

    do
    {
        if (sp->name == NULL)
        {
            sp->name = strdup(s);
            sp->next = NULL;
            return sp;
        }
        else if (strcmp(sp->name, s) == 0)
        {
            return sp;
        }
        else if (sp->next != NULL)
        {
            sp = sp->next;
        }
        else
        {
            struct sym *dyn = (struct sym *)malloc(sizeof(struct sym));
            dyn->name = strdup(s);
            sp = og;
            struct sym *oPtr = NULL;

            while (1)
            {
                if (strcmp(sp->name, s) > 0)
                {
                    if ( oPtr == NULL)
                    {
                        dyn->next = og;
                        dyn->length = og->length;
                        head = dyn;
                        og = head;
                        sp = og;
                    }
                    else
                    {
                        oPtr->next = dyn;
                        dyn->next = sp;
                    }
                    break;
                }
                else
                {
                    if (sp->next != NULL)
                    {
                        oPtr = sp;
                        sp = sp->next;
                    }
                    else
                    {
                        sp->next = dyn;
                        break;
                    }
                }
            }
            sp = og;
            sp->length++;
            return dyn;
        }
    } while(1);
    // yyerror("Too many symbols");
    // exit(-1);
    // return NULL; /* unreachable */
}
// Print out the linked list
void symInv()
{
    struct sym *sp = head;
    printf("num-syms: %d\n", sp->length);
    int j;
    int length = sp->length;
    for ( j = 0; j < length; j++ )
    {
        printf("\t%s => %g\n", sp->name, sp->value);
        sp = sp->next;
    }
}
