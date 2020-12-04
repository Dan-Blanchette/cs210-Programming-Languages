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
%left '(' ')'
%nonassoc UMINUS

%type <dval> expression
%%
statement_list
    : statement '\n'
    | statement_list statement '\n'
    ;

statement
    : NAME '=' expression 
    { 
        char *constSym = $1->name;
        if (strcmp(constSym, "PI") != 0 && strcmp(constSym, "PHI") != 0)
        {        
            $1->value = $3; 
        }
        else
        {
            yyerror("assign to const");
        }
    }
    | expression { printf("= %g\n", $1); }
    ;

expression
    : expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { if ($3 == 0.0)
                                        yyerror("divide by zero");
                                  else 
                                        $$ = $1 / $3; 
                                }
    | '-' expression %prec UMINUS { $$ = -$2; }
    | '(' expression ')' { $$ = $2; }
    | NUMBER
    | NAME { $$ = $1->value; }
    ;

%%

struct sym * sym_lookup(char *s)
{
    if (s_ptr == NULL)
    {
        s_ptr = (struct sym *)malloc(sizeof(struct sym));
    }

    struct sym *og = s_ptr;
    struct sym *sp = s_ptr;

    if (sp->name == NULL)
    {
        struct sym *dyn =  (struct sym *)malloc(sizeof(struct sym));
        dyn->name = "PI";
        dyn->value = 3.14159;
        dyn->next = NULL;
        sp->name = "PHI";
        sp->value = 1.61803;
        sp->next = dyn;
        sp->length = 2;
    }

    while(1)
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
                        s_ptr = dyn;
                        og = s_ptr;
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
    }
    yyerror("Too many symbols");
    exit(-1);
    return NULL; /* unreachable */
}

