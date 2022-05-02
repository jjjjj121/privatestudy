#pragma once
#include <assert.h>

template <typename T>
class CArr				//CArr클레스는 총 16byte : T*는 사용할 os가 64비트니까 8byte이고, 나머지 int, int이기 때문에 총 16byte
{
	
private:  

	T*		m_pData;				 //int*을 찍어낼 자료형 T로 바꿔주고, 자료형이 Int로 국한된것이 아니기 때문에 변수명도 m_pInt 에서 m_pData로 바꿈.
	int		m_iCount;                //여기 int는 카운트 하기위해서 정수 자료형으로 해둔것이므로 T로 바꾸면 안된다.
	int		m_iMaxCount;


	
public:
	void push_back(const T& _Data);        //int에서 const T&로 바뀐이유. 이젠 데이터 단위가 큰 경우가 생길 수 있으므로, 기존의 방식대로 pushback한다면 pushback이라는 함수에
	                                       //기존 데이터를 복사 시킨 후 자신이 가리키고 있는 힙메모리 공간에 복사하는 형식으로 데이터가 크다면 그 데이터를 순간적으로 총 3군데에 저장이 되기 때문에 비효율적.
	                                       //따라서 원본자체의 주소값을 주거나, 참조를 하는 방식으로 변경할 필요가 있다. 다만 원본이 수정되면 안되므로 const 레퍼런스 방식을 이용.
	void resize(int _iResizeCount);      
	T* data() { return m_pData; }
	int size() { return m_iCountl; }
	int capacity() { return m_iMaxCount; }
	
	class iterator;				//begin함수는 CArr의 시작주소값을 CArr<T>::iterator에 넘겨줘야 하므로, iterator 자료형을 가지고 있어야 iterator 값으로 반환을 해줄 수 있다.
	iterator begin();			//class iterator가 begin 함수보다 나중에 나오므로, begin 함수의 자료형으로 iterator를 사용할 수 없다. 따라서 미리 iterator가 있다라고 선언을 먼저 해주는것.
								//이렇게 하지 않더라고 iterator 함수보다 뒤쪽에 begin을 선언하면 상관없다.
	iterator end();

	iterator erase(iterator& _iter);	//유효성 체크가 없을시 const지만 유효성 체크가 생기면서 수정할 여지가 생김.

	iterator clear(iterator& _ither);
	
	void clear()
	{
		m_iCount = 0;	//처음부터 데이터를 기존 데이터 무시하고 덮어씌우면 됨.
	}


	//이 클레스가 일반적인 배열의 역할을 수행 할 수 있도록
	T& operator[] (int idx); //참조하는 대상이 T타입의 자료형(자료형이 정해지지않음)을 가지고 있을 것.



public:    
	CArr();
	~CArr();

	//inner class
	//지금이 iterator class는 CArr class안에 선언되었는데, 그렇다고 해서 CArr안에 포함되어 있다고 볼 수 없다. 간혹 CArr 자료형의 크기가 총 16+iterator크기(8) 해서 총 24byte라고 생각하는데,
	//iterator는 다른 표준 자료형에서도 똑같은 이름으로 구현이 되어 이름이 중복될것을 감안하여 iterator를 호출할때 CArr<int>::iterator와 같이 지정 class안에 있는 iterator라고 호출할 수 있도록
	//inner class로 선언해놓은것이다. 
	//inner 클래스를 포함하고 있는 클래스의 private 멤버로 접근 가능. -> 자신을 포함하고 있는 클래스의 private 멤버를 이너클래스에서 접근가능.
	class iterator
	{
	private:
		CArr*	m_pArr;			//생성된 vector객체에 멤버구성중 데이터의 시작주소를 알기 때문에 그 객체를 알고 있다면 자연스럽게 데이터의 시작주소도 알 수 있는거아님?
								//따라서 데이터가 꽉차서 새로운 메모리에 공간을 할당하여 시작주소가 바뀌더라도, 바뀐 주소는 객체자체에 저장되어있기때문에 바뀐 주소값을 인식할 수 있음.
		T*		m_pData;		//데이터의 시작 주소
								//위 내용에 따라 그럼 이 멤버는 삭제해도 되지 않나? 싶지만, iterator가 받은 기존 주소와 이후에 바뀐 주소값이 달라졌을때 이를 문제삼고싶을때 필요.
								//위처럼 문제삼을시 사용자가 현재 시작주소를 사용해야할때 이전 시작주소를 사용하게되면 문제로 삼고 진행되지 않게끔 막아줄 수 있다.
								//따라서 이 멤버를 포함할지 말지는 개발자의 설계에 따라 달라질 수 있다.
		int		m_iIdx;			//인덱스 값 ex)인덱스 [2]의 데이터가 알고싶으면 2
								//이 두가지만 알면 vector의 모든 데이터를 알 수 있음. ex) 3번배열의 데이터값 -> 시작주소로부터 3번째 떨어진 곳의 데이터

