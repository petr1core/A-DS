#include <gtest.h>
#include "ArrLinearTableLib/ArrLinearTable.h"

///////

TEST(LinearArrTable, Created_AVLTreeTable_with_one_el) {
	LinearArrTable <int, string>t;
	ASSERT_NO_THROW(t);
}
TEST(LinearArrTable, Insert_AVLTreeTable) {
	LinearArrTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(LinearArrTable, Find_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(LinearArrTable, Cant_Find_in_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(AVLTreeTable, Delete_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(0, t.Delete(3));
}

TEST(AVLTreeTable, Cant_Delete_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(-1, t.Delete(4));
}

TEST(AVLTreeTable, GoNext_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(AVLTreeTable, Reset_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(AVLTreeTable, IsTabEnded_AVLTreeTable) {
	LinearArrTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
