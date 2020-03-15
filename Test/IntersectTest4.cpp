#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(deleteline)
		{
			Intersect p;
			int ret;
			Line l1(0, 0, 1, 1, 'L');
			Line l2(0, 0, 0, 1, 'R');
			Line l3(0, 0, 1, 0, 'S');
			Line l4(1, 1, 2, 2, 'R');
			Line l5(1, 1, 2, 2, 'L');
			Line l6(0, 0, 0, -1, 'R');
			Line l7(0, 0, 1, 2, 'S');
			p.insertLine(l1);
			p.insertLine(l2);
			p.insertLine(l3);
			ret = p.deleteLine(l4);
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(l5);
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteLine(l1);
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(l6);
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(l7);
			Assert::AreEqual(ret, (int)1);
		}
	};
}