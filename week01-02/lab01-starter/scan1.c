/* scan1.c - a simple scanner for the tokens (+, -, *, /) */

/* stdbool.h lets us use the values ture and false */
#include <stdbool.h> 
/* stdio.h is needed for common standard C lib functions like printf() */
#include <stdio.h>
/* stdlib.h is needed for exit() */
#include <stdlib.h>
/* string.h is need for strnlen() and other string functions */
#include <string.h>

/* 

# Scanner EBNF (microsyntax)

tokens ::= (symbol)*
symbol ::= '+' | '-' | '*' | '/'

*/

/* You should not embed constant literals in your code. */
/* A convention in C is to use macros for these constants. */

/* The maximum size for an individual token string */
#define SCAN_TOKEN_LEN 32
/* The maximum number of tokens in a table */
#define SCAN_TABLE_LEN 1024
/* The maximum size for input text */
#define SCAN_INPUT_LEN 4096

/* An enum allows you to use symbolic names instead of numbers for a type. */
/* By default, TK_PLUS will be 0, TK_MINUS will be 1, etc. */
/* Don't forget the semicolon at the end. */
enum scan_token_enum {
    TK_PLUS,   /* + */
    TK_MINUS,  /* - */
    TK_MULT,   /* * */
    TK_DIV,    /* / */
    TK_EOT,    /* end of text */
};

/* This array allows us to map enum values to string values for printing. */
/* You need to make sure that order of the strings match the order of the */
/* enums in defined above. */
char *scan_token_strings[] = {
    "TK_PLUS",
    "TK_MINUS",
    "TK_MULT",
    "TK_DIV",
    "TK_EOT"
};

/* C structs need a name and then the fields with types and names */
/* Don't forget the semicolon at the end. */
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
    } else if (*p == '+') {
        tp->value[0] = *p;
        tp->value[1] = '\0';
        tp->id = TK_PLUS;
        p += 1;
    } else if (*p == '-') {
        tp->value[0] = *p;
        tp->value[1] = '\0';
        tp->id = TK_MINUS;
        p += 1;
    } else if (*p == '*') {
        tp->value[0] = *p;
        tp->value[1] = '\0';
        tp->id = TK_MULT;
        p += 1;
    } else if (*p == '/') {
        tp->value[0] = *p;
        tp->value[1] = '\0';
        tp->id = TK_DIV;
        p += 1;
    } else {
        /* Instead of returning an error code, we will usually
           exit on failure. */
        printf("scan error: invalid char\n");
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
    char *input1 = "+-+";

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input1);
    scan_table_print(&scan_table);
    printf("\n");

    char *input2 = "+-*/";
    
    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input2);
    scan_table_print(&scan_table);

    return 0;
}
