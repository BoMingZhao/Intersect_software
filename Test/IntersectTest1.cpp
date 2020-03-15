#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(calculate_line_line)
		{
			Intersect p;
			Line l1(0, 0, 1, 1, 0);
			Line l2(0, 0, 0, 1, 0);
			int ret = p.calculate_line_line(l1, l2);
			Assert::AreEqual(ret,(int)1);
			Line l3(0, 0, 1, 1, 0);
			Line l4(1, 0, 2, 1, 0);
			ret = p.calculate_line_line(l3, l4);
			Assert::AreEqual(ret, (int)0);
			Line l5(0, 0, 1, 0, 2);
			Line l6(1, 0, 2, 0, 2);
			ret = p.calculate_line_line(l5, l6);
			Assert::AreEqual(ret, (int)1);
			Line l7(0, 0, 1, 0, 2);
			Line l8(1, 1, 2, 0, 2);
			ret = p.calculate_line_line(l7, l8);
			Assert::AreEqual(ret, (int)0);
			Line l9(0, 0, 1, 1, 1);
			Line l10(0, 0, -1, -1, 1);
			ret = p.calculate_line_line(l9, l10);
			Assert::AreEqual(ret, (int)1);
			Line l11(0, 0, 1, 0, 1);
			Line l12(0, 1, 0, 2, 1);
			ret = p.calculate_line_line(l11, l12);
			Assert::AreEqual(ret, (int)0);
		}
	};
}
