# ILFindChild function

## Description

Determines whether a specified [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure is the child of another **ITEMIDLIST** structure.

## Parameters

### `pidlParent` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to the parent [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `pidlChild` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to the child [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Return value

Type: **PUIDLIST_RELATIVE**

Returns a pointer to the child's simple [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure if *pidlChild* is a child of *pidlParent*. The returned structure consists of *pidlChild*, minus the [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structures that make up *pidlParent*. Returns **NULL** if *pidlChild* is not a child of *pidlParent*.

**Note** The returned pointer is a pointer into the existing parent structure. It is an alias for *pidlChild*. No new memory is allocated in association with the returned pointer. It is not the caller's responsibility to free the returned value.