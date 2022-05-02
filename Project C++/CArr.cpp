#include "CArr.h"
#include <assert.h>

//생성 함수(생성자)
CArr::CArr()  //CArr :: 의 뜻은 CArr라는 클레스 안에 생성된~ CArr() 생성자의 정의라고 해석한다.
	: m_pData(nullptr)
	, m_iCount(0)                //선언한 멤버 순서대로 초기화 해주는 것이 좋다. 이유는 나도 모름
	, m_iMaxCount(2)
{
	m_pData = new int[2];			//new : 동적할당 할 때 사용하는 키워드 -> new int[2]; : 인트 자료형 2개 어치 만큼 동적 할당한다.

}


//데이터 추가 파트
void CArr::push_back(int _Data)
{
	if (m_iMaxCount <= m_iCount)       //(this->m_iMaxCount <= this->m_iCount)이지만 this가 생략됨.
	{
		//재할당
		resize(m_iMaxCount *2);        //데이터 추가 파트에서 꽉차서 재할당 했을 때만 2배의 공간을 재생성 함.(따로 resize가 호출되었을 땐 지정된 카운트만큼 생성)

	}

	//데이터 추가
	m_pData[m_iCount++] = _Data;

}

//재할당 파트
void CArr::resize(int _iResizeCount)
{
	//예외처리
	//현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);//assert : 발생하면 안되는 특정상황을 if구문으로 특정짓고 그러한 상황이 나왔을 때, assert 경고문을 내보내서 사용자가 인식할 수 있게 해주는 매크로.
		                //즉 이 함수에서 if구문에 해당하는 특정상황이 생기면 경고처리를 해서 프로그램을 중단시키겠다는 뜻.
	}



	//1.리사이즈 시킬 개수 만큼 동적할당 한다.
	int* pNew = new int[_iResizeCount];

	//2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];             // 기존에 있던 i번째 배열의 데이터를 새로할당된 pNew의 i번째 배열에 복사
	}

	//3. 기존 공간 메모리 해제

	delete(m_pData);

	//4. 가변 배열이 가리키는 주소값을 새로 할당된 공간의 주소값으로 변경.

	m_pData = pNew;

	//5.MaxCount 변경점 적용

	m_iMaxCount = _iResizeCount;


}


// 해당class자료형을 사용하는 변수[]가 호출되면 인자에 해당하는 인덱스가 호출 되는 함수. -> 정확하게는 인덱스를 반환한 객체와 동일시 여기기 때문에 반환된 같은 값을 가진 객체이나 그곳을 수정하면 인덱스가 같이 수정됨.
// class에서는 오버로딩이 적용되기 때문에 가능.
int& CArr::operator[](int idx)
{
	return m_pData[idx];        //원본의 주소가 원본을 참조한 반환타입을 주게된다. 결과적으론 원본을 준거나 마찬가지지만, 그건 컴파일러의 입장이고 사용자 입장에선 원본이 아닌 반환타입을 준 것.
}                              //idx번째 주소값(m_pInt)을 반환한다. -> 



//해제 함수(소멸자)
CArr::~CArr()
{
	delete[] m_pData;				//delete : 동적할당 된 부분을 해제할 때 사용하는 키워드
	                                //new int[2]와 같이 여러개의 묶음을 생성했을 땐, 위와 같이 delete[] 로 적어줘야함. int* p = new int와 같이 단일 대상일 경우 delete p; 처럼 적는다. 


}




