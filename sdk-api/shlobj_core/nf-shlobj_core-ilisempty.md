# ILIsEmpty function

## Description

Verifies whether an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure is empty.

## Parameters

### `pidl` [in]

Type: **PCUID_RELATIVE**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to be checked.

## Return value

Type: **BOOL**

**TRUE** if the *pidl* parameter is **NULL** or the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure pointed to by *pidl* is empty; otherwise **FALSE**.