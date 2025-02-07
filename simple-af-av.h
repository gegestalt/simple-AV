#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>


typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $8 (int8 *)
#define $6 (int16)
#define $2 (int32)
#define $4 (int64)
#define $c (char * )
#define $i (int)


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
int main(int, char**);

