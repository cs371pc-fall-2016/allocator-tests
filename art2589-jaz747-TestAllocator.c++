// ------------------------------------
// projects/allocator/TestAllocator1.c++
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------------

// --------
// includes
// --------

#include <algorithm> // count
#include <memory>    // allocator
#include <stdexcept>

#include "gtest/gtest.h"

#include "Allocator.h"

/*
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
            Allocator<int,    100>,
            Allocator<double, 100>>
        my_types_1;

TYPED_TEST_CASE(TestAllocator1, my_types_1);

// Default Constructor Tests

TYPED_TEST(TestAllocator1, test_1) {
    try {
        Allocator<double, 8> x;
        ASSERT_EQ(true, false);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

TYPED_TEST(TestAllocator1, test_2) {
    try {
        Allocator<int, 4> x;
        ASSERT_EQ(true, false);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

// Allocate Tests

TYPED_TEST(TestAllocator1, test_3) {
    try {
        Allocator<int, 100> x;
        x.allocate(-9);
        ASSERT_EQ(true, false);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

TYPED_TEST(TestAllocator1, test_4) {
    try {
        Allocator<int, 100> x;
        x.allocate(25);
        ASSERT_EQ(true, false);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

TYPED_TEST(TestAllocator1, test_5) {
    try {
        Allocator<int, 100> x;
        x.allocate(13);
        ASSERT_EQ(true, true);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, false);
    }
}

// Deallocate Tests

TYPED_TEST(TestAllocator1, test_6) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;

    allocator_type x;
    const size_type s = 100;
    const value_type v = 2;

    try {
        x.deallocate(nullptr, s);
        ASSERT_EQ(true, false);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

TYPED_TEST(TestAllocator1, test_7) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;
    typedef typename TestFixture::pointer pointer;

    allocator_type x;
    const size_type s = 4;
    const value_type v = 2;

    try {
        pointer p = x.allocate(s);
        x.deallocate(p, s);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, false);
    }
}

TYPED_TEST(TestAllocator1, test_8) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;
    typedef typename TestFixture::pointer pointer;

    allocator_type x;
    const size_type s = 4;
    const value_type v = 2;

    try {
        pointer p = x.allocate(s);
        x.deallocate(p, s);
        x.deallocate(p, s);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, true);
    }
}

// force right coalesce
TYPED_TEST(TestAllocator1, test_9) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;
    typedef typename TestFixture::pointer pointer;

    allocator_type x;
    const size_type s = 4;
    const value_type v = 2;

    try {
        pointer p = x.allocate(s);
        pointer q = x.allocate(s);
        x.deallocate(q, s);
        x.deallocate(p, s);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, false);
    }
}

// Force left Coalesce
TYPED_TEST(TestAllocator1, test_10) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;
    typedef typename TestFixture::pointer pointer;

    allocator_type x;
    const size_type s = 4;
    const value_type v = 2;

    try {
        pointer p = x.allocate(s);
        pointer q = x.allocate(s);
        x.deallocate(p, s);
        x.deallocate(q, s);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, false);
    }
}

// Both sides merge test
TYPED_TEST(TestAllocator1, test_11) {
    typedef typename TestFixture::allocator_type allocator_type;
    typedef typename TestFixture::value_type value_type;
    typedef typename TestFixture::size_type size_type;
    typedef typename TestFixture::pointer pointer;

    allocator_type x;
    const size_type s = 3;
    const value_type v = 1;

    try {
        pointer p = x.allocate(s);
        pointer q = x.allocate(s);
        pointer r = x.allocate(s);
        x.deallocate(p, s);
        x.deallocate(r, s);
        x.deallocate(q, s);
    } catch (std::bad_alloc &e) {
        ASSERT_EQ(true, false);
    }
}
*/
 // --------------
// TestAllocator2
// --------------

template <typename A>
struct TestAllocator2 : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          A             allocator_type;
    typedef typename A::value_type value_type;
    typedef typename A::size_type  size_type;
    typedef typename A::pointer    pointer;};

typedef testing::Types<
            Allocator<int,    100>,
            Allocator<double, 100>>
        my_types_2;

TYPED_TEST_CASE(TestAllocator2, my_types_2);

TEST(TestAllocator2, valid) {
    Allocator<int, 20> x;
    assert(x.valid());
}
