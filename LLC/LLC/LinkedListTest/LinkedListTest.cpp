#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include "CppUnitTest.h"
#include "../LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:

		TEST_METHOD(empty)
		{
			LinkedListInt list;
			Assert::IsTrue(list.empty() && list.size() == 0);
		}

		TEST_METHOD(initializer_list)
		{
			LinkedListInt list{ 1, 2, 3, 4, 5 };
			Assert::IsTrue(!list.empty() && list.size() == 5 && list.to_string() == "1, 2, 3, 4, 5");
		}

		TEST_METHOD(last)
		{
			LinkedListInt list = { -1, -2, -3, -4, -5 };
			Assert::IsTrue(-5 == list.back() && -5 == list.pop_back());
		}
		TEST_METHOD(push_front_back_front)
		{
			LinkedListInt list;
			list.push_front(3);
			list.push_front(2);
			list.push_back(4);
			list.push_back(5);
			list.push_front(1);
			Assert::IsTrue(!list.empty() && list.size() == 5 && list.back() == 5 && list.front() == 1 && list.to_string() == "1, 2, 3, 4, 5");
		}

		TEST_METHOD(push_back_front_back)
		{
			LinkedListInt list;
			list.push_back(30);
			list.push_back(40);
			list.push_front(20);
			list.push_front(10);
			list.push_back(50);
			Assert::IsTrue(!list.empty() && list.size() == 5 && list.to_string() == "10, 20, 30, 40, 50");
		}

		TEST_METHOD(pop_front)
		{
			LinkedListInt list = { -1, -2, -3 };
			int a = list.pop_front();
			int b = list.pop_front();
			Assert::IsTrue(a == -1 && b == -2 && !list.empty() && list.size() == 1 && list.to_string() == "-3");
		}
		
		TEST_METHOD(pop_front_empty_exception)
		{
			LinkedListInt list;
			Assert::ExpectException<std::out_of_range>([&]
			{
				list.pop_front();
			});
		}

		TEST_METHOD(pop_back)
		{
			LinkedListInt list = { 11, 22, 33 };
			int a = list.pop_back();
			int b = list.pop_back();
			Assert::IsTrue(a == 33 && b == 22 && !list.empty() && list.size() == 1 && list.to_string() == "11");
		}

		TEST_METHOD(pop_back_empty_exception)
		{
			LinkedListInt list;
			Assert::ExpectException<std::out_of_range>([&]
			{
				list.pop_back();
			});
		}
		TEST_METHOD(clear)
		{
			LinkedListInt list = { 123, 456, 543, 210 };
			list.clear();
			Assert::IsTrue(list.empty() && list.size() == 0 && list.to_string() == "");
		}

		TEST_METHOD(insert)
		{
			LinkedListInt list;
			list.push_front(100);
			list.push_back(500);
			list.push_back(600);
			list.insert(1, 200);
			list.insert(4, 700);
			Assert::IsTrue(!list.empty() && list.size() == 5 && list.to_string() == "100, 200, 500, 600, 700" && list.front() == 100 && list.back() == 700);
		}

		TEST_METHOD(erase)
		{
			LinkedListInt list = { 111, 222, 333, 444, 555 };
			list.erase(0);
			list.erase(1);
			list.erase(3);
			Assert::IsTrue(!list.empty() && list.size() == 2 && list.to_string() == "222, 444" && list.front() == 222 && list.back() == 444);
		}

		TEST_METHOD(erase_after)
		{
			LinkedListInt list = { -111, -222, -333, -444, -555 };
			list.erase_after(0);
			list.erase_after(1);
			Assert::IsTrue(!list.empty() && list.size() == 3 && list.to_string() == "-111, -333, -555");
		}

		TEST_METHOD(to_string)
		{
			LinkedListInt list = { 1, -2, 3, -4, 5 };
			Assert::IsTrue(list.to_string() == "1, -2, 3, -4, 5");
		}

		TEST_METHOD(input_list)
		{
			std::istringstream is{ "123 456 789" };
			std::ostringstream os;
			LinkedListInt list;
			is >> list >> list >> list;
			Assert::IsTrue(!list.empty() && list.size() == 3 && list.to_string() == "123, 456, 789");
		}
	};
}
