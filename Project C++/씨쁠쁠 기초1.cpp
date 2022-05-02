#include <iostream>
#include "Arr.h"
#include "ClassTemplateLinkedList.h"
#include "ClassTemplate(CArr).h"

using namespace std;



//C++에서 헷갈리는 부분 정리
//포인터(*)와 레퍼런스(&)의 차이
//포인터 : 주소값을 받음->포인터변수에 주소값 저장 -> 역참조가능
//레퍼런스 :변수를 받음->레퍼런스 변수와 원본을 동일시함 -> 원본에 참조가능


//쉽게 얘기하면 int &변수 = 원본변수에서 변수앞에 레퍼런스가 붙었으므로 변수는 원본변수의 또다른 이름이라고 생각하면 편하다.
//한마디로 분신임. 따라서 변수에 어떠한 값을 대입하면 원본변수의 데이터를 대입한것과 똑같은 것. 따라서 원본에 참조 가능한것으로 본다.






//구조체 : 사용자 정의 자료형
// 기존에 배웠던 구조체 선언에서 typedef struct 라고 했었는데, typedef의 재정의는 구조체 선언에서 C++에서는 필요가 없기 때문에 이 수업부터는 이제 C언어를 제외한 C++만을 생각할 것이므로
// typedef를 빼고 struct만 해서 구조체 선언을 해도 된다.
//class : 또한 사용자 정의 자료형

struct tMy
{


};

class CMy
{
	//접근 제한 지정자
	//private(비공개), protected(상속), public(공개)
private:                   //:로 필드로 지정. 이 아래 적힌 멤버들은 private(=비공개) 처리이다. 건들지 못한다.
	                       //반대는 public 으로 공개처리.
	int m_i;			   //이 멤버는 비공개처리된다.
	float m_f;

public:
	//멤버함수
	void SetInt(int i)		//클레스 CMy 에서만 사용되는 멤버함수.
	{						//i값을 세팅해주면 private의 멤버인 m_i에 i를 간접적으로 넣어주는 역할.
		m_i = i;            //m_i는 비공개이기 때문에 직접적으로 c.m_i = 1;와 같이 수정할 순 없지만 c.SetInt(10);와 같이 접근하면 수정할 수 있음.
	}

	//대입 연산자
	//기존에 우리가 사용하던 연산자들은 기본 자료형을 바탕으로 하기 때문에, 따로 함수식을 하지 않더라도 사용할 수 있었지만, 내가만든 자료형을 사용하는 클레스끼리의 연산은 어떻게 작동하는가?
	//클레스에서의 대입 연산자는 내가 만들지 않아도 클레스 내에서 자동으로 만들어 주기 때문에 CMy객체 a,b에 대하여 a = b;라는 식이 객체안에 멤버가 다양한데 b의 멤버 데이터값이 a에 하나하나 복사될 수 있었던것.
	//그러나 그 외의 연산자들은 사용자가 직접 만들어야 한다.
	CMy& operator= (const CMy& _Other)		//공식 : 'operator = '는 해당 클레스쪽의 =(대입연산자)가 발생했을 때 호출된다는 뜻.
	{										//멤버함수 operator는 CMy 객체를 참조할 것이고, 추가인자는 데이터를 수정하면 안되기 때문에 const레퍼런스 사용.
		m_i = _Other.m_i;
		this->m_f = _Other.m_f;             //위멤버와 아래멤버식은 결국 같은말로 this가 생략된 것이고, this에는 이미 이 객체의 주소값이 다 들어가 있기 때문에 operator가 객체에 바로 참조 가능.

		return *this;						//반환타입이 *this인 이유는 연산시 반환값이 없다면 c = c2 = c3에서 우선순위로 c2 = c3가 먼저 연산되는데, 연산 후 반환값이 없으면 그 다음연산식은 c = ; 가 되버린다.
		                                    //따라서 반환값이 있어야 하고, 연산식에서 좌변(객체)의 정보가 반환이 되어야 다음 연산식이 정상적으로 돌아가므로 *this로 객체의 정보를 반환하는것
	}

public:
	//생성자(초기화 함수)
	//생성자 함수는 CMy클레스의 객체가 만들어질 때 자동으로 호출된다.
	//CMy()
	//{
	//	m_i = 100;         //이 함수는 생성자 초기화를 주는데 사실상 완벽한 초기화는 아니다. 그 이유는 함수,객체가 만들어지면서 초기값이 동시에 들어가는것을 초기화라 하는데
	//}                    //지금까지의 함수 초기화들은 함수,객체가 선언(생성)되고 제로값을 우리가 넣어서 초기화를 시킨것이기 때문.
	
