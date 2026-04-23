#ifndef HEAD_H
#define HEAD_H


#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>


#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"


#define SUCCESS 1
#define FAILURE 0
#define DUPLICATE -1
#define FULL 2


typedef struct node    // structure to store file
{
    char file[30];
    struct node*link;
}Flist;

typedef struct subnode    // structure to sub data
{
    int count;
    char fname[30];
    struct subnode*snext;
}Slist;

typedef struct mnode    // structure to main data
{
   int fcount;
   char word[30];
   Slist*slink;
   struct mnode*next; 
}Mlist;


typedef struct hnode    // structure to store data according priority
{
    int index;
    Mlist*link;
}Hlist;


void valid(int argc,char** argv,Flist**head);

int insert_last(Flist**,const char *);

void print(Flist*);

int create_database(Flist*,Hlist*);

int get_index(char ch);

int insert_word(Hlist*,char *,char *);

int findsub(Mlist**,char*);

void Display(Hlist*);

void Save(Hlist*,char*);

int fv(char*,Flist**,Flist**);

void search(char*name,Hlist*);


#endif