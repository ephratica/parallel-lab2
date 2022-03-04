#include <iostream>
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include <time.h>
#include <stdlib.h>
#include <typeinfo>
using namespace std;
const int n=2000;//可修改
struct timeval tv_begin,tv_end;
template<class T>
class test{
public:
    T *sum=new T[n],**b=new T*[n],*a=new T[n];
    int m;
    test(int m){
        this->m=m;
        for(int i=0;i<n;i++)b[i]=new T[n];
    }
    void pre(){
        for(int i=0;i<m;i++){
            a[i]= rand();
            for(int j=0;j<m;j++)
                b[i][j]=rand();
        }
    }
    void test1() {
        gettimeofday(&tv_begin,NULL);
        for(int i=0;i<m;i++){
            sum[i]=0;
            for(int j=0;j<m;j++){
                sum[i]+=b[j][i]+a[j];
            }
        }
        gettimeofday(&tv_end,NULL);
        long long sb=tv_begin.tv_sec*(1e6)+tv_begin.tv_usec,se=tv_end.tv_sec*(1e6)+tv_end.tv_usec;
        cout<<"平凡算法："<<m<<" "<< typeid(a[0]).name()<<" "<<se-sb<<"um"<<endl;
    }
    void test2() {
        gettimeofday(&tv_begin,NULL);
        for(int i=0;i<m;i++)sum[i]=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<m;i++){
                sum[i]+=b[j][i]+a[j];
            }
        }
        gettimeofday(&tv_end,NULL);
        long long sb=tv_begin.tv_sec*(1e6)+tv_begin.tv_usec,se=tv_end.tv_sec*(1e6)+tv_end.tv_usec;
        cout<<"优化算法："<<m<<" "<< typeid(a[0]).name()<<" "<<se-sb<<"um"<<endl;
    }
};

int main() {
    test<int> t1(n);
    t1.pre();
    t1.test1();t1.test2();
    test<float>t2(n);
    t2.pre();
    t2.test1();t2.test2();
    test<double>t3(n);
    t3.pre();
    t3.test1();t3.test2();
    return 0;
}
