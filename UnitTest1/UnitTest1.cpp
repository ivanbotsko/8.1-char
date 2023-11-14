#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../8.1 char/8.1 char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(YourTestClass)
    {
    public:

        TEST_METHOD(TestCountFunction)
        {
            const char* testString1 = "abcabcabc";  // тестовий рядок з трьома групами "abc"
            const char* testString2 = "ababab";     // тестовий рядок без груп "abc"
            const char* testString3 = "";           // порожній рядок

            const char* cs = "abc";

            // Очікувані результати
            int expectedCount1 = 3;
            int expectedCount2 = 0;
            int expectedCount3 = 0;

            // Перевірка роботи функції Count
            int result1 = Count(const_cast<char*>(testString1), cs);
            int result2 = Count(const_cast<char*>(testString2), cs);
            int result3 = Count(const_cast<char*>(testString3), cs);

            // Перевірка результатів тестів
            Assert::AreEqual(expectedCount1, result1, L"Test case 1 failed");
            Assert::AreEqual(expectedCount2, result2, L"Test case 2 failed");
            Assert::AreEqual(expectedCount3, result3, L"Test case 3 failed");
        }
    };
}
