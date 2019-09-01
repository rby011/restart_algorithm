## Recursion : 재귀 알고리즘의 설계

**1. 명시적 매개 변수를 정의해서 서브 호출과 일관성 맞추기**

- 최초 호출 時 상태만을 고려하지 말고 재귀 호출 時 상태를 고려해야 한다
- 예를 들어, 배열 內 목표값을 갖는 위치를 찾는 문제에서
  아래 함수의 매개변수에는 배열내의 탐색 구간 中 시작 위치가 생략되어 있고
  끝 위치는 `len` 으로 정의되어 있다
  ~~~c
	int search_target ( int data[] , int len , int target ) {
		for (int i = 0; i < len; i++) {
			if (data[i] == target)	return i;
		}

		return -1;
	}
  ~~~
- 그러나 재귀적 구조로 만들기 위해서는 탐색 구간을 보다 명료하게 매개변수로 정의하는 것이 필요하다
- 위 코드를 예를 들면 탐색 구간의 시작 인덱스는 `begin` 으로 마직막 인덱스는 `end` 로 명시적으로 정의하는 것이 이해가 쉽다
  ~~~c
	int search_target_recursive ( int data[] , int begin , int end , int target ) {
		// 탐색 구간을 넘어면 찾지 못한 것이다
		if (begin > end) return -1;
		
		// 현재의 탐색 구간을 찾는다
		if (data[begin] == target) return begin;
		
		// 다음 탐색 구간을 정의하고 재귀 호출을 실행한다 
		return search_target_recursive ( data , begin + 1 , end , target );
	}
  ~~~ 
- 물론 알고리즘 구조를 완성하고 나서 생략 가능한 매개 변수는 제거할 수 있다

**2. 서브 함수 호출 결과 현 연산 결과로 이분 분할해서 생각하기**

- 아래 코드는 최대값을 찾는 것으로 `다음 서브 루틴에게 맞기는 식으로 생각했다`
  즉, 탐색 과정을 재귀적으로 분할했다. 그러나 간결하지 않다

  ~~~c
	int find_max ( int data[] , int begin , int end, int max ) {
		// 탐색 범위를 넘어서면 이제까지의 max 가 최대값이다
		if (begin > end) return max;
		// 이제까지의 max 보다 큰 것을 발견하면 이를 넘겨 다음 호출에서 최대를 찾을 것이다
		if (data[begin] > max) return find_max ( data , begin + 1 , end , data[begin] );
		// 그렇지 않다면 이제까지의 max 를 가지고 다음 함수에서 최대를 찾을 것이다
		return find_max ( data , begin + 1 , end, max );
	}
  ~~~

- 이를 함수 호출 결과를 최대값으로 생각하면 더 간결하다

   ~~~c
	int find_max ( int data[] , int begin , int end) {
		// 원소의 개수가 하나이면 그 값이 최대값이다
		if (begin == end) return data[begin];
		// 현재 값이 서브루틴들로서의 결과보다 크다면 현재값이 최대값이고
		if (data[begin] > find_max ( data , begin + 1 , end)) return data[begin];
		// 그렇지 않다면 서브루틴들의 결과가 최대값이다
		return find_max ( data , begin + 1 , end );
	}
   ~~~