	//이니셜라이져 : 위 와같은 이유로 생성과 동시에 초기화를 시키는 방식이 존재.
	CMy()
		:m_i(100), m_f(0.f)        //멤버가 여러개면 ,로 뒤이어 붙여주기.
	{
	}

	//소멸자 : 객체가 소멸될 때 자동으로 호출되게 해주는 문법
	//동적할당의 경우 객체가 소멸할 때, 메모리값을 해제해줘야하므로 그럴 때 용이함.
	~CMy()
	{

	}
	//디폴트생성자(기본 생성자), 디폴트소멸자(기본 소멸자)
	//위 생성자와 소멸자등을 작성하지 않아도 프로그램이 이 객체를 호출할때 자동으로 생성자와 소멸자를 만들어서 호출하게 된다.
	//단, 이렇게 호출된 생성자와 소멸자는 아무기능이 없고 구색만을 갖추는 형식이다.

};


int main()
{
	
	//C++ 클래스 특징
	//생성자, 소멸자
	//객채 생성, 소멸 시 자동으로 호출
	//직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐.

	//멤버 함수
	//해당 클래스가 사용하는 전용 함수.
	//해당 클래스의 객체 필요(객체.멤버함수 ->와 같이 호출되어야만 다른 지역에서 사용 가능하다.)
	//멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달된다.


	//void PushBack(tArr * _pArr, int _iData) 데이터를 넣는 역할의 이 함수의 인자는 들어갈 데이터와, 데이터가 들어갈 곳의 주소값인 객체의 주소값이 반드시 들어가야 한다.
	//다만, tArr자료형을 가진 어떠한 객체에서도 사용 가능하도록 만든 목적이기 때문에, 인자자체에 그 호출한 객체의 주소값을 적어라.라고 해논것.
	//하지만 멤버함수는 이미 호출한 객체가 정해져있기 때문에, 이 함수를 호출한 객체의 주소값을 이미 알고있는것이나 마찬가지이다.

	/*void SetInt(CMy* _this, int i)
	{
		this->m_i = i;                 //원래라면 이렇게 함수를 만들어줘야 하지만, 객체의 주소값을 이미 알고있다고 판단하여 객체에 관련된 주소값,멤버지칭 등은 생략하여도 상관없다.
	}*/                                 //객체에 관련된 자료들은 This 키워드가 자리하고 있고, 객체와 함께 호출되면서 this키워드에 자동으로 입력되는 형식이다.
	                                    //따라서 이 함수의 호출방식이 객체가 필요로 한 이유 중 하나이다. ex) c.SetInt(10);


	{



		//자료형 * 변수명; -> 자료형 포인터타입인 변수 : 포인터 변수 선언
		//*포인터 변수; -> 포인터 변수에 저장되어 있는 주소를 역참조 하는것.
		//&변수; ->변수 본인의 주소값을 반환하라
		//자료형 & 변수명; -> 레퍼런스 변수 선언

		//레퍼런스
		//C++에 추가된 기능으로 포인터와 유사하다.
		//원본을 참조한다.
		//참조변수를 통해서 직접적으로 원본을 수정 할 수 있다.
	

		int a = 10;         //a라는 변수가 있고 10이 들어있다.
		int* p = &a;        //a의 주소를 p가 받아와서
		*p = 100;           //p가 주소를 역참조해서 100을 넣는다.


		int& iRef = a;		//iRef가 a를 참조하기 때문에(iRef와 a는 동일취급한다)
		iRef = 100;         //iRef에 100을 넣는건 결국 a에 100을 넣는것이다.

		//포인터와 레퍼런스는 결국 하는 역할은 똑같다.
		//차이점이라면 레퍼런스는 포인터 콘스트 타입과 같다 int* const p <-- 포인터 변수가 상수화이므로 다른 주소를 가리킬 수 없고, 레퍼런스가 이런 특징을 가지고 있다.
		//따라서 포인터 변수는 역참조 연산을 명시해줘야 원본으로 접근해줄 수 있지만, 레퍼런스는 본인이 참조 받자마자 그 원본을 수정 할 수 있음.
		//결과적으로 같은 역할이지만 사용자 입장에선 실수할 여지가 적어짐.

		//레퍼런스에서 원본수정을 못하게 하고싶다면?
		//콘스트 포인터와 같이 콘스트 레퍼런스 형태를 이루면됨.
		const int& iRefConst = a;
		//콘스트 레퍼런스는 결국 const int* const 와 같은 뜻이다.


	}




	//C++ 동적할당 new , delete
	//malloc은 어떤 자료형이 들어오던 그저 메모리 공간 생성하라니까 생성하라는 느낌이면, new는 어떤 자료형이 들어오는건지 판단한 후에 공간을 생성해주는 느낌이다.
	//그 이유는 new라는 키워드는 C++에서 생성자와 소멸자와 같이 호출만하면 자동으로 이 함수들의 기능을 수행해주도록 하는데, 이렇게 컴파일러가 자동으로 힙메모리를 생성할 시
	//malloc의 경우는 어떤 자료형이 들어올 지 모르기 때문에 컴파일러에겐 불확실성이 높아진다. class는 생성자와 소멸자가 필수적으로 호출이 되야하는 자료형이다. 따라서, 생성자와 소멸자의 호출이 되려면
	//해당 객체에 대한 정보를 알아야 하는데, malloc의 경우 앞서 말한 불확실성으로 인해 적합하지 않은 반면, new의 경우는 메모리 생성 후 객체의 자료형을 받아오면서 이후에 생성자 호출이 발생 시, 문제가
	// 없도록 해준다.  따라서 malloc 에서는 size를 받아갔다면, new는 자료형을 받아간다.
	
	//delete도 마찬가지로 해제진행 시 자동으로 해당 객체의 자료형을 받아 가면서 소멸자호출에 문제가 없도록 하는 것.


#include "CArr.h"
	//CArr (C++ 가변배열) 사용예제

	CArr carr; //이렇게 선언만 하더라도 생성자가 호출된것.
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	//소멸은 호출할 필요 없음 : carr가 지역변수 이기 때문에 이 함수가 끝났을때 자동으로 소멸자함수가 호출되어 해제시켜줌.
	
	//사용자 정의 자료형으로 만든 가변배열은 사실상 함수이지 배열은 아니다.
	//배열 []처럼 같은 역할을 수행할 수 있게 만들고 싶다면? -> []를 operator로 배열과 같은 역할을 할 수 있도록 함수를 정의해준다.

	int iData = carr[1];  //배열[1]에 있는 인덱스를 확인 할 수 있고,
	carr[1] = 100;        //배열[1] 인덱스에 100을 넣을 수 있다.

	//자세한 사항은 CArr.h와 CArr.cpp 파일에 설명이 있으니 참고하자.

	

}

