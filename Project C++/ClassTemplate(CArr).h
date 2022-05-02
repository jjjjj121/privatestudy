#pragma once
#include <assert.h>

template <typename T>
class CArr				//CArrŬ������ �� 16byte : T*�� ����� os�� 64��Ʈ�ϱ� 8byte�̰�, ������ int, int�̱� ������ �� 16byte
{
	
private:  

	T*		m_pData;				 //int*�� �� �ڷ��� T�� �ٲ��ְ�, �ڷ����� Int�� ���ѵȰ��� �ƴϱ� ������ ������ m_pInt ���� m_pData�� �ٲ�.
	int		m_iCount;                //���� int�� ī��Ʈ �ϱ����ؼ� ���� �ڷ������� �صа��̹Ƿ� T�� �ٲٸ� �ȵȴ�.
	int		m_iMaxCount;


	
public:
	void push_back(const T& _Data);        //int���� const T&�� �ٲ�����. ���� ������ ������ ū ��찡 ���� �� �����Ƿ�, ������ ��Ĵ�� pushback�Ѵٸ� pushback�̶�� �Լ���
	                                       //���� �����͸� ���� ��Ų �� �ڽ��� ����Ű�� �ִ� ���޸� ������ �����ϴ� �������� �����Ͱ� ũ�ٸ� �� �����͸� ���������� �� 3������ ������ �Ǳ� ������ ��ȿ����.
	                                       //���� ������ü�� �ּҰ��� �ְų�, ������ �ϴ� ������� ������ �ʿ䰡 �ִ�. �ٸ� ������ �����Ǹ� �ȵǹǷ� const ���۷��� ����� �̿�.
	void resize(int _iResizeCount);      
	T* data() { return m_pData; }
	int size() { return m_iCountl; }
	int capacity() { return m_iMaxCount; }
	
	class iterator;				//begin�Լ��� CArr�� �����ּҰ��� CArr<T>::iterator�� �Ѱ���� �ϹǷ�, iterator �ڷ����� ������ �־�� iterator ������ ��ȯ�� ���� �� �ִ�.
	iterator begin();			//class iterator�� begin �Լ����� ���߿� �����Ƿ�, begin �Լ��� �ڷ������� iterator�� ����� �� ����. ���� �̸� iterator�� �ִٶ�� ������ ���� ���ִ°�.
								//�̷��� ���� �ʴ���� iterator �Լ����� ���ʿ� begin�� �����ϸ� �������.
	iterator end();

	iterator erase(iterator& _iter);	//��ȿ�� üũ�� ������ const���� ��ȿ�� üũ�� ����鼭 ������ ������ ����.

	iterator clear(iterator& _ither);
	
	void clear()
	{
		m_iCount = 0;	//ó������ �����͸� ���� ������ �����ϰ� ������ ��.
	}


	//�� Ŭ������ �Ϲ����� �迭�� ������ ���� �� �� �ֵ���
	T& operator[] (int idx); //�����ϴ� ����� TŸ���� �ڷ���(�ڷ����� ������������)�� ������ ���� ��.



public:    
	CArr();
	~CArr();

	//inner class
	//������ iterator class�� CArr class�ȿ� ����Ǿ��µ�, �׷��ٰ� �ؼ� CArr�ȿ� ���ԵǾ� �ִٰ� �� �� ����. ��Ȥ CArr �ڷ����� ũ�Ⱑ �� 16+iteratorũ��(8) �ؼ� �� 24byte��� �����ϴµ�,
	//iterator�� �ٸ� ǥ�� �ڷ��������� �Ȱ��� �̸����� ������ �Ǿ� �̸��� �ߺ��ɰ��� �����Ͽ� iterator�� ȣ���Ҷ� CArr<int>::iterator�� ���� ���� class�ȿ� �ִ� iterator��� ȣ���� �� �ֵ���
	//inner class�� �����س������̴�. 
	//inner Ŭ������ �����ϰ� �ִ� Ŭ������ private ����� ���� ����. -> �ڽ��� �����ϰ� �ִ� Ŭ������ private ����� �̳�Ŭ�������� ���ٰ���.
	class iterator
	{
	private:
		CArr*	m_pArr;			//������ vector��ü�� ��������� �������� �����ּҸ� �˱� ������ �� ��ü�� �˰� �ִٸ� �ڿ������� �������� �����ּҵ� �� �� �ִ°žƴ�?
								//���� �����Ͱ� ������ ���ο� �޸𸮿� ������ �Ҵ��Ͽ� �����ּҰ� �ٲ����, �ٲ� �ּҴ� ��ü��ü�� ����Ǿ��ֱ⶧���� �ٲ� �ּҰ��� �ν��� �� ����.
		T*		m_pData;		//�������� ���� �ּ�
								//�� ���뿡 ���� �׷� �� ����� �����ص� ���� �ʳ�? ������, iterator�� ���� ���� �ּҿ� ���Ŀ� �ٲ� �ּҰ��� �޶������� �̸� ������������ �ʿ�.
								//��ó�� ���������� ����ڰ� ���� �����ּҸ� ����ؾ��Ҷ� ���� �����ּҸ� ����ϰԵǸ� ������ ��� ������� �ʰԲ� ������ �� �ִ�.
								//���� �� ����� �������� ������ �������� ���迡 ���� �޶��� �� �ִ�.
		int		m_iIdx;			//�ε��� �� ex)�ε��� [2]�� �����Ͱ� �˰������ 2
								//�� �ΰ����� �˸� vector�� ��� �����͸� �� �� ����. ex) 3���迭�� �����Ͱ� -> �����ּҷκ��� 3��° ������ ���� ������

