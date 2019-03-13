#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

char arr[102];

//4*(7+3*6)-(4/2)+9-(2*3)
int main(){
	fgets(arr, sizeof(arr), stdin);
	arr[strlen(arr) - 1] = '\0';
	stack<char> s;

	for (int i = 0; i < strlen(arr); i++){
		if(arr[i] >= 'A' && arr[i]<='Z'){
			printf("%c", arr[i]);
		}
		else if (arr[i] == '+' || arr[i] == '-'){
			while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')){
				printf("%c", s.top());
				s.pop();
			}
			s.push(arr[i]);
		}
		else if (arr[i] == '/' || arr[i] == '*'){
			while (!s.empty() && (s.top() == '*' || s.top() == '/')){
				printf("%c", s.top());
				s.pop();
			}
			s.push(arr[i]);
		}
		else if (arr[i] == '('){
			s.push(arr[i]);
		}
		else if (arr[i] == ')'){
			while (s.top() != '('){
				printf("%c", s.top());
				s.pop();
			}
			s.pop();
		}
	}

	while (!s.empty()){
		printf("%c", s.top());
		s.pop();
	}
	
	return 0;
}