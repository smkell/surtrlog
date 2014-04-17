#include "gtest/gtest.h"
#include "surtrlog/surtrlog.h"
#include <iostream>
#include <sstream>

TEST(DefaultLogger, WriteToStreamBuf) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.Log().rdbuf(out.rdbuf());

	auto expect = "This is a test.";
	logger.Log() << expect;

	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(InfoLogger, WritesCorrectHeader) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.Log<surtrlog::Info>().rdbuf(out.rdbuf());

	auto input = "This is a test.";
	logger.Log<surtrlog::Info>() << input;

	auto expect = "[ INFO ] This is a test.";
	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}

TEST(DebugLogger, WritesCorrectHeader) {
	surtrlog::Logger logger;

	std::ostringstream out;
	logger.Log<surtrlog::Debug>().rdbuf(out.rdbuf());

	auto input = "This is a test.";
	logger.Log<surtrlog::Debug>() << input;

	auto expect = "[ DEBUG ] This is a test.";
	auto actual = out.str();

	EXPECT_EQ(expect, actual);
}