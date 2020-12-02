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
%token PI PHI
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
    char * p;
    struct sym *sp;

    for (sp=sym_tbl; sp < &sym_tbl[NSYMS]; sp++)
    {
        if (sp->name && strcmp(sp->name, s) == 0)
            return sp;
        if (sp->name)
            continue;

        sp->name = strdup(s);
        return sp; 
    }
   
    yyerror("Too many symbols");
    exit(-1);
    return NULL; /* unreachable */
}

