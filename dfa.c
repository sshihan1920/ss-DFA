/*
 * dfa.c
 *
 *  Created on: Sep 6, 2021
 *      Author: syeds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

typedef struct DFA {
    int nStates;
    int initState;
    bool accStates[10];
    int transTable[40][128];
    //bool accStates[];
}*DFA;

//DFA Constructor Method
DFA new_DFA(int nstates) {
    DFA dfa = (DFA)malloc(sizeof(struct DFA));
    //printf("%d", sizeof(struct DFA));
    	dfa->nStates = nstates;
    	dfa->initState = 0;

    	for (int i = 0; i < nstates; ++i) {
    		dfa->transTable[i][0] = i;
    	}

    	//Implement ASCII Characters
    	for (int j = 0; j < 128; j++) {
    		dfa->transTable[0][j] = j;
    	}

    	for (int k = 0; k < 10; ++k) {
    		dfa->accStates[k] = false;
    	}

    	return dfa;
}

//Convert Char to Int Method
int toInt(char c) {
	int ASCIIval = c;
	return ASCIIval;
}

//DFA Free Method
void DFA_free(DFA dfa) {
   free(dfa);
}

//DFA Get Size Method
int DFA_get_size(DFA dfa) {
	return dfa->nStates;
}

//DFA Get Transition Method
int DFA_get_transition(DFA dfa, int src, char sym) {
	int x = toInt(sym);
	return dfa->transTable[src][x];
}

//DFA Set Transition Method
void DFA_set_transition(DFA dfa, int src, char sym, int dst) {
	//Rows are States
	//Columns are all possible symbols

	int numVal = toInt(sym);
	dfa->transTable[src][numVal] = dst;
}

//DFA Set Accepting State Method
void DFA_set_accepting(DFA dfa, int state, bool value) {
	dfa->accStates[state] = value;
}

//DFA Get Accepting State Method
bool DFA_get_accepting(DFA dfa, int state) {
	return dfa->accStates[state];
}

//DFA Execute Method
bool DFA_execute(DFA dfa, char input[]) {
	int k = dfa->initState;
	bool val;

		for (int i = 0; i < strlen(input); ++i) {
			int x = DFA_get_transition(dfa, k, input[i]);
			k = x;

			if (k == -1) {
				break;
			}
		}

		//DFA_set_accepting(dfa, 0, false);
		return DFA_get_accepting(dfa, k);
}

//DFA Set Transition All Method
void DFA_set_transition_all(DFA dfa, int src, int dst) {
	for (int i = 0; i < 128; ++i) {
		dfa->transTable[src][i] = dst;
	}
}
