#include <gtest.h>
#include "ListLinearTableLib/ListLinearTable.h"
///////

TEST(LinearListTable, Created_LinearListTable_with_one_el) {
	LinearListTable <int, string> t;
	ASSERT_NO_THROW(t);
}
TEST(LinearListTable, Insert_LinearListTable) {
	LinearListTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(LinearListTable, Find_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(LinearListTable, Cant_Find_in_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(LinearListTable, Delete_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(0, t.Delete(3));
}

TEST(LinearListTable, Cant_Delete_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(-1, t.Delete(4));
}

TEST(LinearListTable, GoNext_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(LinearListTable, Reset_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(LinearListTable, IsTabEnded_LinearListTable) {
	LinearListTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
