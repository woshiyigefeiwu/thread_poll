#include "ThreadPool.cpp"
// #include "TaskQueue.h"
#include <unistd.h>
using namespace std;

#define min_num 3   //线程池里的线程数量
#define max_capacity 10 //线程池容量

void taskFunc(void* arg)
{
    int num = *(int*)arg;
    printf("线程 %ld 正在工作, number = %d\n", pthread_self(), num);
    sleep(1);
}

int main()
{
    // 创建线程池
    ThreadPool pool(min_num,max_capacity);
    for (int i = 1; i <= 10; ++i)   //往任务队列里面添加任务
    {
        int* num = new int(i);
        pool.addTask(Task(taskFunc, num));
    }

    sleep(30);

    return 0;
}
