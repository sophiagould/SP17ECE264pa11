#include <stdio.h>
#include <stdlib.h>
#include "pa11.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//#include "pa11.c"
//StackList * buildStack(){
//	StackList * stack = malloc(sizeof(StackList));
//	stack -> head = NULL;
//	return stack;
//}

float solver(char * in, StackNode ** stack, int * error){
	char val;
	double too;
	//int x = 0;
	float temp;
	float result;
	char list[256];
	//char mop;
//	StackNode * cur = malloc(sizeof(StackNode));
//	*cur = *stack;


	FILE * fle = fopen(in,"r");
	if (fle == NULL){
		fprintf(stderr, "Error while trying to open file to read");
		*error = 1;
		//fclose(fle);
		return 0;
	}

	while((fscanf(fle, "%s", list) == 1)){
	//while((fscanf(fle, "%s", list) != 0) || (((*stack) -> next) != NULL)){

	//	printf("x%s   ",list);
		too = atof(list);
		val = list[0];
	//	printf("%f    ",too);
//		printf("%c    ",val);
		if((val == '-') || (val == '+') || (val == '*') ||(val == '/') ){
			result = pop(val, stack, error);
			if((result == 0) || (*error == 1)){
				*error = 1;
				fclose(fle);
				return result;
			}
			push(stack, result);
		//	free(*cur);
			
		}else if(isdigit(val) || (val == '.')){
			too = atof(list);
			temp = (float) too;
			push(stack, temp);
		//	free(*cur);
			*error = 0;
		}else{
			*error = 1;
		}
		//x++;
	}
	fclose(fle);
	if((*stack)->next != NULL){
		*error = 1;
	}
	freeze(*stack);
	result = (*stack)->val;
	//free(list);
//	free(*stack);
	//free(stack);
//	free(cur);
	return result;
}
float pop(char oper, StackNode ** stack, int * error){
	//cur = NULL;
	float result;
	float num1;
	float num2;
	if((((*stack)) == NULL || (*stack)-> next == NULL)){
		*error = 1;
	//	free(*stack);
	//	free(stack);
		return 0;
	}

	StackNode *cur = *stack;
	
	num1 = (float)((cur)->val);
	num2 = (float)(((cur)->next)->val);
	if((num1 == 0) && (oper == '/')) *error = 1;
	if((num1 == 0) && (num2 == 0) && (oper == '/')) *error = 1;
	result = calc(num1, num2, oper);
	*stack = ((cur->next)->next); 

	free(cur->next);
	free(cur);
//	free(temp);
	return result;
}
void push(StackNode ** stack, float result){
	StackNode * cur = malloc(sizeof(StackNode));
//	cur = NULL;
	(cur) -> val = result;
	(cur) -> next = *stack;
	*stack = cur;
	return;
//	cur = *stack;
  //  free(cur);
}
float calc(float num1, float num2, char var){
	float result;
	if(var == '-'){
		result = num2 - num1;
	}
	if(var == '+'){
		result = num2 + num1;
	}
	if(var == '*'){
		result = num2 * num1;
	}
	if(var == '/'){
		result = num2 / num1;
	}
	return result;
}
void freeze(StackNode * stack){
	if((stack)->next != NULL){
		free((stack)->next);
		if((((stack) -> next)->next) != NULL){
			freeze(((stack)->next));
		}
	}
	return;
}

	
