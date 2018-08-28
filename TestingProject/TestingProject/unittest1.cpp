#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingProject
{		
	TEST_CLASS(SimpleTest)
	{
	private:
		int *m_10_1, *m_10_2, *m_10_3;
	public:
		void setUp()
		{
			*m_10_1 = 245;
			*m_10_2 = 245;

		}

		void tearDown()
		{
			delete m_10_1;
			delete m_10_2;	//destroy the variables you use
			delete m_10_3;
		}
	public:
		TEST_METHOD(Method1)
		{
			Logger::WriteMessage("Method1 is tested");
			Assert::AreEqual(0, 0);
		}
		TEST_METHOD(Method2)
		{

			Assert::AreEqual(m_10_1, m_10_2);
			Logger::WriteMessage("Method2 is tested");
			tearDown();
		}
	};
}