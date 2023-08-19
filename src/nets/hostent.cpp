#include <netdb.h>
#include <iostream>

int main()
{
    using namespace std;
    /**
     * 这个会读取 /etc/hosts 文件， p->h_name 就是里面记录的本机的主机名
     */
    hostent *p = gethostent();
    cout << p->h_name << endl;
    return 0;
}