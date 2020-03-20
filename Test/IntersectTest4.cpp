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
			p.insertLine(0, 0, 1, 1, 'L');
			p.insertLine(0, 0, 0, 1, 'R');
			p.insertLine(0, 0, 1, 0, 'S');
			ret = p.deleteLine(1, 1, 2, 2, 'R');
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(1, 1, 2, 2, 'L');
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteLine(0, 0, 1, 1, 'L');
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(0, 0, 0, -1, 'R');
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteLine(0, 0, 1, 2, 'S');
			Assert::AreEqual(ret, (int)1);
		}
	};
}