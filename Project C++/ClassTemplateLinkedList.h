#pragma once

template<typename T>
struct tListNode						 //C++���� ����ü�� class�� ����. �ٸ� �ʵ带 �ƹ��͵� ���� �ʾ����� ����ü�� public , class�� private�̴�.
{ 

	T						data;       //����� �����Ͱ� -> �ڷ����� ������ ���� �����Ƿ� T
	tListNode<T>*			pNext;      //���� ����� �ּҸ� �˱� ���ؼ� �ڷ����� Ư�� �Ǿ�� �ϴµ� tListNode�� ����ü���ø��̱� ������ <T>�� �ٿ��� �̸� �ۼ��ϴ°� ������,
										 //tListNode ���ο��� �ڱ� �ڽ��� ��Ī�� ���� <T>�� �����ص� ����ü���ø��̶� TŸ���� �ڷ����̶�� ���� �����ϱ� ������ �����ص� �ȴ�.
	tListNode*				pPrev;       //���� ����� �ּ� : ��������� �����ϱ� ����.

public:
	//C++������ ����ü�� class�� �����Ƿ� ������ �Ҹ��ڵ� ���� �� ����.
	tListNode()
		:data()
		,pNext(nullptr)
		,pPrev(nullptr)
	{

	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) //������ ���ڸ� ���� �޾� �ʱ�ȭ�� ���ְ� ���� �� ���Ǵ� ����
		:data( _data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}

};

template<typename T>
class CList
{
	//�ʿ��� ��� : ����� �����ּ� , �������� ����
private:
	tListNode<T>*		m_pHead;       //���� ó�� ��� :����ڰ� Ư��Ÿ�� T�ڷ����� CList �� ȣ���ϸ� List�� TŸ������ tListNode�� �ּҰ��� �޾ƿ;� �ϹǷ� tListNode<T>*
	tListNode<T>*	    m_pTail;       //���� ������ ���
	int					m_iCount;      //ī��Ʈ�� �����ϱ� T�� ���� ����.
	
public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);	//����Ű�� �ִ� iterator�� �������� �����Ͱ� �߰���.


