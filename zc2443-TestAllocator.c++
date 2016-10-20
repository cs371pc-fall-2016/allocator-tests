// -------------------------------------
// projects/allocator/TestAllocator1.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------------

// --------
// includes
// --------

#include <algorithm> // count
#include <memory>    // allocator

#include "gtest/gtest.h"

#include "Allocator.h"

// --------------
// TestAllocator1
// --------------

template <typename A>
struct TestAllocator1 : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          A             allocator_type;
    typedef typename A::value_type value_type;
    typedef typename A::size_type  size_type;
    typedef typename A::pointer    pointer;};

typedef testing::Types<
            std::allocator<int>,
            std::allocator<double>,
            my_allocator<int,    100>,
            my_allocator<double, 100>>
        my_types_1;

TYPED_TEST_CASE(TestAllocator1, my_types_1);

TYPED_TEST(TestAllocator1, test_1) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type     value_type;
    typedef typename TestFixture::size_type      size_type;
    typedef typename TestFixture::pointer        pointer;

          allocator_type x;
    const size_type      s = 1;
    const value_type     v = 2;
    const pointer        p = x.allocate(s);
    if (p != nullptr) {
        x.construct(p, v);
        ASSERT_EQ(v, *p);
        x.destroy(p);
        x.deallocate(p, s);}}

TYPED_TEST(TestAllocator1, test_10) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type     value_type;
    typedef typename TestFixture::size_type      size_type;
    typedef typename TestFixture::pointer        pointer;

          allocator_type  x;
    const size_type       s = 10;
    const value_type      v = 2;
    const pointer         b = x.allocate(s);
    if (b != nullptr) {
        pointer e = b + s;
        pointer p = b;
        try {
            while (p != e) {
                x.construct(p, v);
                ++p;}}
        catch (...) {
            while (b != p) {
                --p;
                x.destroy(p);}
            x.deallocate(b, s);
            throw;}
        ASSERT_EQ(s, std::count(b, e, v));
        while (b != e) {
            --e;
            x.destroy(e);}
        x.deallocate(b, s);}}

// --------------
// TestAllocator2
// --------------

// zachTest
TEST(TestAllocator2, const_index) {
    const my_allocator<int, 100> x;
    ASSERT_EQ(x[0], 92);}

// zachTest
TEST(TestAllocator2, index) {
    my_allocator<int, 100> x;
    x[0] = 5;
    ASSERT_EQ(x[0], 5);}

// zachTest
TEST(TestAllocator3, index) {
    my_allocator<int, 100> x;
    x.allocate(1);
    x[0] = 5;
    ASSERT_EQ(x[0], 5);}

// zachTest
TEST(TestAllocator3, const_index) {
    const my_allocator<int, 12> x;
    ASSERT_EQ(x[0], 4);}

// zachTest
TEST(TestAllocator4, index) {
    my_allocator<int, 100> x;
    x.allocate(1);
    ASSERT_EQ(x[0], -4);}

// zachTest
TEST(TestAllocator5, index) {
    my_allocator<int, 20> x;
    x.allocate(1);
    ASSERT_EQ(x[0], -12);}

// zachTest
TEST(TestAllocator6, index) {
    my_allocator<int, 20> x;
    int * p = x.allocate(1);
    x.deallocate(p, 10);
    ASSERT_EQ(x[0], 12);}

// zachTest
TEST(TestAllocator7, index) {
    my_allocator<int, 20> x;
    int * p = x.allocate(1);
    x.deallocate(p, 10);
    x.allocate(1);
    ASSERT_EQ(x[0], -12);}

// zachTest
TEST(TestAllocator8, index) {
    my_allocator<int, 20> x;
    int * p = x.allocate(1);
    x.deallocate(p, 10);
    p = x.allocate(1);
    x.deallocate(p, 10);
    ASSERT_EQ(x[0], 12);}

// zachTest
TEST(TestAllocator9, index) {
    my_allocator<int, 20> x;
    int * p = x.allocate(10);
    ASSERT_EQ(p, nullptr);
}


// zachTest
TEST(TestAllocator10, indexAndValid) {
    my_allocator<int, 20> x;
    x[0] = 23;
    ASSERT_FALSE(x.valid());}

// zachTest
TEST(TestAllocator11, indexAndValid) {
    my_allocator<int, 20> x;
    x[16] = 23;
    ASSERT_FALSE(x.valid());}

TEST(TestAllocator12, allocateTest) {
    my_allocator<int, 30> x;
    x.allocate(1);
    x.allocate(1);
    ASSERT_EQ(x[0], -4);}

TEST(TestAllocator13, allocateTest) {
    my_allocator<int, 30> x;
    x.allocate(1);
    x.allocate(1);
    ASSERT_EQ(x[8], -4);}

TEST(TestAllocator14, allocateTest) {
    my_allocator<int, 30> x;
    x.allocate(1);
    x.allocate(1);
    ASSERT_EQ(x[12], -10);}

TEST(TestAllocator15, allocateTest) {
    my_allocator<int, 30> x;
    x.allocate(1);
    x.allocate(1);
    ASSERT_EQ(x[26], -10);}


TEST(TestAllocator16, deallocateTest) {
    my_allocator<int, 30> x;
    x.allocate(5);
    ASSERT_EQ(x[0], -22);}

TEST(TestAllocator17, deallocateTest) {
    my_allocator<int, 30> x;
    x.deallocate(x.allocate(5), 10);
    ASSERT_EQ(x[0], 22);}

TEST(TestAllocator18, allocateTest) {
    my_allocator<int, 10000> x;
    ASSERT_EQ(x[0], 10000 - 8);}

TEST(TestAllocator19, allocateTest) {
    my_allocator<int, 10000> x;
    ASSERT_EQ(x[0], x[10000 - 4]);}


// --------------
// TestAllocator3
// --------------

template <typename A>
struct TestAllocator3 : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          A             allocator_type;
    typedef typename A::value_type value_type;
    typedef typename A::size_type  size_type;
    typedef typename A::pointer    pointer;};

typedef testing::Types<
            my_allocator<int,    100>,
            my_allocator<double, 100>>
        my_types_2;

TYPED_TEST_CASE(TestAllocator3, my_types_2);

TYPED_TEST(TestAllocator3, test_1) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type     value_type;
    typedef typename TestFixture::size_type      size_type;
    typedef typename TestFixture::pointer        pointer;

          allocator_type x;
    const size_type      s = 1;
    const value_type     v = 2;
    const pointer        p = x.allocate(s);
    if (p != nullptr) {
        x.construct(p, v);
        ASSERT_EQ(v, *p);
        x.destroy(p);
        x.deallocate(p, s);}}

TYPED_TEST(TestAllocator3, test_10) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type     value_type;
    typedef typename TestFixture::size_type      size_type;
    typedef typename TestFixture::pointer        pointer;

          allocator_type x;
    const size_type      s = 10;
    const value_type     v = 2;
    const pointer        b = x.allocate(s);
    if (b != nullptr) {
        pointer e = b + s;
        pointer p = b;
        try {
            while (p != e) {
                x.construct(p, v);
                ++p;}}
        catch (...) {
            while (b != p) {
                --p;
                x.destroy(p);}
            x.deallocate(b, s);
            throw;}
        ASSERT_EQ(s, std::count(b, e, v));
        while (b != e) {
            --e;
            x.destroy(e);}
        x.deallocate(b, s);}}

