# ILIsParent function

## Description

Tests whether an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure is the parent of another **ITEMIDLIST** structure.

## Parameters

### `pidl1` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDL) structure that specifies the parent. This must be an absolute PIDL.

### `pidl2` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDL) structure that specifies the child. This must be an absolute PIDL.

### `fImmediate` [in]

Type: **BOOL**

A Boolean value that is set to **TRUE** to test for immediate parents of *pidl2*, or **FALSE** to test for any parents of *pidl2*.

## Return value

Type: **BOOL**

Returns **TRUE** if *pidl1* is a parent of *pidl2*. If *fImmediate* is set to **TRUE**, the function only returns **TRUE** if *pidl1* is the immediate parent of *pidl2*. Otherwise, the function returns **FALSE**.