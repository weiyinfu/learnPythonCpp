#include <boost/python.hpp> 
using namespace boost::python; 
  
class Test 
{ 
public: 
 int Add(const int x, const int y, const int z = 100) 
 { 
  return x + y + z; 
 } 
}; 
  
int Del(const int x, const int y, const int z = 100) 
{ 
 return x - y - z; 
} 
  
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Add_member_overloads, Add, 2, 3) 
BOOST_PYTHON_FUNCTION_OVERLOADS(Del_overloads, Del, 2, 3) 
  
BOOST_PYTHON_MODULE(test4) 
{ 
 class_<Test>("Test") 
  .def("Add", &Test::Add, Add_member_overloads(args("x", "y", "z"), "something")); 
 def("Del", Del, Del_overloads(args("x", "y", "z"), "something")); 
}
/*
>>> import test4 
>>> test = test4.Test() 
>>> print test.Add(1,2) 
103
>>> print test.Add(1,2,z=3) 
6
>>> print test4.Del(1,2) 
-1
>>> print test4.Del(1,2,z=3) 
-1
 */
