#pragma once

//연결형 리스트가 되기 위해서 필요한 것
//시작주소값 , 다음 생성된 인덱스의 주소값, 


typedef struct _tagNode      //tLinkedList에선 시작 노드의 주소만 알면 되지만 그 노드안에는 다음 노드의 주소값을 알아야 하므로, 새로운 구조체를 선언하는것.(두개의 함수식이 다를 수 밖에 없기때문)
{ //필요한 멤버 : 생성된 다음 노드의 주소값, 저장할 데이터값

	int					iData;      //저장될 데이터값(자료형)
	struct _tagNode*	pNextNode;  //다음 노드를 가리키는 포인터타입.
	

}tNode;


typedef struct _tagList
{
	//필요한 멤버 : 노드의 시작주소 , 데이터의 갯수

	tNode*	pHeadNode;  //첫 노드의 주소
	int		iCount;    //데이터의 갯수
	//int iMaxCount; -> 연결형 리스트는 데이터 추가 할 때 마다 동적할당을 따로 하기때문에 최대값 필요없음.

}tLinkedList;


//연결형 리스트 초기화(초기값)
void InitList(tLinkedList* _pList);

//연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);  //PushBack : 데이터가 뒤쪽으로 배치됨 : 새로 생성된 메모리가 마지막 데이터 뒤에 생성됨.

//연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);


//연결형 리스트 PushFront 함수 : 데이터 앞쪽으로 생성됨.

void PushFront(tLinkedList* _pList, int _iData);