#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class foo 
{
public:
    foo(int n): n_(n) { } ;
private:
    int n_;
};

void fun(std::vector<shared_ptr<foo>>& v)
{
    auto p = make_shared<foo>(1);
    cout<<p.use_count()<<endl;
    
    v.push_back(p);
    cout<<p.use_count()<<endl;

    v.pop_back();
    cout<<p.use_count()<<endl;
}

int main()
{
    vector<shared_ptr<foo>> v;
    fun(v);
    return 0;
}
