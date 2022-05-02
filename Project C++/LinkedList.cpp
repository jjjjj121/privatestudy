#include "LinkedList.h"
#include <iostream>

//연결형 리스트 초기화
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;    //연결형 리스트는 데이터가 들어올때 그때 그때 만들기 때문에 초기값은 주소값 없음.
	_pList->iCount = 0;             //위와 같은 이유로 데이터 갯수 없음.

}

//연결형 리스트 데이터 추가
//데이터가 들어갈 노드가 생성되야함.
//그 노드에 데이터가 들어가야함.
//다음 생성될 노드의 주소값을 가리키고 있어야함.
void PushBack(tLinkedList* _pList, int _iData)  
{
	//데이터를 저장할 노드 생성
	//데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));          //메모리가 부족할 떄마다 생성해야 하므로 동적할당을 사용해야 하고, 그 크기는 노드 한개의 크기만큼을 데이터가 들어올 때마다 
														   //반복하기 때문에 힙메모리에 1개의 노드크기만큼의 공간을 생성한다. 또한 노드가 생성될 때마다 해당 노드의 주소값을 받아야 하므로 노드포인터(tNode*)로 받아야함.
														   //가변 배열에서는 int배열이라고 생각하고 짯지만 여기에서 자료형 단위는 노드이기 때문에 노드포인터가 필요.

	pNode->iData = _iData;									//pNode 객체에 데이터 멤버에 들어갈 데이터값 입력
	pNode->pNextNode = nullptr;								//pNextNode 멤버에는 아무것도 없음 : 그 이유는 기존에 있던 데이터 제일 마지막(뒤쪽)에 데이터값이 생성되므로 생성된 이 노드가 마지막.
	                                                        //따라서 다음 노드를 가리키고 있지 않음.

	// 추가한 데이터가 처음인지 아닌지
	if (_pList->pHeadNode == nullptr)//or (_pList->iCount == 0;)				//초기화 상태 그대로라면 데이터가 들어온게 최초이다.
	{

		_pList->pHeadNode = pNode;							//

	}
	else
	{
		//현재 가장 마지막 노드를 찾아서(내가 (데이터값)이 들어오기 이전에 마지막 노드)
		//해당 노드의 pNextNode(다음노드의 주소값)를 생성시킨 노드의 주소로 채움.

		tNode* pCurFinalNode = _pList->pHeadNode;     //_pList->pHeadNode의 값을 건들면 기존 리스트가 첫 노드를 가리키고 있는 주소가 바뀌어 버리므로 새로운 변수를 선언해서 그 변수로 반복문을 돌릴예정.
		while (true)
		{
			//대상이 첫번째(최초) 노드였을 경우
			if (nullptr == pCurFinalNode->pNextNode) //새로 생성된 변수에 저장된 노드주소가 아무것도 가리키고 있지 않다면 == 내가 들어가기전 노드가 첫번쨰 노드였던것. 그럼 나는 2번째 노드
				break;							     //이 경우 이미 마지막 노드를 찾았으므로 break;

			//그밖의 경우(뒤이어 n개의 노드가 존재한다는 뜻)
			pCurFinalNode = pCurFinalNode->pNextNode; //다음 노드를 가리키는 주소값을 기존 변수에 다시 덮어씌움.

		}

		pCurFinalNode->pNextNode = pNode;        //pCurFinalNode->pNextNode(현재기준 마지막 노드의 주소)에 pNode(현재 생성된 노드)를 대입

	}

	++_pList->iCount;

}


//연결형 리스트 메모리 해제
//주소 하나하나 따라가면서 일일히 다 해제해줘야됨.

//시작 노드부터 지우는 대신 , 각 노드에 저장된 다음 노드의 주소를 미리 받아논 다음, 노드를 해제한 후 받아논 주소를 현재 반복문에 다시 적용하여 반복하는 과정.
void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;		//첫번째 노드의 주소부터 받아놈.

	while (pDeletNode) //반복조건 : pDeletNode가 null이 들어올때까지 -> null은 false므로 null이 들어오면 반복문 정지.
	{
		tNode* pNext = pDeletNode->pNextNode;  //새로운 객체선언해서 현재 지울 노드의 다음 노드주소 받아놈.
		free(pDeletNode);
		pDeletNode = pNext;                    //반복문이 돌기 전에 받아논 다음 주소를 다시 기존 노드주소에 덮어씌우기.


	}

}




//연결형 리스트 PushFront 함수 : 데이터 앞쪽으로 생성됨.
//이 함수는 항상 1번째로 노드가 들어오기 때문에 넣어줄 데이터의 노드가 HeadNod(첫 노드의 주소)로 갱신되어야 한다.
void PushFront(tLinkedList* _pList, int _iData)
{
	//새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));   //노드 사이즈만큼의 메모리 힙영역에 생성 후 포인터(주소값) 받아옴.-> pNewNode 포인터 변수에
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;		

	//리스트의 헤드노드 포인터를 갱신한다.

	_pList->pHeadNode = pNewNode;

	//데이터 카운트 증가.

	++_pList->iCount;


}