//함수 템플릿(틀)
//함수의 틀을 짜놓은 것으로, 어떤 역할을 하도록 함수의 틀을 만들언 놓고, 이 함수 템플릿이 호출이 되었을 때 비로소 함수가 만들어지는 방식이다.
//따라서 호출이 되지 않으면 템플릿은 코드안에 존재하지 않는 것처럼 인식된다. 자료형과 함께 함수템플릿을 호출하면 그 버전의 함수가 그제서야 만들어짐.
//장점 : 기존 Add함수를 생각하면 정수는 정수끼리 실수는 실수끼리 연산이 가능하기 때문에, 정수형 자료형 Add함수 , 실수형 자료형 Add함수 총 2개의 함수를 만들었어야 했다.
//그러나 함수 템플릿을 사용하면 T에 들어가는 자료형이 무엇이냐에 따라 호출했을때 자료형에 맞는 함수를 찍어내기 때문에, 효율적임.

template<typename T>  //Typename 또는 class을 적어준다. 여기서의 class는 사용자정의자료형 class가 아니다.
T Add(T a, T b)       //typename 뒤에 T는 치환부분으로 이 함수를 호출했을 때의 자료형으로 치환되어 호출된다.
{
	return a + b;
}


int i = Add<int>(10, 20);  //T부분에 int가 들어간 Add함수 템플릿을 호출.
int i = Add(10, 20);       //Add의 반환값을 받아가는 i의 자료형이 int이므로 자연스럽게 T부분이 int가 되어야 받아갈 수 있기 때문에 <int>를 생략해도 컴파일러가 int로 인식해줌.
						   //엄밀히 말하면 Add는 함수가 아닌 함수 템플릿으로 서로 구분지어 생각해야함.






