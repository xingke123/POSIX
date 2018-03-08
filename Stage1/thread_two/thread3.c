/*
#include <iostream>  
#include <pthread.h> //多线程相关操作头文件，可移植众多平台  
using namespace std;  
#define NUM_THREADS 5 //线程数  
void* say_hello( void* args )  
{  
    int i = *( (int*)args ); //对传入的参数进行强制类型转换，由无类型指针转变为整形指针，再用*读取其指向到内容  
    cout << "hello in " << i <<  endl;  
} //函数返回的是函数指针，便于后面作为参数  
int main()  
{  
    pthread_t tids[NUM_THREADS]; //线程id  
    cout << "hello in main.." << endl;  
    for( int i = 0; i < NUM_THREADS; ++i )  
    {  
        int ret = pthread_create( &tids[i], NULL, say_hello, (void*)&i ); //传入到参数必须强转为void*类型，即无类型指针，&i表示取i的地址，即指向i的指针  
        cout << "Current pthread id = " << tids[i] << endl; //用tids数组打印创建的进程id信息  
        if( ret != 0 ) //创建线程成功返回0  
        {  
            cout << "pthread_create error:error_code=" << ret << endl;  
        }  
    }  
    pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态  
}  
*/

//改进

#include <iostream>  
#include <pthread.h> //多线程相关操作头文件，可移植众多平台  
using namespace std;  
#define NUM_THREADS 5 //线程数  
void* say_hello( void* args )  
{  
    cout << "hello in thread " << *( (int *)args ) <<  endl;  
} //函数返回的是函数指针，便于后面作为参数  
int main()  
{  
    pthread_t tids[NUM_THREADS]; //线程id  
    int indexes[NUM_THREADS]; //用来保存i的值避免被修改  
    cout << "hello in main.." << endl; 
	for( int i = 0; i < NUM_THREADS; ++i )  
	{  
	    indexes[i] = i;  
	    int ret = pthread_create( &tids[i], NULL, say_hello, (void*)&(indexes[i]) );  
            
	    if( ret != 0 ) //创建线程成功返回0  
	    {  
		cout << "pthread_create error:error_code=" << ret << endl;  
	    }  
	}  
for( int i = 0; i < NUM_THREADS; ++i ){
    pthread_join( tids[i], NULL ); //pthread_join用来等待一个线程的结束，是一个线程阻塞的函数 
    cout << "Current pthread id = " << tids[i] << endl;
    } 
}  
