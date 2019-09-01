#include "stdafx.h"



void print_string ( char *ptr_str ) {
	if (*ptr_str == 0)	return;
	
	print_string ( ptr_str + 1 );
	
	printf ( "%c", *ptr_str );
}

char test[] = "abcdef";

void convert_bin ( int num ) {
	if (num == 0) return;

	int remain = num % 2, quantity = num / 2;

	convert_bin ( quantity );

	printf ( "%d" , remain );
}

int sum_array ( int arr[] , int idx, int arr_len, int sum) {
	if (idx == arr_len)	return sum;

	sum += arr[idx];

	return sum_array ( arr , idx + 1 , arr_len , sum );
}

int main()
{
	int arr[] = { 1,2 };

	printf ( "sum = %d" , sum_array ( arr , 0 , 2 , 0 ));

    return 0;
}