		bool	m_bValid;		//iterator ��ȿ�� üũ�ϱ� ���� ���.

	public:
		T& operator * ()		//���� iterator�� *�� ���Ǵ°� ���Ϳ� ������ �ϰڴٴ� ������ �̸� �����ϰ� ���ַ��� T&�� ������ �ּҰ�(����)�� ��ȯ(���� ����Ѵ�.
		{						//�ܼ��� T���ٸ� �ּҰ��� ��ȯ��Ų ���� �ƴ϶� iterator�� � ���� �־����� ���Ϳ� �� ���� �������� �ʾ��� ��
			
			//iterator�� �˰��ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			//iterator�� end iterator �� ���
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx = || false == m_bValid )
			{
				assert(nullptr); //aseert : ���â�߰��ϱ�
			}
			
			return m_pData[m_iIdx];
		}

		//���� ++����
		iterator& operator ++ ()	//++(++i)�� ��� i�� +1�� ���Ե��� ++i�� �ѹ� �� ����� �� 2�� �Ǵ� ���̹Ƿ� �̸� �����Ϸ��� ++���� �� ������ ��ȯ�Ǿ�� �Ѵ�.
		{
			//2.end iterator�� ���
			//3.������ ���Ҵ����� �ּҰ��� ����� ���
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); //aseert : ���â�߰��ϱ�
			}

			//1.iterator�� ������ �����͸� ����Ű�� �ִ� ���
			//-->end iterator�� �ȴ�. = ���⼭ ���� [-1]�϶� end iterator��� ����� ��.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}

			else
			{
				++m_iIdx;				//���� �ε����� ����Ŵ.
			}

			return *this;
		}

		//���� ++����
		iterator operator ++ (int)		//(int)�� ������ ���ڿ� �ڷ����� �־������ν� ++�� ������ �پ������� �����Ͽ� ȣ������ش�.
		{								//��ȯŸ���� iterator&�� �ƴ� ���� : ���۷����� ���� ��ü�� ��ȯ(����)�Ѵٴ� ���̰�, iterator�� ������ ������ ���纻�� ��ȯ�Ѵٴ� ��.


			iterator copy_iter = *this;		//���纻iterator�� ���������� ���� �� *this �� ȣ���� ��ü�� �����͸� �״�� �����ؿ�.
											
			++(*this);						//ȣ���� ��ü�� iterator ++ ���� ����.

			return copy_iter;				//����� ��ȯ�޴� ����(��ü?)�� ++�������� �������� ���� ���� ��ȯ�ްԵ�.

		}




		//���� --����
		iterator& operator -- ()
		{
			return *this;
		}

		//�񱳿����� ==, !=
		//���� �����ϱ�?��� �������� -> ==
		bool operator == (const iterator& _otheriter)		//��ȯŸ���� true or flase�̱� ������ �������ڷ��� bool���
		{													//iterator�� ����Ű�� ���� ������ ���� iterator�� ����.
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}

			return false;

		}

		//���� �ٸ��ϱ�? -> !=
		bool operator != (const iterator& _otheriter)		//��ȯŸ���� true or flase�̱� ������ �������ڷ��� bool���
		{													//iterator�� ����Ű�� ���� ������ ���� iterator�� ����.
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return false;
			}


			//return !(*this == _otheriter);			//��� ���� ==�� ����ؼ� *this �� !=�Լ��� ȣ���� ��ü�� �񱳴���� �������� ���� ==�Լ��� ȣ���Ͽ� �� ������� �ݴ���Ͽ� ��ȯ�Ѵ�.
														//==�� !=�� ���ݴ��� �ǹ̸� ��Ÿ���� ����̱� ������ ������� ������ �ݴ�� ���;���. ���� �̷��� ǥ�� �� �� ����.
														//���߿� �Լ������� ���������ٸ� �̷��� ǥ���ϴ°��� ���Ŀ� �����Ҷ����� ���ʸ� �����ϸ�Ǽ� �����Ұ�.


			return true;

		}




	public:
		iterator()				//�ʱ�ȭ(������)
			: m_pArr(nullptr)
			, m_pData(nullptr)	//�����ּҰ� �ƹ��͵� ����Ű�� ���� ����.
			, m_idx(-1)			//�ε����� �ƹ��͵� ����Ű�� ���� �ʴٴ� �ǹ̷� -1�� ����.
			, m_bValid(false)
		{


		}
		//���� ���ϴ� �ʱⰪ���� �����ڸ� ������ ���� ��
		iterator(CArr* _pArr, T* _pData, int _iIdx)				
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)	
		{
			//iterator�� nullptr�� ����Ű�� ���� �ʰ�. ����Ű�� �ִ� index�� ��ȿ��(end iterator�� �ش�ȵ�) ���
			if (nullptr != _pArr && 0 <= _iIdx)	

			{
				m_bValid = true;	//��ü���� ������� ��������� ��ȿ�ϴٰ� ��.
			}


		}

		~iterator()
		{

		}


		friend class CArr; //friend �� private�� ���� �Ұ����ϰ� �� ���� �����ϰ� ��������� ���� private �ɾ�� �ǹ̰� �������Ƿ�
						   //�̷���Ȳ������ ����Լ� ����� �� ����Լ��θ� ������ �� �ֵ��� �ϴ°��� ����.
	};




};


