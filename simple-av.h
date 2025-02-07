#ifndef SIMPLE_AV_H
#define SIMPLE_AV_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    int32_t id;
    char name[256];
} Entry;

typedef struct {
    int32_t number_of_entries;
    int32_t capacity;
    Entry *entries;
} Database;

Database mk_database(int32_t capacity);
void destroy_database(Database db);
void show_database(Database db);

#endif