public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>* m_pList;		//�� ��带 �����ϰ� �ִ� �����̳��� List�� �˾ƾ���.
		tListNode<T>* m_pNode;		//���� ���� ����Ű�� �ִ� ��� ��ü�� �ּ�
										//nullptr �� ��� end iterator �� ����
		bool			m_bValid;		//��ȿ��üũ



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
		{	//end���� ++�� ���
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator& operator ++(int) //����
		{
			iterator copyiter(*this);	//���纻�� ���� �״�� ����

			++(*this);					//������ ++

			return copyiter;			//��ȯ�� ++�� �������� ���纻
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
			iterator copyiter(*this);	//���纻�� ���� �״�� ����

			--(*this);					//������ --

			return copyiter;			//��ȯ�� --�� �������� ���纻

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




//���� ������ �ڷ� ����
template<typename T>
void CList<T>::push_back(const T& _data)
{
	//�Էµ� �����͸� ������ ��带 �����Ҵ� ��.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);   //Node�� ������(�ʱ�ȭ)�� Node(����ü) ȣ��� �ڵ����� �����ڰ� ȣ��Ǵµ�, �ʱ�ȭ�� �ϰ� ���Ŀ� ��ü�� �����͸� �ٽ� �� �Է��� �ϰ� �ȴ�.
																		  //�̷��� ������ ��ü�� �����͸� �ٷ� ������ ȣ��� �ʱⰪ���� �־��ָ� ������ ��������.

	//���� ó��
	if (nullptr == m_pHead)
	{
		//ó�� �Էµ� �����Ͷ��
		m_pHead = pNewNode;
		m_pTail = pNewNode;   //m_pHead�� nullptr�̶�°� �����Ͱ� ó�� �Էµƴٴ� ���̰�, ���ÿ� �� �����Ͱ� ó������ ������ �������̱� ������ phead�� ���ÿ� pTail�� �̰��� �����Ѿ� ��.

	}

	else
	{
		//�����Ͱ� 1�� �̻󿡼� �Էµ� ���.
		//���� ���� ������ ������(tail)�� �����ϰ� �ִ� ����
		//���� ������ ��尡 ���� ����Ű�� �Ѵ�.(��������� ����)

		m_pTail->pNext = pNewNode;     //������ �ִ� ����� ������ ��尡 ���ο� ��带 �⸮Ų��.
		pNewNode->pPrev = m_pTail;     //����尡 ������ �ִ� ����� ������ ��带 ����Ų��.
		
		//List�� ������ ����� �ּҰ��� ���� �Էµ� ���� ����.
		m_pTail = pNewNode;
	}

	//������ ���� ����
	++m_iCount;

}

//���� ������ ������ ����
template<typename T>
void CList<T>::push_front(const T& _data)
{
	//���� ������ ����� ������ ���� ������� �ּҰ����� ä��.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);   //���� ���� ����� ���� ����ּ� ��Ʈ���� ���� ����� ���� ù�κ�(Head)�� �ּҰ��� ���;� �ϹǷ� ȣ���� ��ü�� m_pHead �ּҰ� ����Ǹ��.
	
	//���� ������� ������� �ּҰ��� ���� ������ ����� �ּҷ� ä��.
	m_pHead->pPrev = pNewNode; 

	//����Ʈ�� ���� ������ ��带 ���ο� ��� �ּҷ� �����Ѵ�.
	m_pHead = pNewNode;

	//�������� ���� ����
	++m_iCount;




}



//������ : �ʱ�ȭ �κ�
template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)

{


}





//�Ҹ��� : �޸� ���� �κ�
template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_pHead;		//ù��° ����� �ּҺ��� �޾Ƴ�.

	while (pDeletNode) //�ݺ����� : pDeletNode�� null�� ���ö����� -> null�� false�Ƿ� null�� ������ �ݺ��� ����.
	{
		tListNode<T>* pNext = pDeletNode->pNext;  //���ο� ��ü�����ؼ� ���� ���� ����� ���� ����ּ� �޾Ƴ�.
		delete(pDeletNode);
		pDeletNode = pNext;                    //�ݺ����� ���� ���� �޾Ƴ� ���� �ּҸ� �ٽ� ���� ����ּҿ� ������.


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

//erase �Լ��� �ڵ� ¥���� (����)
template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	return iterator();
}



template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	//����ó�� : iterator�� end iterator�� ���
	if (end() == _iter)
	{
		assert(nullptr);
	}
	
	
	//����Ʈ�� �߰��Ǵ� �����͸� ������ ����(Node)�� �߰� 
	tListNode<T>* pNode = new tListNdoe<T>(_data, nullptr, nullptr); 


	//iterator �� ����Ű�� ��尡 ����� �� ���
	if(_iter.m_pNode == m_pHead)
	{
		//���� ������� ���� �ּҰ� ���� ������ ����̰�
		//List�� ����Ű�� ����尡 ���� ������ ��� �ּҷ� �ٲ�����.

		_iter.m_pNode->pPrev = pNode;	//���� iterator(�����)�� �����ּҰ� ���ε��� iterator�� �ּ�
		pNode->pNext = _iter.m_pNode;	//�ֹ���

		m_pNode = pNode;

	}
	else
	{
		//iterator �� ���� ����Ű�� �ִ� ���� ���� ����
		//�� ����� ���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����

		_iter.m_pNode->pPrev->pNext = pNode;	//
		pNode->pPrev = _iter.m_pNode->pPrev;	//�ֹ���


		//iterator �� ����Ű�� �ִ� ����� ������ ���ο� ���� ����
		//���ο� ����� pNext�� iterator�� ����Ű�� �ִ� ���� ����.
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

	}

	++m_iCount;

	//���� ���Ե� iterator�� ��ȯ.
	return iterator(this, pNode);
}



//������ �򰥸��� �κ�
//m_pHead				����Ʈ�� ����� ������� �ּҰ� : ����Ʈ�� �˰��ִ� ���� �� ��ȣ ���
//m_pHead->pPrev		�����(�Ǿճ��)�� �ճ�带 ����Ű�� �ּ���Ʈ.

//m_pHead�� this->m_pHead ���� this->�� �����Ȱ��̴�. m_pHead->pPrev�� ���� ���� ���� ->���� ���� this�� ����Ʈ�� m_pHead �����Ʈ �κ��� ��Ī�ϰ�
//m_pHead�� ����Ʈ�� ����Ű�� �� ����� ��ü�� ���ϴ� ������ m_pHead-> ������� pPrev ���� �ּ� ���尪 �� ���Ѵ�.
//this�� �����Ǹ鼭 m_pHead�� �ܵ����� ������ ��, ����� ��ü�� ���ϴ°����� �򰥸����� ����带 ��Ī�ϴ°��� �ƴ� ����Ʈ�� m_pHead��Ʈ�� ��Ī�ϴ°�.