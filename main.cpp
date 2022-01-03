#include <iostream>
#include "user.h"
using namespace std;

int main()
{
    User user1(1,"rob","roy","free","scotland");
    user1.showUserData();
    user1.setPassword( "scotlandTheBrave");
    user1.showUserData();
    User user2;
    user2.showUserData();
    return 0;
}
