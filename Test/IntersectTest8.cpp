#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(insertLine)
		{
			Intersect p;
			int ret = p.insertLine(1, 2, 1, 2, 'L');
			Assert::AreEqual(ret, (int)1);
			ret = p.insertLine(100001, 0, 2, 1, 'L');
			Assert::AreEqual(ret, (int)2);
			ret = p.insertLine(0, -100006, 2, 1, 'L');
			Assert::AreEqual(ret, (int)3);
			p.insertLine(0, 0, 1, 2, 'L');
			ret = p.insertLine(0, 0, -1, -2, 'R');
			Assert::AreEqual(ret, (int)4);
			ret = p.insertLine(0, 0, 1, 1, 'L');
			Assert::AreEqual(ret, (int)0);
		}
	};
}