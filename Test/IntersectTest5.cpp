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
			p.insertCircle(0, 0, 1);
			p.insertCircle(1, 1, 1);
			p.insertCircle(0, 0, 2);
			int ret = p.deleteCircle(1, 1, 1);
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteCircle(1, 1, 1);
			Assert::AreEqual(ret, (int)1);
			ret = p.deleteCircle(0, 0, 1);
			Assert::AreEqual(ret, (int)0);
			ret = p.deleteCircle(0, 2, 1);
			Assert::AreEqual(ret, (int)1);
		}
	};
}