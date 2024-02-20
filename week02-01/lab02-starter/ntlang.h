/* ntlang.h - header file for Project02 (ntlang) */

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * scan.c
 */
 
/* 

# Scanner EBNF (microsyntax)

tokens ::= (token)*
token  ::= intlit | symbol
symbol ::= '+' | '-'
intlit ::= digit (digit)*
digit  ::= '0' | '1' | ... | '9'

# Ignore

whitespace ::= (' ' | '\t') (' ' | '\t')*

*/

#define SCAN_TOKEN_LEN 32
#define SCAN_TABLE_LEN 1024
#define SCAN_INPUT_LEN 4096

enum scan_token_enum {
    TK_INTLIT, /* 1, 22, 403 */
    TK_PLUS,   /* + */
    TK_MINUS,  /* - */
    TK_EOT,    /* end of text */
    TK_ANY,    /* A wildcard token used for parsing */
};

#define SCAN_TOKEN_STRINGS {\
    "TK_INTLIT",\
    "TK_PLUS",\
    "TK_MINUS",\
    "TK_EOT",\
    "TK_ANY"\
};

struct scan_token_st {
    enum scan_token_enum id;
    char value[SCAN_TOKEN_LEN];
};

struct scan_table_st {
    struct scan_token_st table[SCAN_TABLE_LEN];
    int len;
    int cur;
};

void scan_token_print(struct scan_token_st *tk);
void scan_table_init(struct scan_table_st *st);
void scan_table_scan(struct scan_table_st *st, char *input);
void scan_table_print(struct scan_table_st *st);

struct scan_token_st * scan_table_get(struct scan_table_st *st, int i);
bool scan_table_accept(struct scan_table_st *st, enum scan_token_enum tk_expected);

/*
 * parse.c
 */

 /*
 A simple grammar for the ntlang langauge

# Parser

program    ::= expression EOT
expression ::= operand (operator operand)*
operand    ::= intlit

operator   ::= '+' | '-'
*/

enum parse_expr_enum {EX_INTVAL, EX_OPER1, EX_OPER2};
enum parse_oper_enum {OP_PLUS, OP_MINUS, OP_MULT, OP_DIV};

struct parse_node_st {
    enum parse_expr_enum type;
    union {
        struct {int value;} intval;
        struct {enum parse_oper_enum oper;
                struct parse_node_st *operand;} oper1;
        struct {enum parse_oper_enum oper;
                struct parse_node_st *left;
                struct parse_node_st *right;} oper2;
    };
};


#define PARSE_TABLE_LEN 1024

/* The parse_table_st is similar to the scan_table_st and is
 * used to allocatio parse_node_st structs so we can avoid
 * heap allocation.
 */
struct parse_table_st {
    struct parse_node_st table[PARSE_TABLE_LEN];
    int len;
};

void parse_table_init(struct parse_table_st *pt);
struct parse_node_st * parse_node_new(struct parse_table_st *pt);
struct parse_node_st * parse_program(struct parse_table_st *pt,
                                        struct scan_table_st *st);
void parse_tree_print(struct parse_node_st *np);
