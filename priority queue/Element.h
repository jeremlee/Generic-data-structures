#include<type_traits>
using namespace std;
template<typename T, typename Y,typename = typename enable_if<is_arithmetic<Y>::value>::type>
struct Element{
	T elem;
	Y priority;
};