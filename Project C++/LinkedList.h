#pragma once

//������ ����Ʈ�� �Ǳ� ���ؼ� �ʿ��� ��
//�����ּҰ� , ���� ������ �ε����� �ּҰ�, 


typedef struct _tagNode      //tLinkedList���� ���� ����� �ּҸ� �˸� ������ �� ���ȿ��� ���� ����� �ּҰ��� �˾ƾ� �ϹǷ�, ���ο� ����ü�� �����ϴ°�.(�ΰ��� �Լ����� �ٸ� �� �ۿ� ���⶧��)
{ //�ʿ��� ��� : ������ ���� ����� �ּҰ�, ������ �����Ͱ�

	int					iData;      //����� �����Ͱ�(�ڷ���)
	struct _tagNode*	pNextNode;  //���� ��带 ����Ű�� ������Ÿ��.
	

}tNode;


typedef struct _tagList
{
	//�ʿ��� ��� : ����� �����ּ� , �������� ����

	tNode*	pHeadNode;  //ù ����� �ּ�
	int		iCount;    //�������� ����
	//int iMaxCount; -> ������ ����Ʈ�� ������ �߰� �� �� ���� �����Ҵ��� ���� �ϱ⶧���� �ִ밪 �ʿ����.

}tLinkedList;


//������ ����Ʈ �ʱ�ȭ(�ʱⰪ)
void InitList(tLinkedList* _pList);

//������ ����Ʈ ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);  //PushBack : �����Ͱ� �������� ��ġ�� : ���� ������ �޸𸮰� ������ ������ �ڿ� ������.

//������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);


//������ ����Ʈ PushFront �Լ� : ������ �������� ������.

void PushFront(tLinkedList* _pList, int _iData);