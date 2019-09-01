## Recursion : ��� �˰����� ����

**1. ����� �Ű� ������ �����ؼ� ���� ȣ��� �ϰ��� ���߱�**

- ���� ȣ�� �� ���¸��� ������� ���� ��� ȣ�� �� ���¸� ����ؾ� �Ѵ�
- ���� ���, �迭 Ү ��ǥ���� ���� ��ġ�� ã�� ��������
  �Ʒ� �Լ��� �Ű��������� �迭���� Ž�� ���� �� ���� ��ġ�� �����Ǿ� �ְ�
  �� ��ġ�� `len` ���� ���ǵǾ� �ִ�
  ~~~c
	int search_target ( int data[] , int len , int target ) {
		for (int i = 0; i < len; i++) {
			if (data[i] == target)	return i;
		}

		return -1;
	}
  ~~~
- �׷��� ����� ������ ����� ���ؼ��� Ž�� ������ ���� ����ϰ� �Ű������� �����ϴ� ���� �ʿ��ϴ�
- �� �ڵ带 ���� ��� Ž�� ������ ���� �ε����� `begin` ���� ������ �ε����� `end` �� ��������� �����ϴ� ���� ���ذ� ����
  ~~~c
	int search_target_recursive ( int data[] , int begin , int end , int target ) {
		// Ž�� ������ �Ѿ�� ã�� ���� ���̴�
		if (begin > end) return -1;
		
		// ������ Ž�� ������ ã�´�
		if (data[begin] == target) return begin;
		
		// ���� Ž�� ������ �����ϰ� ��� ȣ���� �����Ѵ� 
		return search_target_recursive ( data , begin + 1 , end , target );
	}
  ~~~ 
- ���� �˰��� ������ �ϼ��ϰ� ���� ���� ������ �Ű� ������ ������ �� �ִ�

**2. ���� �Լ� ȣ�� ��� �� ���� ����� �̺� �����ؼ� �����ϱ�**

- �Ʒ� �ڵ�� �ִ밪�� ã�� ������ `���� ���� ��ƾ���� �±�� ������ �����ߴ�`
  ��, Ž�� ������ ��������� �����ߴ�. �׷��� �������� �ʴ�

  ~~~c
	int find_max ( int data[] , int begin , int end, int max ) {
		// Ž�� ������ �Ѿ�� ���������� max �� �ִ밪�̴�
		if (begin > end) return max;
		// ���������� max ���� ū ���� �߰��ϸ� �̸� �Ѱ� ���� ȣ�⿡�� �ִ븦 ã�� ���̴�
		if (data[begin] > max) return find_max ( data , begin + 1 , end , data[begin] );
		// �׷��� �ʴٸ� ���������� max �� ������ ���� �Լ����� �ִ븦 ã�� ���̴�
		return find_max ( data , begin + 1 , end, max );
	}
  ~~~

- �̸� �Լ� ȣ�� ����� �ִ밪���� �����ϸ� �� �����ϴ�

   ~~~c
	int find_max ( int data[] , int begin , int end) {
		// ������ ������ �ϳ��̸� �� ���� �ִ밪�̴�
		if (begin == end) return data[begin];
		// ���� ���� �����ƾ��μ��� ������� ũ�ٸ� ���簪�� �ִ밪�̰�
		if (data[begin] > find_max ( data , begin + 1 , end)) return data[begin];
		// �׷��� �ʴٸ� �����ƾ���� ����� �ִ밪�̴�
		return find_max ( data , begin + 1 , end );
	}
   ~~~