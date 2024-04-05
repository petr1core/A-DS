#include <gtest.h>
#include "TreeAVLTableLib/TreeAVL_Table.h"
#include "Polinom/PolinomLib/TPolinom.h"

TEST(SearchTreeTable, Created_searchTable_with_one_el) {
	SearchTreeTable <int, TPolinom> t;
	ASSERT_NO_THROW(t);
}
TEST(SearchTreeTable, Insert_searchTable) {
	SearchTreeTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(SearchTreeTable, Find_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(SearchTreeTable, Cant_Find_in_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr,t.Find(3));
}

TEST(SearchTreeTable, Delete_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(0,t.Delete(3));
}

TEST(SearchTreeTable, Cant_Delete_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(1, t.Delete(4));
}

TEST(SearchTreeTable, GoNext_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(SearchTreeTable, Reset_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(SearchTreeTable, IsTabEnded_searchTable) {
	SearchTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}

///////

TEST(AVLTreeTable, Created_AVLTreeTable_with_one_el) {
	AVLTreeTable <int, TPolinom> t;
	ASSERT_NO_THROW(t);
}
TEST(AVLTreeTable, Insert_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(AVLTreeTable, Find_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(AVLTreeTable, Cant_Find_in_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(AVLTreeTable, Delete_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(1, t.Delete(3));
}

TEST(AVLTreeTable, Cant_Delete_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(0, t.Delete(4));
}

TEST(AVLTreeTable, GoNext_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(AVLTreeTable, Reset_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(AVLTreeTable, IsTabEnded_AVLTreeTable) {
	AVLTreeTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