//클래스 템플릿
//선언식과 구현함수가 같은 헤더파일에 구현되야함 -> 클레스 템플릿은 타입을 정해놓지 않기 때문에 호출되었을 때 특정타입으로 치환시켜 함수생성. 같은 파일에 있어야 구현식도 같이 치환되어 생성.
//ClassTemplate.h 참조

//호출방법
#include "ClassTemplate(CArr).h"
int main()
{
	CArr<float> cArr; //float 자료형을 목적으로 하는 CArr클래스 템플릿을 호출하여 객체 cArr으로 생성.

}




//클래스 템플릿 리스트

//호출방법
#include "ClassTemplateLinkedList.h"
int main()
{
	
	CList<float> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);

	}

	//C++에서의 출력 입력 키워드
	
	printf("안녕", 10); //기존 사용하던 C언어의 printf

	//c prinf 역할
	std::cout << "안녕" << 10 << std::endl;  //"안녕"에 L이 안붙었으므로 1byte

	wcout << L"안녕" << 10;					//"안녕"에 L이 붙었으므로 각각 2byte


	//c scanf 역할

	int iInput = 0;
	std::cin >> iInput;


	return 0;

}
// <<는 비트연산자인데 왜 저렇게 작동하는가?
	//cout, cin은 객체명(변수명)이고, 
	//
	 

void MyEndL()       //반환타입 void , 인자도 받지않음.
{
	wprintf(L"\n"); //계획문자를 콘솔창에 출력 == 커서가 한줄 아래로 내려감.
}

class CMyOStream
{

public :
	//cout 구현
	CMyOStream& operator << (int _iData)
	{
		printf("%d", _iData);  // <<가 시행될때 문자를 출력해줌.

		return *this;    //리턴타입이 본인 자신의 주소값이여야함. 그래야 cout << "안녕" << 10 << endl 
	}

	//wchar 일때 cout 구현
	CMyOStream& operator << (const wchar_t* _pString)
	{
		printf("&s", _pString);
		return *this;

	}

	//endl 구현
	CMyOStream& operator << (void(*_pFunc)(void))  //MyEndL과 같이 void타입의 void타입 인자를 반환하는 데이터를 인자로 하여 식의 마지막이 << MyEndL 이 되었을때 커서가 다음줄로 넘어가게끔 한다.
	{
		_pFunc();         //받아온 애를 호출해준다.
		return *this;

	}


	//
	CMyOStream& operator >> (int& _iData)
	{
		scanf_s("%d", &_iData);
		return *this;

	}

};




CMyOStream mycout; //class 안에 아무것도 적지 않아도 자동으로 1byte가 할당이 된다.





// :: <- 범위 지정 연산자
// CTest :: MemberFunc(); CTest 클레스 안에 선언 되어 있는 멤버함수 MemberFunc

//namespace : 네임스페이스 : 이름 공간

