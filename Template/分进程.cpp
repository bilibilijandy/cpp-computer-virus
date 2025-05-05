#include <bits/stdc++.h>
#include <windows.h>

void thread_func(int id) {
    // 线程函数
    // id为线程编号
}

int main(){
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 线程数; i++) {
        threads.emplace_back(thread_func, i);
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        if (th.joinable()) th.join();
    }

}