//�߿����� ! Ŭ���� ���ø��� ����� ��, �� ����� ������� ���ǰ� ���� ������Ͽ� �����ؾ��Ѵ�.
//Ŭ���� ���ø��� ����ڰ� �ش� ���ø��� ȣ���Ͽ��� �� ��μ� ��������µ�, �̷��� ȣ���� �Ǹ� ȣ��� �ڷ����� ���缭 �Լ��� ¥������, �׿� ���ÿ� �����ĵ� �ϼ��� �ȴ�.(�����Ŀ��� �ڷ����� �����̱⶧��)
//���� �������� �ٸ� cpp�� �������ٸ�, ���ø��� ȣ��Ǿ��� �� ����Ŀ����� ġȯ�� �Ͼ��, �ٸ� ���Ͽ� �ִ� �����Ŀ��� ������ ���� �ʴ´�. ����,  ������Ͽ� ����Ŀ� T�� �ƴ϶� Ư���ڷ������� ġȯ�Ǿ�
//������ �Ǿ�����, cpp���� ���� TŸ���� �ڷ������� �Լ��� ¥���ִ°�. �����Ϸ� ���忡�� �տ��� ���ø��� int(����)�ڷ������� ��������� ������־ �Ѿ�� cpp�� �Ѿ�Դ��� int�� ���� �� T���ֳ�?�� �ǹ���.
//���� ����ȿ� �����ı��� ����� ���ø��� Ư��Ÿ���� �Լ��� ���� �����ĵ� �Բ� �� �� �ִ°��̴�.

//�ڷ����� �Բ� ���ø� ȣ�� -> TŸ�Կ� Ư�� �ڷ����� ġȯ�Ͽ� �Լ��� ��(���� �� �����ı��� �Բ� ġȯ)


template <typename T>       //Ŭ�������ø� ��Ī.
CArr<T>::CArr()				//CArr Ŭ������ T���� �ȿ� �����Ǿ� �ִ� �����ڸ� ��Ī.
	: m_pData(nullptr)
	, m_iCount(0)                
	, m_iMaxCount(2)
{
	m_pData = new T[2];			

}


template <typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)       
	{
		
		resize(m_iMaxCount * 2);        

	}

	m_pData[m_iCount++] = _Data;

}

template <typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);

	}


	T* pNew = new T[_iResizeCount];

	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];            
	}


	delete(m_pData);


	m_pData = pNew;


	m_iMaxCount = _iResizeCount;


}

