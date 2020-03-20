#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(checkLine)
		{
			Intersect p;
			bool ret;
			Line l4(0, -2, 0, 3, 'R');
			Line l5(0, 0, -1, -1, 'S');
			Line l6(0, 1, 0, 0, 'S');
			Line l7(0, -1, 0, -2, 'R');
			p.insertLine(0, 0, 0, 1, 'S');
			p.insertLine(0, 0, 1, 0, 'R');
			p.insertLine(0, 0, 1, 1, 'L');
			ret = p.checkLine(l4);
			Assert::AreEqual(ret, (bool)false);
			ret = p.checkLine(l5);
			Assert::AreEqual(ret, (bool)false);
			ret = p.checkLine(l6);
			Assert::AreEqual(ret, (bool)false);
			ret = p.checkLine(l7);
			Assert::AreEqual(ret, (bool)true);
		}
	};
}