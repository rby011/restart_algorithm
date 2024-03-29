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

//however, acutally the above doesn't need 'sum' and 'arr_len' variable
int sum_array_opt ( int arr[] , int idx, int arr_len) {
	if (idx == arr_len) return 0;

	return arr[idx] + sum_array_opt ( arr , idx + 1, arr_len );
}

int search_target ( int data[] , int len , int target ) {
	for (int i = 0; i < len; i++) {
		if (data[i] == target)	return i;
	}

	return -1;
}

int search_target_recursive ( int data[] , int begin , int end , int target ) {
	if (begin > end) return -1;

	if (data[begin] == target) return begin;

	return search_target_recursive ( data , begin + 1 , end , target );
}

int search ( int data[] , int begin , int end , int target ) {
	if (begin > end) return -1;

	int mid = (begin + end) / 2;

	int found = search ( data , begin , mid , target );
	if (found != -1) return found;

	return search ( data , mid + 1 , end , target );
}

int find_max ( int data[] , int begin , int end, int max ) {
	if (begin > end) return max;
	if (data[begin] > max) return find_max ( data , begin + 1 , end , data[begin] );
	return find_max ( data , begin + 1 , end, max );
}

int bigger ( int n1 , int n2 ) {
	if (n1 > n2) return n1;
	else return n2;
}

int find_max2 ( int data[] , int begin , int end ) {
	if (begin == end) return data[begin]; // 데이터가 한 개인 경우
	return bigger ( data[begin] , find_max2 ( data , begin + 1 , end ) );
}

int find_max3 ( int data[] , int begin , int end) {
	if (begin == end) return data[begin];
	if (data[begin] > find_max3 ( data , begin + 1 , end)) return data[begin];
	return find_max3 ( data , begin + 1 , end );
}

int main()
{
	int arr[] = { 1,2 };

	printf ( "sum = %d" , sum_array ( arr , 0 , 2 , 0 ));

    return 0;
}