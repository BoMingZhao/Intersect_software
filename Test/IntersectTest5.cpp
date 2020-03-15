#include "pch.h"
#include "CppUnitTest.h"
#include "../count number of point/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		TEST_METHOD(deletecircle)
		{
			Intersect p;
			Circle c1(0, 0, 1);
			Circle c2(1, 1, 1);
			Circle c3(0, 0, 2);
			p.insertCircle(c1);
			p.insertCircle(c2);
			p.insertCircle(c3);
			int ret = p.deleteCircle(c2);
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteCircle(c2);
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteCircle(c1);
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteCircle(0, 2, 1);
			Assert::AreEqual(ret, (int)1);
		}
	};
}