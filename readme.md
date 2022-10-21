# 记录问题及解决过程    
    1. 书上源程序报错wait函数
![wait](./images/111.png)
解决方法：引入#include <wait.h>  [解决问题的链接][1]


# 实验的具体步骤
## 任务一
- 多次运行程序并且观察结果
![实验结果](images/result1.png)
![实验结果](images/result2.png)
![实验结果](images/result3.png)
结果分析：
    + 进行三次运行，从每次的结果我们可以发现子进程里面的pid1与父进程的pid相同，这是因为父进程经过fork返回的是子进程的pid，而子进程getpid()后获得自己的pid，二者当然相同
    + 子进程经过fork后获得的pid是0
    + 父进程gitpid()获得自己的pid，与子进程的不同，并且父进程的pid比子进程的小4


































---
---


[1]: https://blog.csdn.net/wyhh_0101/article/details/83933308?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166633485316782390525276%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166633485316782390525276&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-83933308-null-null.142^v59^opensearch_v2,201^v3^add_ask&utm_term=wait&spm=1018.2226.3001.4187