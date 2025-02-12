#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

struct Dict {
    Node *head;
};

Dict* dict_create() {
    Dict *dict = malloc(sizeof(Dict));
    dict->head = NULL;
    return dict;
}

void dict_add_word(Dict *dict, const char *word) {
    Node *current = dict->head;
    while (current) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = dict->head;
    dict->head = new_node;
}

void dict_print(Dict *dict) {
    Node *current = dict->head;
    while (current) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void dict_destroy(Dict *dict) {
    Node *current = dict->head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
    free(dict);
}