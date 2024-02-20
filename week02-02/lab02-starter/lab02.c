/* lab02.c - initial parsing implemenation */

#include "ntlang.h"

int main(int argc, char **argv) {
    struct scan_table_st scan_table;
    char *input;

    /* This first part is from lab01_start/scan2.c */
    
    if (argc != 2) {
        printf("Usage: lab02 <expression>\n");
        printf("  Example: lab02 \"1 + 2\"\n");
        exit(-1);
    }

    input = argv[1];

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input);
    scan_table_print(&scan_table);
    printf("\n");

    /* We will need some new scan functions to help the parser.
     *
     * struct scan_token_st *scan_table_get(struct scan_table_st *st, int i)
     * 
     * retrieves a token relative to the current position in the table,
     * which is initially 0. You can use negative numbers to get tokens
     * before the current position in the token table. Here is an example:
     */

    struct scan_token_st *tp;

    /* get the token at current (0) + 1 = 1 */
    tp = scan_table_get(&scan_table, 1);
    printf("The second token in scan_table:\n");
    scan_token_print(tp);
    printf("\n");

    /* The function
     * 
     * scan_table_accept(struct scan_table_st *st,
     *                   enum scan_token_enum tk_expected);
     *
     * match the expected token (tk_expected) with the token at the
     * current position. It returns true and increments the current
     * position by 1 if there is a match. Otherwise it returns false.
     */

    bool rv;
    rv = scan_table_accept(&scan_table, TK_MINUS);
    if (rv) {
        printf("The first token is a TK_MINUS\n");
    } else {
        printf("The first token is not a TK_MINUS\n");
    }
      
    rv = scan_table_accept(&scan_table, TK_INTLIT);
    if (rv) {
        printf("The first token is a TK_INTLIT\n");
        /* Since we accpted the token, to get it, we need to use -1 */
        tp = scan_table_get(&scan_table, -1);
        scan_token_print(tp);
    } else {
        printf("The first token is not a TK_INTLIT\n");
    }
    printf("\n");

    /* Parse tree construction manually */
    
    struct parse_node_st node1;
    struct parse_node_st node2;
    struct parse_node_st node3;

    node1.type = EX_INTVAL;
    node1.intval.value = 1;

    node2.type = EX_INTVAL;
    node2.intval.value = 2;

    node3.type = EX_OPER2;
    node3.oper2.oper = OP_PLUS;
    node3.oper2.left = &node1;
    node3.oper2.right = &node2;

    parse_tree_print(&node3);
    printf("\n");
    
    /* Parse tree construction from parse_table */
    struct parse_node_st *np1, *np2, *np3;
    struct parse_table_st parse_table;

    parse_table_init(&parse_table);

    np1 = parse_node_new(&parse_table);
    np1->type = EX_INTVAL;
    np1->intval.value = 1;

    np2 = parse_node_new(&parse_table);
    np2->type = EX_INTVAL;
    np2->intval.value = 1;

    np3 = parse_node_new(&parse_table);
    np3->type = EX_OPER2;
    np3->oper2.oper = OP_PLUS;
    np3->oper2.left = np1;
    np3->oper2.right = np2;

    parse_tree_print(np3);
    printf("\n");

    /* Parsing */
    struct parse_node_st *parse_tree;

    /* We need to rescan the input because we accepted a token above. */
    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input);

    parse_table_init(&parse_table);
    parse_tree = parse_program(&parse_table, &scan_table);
    parse_tree_print(parse_tree);

    return 0;
}
