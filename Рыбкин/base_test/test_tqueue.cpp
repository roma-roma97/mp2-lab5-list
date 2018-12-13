#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int>q(5));
}
TEST(TQueue, cant_create_queue_too_large_length)
{
	ASSERT_ANY_THROW(TQueue<int>q(MaxStackSize+1));
}
TEST(TQueue, can_create_queue_with_negativ_length)
{
	ASSERT_ANY_THROW(TQueue<int>q(-1));
}
TEST(TQueue,check_IsEmpty_with_empty_queue)
{
	TQueue<int> q(5);
	EXPECT_EQ(true,q.IsEmpty());
}
TEST(TQueue, check_IsEmpty_with_not_empty_queue)
{
	TQueue<int> q(5);
	q.Push(2);
	EXPECT_EQ(false, q.IsEmpty());
}
TEST(TQueue, check_IsFull_with_full_queue)
{
	TQueue<int> q(2);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(true, q.IsFull());
}
TEST(TQueue, check_IsFull_with_not_full_queue)
{
	TQueue<int> q(5);
	q.Push(2);
	EXPECT_EQ(false, q.IsFull());
}
TEST(TQueue, throws_when_Pop_queue_IsEmty)
{
	TQueue<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}
TEST(TQueue, throws_when_Push_queue_IsFull)
{
	TQueue<int> q(2);
	q.Push(1);
	q.Push(2);
	ASSERT_ANY_THROW(q.Push(2));
}
TEST(TQueue, check_FirstEl_queue)
{
	TQueue<int> q(2);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(1,q.GetFirstEl());
}
TEST(TQueue, check_GetCount_queue)
{
	TQueue<int> q(4);
	q.Push(1);
	q.Push(2);
	EXPECT_EQ(2, q.GetCount());
}

