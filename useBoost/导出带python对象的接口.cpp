#include <boost/python.hpp> 
  
boost::python::list Square(boost::python::list& data) 
{ 
 boost::python::list ret; 
 for (int i = 0; i < len(data); ++i) 
 { 
  ret.append(data[i] * data[i]); 
 } 
  
 return ret; 
} 
  
BOOST_PYTHON_MODULE(test5) 
{ 
 def("Square", Square); 
}
/*

>>> import test5 
>>> test5.Square([1,2,3]) 
[1, 4, 9] 

tuple的用法
boost::python::tuple(int a, int b, int c) 
{  
    return boost::python::make_tuple(a, b, c); 
}
 */
