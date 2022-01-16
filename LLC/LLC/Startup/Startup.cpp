#include <iostream>
#include <cstdlib>
#include "../LinkedList/LinkedList.h"

using namespace std;

int main()
{
	LinkedListInt list = { -111, -222, -333, -444, -555 };
	list.erase_after(0);
	list.erase_after(1);
    cout << list.to_string();

}