//iterator�� �����ּҰ��� iterator�� �ֱ����� begin �Լ�
template<typename T>
typename CArr<T>::iterator CArr<T>::begin()		//��ȯŸ���� inner class �� ��� �տ� typename�� �ٿ��� Ư�� Ÿ���̶�� ������ �ٿ���� �Ѵ�.
{												//���� ��ȯŸ���� iterator&�� �ߴٸ� iterator�� �����ؼ� �ְڴٴ� �ǵ�, ���������� ���� �װ��� �����͸� �ְ� ��������� �ϴµ� �װ��� �����Ѵٴ� ����
												//�� �Լ��� �������� ���������� �Բ� ������Ƿ�, ����� ���� �����Ѵٴ� ���� �ȴ�. ����, ���۷����� ����ϸ� �ȵ�.
					

	//����ó�� : �����Ͱ� ���� ���, begin() == end()
	if (0 == m_icount)
		return  iterator(this, m_pDatam, -1);



	//������ ����Ű�� iterator�� ���� ��ȯ����.
	//iterator iter;
	//iter.m_pData = this->m_pData; //this-> ��������
	//iter.m_iIdx = 0;			  //�ᱹ �� ������� iterator�� �ʱⰪ�� �ִ°Ͱ� �������� �̹Ƿ� iterator�� �����ڸ� �ϳ� �� ����� ���� ����. 


	//iterator iter(m_pData, 0);		//�����ڿ� m_pData(_pData) , m_iIdx(_iIdx) �� ����� �����Ͽ� ���� ����� �̷��� ������ �� �ִ�.
	//return iter;

	//�� ���� �� �����Ű��
	return iterator(this, m_pData, 0);		//�ӽ� ��ü����ؼ� ���������� ���� �ʰ�, �����ڸ��� �� ���� ��ȯ�ϰڴٴ� �ǹ̷�, ������� ����� ������ ����� �������Ե�.
											//���⼭ this�� ���� �ڽ��� ���ϴµ�, ���Լ��� begin�Լ��� begin�� ȣ���� �� ��ü �ڽ��� ����Ű�°����� �� ��ü�� CArrŬ���� �� �����迭(����)��
											//�� ���ϹǷ� ù��° ���ڷ� this�� ���� �Ѵ�. �׷��� iterator�� �޸𸮰� �����Ǿ �ٲ� �����迭(����)�� �ּҰ��� ã�ư���.

}

//end �Լ� -> �� end�Լ��� ������ �������� ���� �� NUL�� ����Ų��.
template<typename T>
typename CArr<T>::iterator CArr<T>::end()		
{

	//����ó�� : �����Ͱ� ���� ���, begin() == end()
		return  iterator(this, m_pData, -1);

}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{		//erase�Լ��� iterator�� ���ڷ� �޾ƿ� �� vector �ȿ� �Ҽӵ� �Լ��̴�. iterator �Ҽ� �ƴ�.
		//inner class������ ���� Ŭ������ private�� ���� �����ϳ�, �ݴ�� ���� Ŭ�������� inner class�� ���� �Ұ���.
		//���� �����ϰ� �ϰ� ������ inner class���� friend class CArr(����Ŭ����);�� �����ϸ� ��������� ���� ����.
		//A Ŭ������ friend B�� �����ϸ� A���� B�� ������ �� �ִ°� �ƴ�, B���� A�� ������ �� �ְ� �Ѱ��̴�.


	//iterator�� �ٸ� (�迭)��ü�� ����ų ���
	//iterator�� end iterator �� ��� (end�� ������ ������ ����(NUL)�� ����Ŵ)
	//ȣ���� ��ü�� ������ ���� �������� iterator�� �ε������� ���ų� �� Ŭ���(������ ���� ��� ������ �Ѿ�Ե�)
	if (this !=_iter.m_pArr || end() == _iter || m_iCount <=_iter.m_iIdx) 
					

		assert(nullptr);

	//iterator�� ����Ű�� �����͸� �迭 ������ �����Ѵ�.(�ݺ���)

	int iLoopCount = m_iCount - (_iter + 1);	//�ݺ��� Ƚ�� : ��ü ������ ī��Ʈ���� �����Ϸ��� �ε����� +1�� �����.

	for (int i = 0; i < iLoopCount; ++i)
	{

		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1]; //�����ؾ��� �ε����� ���� �ε��� �����Ͱ� ����������.


	}

	_iter.m_iIdx = false;	//������ ���� iterator�� flase ó���ؼ� ��ɻ��ó��

	//ī��Ʈ ����

	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx); //�� �ݺ������� �����ε��� �����͸� ��ĭ�� ���ܿͼ� ������ױ� ������
												  //������ ������ �� �������� �迭�� ������ �Ǿ�����, ������ iterator�� ����� ����߱� ������
												  //������ iterator�� ��ȯ�ϵ� ����Ű�� ���� ������ ����Ű�� �ε����� ����Ű�� �Ѵ�.
}												  //��ȯ�ϴ� iteraotor�� ��������ڿ��� ��ȿ��üũ true�� ������ �Ǹ鼭 ���� iterator�� �Ȱ��� ����
												  //����Ű�� �ְ�, ���� �����Ͱ� �� �� iteraotor�� ��ȯ�ǰ� �ȴ�.







template <typename T>
T& CArr<T>::operator[](int idx)    //�����ϴ� ����� T�ڷ����� ������ ���� ��
{
	return m_pData[idx];
}



template <typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}