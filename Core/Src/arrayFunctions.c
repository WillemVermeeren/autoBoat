/*
 * arrayFunctions.c
 *
 *  Created on: Mar 6, 2024
 *      Author: vw060611
 */
#include "arrayFunctions.h"

void remove_element(double arrayA[][2], int index, int arrayLength){
	for(int i = index; i < arrayLength - 1; i++){
		for(int j = 0; j<2; j++){
			arrayA[i][j] = arrayA[i+1][j];
		}
	}

}

void append_array(double arrayA[][2], int arrayLength, double arrayB[]){
	for(int i = 0; i < arrayLength - 1; i++){
		if((arrayA)[i][0]==0 && (arrayA)[i][1]==0){
			(arrayA)[i][0] = arrayB[0];
			(arrayA)[i][1] = arrayB[1];
			return;
		}
	}
}


