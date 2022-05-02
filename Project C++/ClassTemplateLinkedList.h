#pragma once

template<typename T>
struct tListNode						 //C++에서 구조체와 class는 같다. 다만 필드를 아무것도 적지 않았을때 구조체는 public , class는 private이다.
{ 

	T						data;       //저장될 데이터값 -> 자료형이 정해져 있지 않으므로 T
	tListNode<T>*			pNext;      //다음 노드의 주소를 알기 위해선 자료형이 특정 되어야 하는데 tListNode는 구조체템플릿이기 때문에 <T>를 붙여서 이를 작성하는게 맞으나,
										 //tListNode 내부에서 자기 자신을 지칭한 것은 <T>를 생략해도 구조체템플릿이라 T타입의 자료형이라는 것이 인지하기 때문에 생략해도 된다.
	tListNode*				pPrev;       //이전 노드의 주소 : 양방향으로 관리하기 위함.

public:
	//C++에서는 구조체와 class가 같으므로 생성자 소멸자도 만들 수 있음.
	tListNode()
		:data()
		,pNext(nullptr)
		,pPrev(nullptr)
	{

	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) //지정한 인자를 직접 받아 초기화를 해주고 싶을 때 사용되는 버전
		:data( _data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}

};

template<typename T>
class CList
{
	//필요한 멤버 : 노드의 시작주소 , 데이터의 갯수
private:
	tListNode<T>*		m_pHead;       //제일 처음 노드 :사용자가 특정타입 T자료형의 CList 를 호출하면 List는 T타입으로 tListNode의 주소값을 받아와야 하므로 tListNode<T>*
	tListNode<T>*	    m_pTail;       //제일 마지막 노드
	int					m_iCount;      //카운트는 정수니까 T와 관련 없음.
	
public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);	//가리키고 있는 iterator의 앞쪽으로 데이터가 추가됨.


public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>* m_pList;		//각 노드를 관리하고 있는 컨테이너인 List를 알아야함.
		tListNode<T>* m_pNode;		//내가 현재 가리키고 있는 노드 자체의 주소
										//nullptr 일 경우 end iterator 로 간주
		bool			m_bValid;		//유효성체크



	public:

		T& operator* ()
		{
			return m_pNode->data;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter && m_pNode == _otheriter.m_pNode)

				return true;
		}

		return false;

		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{	//end에서 ++한 경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator& operator ++(int) //후위
		{
			iterator copyiter(*this);	//복사본을 만들어서 그대로 복사

			++(*this);					//원본은 ++

			return copyiter;			//반환은 ++전 데이터인 복사본
		}

		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;

			return* this;

		}

		iterator& operator --(int)
		{
			iterator copyiter(*this);	//복사본을 만들어서 그대로 복사

			--(*this);					//원본은 --

			return copyiter;			//반환은 --전 데이터인 복사본

		}



	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{
			
		}
		
		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}
		
		friend class CList;
	};

};




//기존 데이터 뒤로 생성
template<typename T>
void CList<T>::push_back(const T& _data)
{
	//입력된 데이터를 저장할 노드를 동적할당 함.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);   //Node의 생성자(초기화)는 Node(구조체) 호출시 자동으로 생성자가 호출되는데, 초기화를 하고 이후에 객체의 데이터를 다시 또 입력을 하게 된다.
																		  //이러한 과정을 객체의 데이터를 바로 생성자 호출시 초기값으로 넣어주면 과정이 간소해짐.

	//예외 처리
	if (nullptr == m_pHead)
	{
		//처음 입력된 데이터라면
		m_pHead = pNewNode;
		m_pTail = pNewNode;   //m_pHead가 nullptr이라는건 데이터가 처음 입력됐다는 뜻이고, 동시에 이 데이터가 처음이자 마지막 데이터이기 때문에 phead와 동시에 pTail도 이곳을 가리켜야 함.

	}

	else
	{
		//데이터가 1개 이상에서 입력된 경우.
		//현재 가장 마지막 데이터(tail)를 저장하고 있는 노드와
		//새로 생성된 노드가 서로 가리키게 한다.(양방향으로 관리)

		m_pTail->pNext = pNewNode;     //기존에 있던 노드중 마지막 노드가 새로운 노드를 기리킨다.
		pNewNode->pPrev = m_pTail;     //새노드가 기존에 있던 노드중 마지막 노드를 가리킨다.
		
		//List가 마지막 노드의 주소값을 새로 입력된 노드로 갱신.
		m_pTail = pNewNode;
	}

	//데이터 개수 증가
	++m_iCount;

}

