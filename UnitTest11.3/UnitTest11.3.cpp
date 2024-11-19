#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../LB11.3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod_SearchRoute)
        {
            string test_file = "test_routes.txt";
            ofstream f(test_file);
            f << "StartPoint1\nEndPoint1\n1\n";
            f << "StartPoint2\nEndPoint2\n2\n";
            f << "StartPoint3\nEndPoint3\n3\n";
            f.close();

            stringstream buffer;
            streambuf* old = cout.rdbuf(buffer.rdbuf());

            istringstream input("2\n");
            cin.rdbuf(input.rdbuf());

            Search(test_file);

            cout.rdbuf(old);

            string output = buffer.str();

            string expected_output =
                "Введіть номер маршруту: "

                "==========================================================================\n"
                "|  №  |   Початковий пункт   |    Кінцевий пункт    |   Номер маршруту   |\n"
                "--------------------------------------------------------------------------\n"
                "|   1 |          StartPoint2 |            EndPoint2 |                  2 |\n"
                "==========================================================================\n\n";

            Assert::AreEqual(expected_output, output);
        }
    };
}
