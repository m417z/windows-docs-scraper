# SSortOrder structure

## Description

Do not use. Defines how to sort rows of a table, describing both the column to use as the sort key and the direction of the sort.

## Members

### `ulPropTag`

Type: **ULONG**

Variable of type **ULONG** that specifies the property tag identifying either the sort key or, for a categorized sort, the category column.

### `ulOrder`

Type: **ULONG**

Variable of type **ULONG** that specifies the order in which the data is to be sorted. The possible values are as follows.

#### TABLE_SORT_ASCEND

Table is sorted in ascending order.

#### TABLE_SORT_COMBINE

Sort operation creates a category that combines the property identified as the sort key column in the **ulPropTag** member with the sort key column specified in the previous **SSortOrder** structure.

TABLE_SORT_COMBINE can only be used when the **SSortOrder** structure is being used as an entry in an [SSortOrderSet](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-ssortorderset) structure to specify multiple sort orders for a categorized sort. TABLE_SORT_COMBINE cannot be used in the first **SSortOrder** structure in an **SSortOrderSet** structure.

#### TABLE_SORT_DESCEND

Table is sorted in descending order.