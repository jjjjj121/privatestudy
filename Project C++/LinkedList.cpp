#include "LinkedList.h"
#include <iostream>

//������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;    //������ ����Ʈ�� �����Ͱ� ���ö� �׶� �׶� ����� ������ �ʱⰪ�� �ּҰ� ����.
	_pList->iCount = 0;             //���� ���� ������ ������ ���� ����.

}

//������ ����Ʈ ������ �߰�
//�����Ͱ� �� ��尡 �����Ǿ���.
//�� ��忡 �����Ͱ� ������.
//���� ������ ����� �ּҰ��� ����Ű�� �־����.
void PushBack(tLinkedList* _pList, int _iData)  
{
	//�����͸� ������ ��� ����
	//������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));          //�޸𸮰� ������ ������ �����ؾ� �ϹǷ� �����Ҵ��� ����ؾ� �ϰ�, �� ũ��� ��� �Ѱ��� ũ�⸸ŭ�� �����Ͱ� ���� ������ 
														   //�ݺ��ϱ� ������ ���޸𸮿� 1���� ���ũ�⸸ŭ�� ������ �����Ѵ�. ���� ��尡 ������ ������ �ش� ����� �ּҰ��� �޾ƾ� �ϹǷ� ���������(tNode*)�� �޾ƾ���.
														   //���� �迭������ int�迭�̶�� �����ϰ� ­���� ���⿡�� �ڷ��� ������ ����̱� ������ ��������Ͱ� �ʿ�.

	pNode->iData = _iData;									//pNode ��ü�� ������ ����� �� �����Ͱ� �Է�
	pNode->pNextNode = nullptr;								//pNextNode ������� �ƹ��͵� ���� : �� ������ ������ �ִ� ������ ���� ������(����)�� �����Ͱ��� �����ǹǷ� ������ �� ��尡 ������.
	                                                        //���� ���� ��带 ����Ű�� ���� ����.

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (_pList->pHeadNode == nullptr)//or (_pList->iCount == 0;)				//�ʱ�ȭ ���� �״�ζ�� �����Ͱ� ���°� �����̴�.
	{

		_pList->pHeadNode = pNode;							//

	}
	else
	{
		//���� ���� ������ ��带 ã�Ƽ�(���� (�����Ͱ�)�� ������ ������ ������ ���)
		//�ش� ����� pNextNode(��������� �ּҰ�)�� ������Ų ����� �ּҷ� ä��.

		tNode* pCurFinalNode = _pList->pHeadNode;     //_pList->pHeadNode�� ���� �ǵ�� ���� ����Ʈ�� ù ��带 ����Ű�� �ִ� �ּҰ� �ٲ�� �����Ƿ� ���ο� ������ �����ؼ� �� ������ �ݺ����� ��������.
		while (true)
		{
			//����� ù��°(����) ��忴�� ���
			if (nullptr == pCurFinalNode->pNextNode) //���� ������ ������ ����� ����ּҰ� �ƹ��͵� ����Ű�� ���� �ʴٸ� == ���� ������ ��尡 ù���� ��忴����. �׷� ���� 2��° ���
				break;							     //�� ��� �̹� ������ ��带 ã�����Ƿ� break;

			//�׹��� ���(���̾� n���� ��尡 �����Ѵٴ� ��)
			pCurFinalNode = pCurFinalNode->pNextNode; //���� ��带 ����Ű�� �ּҰ��� ���� ������ �ٽ� �����.

		}

		pCurFinalNode->pNextNode = pNode;        //pCurFinalNode->pNextNode(������� ������ ����� �ּ�)�� pNode(���� ������ ���)�� ����

	}

	++_pList->iCount;

}


//������ ����Ʈ �޸� ����
//�ּ� �ϳ��ϳ� ���󰡸鼭 ������ �� ��������ߵ�.

//���� ������ ����� ��� , �� ��忡 ����� ���� ����� �ּҸ� �̸� �޾Ƴ� ����, ��带 ������ �� �޾Ƴ� �ּҸ� ���� �ݺ����� �ٽ� �����Ͽ� �ݺ��ϴ� ����.
void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;		//ù��° ����� �ּҺ��� �޾Ƴ�.

	while (pDeletNode) //�ݺ����� : pDeletNode�� null�� ���ö����� -> null�� false�Ƿ� null�� ������ �ݺ��� ����.
	{
		tNode* pNext = pDeletNode->pNextNode;  //���ο� ��ü�����ؼ� ���� ���� ����� ���� ����ּ� �޾Ƴ�.
		free(pDeletNode);
		pDeletNode = pNext;                    //�ݺ����� ���� ���� �޾Ƴ� ���� �ּҸ� �ٽ� ���� ����ּҿ� ������.


	}

}




//������ ����Ʈ PushFront �Լ� : ������ �������� ������.
//�� �Լ��� �׻� 1��°�� ��尡 ������ ������ �־��� �������� ��尡 HeadNod(ù ����� �ּ�)�� ���ŵǾ�� �Ѵ�.
void PushFront(tLinkedList* _pList, int _iData)
{
	//���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));   //��� �����ŭ�� �޸� �������� ���� �� ������(�ּҰ�) �޾ƿ�.-> pNewNode ������ ������
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;		

	//����Ʈ�� ����� �����͸� �����Ѵ�.

	_pList->pHeadNode = pNewNode;

	//������ ī��Ʈ ����.

	++_pList->iCount;


}