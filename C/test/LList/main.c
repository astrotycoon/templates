#include <stdio.h>
/*LList即线性表容器*/
#include <LList.h>
/*被测试自定义数据类型*/
struct node {
	int value;
};

int main()
{
	int i;
/**
 * 相于c++代码的List<struct node> *list = new(list<struct node>)
**/
	LList(struct node) *list = new(LList(struct node));
/**
 * 由于没有构造方法。只好手动调用
**/
	LList_init(list);

	for (i = 0; i < 10; i++) {
		struct node node;
		node.value = 10 * (i + 1);
/**
 * 相当于list->append(node);
**/
		LList_append(node, list);
	}

/**
 * 相当于list->size();
**/
	printf("size: %d\n", LList_size(list));

/**
 * 用传入容器的类型参数对应指针做为迭代器
**/
	struct node *itt;
/**
 * 相当于for (itt = list->begin(); itt != list->end(); itt++)
**/
	puts("print:");
	for (itt = LList_begin(list);
			itt != LList_end(list);
			itt = LList_next(itt, list)) {
		printf("%d\n", itt->value);
	}

	return 0;
}