		bool	m_bValid;		//iterator 유효성 체크하기 위한 멤버.

	public:
		T& operator * ()		//기존 iterator에 *이 사용되는건 벡터에 역참조 하겠다는 뜻으로 이를 구현하게 해주려면 T&로 벡터의 주소값(참조)을 반환(시켜 줘야한다.
		{						//단순히 T였다면 주소값을 반환시킨 것이 아니라 iterator에 어떤 값을 넣었을때 벡터에 그 값이 참조되지 않았을 것
			
			//iterator가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			//iterator가 end iterator 인 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx = || false == m_bValid )
			{
				assert(nullptr); //aseert : 경고창뜨게하기
			}
			
			return m_pData[m_iIdx];
		}

		//전위 ++연산
		iterator& operator ++ ()	//++(++i)의 경우 i에 +1이 대입된후 ++i가 한번 더 실행돼 총 2가 되는 식이므로 이를 구현하려면 ++연산 후 본인이 반환되어야 한다.
		{
			//2.end iterator인 경우
			//3.데이터 재할당으로 주소값이 변경된 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); //aseert : 경고창뜨게하기
			}

			//1.iterator가 마지막 데이터를 가리키고 있는 경우
			//-->end iterator가 된다. = 여기서 나는 [-1]일때 end iterator라고 보기로 함.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}

			else
			{
				++m_iIdx;				//다음 인덱스를 가리킴.
			}

			return *this;
		}

		//후위 ++연산
		iterator operator ++ (int)		//(int)인 이유는 인자에 자료형을 넣어줌으로써 ++이 후위에 붙었는지를 구분하여 호출시켜준다.
		{								//반환타입이 iterator&가 아닌 이유 : 레퍼런스는 원본 자체를 반환(참조)한다는 뜻이고, iterator는 원본을 복사한 복사본을 반환한다는 뜻.


			iterator copy_iter = *this;		//복사본iterator를 지역변수로 생성 후 *this 즉 호출한 객체의 데이터를 그대로 복사해옴.
											
			++(*this);						//호출한 객체에 iterator ++ 연산 적용.

			return copy_iter;				//결과를 반환받는 변수(객체?)는 ++연산으로 증가하지 않은 값을 반환받게됨.

		}




		//전위 --연산
		iterator& operator -- ()
		{
			return *this;
		}

		//비교연산자 ==, !=
		//둘이 같습니까?라고 물었을때 -> ==
		bool operator == (const iterator& _otheriter)		//반환타입이 true or flase이기 때문에 참거짓자료형 bool사용
		{													//iterator가 가리키는 곳이 같으면 같은 iterator로 본다.
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}

