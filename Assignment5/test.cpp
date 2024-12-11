//Fadeev Eugene st128225@student.spbu.ru
//This file contains implementation of test for assignment 5.


#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Weapon.h"
#include "Vehicle.h"


TEST(DirectMethodCalls, Transformer)
{
    Transformer transformer;
    std::string output;

    testing::internal::CaptureStdout();
    transformer.transform();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "transform Transformer\n");

    testing::internal::CaptureStdout();
    transformer.openFire();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "openFire Transformer\n");

    testing::internal::CaptureStdout();
    transformer.ulta();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ulta Transformer\n");
}


TEST(DirectMethodCalls, Autobot)
{
    Autobot autobot;
    std::string output;

    testing::internal::CaptureStdout();
    autobot.transform();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "transform Autobot\n");

    testing::internal::CaptureStdout();
    autobot.openFire();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "openFire Autobot\n");

    testing::internal::CaptureStdout();
    autobot.ulta();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ulta Autobot\n");
}


TEST(DirectMethodCalls, Decepticon)
{
    Decepticon decepticon;
    std::string output;

    testing::internal::CaptureStdout();
    decepticon.transform();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "transform Decepticon\n");

    testing::internal::CaptureStdout();
    decepticon.openFire();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "openFire Decepticon\n");

    testing::internal::CaptureStdout();
    decepticon.ulta();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ulta Decepticon\n");
}



TEST(MethodCallsThroughBaseClassPointers, Autobot)
{
    Autobot autobot;
    std::string output;

    Transformer* t1 = &autobot;

    testing::internal::CaptureStdout();
    t1->transform();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "transform Autobot\n");

    testing::internal::CaptureStdout();
    t1->openFire();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "openFire Autobot\n");

    testing::internal::CaptureStdout();
    t1->ulta();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ulta Autobot\n");
}

TEST(MethodCallsThroughBaseClassPointers, Decepticon)
{
    Decepticon decepticon;
    std::string output;

    Transformer* t2 = &decepticon;

    testing::internal::CaptureStdout();
    t2->transform();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "transform Decepticon\n");

    testing::internal::CaptureStdout();
    t2->openFire();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "openFire Decepticon\n");

    testing::internal::CaptureStdout();
    t2->ulta();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ulta Decepticon\n");
}

TEST(VirtualMethodCallsThroughVector, null)
{
    std::vector<Transformer*> transformers;
    std::string output;
    for (int i = 0; i < 3; ++i)
    {
        transformers.push_back(new Transformer());
        transformers.push_back(new Autobot());
        transformers.push_back(new Decepticon());
    }


    for (Transformer* transformer : transformers)
    {
        if (dynamic_cast<Autobot*>(transformer))
        {
            testing::internal::CaptureStdout();
            transformer->transform();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "transform Autobot\n");

            testing::internal::CaptureStdout();
            transformer->openFire();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "openFire Autobot\n");

            testing::internal::CaptureStdout();
            transformer->ulta();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "ulta Autobot\n");
        }
        else if (dynamic_cast<Decepticon*>(transformer))
        {
            testing::internal::CaptureStdout();
            transformer->transform();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "transform Decepticon\n");

            testing::internal::CaptureStdout();
            transformer->openFire();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "openFire Decepticon\n");

            testing::internal::CaptureStdout();
            transformer->ulta();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "ulta Decepticon\n");
        }
        else
        {
            testing::internal::CaptureStdout();
            transformer->transform();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "transform Transformer\n");

            testing::internal::CaptureStdout();
            transformer->openFire();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "openFire Transformer\n");

            testing::internal::CaptureStdout();
            transformer->ulta();
            output = testing::internal::GetCapturedStdout();
            EXPECT_EQ(output, "ulta Transformer\n");
        }
    }


    for (Transformer* transformer : transformers)
    {
        delete transformer;
    }
}
