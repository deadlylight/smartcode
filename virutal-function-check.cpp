
#include <stdio.h>
#include <typeinfo>

struct Base
{
    int check()
    {
        printf("%s\n", typeid(&Base::func).name());
        return 0;
    }

    virtual void func()
    {
    }
};

struct Deliver1 : public Base
{

};

struct Deliver2 : public Base
{
    void func()
    {
    }
};


int main()
{
    Deliver1 d1;
    Deliver2 d2;
    Base* p1 = &d1;
    Base* p2 = &d2;
    printf("%d, %d\n", p1->check(), p2->check());
    printf("%s, %s\n", typeid(p1).name(), typeid(*p2).name());
    return 0;
}
