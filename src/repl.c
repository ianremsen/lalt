#include "repl.h"

static char buffer[2048];

int lalt_repl() {
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Symbol = mpc_new("symbol");
    mpc_parser_t* Sexpr  = mpc_new("sexpr");
    mpc_parser_t* Expr   = mpc_new("expr");
    mpc_parser_t* Lalt   = mpc_new("Lalt");

    mpca_lang(MPCA_LANG_DEFAULT,
        "                                    \
    number : /-?[0-9]+/ ;                    \
    symbol : '+' | '-' | '*' | '/' ;         \
    sexpr  : '(' <expr>* ')' ;               \
    expr   : <number> | <symbol> | <sexpr> ; \
    Lalt  : /^/ <expr>* /$/ ;                \
    ", Number, Symbol, Sexpr, Expr, Lalt);

    puts("Press ^C to Exit\n");
    while (1) {
        char* input = readline("Lalt> ");
        add_history(input);
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lalt, &r)) {
            lval* x = lval_eval(lval_read(r.output));
            lval_println(x);
            lval_del(x);
            mpc_ast_delete(r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    mpc_cleanup(5, Number, Symbol, Sexpr, Expr, Lalt);

    return 0;
}
