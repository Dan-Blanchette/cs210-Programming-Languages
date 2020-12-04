#ifndef SYMTBL_H
#define SYMTBL_H

// #define NSYMS   (500)

struct sym 
{
    int length;
    char * name;
    double value;
    struct sym *prev;
    struct sym *next;
} ;
// sym_tbl[NSYMS];
struct sym *head;
struct sym * sym_lookup(char *);
void symInv();

#endif /* SYMTBL_H */
