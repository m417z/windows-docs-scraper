# ILGetNext function

## Description

Retrieves the next [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure in an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in, optional]

Type: **PCUIDLIST_RELATIVE**

A pointer to a particular [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure in a larger [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Return value

Type: **PUIDLIST_RELATIVE**

Returns a pointer to the [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure that follows the one specified by *pidl*. Returns **NULL** if *pidl* points to the last **SHITEMID** structure.