			return false;

		}

		//둘이 다릅니까? -> !=
		bool operator != (const iterator& _otheriter)		//반환타입이 true or flase이기 때문에 참거짓자료형 bool사용
		{													//iterator가 가리키는 곳이 같으면 같은 iterator로 본다.
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return false;
			}


			//return !(*this == _otheriter);			//방금 만든 ==를 사용해서 *this 즉 !=함수를 호출한 객체와 비교대상이 같은지에 대한 ==함수를 호출하여 그 결과값을 반대로하여 반환한다.
														//==와 !=는 정반대의 의미를 나타내는 기능이기 때문에 결과값이 무조건 반대로 나와야함. 따라서 이렇게 표현 할 수 있음.
														//나중에 함수구현이 복잡해진다면 이렇게 표현하는것이 이후에 보수할때에도 한쪽만 수정하면되서 간편할것.


			return true;

		}




	public:
		iterator()				//초기화(생성자)
			: m_pArr(nullptr)
			, m_pData(nullptr)	//시작주소가 아무것도 가리키고 있지 않음.
			, m_idx(-1)			//인덱스가 아무것도 가리키고 있지 않다는 의미로 -1을 기입.
			, m_bValid(false)
		{


		}
		//내가 원하는 초기값으로 생성자를 돌리고 싶을 때
		iterator(CArr* _pArr, T* _pData, int _iIdx)				
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)	
		{
			//iterator가 nullptr을 가리키고 있지 않고. 가리키고 있는 index가 유효한(end iterator는 해당안됨) 경우
			if (nullptr != _pArr && 0 <= _iIdx)	

			{
				m_bValid = true;	//구체적인 멤버값이 들어가있을경우 유효하다고 봄.
			}


		}

		~iterator()
		{

		}


		friend class CArr; //friend 는 private로 접근 불가능하게 한 것을 공유하게 만든것으로 기존 private 걸어논 의미가 없어지므로
						   //이런상황에서는 멤버함수 만들어 그 멤버함수로만 접근할 수 있도록 하는것이 좋다.
	};




};


//중요한점 ! 클레스 템플릿을 사용할 땐, 위 헤더의 선언식의 정의가 같은 헤더파일에 존재해야한다.
//클레스 템플릿은 사용자가 해당 템플릿을 호출하였을 때 비로소 만들어지는데, 이렇게 호출이 되면 호출된 자료형에 맞춰서 함수가 짜여지고, 그와 동시에 구현식도 완성이 된다.(구현식에도 자료형이 미정이기때문)
//만약 구현식을 다른 cpp에 만들어놨다면, 템플릿이 호출되었을 때 선언식에서만 치환이 일어나고, 다른 파일에 있는 구현식에는 관여가 되지 않는다. 따라서,  헤더파일에 선언식엔 T가 아니라 특정자료형으로 치환되어
//선언이 되었지만, cpp에는 아직 T타입의 자료형으로 함수가 짜여있는것. 컴파일러 입장에선 앞에서 템플릿이 int(예시)자료형으로 있을꺼라고 선언되있어서 넘어가고 cpp로 넘어왔더니 int는 없고 왠 T가있네?가 되버림.
//따라서 헤더안에 구현식까지 해줘야 템플릿이 특정타입의 함수를 찍어낼때 구현식도 함께 찍어낼 수 있는것이다.

//자료형과 함께 템플릿 호출 -> T타입에 특정 자료형을 치환하여 함수를 찍어냄(선언 및 구현식까지 함께 치환)


template <typename T>       //클레스템플릿 지칭.
CArr<T>::CArr()				//CArr 클레스의 T버전 안에 구현되어 있는 생성자를 지칭.
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

