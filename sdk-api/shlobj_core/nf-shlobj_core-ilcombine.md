# ILCombine function

## Description

Combines two [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures.

## Parameters

### `pidl1` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to the first [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `pidl2` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to the second [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. This structure is appended to the structure pointed to by *pidl1*.

## Return value

Type: **PIDLIST_ABSOLUTE**

Returns an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) containing the combined structures. If you set either *pidl1* or *pidl2* to **NULL**, the returned **ITEMIDLIST** structure is a clone of the non-**NULL** parameter. Returns **NULL** if *pidl1* and *pidl2* are both set to **NULL**.