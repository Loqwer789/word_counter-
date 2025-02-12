#ifndef PARSER_H
#define PARSER_H

#include "dict.h"

typedef struct Parser Parser;

Parser* parser_create(const char *filename, Dict *dict);
void parser_parse(Parser *parser);
void parser_destroy(Parser *parser);

#endif
