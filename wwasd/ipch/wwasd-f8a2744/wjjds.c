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
	Elemtype *elem;//�洢�ռ����ַ
	int length;//���Ա���
}sqlist;
sqlist L;
int InitList()//��ʼ�����Ա�
{
	L.elem=(Elemtype *)(malloc(sizeof(Elemtype)*MaxSize));//���Ա�̬�����ڴ�
	L.length=0;//��ʼ������Ϊ0
	if(!(L.elem))//�ڴ����ʧ��
		exit(OVERFLOW);
	return OK;
}
int Inputlist(int num)
{
	int i;
	if(num>MaxSize)//�ж��Ƿ�����Ԫ�ظ����������洢�ռ�
		return 0;
	for(i=0;i<num;i++)
		scanf("%d",&L.elem[i]);//��������
	L.length=num;
	return 1;
}
void ShowList()
{
	int i;
	if(L.length==0)
	{
		printf("�����Ա��ѿ�\n");
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
	return L.length;//�������Ա���
}
int Locateelem(int e)
{
	int i;
	for(i=0;i<Listlength();i++)
	{
		if(L.elem[i]==e)
		{
			printf("��Ԫ���ڵ�%d��λ��\n",i+1);
			return i+1;
		}
	}
	printf("����û���ҵ�\n");
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
	if(L.length+1>MaxSize)//�жϴ洢�ռ��Ƿ񳬹�����
	{
		printf("��Ҫ���������ʹ�洢�������ޣ�����ִ��ɾ������\n");
		return -1;
	}
	else
	{
		if(i<1||i>L.length+1)//�жϲ���λ���Ƿ�Ϸ�
		{
			printf("����λ�÷Ƿ�\n");
			return -1;
		}
		else
		{
			for(j=L.length-1;j>=i-1;j--)//������Ʋ���
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
		printf("�����Ա��ѿգ����Ƚ��в������\n");
		return -1;
	}
	else
	{
		if(i<0||i>=L.length)
		{
			printf("ɾ����λ�÷Ƿ�\n");
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
	//���º�����Ϊ��������
	InitList();//�Ƚ��г�ʼ��
	scanf("%d",&x);
	Inputlist(x);//�ٽ����������
	ShowList();//��ʾ�鿴��ǰ���Ա�Ԫ��
	scanf("%d",&e);
	Locateelem(e);//����ֵΪe��Ԫ�أ��ҵ���
	scanf("%d",&m);
	Locateelem(m);//����ֵΪm��Ԫ�أ�û�ҵ���
	scanf("%d%d",&i,&e);
	ListInsert(i,e);//�ڵ�i��Ԫ�ز���ֵΪe��Ԫ��
	ShowList();//��ʾ�鿴��ǰ���Ա�Ԫ��
	scanf("%d",&i);
	ListDelete(i);//ɾ����i��Ԫ��
	ShowList();//��ʾ�鿴��ǰ���Ա�Ԫ��
	return 0;
}