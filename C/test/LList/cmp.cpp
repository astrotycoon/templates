#include <iostream>
#include <list>
using namespace std;
struct node {
	int value;
};
int main()
{
	list<struct node> l;
	for (int i = 0; i < 10; i++) {
		struct node node;
		node.value = i * 10;
		l.push_back(node);
	}
	cout << l.size() << endl;
	list<struct node>::iterator itt;
	for (itt = l.begin(); itt != l.end(); itt++) {
		cout << itt->value << endl;
	}
	return 0;
}
