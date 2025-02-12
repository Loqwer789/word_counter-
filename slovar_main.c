#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
#include "parser.h"


int main(int argc, char *argv[])
{
Dict  *dict = dict_create(argv[1], dict);
Parser *parser = parser_create(argv[1], dict);

parser_parse(parser);
dict_print(dict);

parser_destroy(parser);
dict_destroy(dict);
return 0;



}

