#include "list.h"
#include <gtest.h>
//
TEST(TList, can_create_list)
{
	TList<int> list;
	EXPECT_EQ(nullptr, list.begin());
}
TEST(TList, can_create_list_with_el)
{
	TList<int> list(3);
	EXPECT_EQ(3, list[0]);
}
TEST(TList, check_empty)
{
	TList<int> list;
	EXPECT_EQ(true, list.IsEmpty());
}
TEST(TList, check_nempty)
{
	TList<int> list(3);
	EXPECT_EQ(false, list.IsEmpty());
}
TEST(TList, check_push_begin)
{
	TList<int> list(3);
	list.Push_begin(6);
	EXPECT_EQ(6, list[0]);
}
TEST(TList, check_push_back)
{
	TList<int> list(3);
	list.Push_back(5);
	EXPECT_EQ(5, list[1]);
}
TEST(TList, check_get_size)
{
	TList<int> list(3);
	list.Push_back(5);
	list.Push_back(5);
	EXPECT_EQ(3,list.GetSize());
}
TEST(TList, del_el)
{
	bool flag = false;
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	list.DeleteEl(1);
	if (list.GetSize() == 2 && list[1] == 5)
		flag = true;
	EXPECT_EQ(true, flag);
}
TEST(TList, throw_when_delete_negativ_index)
{
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	ASSERT_ANY_THROW(list.DeleteEl(-1));
}
TEST(TList, throw_when_delete_large_index)
{
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	ASSERT_ANY_THROW(list.DeleteEl(10));
}
TEST(TList, list_clear)
{
	bool flag = false;
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	list.Clear();
	if (list.begin() == nullptr&&list.GetSize() == 0)
		flag = true;
	EXPECT_EQ(true, flag);
}
TEST(TList, list_insert)
{
	bool flag = false;
	TList<int> list(1);
	list.Push_back(3);
	list.Push_back(4);
	list.Insert(1,2);
	if (list.GetSize() == 4 && list[1] == 2 && list[2] == 3 && list[0] == 1)
		flag = true;
	EXPECT_EQ(true, flag);
}
TEST(TList, throw_when_insert_large_index)
{
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	ASSERT_ANY_THROW(list.Insert(10,11));
}
TEST(TList, throw_when_insert_negativ_index)
{
	TList<int> list(3);
	list.Push_back(4);
	list.Push_back(5);
	ASSERT_ANY_THROW(list.Insert(-1, 1));
}


