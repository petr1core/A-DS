#include <gtest.h>
#include "HashChainTableLib/HashChainTable.h"
///////

TEST(HashChainTable, Created_HashChainTable_with_one_el) {
	HashChainTable <int, string> t;
	ASSERT_NO_THROW(t);
}
TEST(HashChainTable, Insert_HashChainTable) {
	HashChainTable <int, string> t;
	ASSERT_NO_THROW(t.Insert(2, "dva"));
}

TEST(HashChainTable, Find_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_NO_THROW(t.Find(2));
}

TEST(HashChainTable, Cant_Find_in_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dva");
	ASSERT_EQ(nullptr, t.Find(3));
}

TEST(HashChainTable, Delete_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");

	ASSERT_EQ(0, t.Delete(3));
}

TEST(HashChainTable, Cant_Delete_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dwa");
	t.Insert(3, "tri");
	ASSERT_EQ(-1, t.Delete(4));
}

TEST(HashChainTable, GoNext_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.GoNext());
}

TEST(HashChainTable, Reset_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.Reset());
}

TEST(HashChainTable, IsTabEnded_HashChainTable) {
	HashChainTable <int, string> t;
	t.Insert(2, "dva");
	t.Insert(3, "tri");
	ASSERT_NO_THROW(t.IsTabEnded());
}
