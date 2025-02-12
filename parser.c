#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Parser {
    FILE *file;
    Dict *dict;
};

Parser* parser_create(const char *filename, Dict *dict) {
    Parser *parser = malloc(sizeof(Parser));
    parser->file = fopen(filename, "r");
    if (!parser->file) {
        free(parser);
        return NULL;
    }
    parser->dict = dict;
    return parser;
}

void parser_parse(Parser *parser) {
    char line[1024];
    const char *delimiters = " \t\n\r\f\v.,;:!?()\"'";
    
    while (fgets(line, sizeof(line), parser->file)) {
        char *token = strtok(line, delimiters);
        while (token) {
            if (*token != '\0') {
                dict_add_word(parser->dict, token);
            }
            token = strtok(NULL, delimiters);
        }
    }
}

void parser_destroy(Parser *parser) {
    if (parser) {
        if (parser->file) fclose(parser->file);
        free(parser);
    }
}