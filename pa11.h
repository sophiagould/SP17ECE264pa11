#ifndef _PA11_H_
#define _PA11_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct StackNode {
	float val;
	struct StackNode * next;
} StackNode;

//typedef struct StackList {
//	StackNode * head;
//}StackList;

//StackNode * buildStack();

float solver(char* , StackNode ** stack, int* error);

void push(StackNode ** stack, float var);

bool pop(char val, StackNode ** stack);

float calc(float num1, float num2, char val);

#endif
