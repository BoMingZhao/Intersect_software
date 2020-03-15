#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(calculate_circle_circle)
		{
			Intersect cal;
			Circle c1(0, 0, 1);
			Circle c2(1, 1, 1);
			int ret = cal.calculate_circle_circle(c1, c2);
			Assert::AreEqual(ret, (int)2);
			Circle c3(0, 0, 2);
			Circle c4(3, 0, 1);
			ret = cal.calculate_circle_circle(c3, c4);
			Assert::AreEqual(ret, (int)1);
			Circle c5(0, 0, 3);
			Circle c6(0, 0, 1);
			ret = cal.calculate_circle_circle(c5, c6);
			Assert::AreEqual(ret, (int)0);
			Circle c7(0, 0, 1);
			Circle c8(0, 9, 1);
			ret = cal.calculate_circle_circle(c7, c8);
			Assert::AreEqual(ret, (int)0);
		}
	};
}