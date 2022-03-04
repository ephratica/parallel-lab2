#include <iostream>
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include <time.h>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
const int n=(1<<17)+3;
struct timeval tv_begin,tv_end;
template<class T>
class test{
public:
    T sum, *a=new T[n];
    int m;
    test(int m){
        this->m=m;
        for(int i=0;i<n;i++)a[i]=rand();
    }
    void test1() {
        gettimeofday(&tv_begin,NULL);
        for(int i=0;i<m;i++)sum+=a[i];
        gettimeofday(&tv_end,NULL);
        long long sb=tv_begin.tv_sec*(1e6)+tv_begin.tv_usec,se=tv_end.tv_sec*(1e6)+tv_end.tv_usec;
        cout<<"平凡算法："<<m<<" "<< typeid(a[0]).name()<<" "<<se-sb<<"um"<<endl;
    }
    void test2() {
        gettimeofday(&tv_begin,NULL);
        T sum1=0,sum2=0;
        for(int i=0;i<m;i+=2){
            sum1+=a[i];
            sum2+=a[i+1];
        }
        sum=sum1+sum2;
        gettimeofday(&tv_end,NULL);
        long long sb=tv_begin.tv_sec*(1e6)+tv_begin.tv_usec,se=tv_end.tv_sec*(1e6)+tv_end.tv_usec;
        cout<<"多链路式优化算法："<<m<<" "<< typeid(a[0]).name()<<" "<<se-sb<<"um"<<endl;
    }
    void test3() {
        gettimeofday(&tv_begin,NULL);
        for(int i=m;i>1;i/=2){
            for(int j=0;j<i/2;j++){
                a[j]=a[j*2]+a[j*2+1];
            }
        }
        sum=a[0];
        gettimeofday(&tv_end,NULL);
        long long sb=tv_begin.tv_sec*(1e6)+tv_begin.tv_usec,se=tv_end.tv_sec*(1e6)+tv_end.tv_usec;
        cout<<"递归优化算法："<<m<<" "<< typeid(a[0]).name()<<" "<<se-sb<<"um"<<endl;
    }
};

int main() {
    test<int> t1(n-3);
    t1.test1();t1.test2();t1.test3();
    test<float>t2(n-3);
    t2.test1();t2.test2();t2.test3();
    test<double>t3(n-3);
    t3.test1();t3.test2();t3.test3();
    return 0;
}
