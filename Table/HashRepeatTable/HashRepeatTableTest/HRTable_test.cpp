#include <gtest.h>
#include "HashRepeatTableLib/HashRepeatTable.h"
///////

TEST(HashRepeatTable, Created_HashRepeatTable_with_one_el) {
	HashRepeatTable <int, string> t;
	ASSERT_NO_THROW(t);
}
TEST(HashRepeatTable, Insert_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(HashRepeatTable, Find_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(HashRepeatTable, Cant_Find_in_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(HashRepeatTable, Delete_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(0, t.Delete(3));
}

TEST(HashRepeatTable, Cant_Delete_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(-1, t.Delete(4));
}

TEST(HashRepeatTable, GoNext_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(HashRepeatTable, Reset_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(HashRepeatTable, IsTabEnded_HashRepeatTable) {
	HashRepeatTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