//기존 데이터 앞으로 생성
template<typename T>
void CList<T>::push_front(const T& _data)
{
	//새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);   //새로 들어가는 노드의 다음 노드주소 파트에는 기존 노드중 제일 첫부분(Head)의 주소값이 들어와야 하므로 호출한 객체의 m_pHead 주소가 저장되면됨.
	
	//현재 헤드노드의 이전노드 주소값을 새로 생성된 노드의 주소로 채움.
	m_pHead->pPrev = pNewNode; 

	//리스트가 새로 생성된 노드를 새로운 헤드 주소로 갱신한다.
	m_pHead = pNewNode;

	//데이터의 개수 증가
	++m_iCount;




}



//생성자 : 초기화 부분
template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)

{


}





//소멸자 : 메모리 해제 부분
template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_pHead;		//첫번째 노드의 주소부터 받아놈.

	while (pDeletNode) //반복조건 : pDeletNode가 null이 들어올때까지 -> null은 false므로 null이 들어오면 반복문 정지.
	{
		tListNode<T>* pNext = pDeletNode->pNext;  //새로운 객체선언해서 현재 지울 노드의 다음 노드주소 받아놈.
		delete(pDeletNode);
		pDeletNode = pNext;                    //반복문이 돌기 전에 받아논 다음 주소를 다시 기존 노드주소에 덮어씌우기.


	}

}


template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);	
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

//erase 함수식 코드 짜보기 (과제)
template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	return iterator();
}



template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	//예외처리 : iterator가 end iterator일 경우
	if (end() == _iter)
	{
		assert(nullptr);
	}
	
	
	//리스트에 추가되는 데이터를 저장할 공간(Node)을 추가 
	tListNode<T>* pNode = new tListNdoe<T>(_data, nullptr, nullptr); 


	//iterator 가 가리키는 노드가 헤드노드 일 경우
	if(_iter.m_pNode == m_pHead)
	{
		//기존 헤드노드의 이전 주소가 새로 생성된 노드이고
		//List가 가리키는 헤드노드가 새로 생성된 노드 주소로 바뀌어야함.

		_iter.m_pNode->pPrev = pNode;	//기존 iterator(헤드노드)의 이전주소가 새로들어올 iterator의 주소
		pNode->pNext = _iter.m_pNode;	//쌍방향

		m_pNode = pNode;

	}
	else
	{
		//iterator 가 현재 가리키고 있는 이전 노드로 가서
		//그 노드의 다음 노드 주소 파트를 새로 생성된 노드로 지정

		_iter.m_pNode->pPrev->pNext = pNode;	//
		pNode->pPrev = _iter.m_pNode->pPrev;	//쌍방향


		//iterator 가 가리키고 있는 노드의 이전을 새로운 노드로 지정
		//새로운 노드의 pNext를 iterator가 가리키고 있느 노드로 지정.
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

	}

	++m_iCount;

	//새로 삽입된 iterator를 반환.
	return iterator(this, pNode);
}



//존나게 헷갈리는 부분
//m_pHead				리스트에 저장된 헤드노드의 주소값 : 리스트가 알고있는 제일 앞 번호 노드
//m_pHead->pPrev		헤드노드(맨앞노드)의 앞노드를 가리키는 주소파트.

//m_pHead는 this->m_pHead 에서 this->가 생략된것이다. m_pHead->pPrev랑 둘이 놓고 보면 ->으로 인해 this는 리스트의 m_pHead 멤버파트 부분을 지칭하고
//m_pHead는 리스트가 가리키던 그 헤드노드 자체를 뜻하는 것으로 m_pHead-> 헤드노드의 pPrev 이전 주소 저장값 을 뜻한다.
//this가 생략되면서 m_pHead이 단독으로 나왔을 때, 헤드노드 자체를 뜻하는것으로 헷갈리지만 헤드노드를 지칭하는것이 아닌 리스트의 m_pHead파트를 지칭하는것.