/* scan2.c - a scanner based on scan1.c with intlit and whitespace support */

#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

# Scanner EBNF (microsyntax)

tokens ::= (token)*
token  ::= intlit | symbol
symbol ::= '+' | '-' | '*' | '/'
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
    TK_MULT,   /* * */
    TK_DIV,    /* / */
    TK_EOT,    /* end of text */
};

char *scan_token_strings[] = {
    "TK_INTLIT",
    "TK_PLUS",
    "TK_MINUS",
    "TK_MULT",
    "TK_DIV",
    "TK_EOT"
};

struct scan_token_st {
    enum scan_token_enum id;
    char value[SCAN_TOKEN_LEN];
};

struct scan_table_st {
    struct scan_token_st table[SCAN_TABLE_LEN];
    int len;
};

void scan_table_init(struct scan_table_st *st) {
    st->len = 0;
}

void scan_token_print(struct scan_token_st *tp) {
    printf("%s(\"%s\")\n", scan_token_strings[tp->id], tp->value);
}

void scan_table_print(struct scan_table_st *st) {
    int i;

    for (i = 0; i < st->len; i++) {
        scan_token_print(&st->table[i]);
    }
}

struct scan_token_st * scan_table_new_token(struct scan_table_st *st) {
    /* Allocate a new token from the token table */
    /* We just return a pointer to the next avaiable token in the array. */
    struct scan_token_st *tp;

    tp = &(st->table[st->len]);
    st->len += 1;

    return tp;
}

bool scan_is_whitespace(char ch) {
    return (ch == ' ') || (ch == '\t');
}

char * scan_whitespace(char *p, char *end) {
    while(scan_is_whitespace(*p) && (p < end)) {
        p += 1;
    }
    return p;
}

bool scan_is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

char * scan_intlit(char *p, char *end, struct scan_token_st *tp) {
    int i = 0;

    while (scan_is_digit(*p) && (p < end)) {
        tp->value[i] = *p;
        p += 1;
        i += 1;
    }
    tp->value[i] = '\0';
    tp->id = TK_INTLIT;

    return p;
}

char * scan_token_helper(struct scan_token_st *tp, char *p, int len,
                       enum scan_token_enum id) {
    /* Read a token starting a p for len characters.
       Update the given token with the token string and token id. */
    int i;

    tp->id = id;
    for (i = 0; i < len; i++) {
        tp->value[i] = *p;
        p += 1;
    }
    tp->value[i] = '\0';
    return p;
}

char * scan_token(char *p, char *end, struct scan_token_st *tp) {
    /* Scan the next token at the current location in the input string */
    /* p points to the current location in the input string */
    /* end is a pointer to the end of the string */
    /* The return value is the updated location in the input string. */
    /* The token pointed to by tp is updated with the scanned token. */

    if (p == end) {
        /* Check if we are at the end of the input string */
        tp->value[0] = '\0';
        tp->id = TK_EOT;
    } else if (scan_is_whitespace(*p)) {
        /* Ingore whitespace. Notice the recursive call. */
        p = scan_whitespace(p, end);
        p = scan_token(p, end, tp);
    } else if (scan_is_digit(*p)) {
        p = scan_intlit(p, end, tp);        
    } else if (*p == '+') {
        p = scan_token_helper(tp, p, 1, TK_PLUS);
    } else if (*p == '-') {
        p = scan_token_helper(tp, p, 1, TK_MINUS);
    } else if (*p == '*') {
        p = scan_token_helper(tp, p, 1, TK_MULT);
    } else if (*p == '/') {
        p = scan_token_helper(tp, p, 1, TK_DIV);
    } else {
        /* Instead of returning an error code, we will usually
           exit on failure. */
        printf("scan error: invalid char: %c\n", *p);
        exit(-1);
    }
    return p;
}

void scan_table_scan(struct scan_table_st *st, char *input) {
    struct scan_token_st *tp;
    char *p = input;
    char *end;
    int len;

    /* Get a pointer to the end of the input string. */
    /* Technically this pointer points to the null termination character. */
    len = strnlen(input, SCAN_INPUT_LEN);
    end = p + len;

    do {
        /* Allocate a token */
        tp = scan_table_new_token(st);
        /* Scan one token from input string */
        p = scan_token(p, end, tp);
        /* Are we done? */
        if (tp->id == TK_EOT) {
            break;
       }
    } while(true);
}

int main(int argc, char **argv) {
    struct scan_table_st scan_table;
    char *input;

    if (argc != 2) {
        printf("Usage: scan <expression>\n");
        printf("  Example: scan \"1 + 2\"\n");
        exit(-1);
    }

    input = argv[1];

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input);
    scan_table_print(&scan_table);

    return 0;
}
