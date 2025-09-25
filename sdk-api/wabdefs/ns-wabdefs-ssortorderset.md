# SSortOrderSet structure

## Description

Do not use. Defines a collection of keys for a table to be used for standard or categorized sorting.

## Members

### `cSorts`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of [SSortOrder](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-ssortorder) structures that are included in the **aSort** member.

### `cCategories`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of columns that are designated as category columns. Possible values range from zero, which indicates a non-categorized or standard sort, to the number indicated by the **cSorts** member.

### `cExpanded`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of categories that start in an expanded state, where all the rows that apply to the category are visible in the table view. Possible values range from zero to the number indicated by **cCategories**.

### `aSort`

Type: **[SSortOrder](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-ssortorder)[MAPI_DIM]**

Array of variables of type [SSortOrder](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-ssortorder) that specifies the structures that define a sort order.