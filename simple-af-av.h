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

#define Blocksize 50000
#define $1 (int8 * )
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

typedef char Dir[64];
typedef char File[32];

struct s_entry {
    Dir dir; 
    File  file; 
};

typedef struct s_entry Entry; 

struct s_database {
    Entry* entries;
    int32 cap;
    int32 num;
};

typedef struct s_database Database;

Database mkdatabase(int32);
void addto_database(Database, Entry);
void destroydb(Database);
void showdb(Database);

#endif