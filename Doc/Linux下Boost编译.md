<!--
 * @Source: 
 * @Author: Arvin Huang
 * @Date: 2020-10-18 12:48:21
-->

##Build Boost 

#### 1.Downlod
https://dl.bintray.com/boostorg/release/1.74.0/source/
#### 2.Unzip
tar xzvf boost_xxx.tar.gz

#### 3.Build
cd xxx 
./bootstrap.sh 
./b2

#### 4.Install
sudo ./b2 --prefix=/usr/local/boost install

#### 5.Test
```
#include <boost/version.hpp> 
#include <boost/config.hpp>  
int main()
{
    cout << BOOST_VERSION << endl; 
    cout << BOOST_LIB_VERSION << endl; 
    cout << BOOST_PLATFORM << endl; 
    cout << BOOST_COMPILER << endl; 
    cout << BOOST_STDLIB << endl;  
    return 0;
}
```

>arvin@ubuntu-server:~/code$ ./a.out
106600
1_66
linux
GNU C++ version 9.3.0