//std::cout , std::cin
//std라는 네임스페이스 안에 cout, cin이 구현이 되어 있기 때문(단 iostream.h를 참조해야함)에 ::을 이용해 std안에 cout 호출
//이렇게 네임스페이스를 하는 이유는 헤더 참조시 헤더안에 std 네임스페이스가 구현이 되어 있는데, 사용자가 사용하는 변수의 이름이 cout, cin과 같이 곂치게 된다면
//변수명이 중복이 되므로 구분짓기 위해 네임스페이스 안에 넣어서 구분지어 주는것.

//만약 std :: 를 매번 하는것이 귀찮고, 난 변수명이 중복이 될 수 없게 만들것이기 때문에 그냥 cout, cin만을 가져다 쓰고싶다. 라고한다면
//using namespace std; //라고 선언하면, 네임스페이스 std를 사용하겠다는 뜻으로 인식되어져 바로 cout, cin을 사용할 수 있지만, 이렇게되면 네임스페이스 자체의 기능을 잃기 때문에
					 //네임스페이스로 나눠논 의미가 사라지고, 중복이 생길 가능성이 생기기 때문에 애매해진다.
					 
//따라서 이런 리스크를 조금이나마 줄이기 위해 네임스페이스 자체를 없애는게 아닌, 네임스페이스 안에 몇개의 부분만을 사용하겠다고 할 수 있다.
using std::cout;
using std::cin;




#include <vector>   //표준으로 제공된 벡터     , 템플릿으로 구성
#include <list>     //표준으로 제공된 리스트   , 템플릿으로 구성


using namespace std;

