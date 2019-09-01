## Recursion

#### ��������� ������ �ٶ󺸴� ���

   **1. ���ڿ� ����� ����ϴ� ���**

  ![File](file.png)


  ~~~c
    // (1) ���̰� len �� string �� ������ ����ϰ��� �ϸ�
    void print_string(char[] string, int len){
       if(len == 0)  return;
       
		// (2) string[1..] �� ������ ����ϰ� ���� 
		print_string(string, len-1);

       // (3) string[0] �� ����ϸ� �ȴ�
		printf("%c", string[len]);
	}
  ~~~

   **10������ 2������ ��ȯ�Ͽ� ����ϴ� ���**
  
  - �Է��� 0 ���� ū ���
    - 2�� ���� �� ���� 2������ ���Ѵ�
    - 2�� ���� �������� �ش��ϴ� ��Ʈ�� �������� ����Ѵ�
  - �׷��� ���� ��� �����Ѵ�
  
  `��, 2�� ������ ��� �������� �и��ϰ� ���� ������� ������ ����� �������� �ܰ����� ����� �����Ѵ�.`
  `�ܰ��� ���⹰�� ����� ����� ���� ��/�� ��� �� ���ΰ��� �����ؾ��Ѵ�` 
  ~~~c
  void convert_bin ( int num ) {
	if (num == 0) return;

	int remain = num % 2, quantity = num / 2;

	convert_bin ( quantity );

	printf ( "%d" , remain );
  }
  ~~~

  **2. ��� ���������� ��ȯ ��ƾ**

  **�迭�� ���� ���Ͽ� ��ȯ�ϴ� ���**

   - �߸��� ��� ��� (�Ź� Ʋ��)
   - `��ȯ�Ǵ� sum ���� ������ ��ȯ ��ƾ���� �̾����� �ʴ� ������`    

   ~~~c
	int sum_array ( int arr[] , int idx, int arr_len, int sum) {
		if (idx == arr_len)	return sum;

		sum += arr[idx++];

		sum_array ( arr , idx , arr_len , sum );

		return sum;
	}
   ~~~
    
   - ���� ���� �ڵ�� �Ʒ��� �帧���� ������
      `��, ���� �����Ǵ� ���� ������ ������ �ܺη� ���޵Ǿ� �Լ� ȣ��� ��������� ���� ���� ����� ���޵��� ����`
      ![Error 1](error_1.png)

   - �Ʒ��� ���� ������ �ؾ� ��
    
   ~~~c
	int sum_array ( int arr[] , int idx, int arr_len, int sum) {
		if (idx == arr_len)	return sum;

		sum += arr[idx];

		return sum_array ( arr , idx + 1 , arr_len , sum );
	}
   ~~~

   - �� �ڵ�� �Ʒ��� ���� ������
    ![Correct 1](correct_1.png)

   - ���� �� �ڵ忡�� ���ʿ��� �޸� �Ҵ��� �߱��ϴ� sum ������ �ʿ� ����
   
   ~~~c
	int sum_array_opt ( int arr[] , int idx, int arr_len) {
		if (idx == arr_len) return 0;

		return arr[idx] + sum_array_opt ( arr , idx + 1, arr_len );
	}
   ~~~ 