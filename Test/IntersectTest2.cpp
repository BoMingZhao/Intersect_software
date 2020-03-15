#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(calculate_line_circle)
		{
			Intersect p;
			Line l1(0, 0, 1, 1, 0);
			Circle c1(0, 1, 1);
			int ret = p.calculate_line_circle(l1, c1);
			Assert::AreEqual(ret, (int)2);
			Line l2(0, 0, 0, 1, 0);
			Circle c2(1, 0, 1);
			ret = p.calculate_line_circle(l2, c2);
			Assert::AreEqual(ret, (int)1);
			Line l3(0, 0, 1, 0, 0);
			Circle c3(0, 2, 1);
			ret = p.calculate_line_circle(l3, c3);
			Assert::AreEqual(ret, (int)0);
			Line l4(0, 1, 1, 1, 1);
			ret = p.calculate_line_circle(l4, c1);
			Assert::AreEqual(ret, (int)1);
			Line l5(0, 0, 0, 1, 2);
			Circle c4(0, 0, 3);
			ret = p.calculate_line_circle(l5, c4);
			Assert::AreEqual(ret, (int)0);
			Line l6(2, 1, 0, 1, 2);
			ret = p.calculate_line_circle(l4, c1);
			Assert::AreEqual(ret, (int)1);
		}
	};
}
