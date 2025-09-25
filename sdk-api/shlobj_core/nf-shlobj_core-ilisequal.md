# ILIsEqual function

## Description

Tests whether two [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures are equal in a binary comparison.

## Parameters

### `pidl1` [in]

Type: **PCIDLIST_ABSOLUTE**

The first [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `pidl2` [in]

Type: **PCIDLIST_ABSOLUTE**

The second [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Return value

Type: **BOOL**

Returns **TRUE** if the two structures are equal, **FALSE** otherwise.

## Remarks

**ILIsEqual** performs a binary comparison of the item data. It is possible for two [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures to differ at the binary level while referring to the same item. [IShellFolder::CompareIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-compareids) should be used to perform a non-binary comparison.