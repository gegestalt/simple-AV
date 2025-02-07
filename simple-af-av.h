#ifndef SIMPLE_AF_AV_H
#define SIMPLE_AF_AV_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

typedef int8 Dir[64];
typedef int8 File[32];

struct s_entry {
    Dir* dir; 
    File* file; 
};

typedef struct s_entry Entry; 

struct s_database {
    Entry* entries;
    int16 cap;
    int16 num;
};

typedef struct s_database Database;

Database mkdatabase(int16);
void addtodb(Database, Entry);
void destroydb(Database);
void showdb(Database);

#endif