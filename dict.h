#ifndef DICT_H
#define DICT_H

typedef struct Dict Dict;

Dict* dict_create();
void dict_add_word(Dict *dict, const char *word);
void dict_print(Dict * dict);
void dict_destroy(Dict *dict);

#endif
