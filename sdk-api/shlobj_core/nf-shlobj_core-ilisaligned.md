# ILIsAligned function

## Description

Verifies whether a constant [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) is aligned on a pointer boundary, which is a **DWORD** on 32-bit architectures and a **QWORD** on 64-bit architectures.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A constant PIDL relative to a parent folder that is being checked for alignment.

## Return value

Type: **BOOL**

Returns **TRUE** if aligned; otherwise, **FALSE**.

## Remarks

For use where STRICT_TYPED_ITEMIDS is defined.