## Recursion

- ��������� ������ �ٶ󺸴� ���

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
