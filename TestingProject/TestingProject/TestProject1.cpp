#include "stdafx.h"
#include <string>
#include "CppUnitTest.h"
#include "../BodySignals/BodySignals/HelloWorld.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TestingProject
{
	TEST_CLASS(TestHelloWorld)
	{
	private:
		std::string *ex1;
		std::string *ex2;
		std::string *ex3;
		HelloWorld h;
	private:
		void setUp()
		{	
			*ex1 = "Acesta este un string";
			*ex2 = "245";
		}
		void tearDown()
		{
			delete ex1;
			delete ex2;	//destroy the variables you use
			delete ex3;
		}
	/*	void _failMethod()
		{
			Logger::WriteMessage("This test fails");
		}

		static void _passingTestMethod()
		{
			Logger::WriteMessage("This test works");
		}
		static void _exitTestMethod()
		{

		} */
		TEST_METHOD(SetMessage)
		{
			Logger::WriteMessage("GetMessage method is testing");
			h.SetMessage(*ex1);
			//Assert::AreEqual(0, 0);
		}
		TEST_METHOD(GetMessage)
		{
			Logger::WriteMessage("GetMessage method is testing");
			//Assert::AreEqual(*ex1, h.GetMessage());
		}
	};
}