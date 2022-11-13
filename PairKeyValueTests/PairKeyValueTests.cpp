#include <string>
#include <sstream>
#include "CppUnitTest.h"
#include "..\PairKeyValueLib\PairKeyValue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParaKeyValueTests
{
	TEST_CLASS(ParaKeyValueTests)
	{
	public:
		TEST_METHOD(ParaDefault)
		{
			Pair<int, int> pi;
			Pair<std::string, std::string> ps;
			std::string s;
			Assert::AreEqual(0, pi.getK());
			Assert::AreEqual(s, ps.getV());
		}
		TEST_METHOD(ParaGetters)
		{
			Pair<int, int> p(123, 456);
			Assert::AreEqual(123, p.getK());
			Assert::AreEqual(456, p.getV());
		}
		TEST_METHOD(ParaCopy)
		{
			Pair<std::string, std::string> p("Key", "Value");
			Pair<std::string, std::string> q(p);
			Assert::AreEqual(p.getK(), q.getK());
			Assert::AreEqual(p.getV(), q.getV());
		}
		TEST_METHOD(ParaAssign)
		{
			std::string ks("one"), vs("jeden");
			Pair<std::string, std::string> p(ks, vs), q;
			q = p;
			Assert::AreEqual(ks, q.getK());
			Assert::AreEqual(vs, q.getV());
		}
		TEST_METHOD(ParaComparators)
		{
			Pair<int, int> p1(7, 4), p2(7, 9);
			Pair<std::string, std::string> p("ABC", "XYZ");
			Assert::IsFalse(cmpK(p1, p2));
			Assert::IsTrue(cmpV(p1, p2));
			Assert::IsFalse(cmpK(p, p));
		}
		TEST_METHOD(ParaOutput)
		{
			std::stringstream ss;
			Pair<std::string, std::string> p("ABC","XYZ");
			std::string s1("<ABC:XYZ>"), s2;
			ss<<p;
			ss>>s2;
			Assert::AreEqual(s1, s2);
		}
	};
}
