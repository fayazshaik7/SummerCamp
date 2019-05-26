#include "stdafx.h"
#include "CppUnitTest.h"
#include "../summer1/Strcompress.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		int compare(char *res, char *exp){
			if (strlen(res) != strlen(exp))
				return 0;
			for (int i = 0; res[i]; i++)
				if (res[i] != exp[i])
					return 0;
			return 1;
		}
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			char inp[100] = "aaaaaaaaaa\0";
			char *res = compress(inp);
			char exp[100] = "a10\0";
			Assert::AreEqual(compare(res, exp), 1);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: Your test code here
			char inp[100] = "abcd\0";
			char *res = compress(inp);
			char exp[100] = "abcd\0";
			Assert::AreEqual(compare(res, exp), 1);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: Your test code here
			char inp[100] = "abcdaaaaaaaaaabbb\0";
			char *res = compress(inp);
			char exp[100] = "abcda10b3\0";
			Assert::AreEqual(compare(res, exp), 1);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: Your test code here
			char inp[100] = "aaaaaaaaaaaaab\0";
			char *res = compress(inp);
			char exp[100] = "a13b\0";
			Assert::AreEqual(compare(res, exp), 1);
		}

	};
}