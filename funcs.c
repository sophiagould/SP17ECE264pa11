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


	FILE * fle = fopen(in,"r");
	if (fle == NULL){
		fprintf(stderr, "Error while trying to open file to read");
		*error = 1;
		fclose(fle);
		return 0;
	}

	while((fscanf(fle, "%s ", list) != EOF)){
//	while((fscanf(fle, "%s", list) != EOF) || (((*stack) -> next) != NULL)){

	//	printf("%s   ",list);
		too = atof(list);
		val = list[0];
	//	printf("%f    ",too);
	//	printf("%c    ",val);
		if((val == '-') || (val == '+') || (val == '*') || (val == '/') ){
				if(pop(val, stack)){
					*error = 1;
				}
		}else if(isdigit(val) || (val == '.')){
			too = atof(list);
			temp = (float) too;
			push(stack, temp);
			//free(cur);
			*error = 0;
		}else{
			*error = 1;
		}
		//x++;
	}
	fclose(fle);
	result = (*stack)->val;
	free(*stack);
	free(stack);
//	free(cur);
	return result;
}
bool pop(char oper, StackNode ** stack){
	//cur = NULL;
	float result;
	float num1;
	float num2;
	if((((*stack) -> next) == NULL)){
		return true;
	}

	StackNode *cur = *stack;

	num1 = (float)((*stack)->val);
	num2 = (float)(((*stack)->next)->val);
	if((num1 == 0) && (oper == '/')) return true;
	if((num1 == 0) && (num2 == 0) && (oper == '/')) return true;
	result = calc(num1, num2, oper);
	
	*stack = ((cur->next)->next);
    
	push(stack, result);
	free(cur);
	return false;
}
void push(StackNode ** stack, float result){
//	cur = NULL;
	StackNode * cur = malloc(sizeof(StackNode));
	cur -> next = NULL;
	cur -> val = result;
	cur -> next = *stack;
	*stack = cur;
//	cur = *stack;
  //  free(cur);
	return;
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


	
