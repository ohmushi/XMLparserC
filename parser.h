//
// Created by Théo Omnès on 13/05/2021.
//
#include <stdint.h>

#ifndef XMLPARSER_PARSER_H
#define XMLPARSER_PARSER_H

typedef struct Attribute Attribute;
typedef struct Children Children;
typedef struct Element Element;

struct Attribute{
    char *key;
    char *value;
    struct Attribute *next;
};

struct Element {
    char *name;
    char *text;
    Attribute *attributes;
    Element *brother;
    Element *child;
};

void XMLparseString(char *xml);
uint8_t countElements(char* string);
char *getFirstStartTag(char * string);
char * getElementName(char * tag);
int8_t isElementSelfClosing(char* tag);
char * generateEndTag(char * tagName);
char * getElement(char *openTag, char *string);
char * getInnerElement(char *element);
char **getAttributes(char *tag);
char **createArrayString(int8_t sizeArray, int16_t sizeString);
void freeStringArray(char **stringArray, int index);
int getNbAttributes(char *tag);
char *copyString(char *string);
char **splitString(char *separators, char *string, int sizeArray, int sizeString);
int countCharInString(char delimiter, char *string);
char **splitInnerTag(char **splitEqual, int sizeSplitArray);
char **joinSplittedTag(int nbAttributes, char**splitTag);
char * getInnerTag(char *tag);
int8_t prologExists(char *string);
char *getProlog(char *string);


#endif //XMLPARSER_PARSER_H
