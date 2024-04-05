#include <gtest.h>
#include "ArrOrderedTableLib/ArrOrderedTable.h"
///////

TEST(OrderedArrTable, Created_OrderedArrTable_with_one_el) {
	OrderedArrTable <int, string> t;
	ASSERT_NO_THROW(t);
}
TEST(OrderedArrTable, Insert_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(OrderedArrTable, Find_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(OrderedArrTable, Cant_Find_in_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(OrderedArrTable, Delete_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(0, t.Delete(3));
}

TEST(OrderedArrTable, Cant_Delete_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(-1, t.Delete(4));
}

TEST(OrderedArrTable, GoNext_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(OrderedArrTable, Reset_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(OrderedArrTable, IsTabEnded_OrderedArrTable) {
	OrderedArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
