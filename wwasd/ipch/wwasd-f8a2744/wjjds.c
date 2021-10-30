#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100010
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define True 1
#define False 0
typedef int Status;
typedef int Elemtype;
typedef struct{
	Elemtype *elem;//存储空间基地址
	int length;//线性表长度
}sqlist;
sqlist L;
int InitList()//初始化线性表
{
	L.elem=(Elemtype *)(malloc(sizeof(Elemtype)*MaxSize));//线性表动态分配内存
	L.length=0;//初始化长度为0
	if(!(L.elem))//内存分配失败
		exit(OVERFLOW);
	return OK;
}
int Inputlist(int num)
{
	int i;
	if(num>MaxSize)//判断是否输入元素个数大于最大存储空间
		return 0;
	for(i=0;i<num;i++)
		scanf("%d",&L.elem[i]);//输入数据
	L.length=num;
	return 1;
}
void ShowList()
{
	int i;
	if(L.length==0)
	{
		printf("该线性表已空\n");
		return -1;
	}
	else
	{
		for(i=0;i<L.length;i++)
			printf("%d ",L.elem[i]);

	}
}
int DestroyList()
{
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	return OK;
}
int Listlength()
{
	return L.length;//返回线性表长度
}
int Locateelem(int e)
{
	int i;
	for(i=0;i<Listlength();i++)
	{
		if(L.elem[i]==e)
		{
			printf("该元素在第%d个位置\n",i+1);
			return i+1;
		}
	}
	printf("该数没有找到\n");
	return 0;
}
int ListEmpty()
{
	if(L.length==0)
		return True;
	else
		return False;
}
int ListInsert(int i,Elemtype e)
{
	int j;
	if(L.length+1>MaxSize)//判断存储空间是否超过上限
	{
		printf("将要插入的数将使存储超过上限，请先执行删除操作\n");
		return -1;
	}
	else
	{
		if(i<1||i>L.length+1)//判断插入位置是否合法
		{
			printf("插入位置非法\n");
			return -1;
		}
		else
		{
			for(j=L.length-1;j>=i-1;j--)//数组后移操作
				L.elem[j+1]=L.elem[j];
			L.elem[i-1]=e;
			L.length++;
			return 1;
		}
	}
}
int ListDelete(int i)
{
	int j;
	if(L.length==0)
	{
		printf("该线性表已空，请先进行插入操作\n");
		return -1;
	}
	else
	{
		if(i<0||i>=L.length)
		{
			printf("删除的位置非法\n");
			return -1;
		}
		else
		{
			for(j=i-1;j<L.length-1;j++)
				L.elem[j]=L.elem[j+1];
			L.length--;
			return 1;
		}
	}
}
int main()
{
	int x,i,e,m;
	//以下函数均为测试内容
	InitList();//先进行初始化
	scanf("%d",&x);
	Inputlist(x);//再进行输入操作
	ShowList();//显示查看当前线性表元素
	scanf("%d",&e);
	Locateelem(e);//查找值为e的元素（找到）
	scanf("%d",&m);
	Locateelem(m);//查找值为m的元素（没找到）
	scanf("%d%d",&i,&e);
	ListInsert(i,e);//在第i个元素插入值为e的元素
	ShowList();//显示查看当前线性表元素
	scanf("%d",&i);
	ListDelete(i);//删除第i个元素
	ShowList();//显示查看当前线性表元素
	return 0;
}