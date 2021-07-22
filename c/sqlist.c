//sqlist.c 顺序表
#include <stdio.h>
#define MAXSIZE 200 //最大元素数目

//定义顺序表
typedef struct {
	int elem[MAXSIZE]; //最大元素长度（用数组存放就行）
	int length; //长度
} sqlist;

//初始化顺序表
void init_sqlist(sqlist *L) {
	L->length = 0; //初始化，长度为0
}

//定位下标对应元素
int locate_value_sqlist(sqlist *L, int loc) {
	if (loc < 0 || loc > L->length) return -1;
	else return L->elem[loc];
}

//查找值对应的第一个元素的下标（重复的不管）
int search_value_sqlist(sqlist *L, int val) {
	for (int i = 0; i < L->length; i++) 
		if (val == L->elem[i]) {
			return i;
			break;
		}
	return -1;
}

//追加到顺序表末尾
void append_to_sqlist(sqlist *L, int val) {
	if (L->length >= MAXSIZE) return; //如果满了，则不插入
	else {
		L->elem[L->length] = val;
		++L->length;
	}
}

//从末尾删除顺序表
void delete_from_sqlist(sqlist *L) {
	if (L -> length <= 0) return; //如果空了，则不删除
	else {
		--L->length;
		L->elem[L->length] = 0;
	}
}

//插入顺序表（指定插入）
void insert_into_sqlist(sqlist *L, int loc, int val) {
	if (L->length >= MAXSIZE) return; //如果满了，则不插入
	else {
		for (int i = L->length; i >= loc; i--)
			L->elem[i] = L->elem[i - 1];
		L->elem[loc] = val;
		++L->length;
	}
}

//移除顺序表某元素（指定位置）
void remove_from_sqlist(sqlist *L, int loc) {
	if (L->length <= 0) return; //如果空了，则不删除
	else {
		--L->length;
		for (int i = loc; i <= L->length; i++)
			L->elem[i] = L->elem[i + 1];
	}
}

//遍历显示顺序表
void show_sqllist(sqlist *L) {
	if (L->length == 0) return;
	else {
		printf("顺序表：");
		for (int i = 0; i < L->length; i++)
			printf("%d  ", L->elem[i]);
		putchar('\n');
	}
}

//清空顺序表
void clear_sqlist(sqlist *L) {
	for (int i = 0; i < L->length; i++)
		L->elem[i] = 0;
	L->length = 0;
}

//从数组初始化顺序表
void init_sqlist_via_array(sqlist *L, int array[], int len_array) {
	if (L->length != 0)  clear_sqlist(L);
	for (int i = 0; i < len_array; i++) {
		L->elem[i] = array[i];
		++L->length;
	}
}

//将两个顺序表归并
//将两个顺序表合并，要求元素从小到大
void merge_sqlist(sqlist *L1, sqlist *L2, sqlist *L3) {
	int i = 0, j = 0, k = 0;
	while (i < L1->length && j < L2->length)
		if (L1->elem[i] < L2->elem[j])
			L3->elem[k++] = L1->elem[i++];
		else
			L3->elem[k++] = L2->elem[j++];
	while (i < L1->length)
		L3->elem[k++] = L1->elem[i++];
	while (j < L2->length)
		L3->elem[k++] = L2->elem[j++];
	L3->length = k;
}

//运行程序
int main(int argc, char *argv[]) {
	sqlist list1, list2, list3; //定义顺序表
	//初始化和赋值操作
	for (int i = 1; i <= 6; i++)
		append_to_sqlist(&list1, i);
	show_sqllist(&list1);
	//给定位置移除元素
	remove_from_sqlist(&list1, 0);
	show_sqllist(&list1);
	//删除末尾元素
	delete_from_sqlist(&list1);
	show_sqllist(&list1);
	//指定位置插入元素
	insert_into_sqlist(&list1, 0, 1);
	show_sqllist(&list1);
	//用数组重新初始化
	int a[3] = {6, 7, 8};
	init_sqlist_via_array(&list2, a, 3);
	show_sqllist(&list2);
	//将两个顺序表进行归并
	merge_sqlist(&list1, &list2, &list3);
	show_sqllist(&list3);
}
