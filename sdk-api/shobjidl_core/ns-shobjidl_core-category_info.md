# CATEGORY_INFO structure

## Description

Contains category information. A component category is a group of logically-related Component Object Model (COM) classes that share a common category identifier (CATID).

## Members

### `cif`

Type: **[CATEGORYINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-categoryinfo_flags)**

A flag from [CATEGORYINFO_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-categoryinfo_flags) that specifies the type of information to retrieve.

### `wszName`

Type: **WCHAR[260]**

A character array that specifies the name of the category.