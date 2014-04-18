#include "gtest/gtest.h"
#include "surtrlog/surtrlog.h"
#include <iostream>
#include <sstream>

TEST(DefaultLogger, WriteToStreamBuf) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.rdbuf<surtrlog::Default>(out.rdbuf());

	auto expect = "This is a test.";
	logger.Log() << expect;

	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(InfoLogger, WritesCorrectHeader) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.rdbuf<surtrlog::Info>(out.rdbuf());

	auto input = "This is a test.";
	logger.Log<surtrlog::Info>() << input;

	auto expect = "[ INFO ] This is a test.";
	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(DebugLogger, WritesCorrectHeader) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.rdbuf<surtrlog::Debug>(out.rdbuf());

	auto input = "This is a test.";
	logger.Log<surtrlog::Debug>() << input;

	auto expect = "[ DEBUG ] This is a test.";
	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(DebugLogger, WritesHeaderOnlyOncePerStatement) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.rdbuf<surtrlog::Debug>(out.rdbuf());

	auto input1 = "This is a test. ";
	auto input2 = "1..2..3..";
	logger.Log<surtrlog::Debug>() << input1 << input2;

	auto expect = "[ DEBUG ] This is a test. 1..2..3..";
	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(WarnLogger, WritesCorrectHeader) {
    surtrlog::Logger logger;

    std::ostringstream out;
    logger.rdbuf<surtrlog::Warn>(out.rdbuf());

    auto input = "This is a test.";
    logger.Log<surtrlog::Warn>() << input;

    auto expect = "[ WARN ] This is a test.";
    auto actual = out.str();

    EXPECT_EQ(expect, actual);
}

TEST(ErrorLogger, WritesCorrectHeader) {
    surtrlog::Logger logger;

    std::ostringstream out;
    logger.rdbuf<surtrlog::Error>(out.rdbuf());

    auto input = "This is a test.";
    logger.Log<surtrlog::Error>() << input;

    auto expect = "[ ERROR ] This is a test.";
    auto actual = out.str();

    EXPECT_EQ(expect, actual);
}

class Custom : public surtrlog::LogLevel {
public:
    static Custom& GetInstance() { return sInstance; }
protected:
    Custom() : LogLevel("CUSTOM") {}
private:
    static Custom sInstance;
};
Custom Custom::sInstance;

TEST(CustomLogger, WritesCorrectHeader) {
    surtrlog::Logger logger;

    std::ostringstream out;
    logger.rdbuf<Custom>(out.rdbuf());

    auto input = "This is a test.";
    logger.Log<Custom>() << input;

    auto expect = "[ CUSTOM ] This is a test.";
    auto actual = out.str();

    EXPECT_EQ(expect, actual);
}