//iterator에 시작주소값을 iterator로 주기위한 begin 함수
template<typename T>
typename CArr<T>::iterator CArr<T>::begin()		//반환타입이 inner class 인 경우 앞에 typename을 붙여서 특정 타입이라고 설명을 붙여줘야 한다.
{												//만약 반환타입을 iterator&로 했다면 iterator를 참조해서 주겠다는 건데, 지역변수를 만들어서 그곳에 데이터를 넣고 전달해줘야 하는데 그곳을 참조한다는 것은
												//이 함수가 끝났을때 지역변수도 함께 사라지므로, 사라진 곳을 참조한다는 말이 된다. 따라서, 레퍼런스를 사용하면 안됨.
					

	//예외처리 : 데이터가 없는 경우, begin() == end()
	if (0 == m_icount)
		return  iterator(this, m_pDatam, -1);



	//시작을 가리키는 iterator를 만들어서 반환해줌.
	//iterator iter;
	//iter.m_pData = this->m_pData; //this-> 생략가능
	//iter.m_iIdx = 0;			  //결국 이 멤버들은 iterator에 초기값을 주는것과 마찬가지 이므로 iterator에 생성자를 하나 더 만드는 것이 좋음. 


	//iterator iter(m_pData, 0);		//생성자에 m_pData(_pData) , m_iIdx(_iIdx) 를 멤버로 구성하여 새로 만들면 이렇게 정리할 수 있다.
	//return iter;

	//위 식을 더 함축시키면
	return iterator(this, m_pData, 0);		//임시 객체라고해서 변수명조차 짓지 않고, 만들자마자 이 값을 반환하겠다는 의미로, 만든순간 말고는 접근할 방법이 없어지게됨.
											//여기서 this는 본인 자신을 뜻하는데, 이함수는 begin함수로 begin을 호출한 그 본체 자신을 가리키는것으로 그 본체는 CArr클래스 즉 가변배열(벡터)을
											//을 뜻하므로 첫번째 인자로 this가 들어가야 한다. 그래야 iterator가 메모리가 생성되어도 바뀐 가변배열(벡터)의 주소값을 찾아간다.

}

//end 함수 -> 이 end함수는 마지막 데이터의 다음 즉 NUL을 가리킨다.
template<typename T>
typename CArr<T>::iterator CArr<T>::end()		
{

	//예외처리 : 데이터가 없는 경우, begin() == end()
		return  iterator(this, m_pData, -1);

}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{		//erase함수는 iterator를 인자로 받아올 뿐 vector 안에 소속된 함수이다. iterator 소속 아님.
		//inner class에서는 상위 클래스의 private에 접근 가능하나, 반대로 상위 클래스에서 inner class에 접근 불가능.
		//접근 가능하게 하고 싶으면 inner class에서 friend class CArr(상위클래스);를 선언하면 양방향으로 접근 가능.
		//A 클래스가 friend B를 선언하면 A에서 B를 접근할 수 있는게 아닌, B에서 A를 접근할 수 있게 한것이다.


	//iterator가 다른 (배열)객체를 가리킬 경우
	//iterator가 end iterator 일 경우 (end는 마지막 데이터 다음(NUL)을 가리킴)
	//호출한 객체의 데이터 저장 갯수보다 iterator의 인덱스값이 같거나 더 클경우(데이터 저장 허용 범위를 넘어서게됨)
	if (this !=_iter.m_pArr || end() == _iter || m_iCount <=_iter.m_iIdx) 
					

		assert(nullptr);

	//iterator가 가리키는 데이터를 배열 내에서 제거한다.(반복문)

	int iLoopCount = m_iCount - (_iter + 1);	//반복문 횟수 : 전체 데이터 카운트에서 제거하려는 인덱스값 +1을 뺴면됨.

	for (int i = 0; i < iLoopCount; ++i)
	{

		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1]; //제거해야할 인덱스에 다음 인덱스 데이터가 덮어씌워줘야함.


	}

	_iter.m_iIdx = false;	//기존에 사용된 iterator는 flase 처리해서 기능상실처리

	//카운트 감소

	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx); //위 반복문으로 다음인덱스 데이터를 한칸씩 땡겨와서 저장시켰기 때문에
												  //데이터 제거한 후 데이터의 배열은 정돈이 되었으나, 기존에 iterator는 기능을 상실했기 때문에
												  //수정된 iterator를 반환하되 가리키는 곳은 기존에 가리키던 인덱스를 가리키게 한다.
}												  //반환하는 iteraotor는 복사생성자에서 유효성체크 true가 나오게 되면서 기존 iterator와 똑같은 곳을
												  //가리키고 있고, 같은 데이터가 들어간 새 iteraotor로 반환되게 된다.







template <typename T>
T& CArr<T>::operator[](int idx)    //참조하는 대상이 T자료형을 가지고 있을 것
{
	return m_pData[idx];
}



template <typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}