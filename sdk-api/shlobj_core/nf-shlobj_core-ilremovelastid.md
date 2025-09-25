# ILRemoveLastID function

## Description

Removes the last [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure from an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in, out, optional]

Type: **PUIDLIST_RELATIVE**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to be shortened. When the function returns, this variable points to the shortened structure.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, **FALSE** otherwise.