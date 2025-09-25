# ILIsChild function

## Description

Verifies whether a pointer to an item identifier list (PIDL) is a child PIDL, which is a PIDL with exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid).

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A constant, unaligned, relative PIDL that is being checked.

## Return value

Type: **BOOL**

Returns **TRUE** if the given PIDL is a child PIDL; otherwise, **FALSE**.

## Remarks

This function does not guarantee that the PIDL is non-NULL or non-empty.

For use where STRICT_TYPED_ITEMIDS is defined.