int main()
{
	vector<int> vecInt;		//int 자료형을 사용하는 벡터 객체 vecInt; 선언
	vecInt.push_back(10);
	vecInt.push_back(20);   //벡터(가변배열)은 동적할당 및 데이터 기입 구조가 푸쉬백형태이고, 푸쉬프론트 형태를 할 것이라면 벡터보단 리스트가 어울리기 때문에 표준 벡터에선 푸쉬프론트 함수가 구현 x
	vecInt.at(1);			//==vecInt[1]; 와 같은말로 특정 인덱스로 접근하라는 뜻.
	vecInt.data();			//데이터의 시작주소를 보내주는 역할
	vecInt.size();			//현재 내가 데이터를 몇개 넣었는지
	vecInt.capacity();		//현재 기준으로 몇칸까지가 허용 범위인지(최대값)


	//벡터안에 데이터를 순회하면서 하나씩 체크(출력)하는 법

	for (size_t i = 0; i < vecInt.size(); ++i)	//size_t는 벡터의 반환타입이 size_t이기 때문 = __int == long long 자료형을 재정의 한것일 뿐임.
	{										//i < vecInt.size == 벡터의 내가 넣어논 데이터 갯수만큼 반복문이 돌아간다.
		cout << vecInt[i] << endl;			//반복문 돌 때마다 벡터의 i번째 인덱스를 출력
	}





	list<int> listInt;		//int자료형을 사용하는 리스트 객체 listInt 선언
	listInt.push_back(10);
	listInt.push_front(20);
	listInt.size();
	listInt capacity();		//리스트에는 케퍼시티가 없는 이유가 벡터은 최대값에 다다르면 새로 생성하고 하지만 리스트는 데이터 넣을때 마다 그때그때 새로 생성하므로 최대값이 무의미하다.


	//iterator (반복자, inner class)
	//컨테이너안에 저장되어 있는 모든 원소들을 전체적으로 훑어 나갈 때 사용.
	//컨테이너와 컨테이너 안의 있는 요소를 구별
	//요소의 값을 확인
	//컨테이너 안에 있는 요소들 간에 이동할 수 있는 연산을 제공
	//컨테이너가 효과적으로 처리할 수 있는 방식으로 가용한 연산들을 한정.

	list<int> ::iterator iter;	//class(list) 안에 class(iterator)가 구현되어 있음 : inner class, 포함 class 라고도 함.
	list<int> ::iterator iter = listInt.begin();	//iter는 listInt 안에 begin(첫번째) 데이터를 가리켜라. -> 정확히는 첫번째 노드지만 사용자가 그것까지 알 필요가 없도록 구현되있음.
	int iData = *iter;			//여기서 iter는 마치 포인터처럼 listInt의 첫번째 노드의 데이터를 받아서 그안에 있는 데이터를 역참조해서 iData 넣어 확인할 수 있게 해준다.
								//하지만 iter는 iterator라는 class의 객체일뿐이다. 하지만 가리키고 있는 데이터를 역참조하는 느낌을 주기 위해서 앞에 *이 붙으면 같은 역할을 할 수 있게
								//operator를 통해 오버로딩 해놓은것.

	for (iter = listInt.begin(); iter != listInt.end(); ++iter)  // 리스트(컨테이너)안에 데이터를 iterator돌려서 출력하고 싶을때.
																 // 초기화를 컨테이너의 시작주소를 넣어주고, 반복횟수는 컨테이너의 마지막과 같아진다면 끝나도록 설정, ++로 한단계씩 추가
																 // 단, 여기서 listInt.end()는 컨테이너의 마지막 원소 즉 리스트의 마지막 노드를 가리키는 것이 아니다.
																 // 마지막 노드를 가리키고 있다면, 반복문이 끝까지 돌았을 때, 마지막 노드와 값이 같아지게 되고, 결과적으로 마지막노드의 데이터는 출력되지 않는다.
																 // 따라서 listInt.end()는 마지막 원소의 바로 다음번 원소를 가리킨다. 결과적으로 NUL을 가리키게 되는것.
	{
		cout << *iter << endl;
	}

	//직접 구현한 iterator 사용해보기

	//int 자료형을 CArr클레스의 객체 myvoector 생성
	CArr<int> myvector;

	//객체에 데이터 생성
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);

	//iterator 객체 myiter 선언하면서 그안에 myvector의 begin파트 데이터를 가리켜라 지시.
	CArr<int>::iterator myiter = myvector.begin();



	vector<int>::iterator veciter = vecInt.begin(); //vector<int> 안에 있는 iterator라는 class의 객체 veciter를 생성 그리고 그 veciter는 vecInt의 begin파트 데이터를 가리켜라.
													//표준헤더에는 iterator가 모두 구현이 되어있을것. 이름은 같지만 지금 이 iterator는 vector안에 있는 iterator를 가리키고, 위 iterator는 list안을 가리킨다.
													//각 iterator는 구현되어 있는 위치가 다르기 때문에 구현되어 있는 해당 자료구조에 맞게 동작을 함. 내부구조는 다르지만 결과적으로 사용되는 방식은 같음.



	*veciter;
	vecInt[0];



	//++(전위,후위), --, ==, !=
	//iterator가 제대로 순환하는지 확인하는 반복문

	for (; myiter != myvector.end(); ++iter)		//myiter와 myvector.end함수가 모두 iterator를 반환타입으로 하고있기 때문에, iterator안에 !=, ++과 같은 연산자가 구현이 되어 있어야 작동.
	{
		cout << *myiter << endl;
	}

	//후위 연산자
	//후위 연산자는 전위 연산자와 시점이 다르다. 후위는 같은 구문에서 제일 늦게 시행됨. 그러나 전위연산자와 하는 역할은 똑같음.
	//이러한 iterator의 후위 연산자 또한 전위 연산자와 똑같이 operator를 통해 구현된 멤버함수일 뿐이다. 따라서 앞에 붙었냐, 뒤에 붙었냐에 따라서 시점을 옮겨서 실행되도록 하는 것은
	//불가능하고, 그저 전위연산자와 똑같은 시점에 호출이 된다. 따라서 결과적으로 전위연산자와 다르게 나중에 호출된 것처럼 구현하기 위해서 함수를 새로 만들어 줘야한다.

	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	myiter = myvector.begin();

	int idata = *(++myiter);	//++이 먼저 연산되므로 myiter에 ++된 값인 20이 들어가고 그 주소값을 반환하므로 idata에도 10이 들어간다.
	int idata = *(myiter++);	//표준++연산의 경우 myiter.begin값인 10이 idata에 먼저 들어가고 다른 모든 연산이 끝난 후 ++이 적용되어 myiter는 20을 가리키고 있어야한다.
								//이를 iterator 연산으로 구현하여 결과값은 똑같이 나오지만 과정은 후위++가 먼저 호출되어 동작되고 myiter는 20을 가리키고 있지만
								//20을 가리키기 전에 myiter의 복사본을 만들어놨으므로 그 복사본을 idata에 반환한다는 식을 구현하여 과정은 다르지만 결과값을 똑같게하여 흉내냄.





	//복사본 클레스
	//클레스에는 보이지 않지만 자동으로 만들어주는 클레스가 몇개 있다. (ex> 생성자, 소멸자, operator 대입연산자)
	class CTest
	{
	public:						//원래는 private. 편하게 예시들려고 바꿈.
		int			m_i;

	public:
		CTest& operator = (const CTest& _other)		//대입연산자 operator
		{
			m_i = _other.m_i;

			return *this;

		}

	public:
		CTest()							//기본생성자
			: m_i(0)
		{								//아래 기본생성자 이외의 생성자를 사용자가 만들었으므로 기본생성자도 작성을 해줘야한다. 매우 중요!

		}

		CTest(const CTest& _other)		//복사 생성자 : 중요!
			: m_i(_other.m_i)			//만약 이처럼 사용자가 생성자를 하나라도 직접 만들었을 경우 컴파일러는 더이상 생성자를 자동으로 만들어 주지 않음.
		{								//따라서 기본 생성자도 직접 만들어 줘야 한다.

		}


	};


	//반복 생성자 예시

	CTest t1;
	t1.m_i = 100;

	CTest t2;				//t2 생성->생성과 동시에 기본생성자 호출하여 초기화. -> t2에 t1 데이터 대입.
	t2 = t1;				//복사생성자로 대입할 데이터를 넣어서 초기화하는것과 같음.

	CTest t2(t1);			//따라서 위 2개의 식으로 나눈것을 이렇게 간단하게 표현가능.


	CTest t3 = t1;			//t3 선언후 t1을 넣겠다는 뜻. t3선언하면서 기본생성자 호출. 결국 위 함수식과 같은 뜻이므로 이것또한 복사생성자로 표현가능.
	CTest t3(t1);			//따라서 CTest t3 = t1;와 같은 문법을 지닌 식은 복사 생성자를 호출한다는 뜻

	//iterator copy_iter = *this; 또한 *this가 iterator 본인 자체의 주소값을 나타내므로 위처럼 복사 생성자를 호출한다고 생각할 수 있다.
	//iterator의 복사생성자를 구현하지 않았어도 자동으로 만들어주기 때문에 마치 *this를 copy_iter에 대입했다라고 할 수 있게끔 기능이 되어 있는것.


	//vector::erase
	//erase : 삭제

	vector<int> vecint; // vector 클레스 객체 vecint 선언

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);	//벡터 객체에 100~400까지 데이터 삽입.

	vector<int>::iterator veciter = vecInt.begin(); //벡터클래스 안에 iterator 객체 veciter 선언과 동시에 vecInt의 시작을 기리키게함.
													//따라서 iterator 객체 veciter는 100을 가리키고 있음.

	vecInt.erase(veciter);	//erase가 veciter부분 즉 100을 삭제하라고 함. 기존 begin이였던 100이 삭제되었으므로 가변 배열 특성상
							//200이 begin이 되고 동시에 Count도 4에서 3으로 준다.


	int a = *veciter;	//이를 실행시키면 오류가 나오는데 그 이유는 iterator 객체 veciter가 erase에 인해 첫번째 데이터인 100을 삭제했는데,
						//컴파일러 입장에선 데이터가 삭제되어 200이 땡겨왔을뿐 삭제된것에는 변함이 없기 때문에 이 iterator는 사용불가라고 판단.
						//따라서 erase로 데이터를 삭제했으면 iterator를 그냥 재사용할 수 없다.(다른조치를 취해야함.)

	veciter = vecInt.erase(veciter); //vecInt에서 데이터 삭제 이후 veciter에 다시 대입해줘야 수정되어 오류가 생기지 않음.
									 //erase가 실행되면서 원본 veciter가 훼손되었고(false), 반환값으로 반복생성자로 데이터를 수정하여(true)
									 //다시 veciter에 대입해줘야 비로소 데이터를 삭제한 후 정상적으로 돌아가는 iterator 객체가 된다.


	int i = *veciter; // true veciter를 반환했기 때문에 역참조 가능.


	//clear
	vecInt.clear();	//배열안에 모든 데이터를 삭제한다.


	//1~11을 벡터에 입력
	for (int i = 0; i < 11; ++i)
	{
		vecInt.push_back(i + 1);

	}

	//1~5 숫자만 제거
	veciter = vecInt.begin();	//iterator가 시작부터 가리키게 한다.(초기값)
	for (; veciter != vecInt.end();)	//veciter가 end iterator 일 때 까지 반복문 돌린다.
	{

		if (1 <= *veciter && *veciter <= 5)	//1~5인 숫자일 경우
		{
			//제거
			veciter = vecInt.erase(veciter);	//erase로 1을 지우고 그 다음값인 2를 가리키고 있음.
												//따라서 반복문에서 ++veciter 가 들어갔을 경우 이미 erase작업에서 다음을 가리키고 있는데
												//한 번더 ++이 되는 것으로 총 2단계씩 올라가는 것과 같다.
		}
		else
		{
			++veciter;		//위와 같은 이유로 인해 if(erase로 지울때)에 해당하지 않을때만 반복문 ++을 해준다.

		}

	}

	//짝수만 제거
	veciter = vecInt.begin();	//iterator가 시작부터 가리키게 한다.(초기값)
	for (; veciter != vecInt.end(); ++veciter)	//veciter가 end iterator 일 때 까지 반복문 돌린다.
	{

		if (0 == *veciter % 2)	//2로 나눈 나머지가 0인 경우 : 짝수인 경우
		{
			//제거
			veciter = vecInt.erase(veciter);	

		}
			//짝수만 제거 할 경우에는 주의할 점이 데이터값이 1~10일 경우 erase에 해당하는 데이터가 짝수이므로
			//마지막 10에서 erase가 실행되면서 10이 삭제되고 veciter가 10의 다음인 end iterator를 가리키고 있게 된다.
			//추가로 ++veciter를 하므로 결과적으론 end iteraotr의 다음을 가리키고 있게 되므로 오류가 생긴다.
			//따라서 마지막 데이터 값이 홀수가 되도록 하거나, 짝수일경우엔 

	}



	//list iterator

	CList<int> myList;
	myList.push_back(100);
	myList.push_back(200);
	myList.push_back(300);

	CList<int>::iterator listiter = myList.begin();

	*listiter = 150;	//반환타입이 T&이기 때문에 데이터 참조 가능

	//list 의 데이터 순회 방법 : iterator를 사용해 순회해야함.
	for (listiter = myList.begin(); listiter != myList.end(); ++listiter)
	{
		cout << *listiter << endl;

	}



	//inline
	//inline 처리 한다는 것은 그 함수를 호출하는 쪽에 코드를 추가한다는 뜻
	//inline 으로 처리된 함수는 호출 될 때 일반적인 함수의 호출 과정을 거치지 않고, 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식이다.
	//이렇게 inline 처리를 하는 이유는 함수 호출이 반복되면 시간이 많이 걸리게 되므로, 호출비용을 줄이기 위함.
	//함수 실행 시간이 길다면, 호출시간은 문제되지 않지만, 함수 실행 시간이 짧다면, 호출에 걸리는 시간도 부담이 될 수 있다.
	//따라서, 보통 inline 처리를 하는 것들은 자주 호출되고, 함수식이 다소 짧은 것들을 inline 처리 해준다.





	return 0;
}












