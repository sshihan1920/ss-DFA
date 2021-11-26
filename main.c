/*
 * main.c
 *
 *  Created on: Sep 6, 2021
 *      Author: syeds
 */

#include <stdlib.h>
#include <stdio.h>
#include "dfa.h"

//Function Declarations
void com_Finder(char input[]);
void onetwothree_Finder(char input[]);
void twothree_Finder(char input []);
void evenbin_Finder(char input[]);
void abcd_Finder(char input[]);

int main(int argc, char *argv[]) {
	printf("Enter input to test: ");
	char input[25];
	scanf("%s", input);
	printf("%s\n", input);

	com_Finder(input);
	onetwothree_Finder(input);
	twothree_Finder(input);
	abcd_Finder(input);
}

void com_Finder(char input[]) {
	printf("Testing DFA that recognizes exactly for the word \"computer\" \n");
	struct DFA* d = new_DFA(8);

	DFA_set_transition_all(d, 0, -1);
	DFA_set_transition_all(d, 1, -1);
	DFA_set_transition_all(d, 2, -1);
	DFA_set_transition_all(d, 3, -1);
	DFA_set_transition_all(d, 4, -1);
	DFA_set_transition_all(d, 5, -1);
	DFA_set_transition_all(d, 6, -1);
	DFA_set_transition_all(d, 7, -1);

	DFA_set_transition(d, 0, 'c', 1);
	DFA_set_transition(d, 1, 'o', 2);
	DFA_set_transition(d, 2, 'm', 3);
	DFA_set_transition(d, 3, 'p', 4);
	DFA_set_transition(d, 4, 'u', 5);
	DFA_set_transition(d, 5, 't', 6);
	DFA_set_transition(d, 6, 'e', 7);
	DFA_set_transition(d, 7, 'r', 8);
	DFA_set_accepting(d, 8, true);

	bool val = DFA_execute(d, input);

	if (val == true) {
			printf("Result: True");
		}
		else {
			printf("Result: False");
		}
}

void onetwothree_Finder(char input[]) {
	printf("Testing DFA that recognizes strings starting with 123 \n");
	struct DFA* d = new_DFA(4);

	DFA_set_transition_all(d, 0, -1);
	DFA_set_transition_all(d, 1, -1);
	DFA_set_transition_all(d, 2, -1);
	DFA_set_transition_all(d, 3, -1);

	DFA_set_transition(d, 0, '1', 1);
	DFA_set_transition(d, 1, '2', 2);
	DFA_set_transition(d, 2, '3', 3);
	DFA_set_transition_all(d, 3 , 4);
	DFA_set_transition_all(d, 4 , 4);
	DFA_set_accepting(d, 4, true);

	bool val = DFA_execute(d, input);

	if (val == true) {
			printf("Result: True");
		}
		else {
			printf("Result: False");
		}
}

void twothree_Finder(char input []) {
	printf("Testing DFA that recognizes strings starting with either 2 twos or 3 threes \n");
	struct DFA* d = new_DFA(5);

	DFA_set_transition_all(d, 0, -1);
	DFA_set_transition_all(d, 1, -1);
	DFA_set_transition_all(d, 2, -1);
	DFA_set_transition_all(d, 3, -1);
	DFA_set_transition_all(d, 4, -1);

	DFA_set_transition(d, 0, '2', 1);
	DFA_set_transition(d, 1, '2', 2);
	DFA_set_transition_all(d, 2, 2);
	DFA_set_transition(d, 0, '3', 3);
	DFA_set_transition(d, 3, '3', 4);
	DFA_set_transition(d, 4, '3', 2);
	DFA_set_accepting(d, 2, true);

		bool val = DFA_execute(d, input);

		if (val == true) {
				printf("Result: True");
			}
			else {
				printf("Result: False");
			}
}

void evenbin_Finder(char input []) {

}

void abcd_Finder(char input[]) {
	printf("Testing DFA that recognizes strings starting with ab or ending with cd \n");
	struct DFA* d = new_DFA(5);

	DFA_set_transition_all(d, 0, -1);
	DFA_set_transition_all(d, 1, -1);
	DFA_set_transition_all(d, 2, -1);
	DFA_set_transition_all(d, 3, -1);
	DFA_set_transition_all(d, 4, -1);

	DFA_set_transition_all(d, 0, 3);
	DFA_set_transition(d, 0, 'a', 1);
	DFA_set_transition(d, 1, 'b', 2);
	DFA_set_transition_all(d, 2, 2);
	DFA_set_transition_all(d, 3, 3);
	DFA_set_transition(d, 3, 'c', 4);
	DFA_set_transition(d, 4, 'd', 2);
	DFA_set_accepting(d, 2, true);

		bool val = DFA_execute(d, input);

		if (val == true) {
				printf("Result: True");
			}
			else {
				printf("Result: False");
			}
}
