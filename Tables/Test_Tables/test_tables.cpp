#include "gtest.h"
//#include<algorithm>
#include "../Tables/TScanTable.h"
//#include "gtest.h"

TEST(TScanTable, can_create)
{
	TScanTable* tab;

	ASSERT_NO_THROW(tab = new TScanTable(25));
}