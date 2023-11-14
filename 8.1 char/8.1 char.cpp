// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ... 
// 1. Визначити число входжень в послідовність групи букв “abc”.
// 2. Замінити кожну групу букв “abc” парою зірочок “ * *”

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s, const char* cs)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strstr(s + pos, cs))
	{
		pos = t - s + 1;
		k++;
	}
	return k;
}
char* Change(char* s) // s = вказівник на початок рядка
{
 char* t = new char[strlen(s)];
 char* p;
 int pos1 = 0, // pos1 = позиція початку пошуку
 pos2 = 0;
 *t = 0; 
 while (p = strchr(s + pos1, 'a')) // p = вказівник на '+'
 {
 if (s[p - s + 1] == 'b' && s[p - s + 2] == 'c')
 {
 pos2 = p - s + 3; // pos2 = позиція наступного символа після '-'
 strncat(t, s + pos1, pos2 - pos1 - 3); 
 strcat(t, "***");
 pos1 = pos2;
 }
 else
 {
 pos2 = p - s + 1; // pos2 = позиція наступного символа після '+'
 strncat(t, s + pos1, pos2 - pos1);
 pos1 = pos2;
 }
 }
 strcat(t, s + pos1);
 strcpy(s, t);
 return t;
}

int main()
{
	char s[101];
	char cs[] = "abc";
	cout << "Enter string:" << endl;
	cin.getline(s, 100);
	cout << "String contained " << Count(s, cs) << " groups of 'abc'" << endl;
	char* dest = new char[151];
	dest = Change(s);
	cout << "Modified string (param) : " << s << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
