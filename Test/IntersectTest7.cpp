#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(insertCircle)
		{
			Intersect p;
			int ret = p.insertCircle(0, 0, 100005);
			Assert::AreEqual(ret, (int)1);
			ret = p.insertCircle(-100008, 2, 4);
			Assert::AreEqual(ret, (int)2);
			ret = p.insertCircle(0, 2, -2);
			Assert::AreEqual(ret, (int)3);
			p.insertCircle(0, 0, 1);
			ret = p.insertCircle(0, 1, 1);
			Assert::AreEqual(ret, (int)0);
			ret = p.insertCircle(0, 0, 1);
			Assert::AreEqual(ret, (int)4);
		}
	};
}