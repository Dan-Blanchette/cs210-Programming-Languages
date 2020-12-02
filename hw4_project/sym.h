#ifndef SYMTBL_H
#define SYMTBL_H

#define NSYMS   (500)

struct sym {
    int length;
    char * name;
    double value;
    struct sym *prev;
    struct sym *next;

} sym_tbl[NSYMS];

struct sym *sym_list;
struct sym * sym_lookup(char *);
void symbol_inventory();

#endif /* SYMTBL_H */
