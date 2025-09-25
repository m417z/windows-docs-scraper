# ILNext function

## Description

Retrieves the next [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure in an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A constant, unaligned, relative PIDL for which the next [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure is being retrieved.

## Return value

Type: **PCUIDLIST_RELATIVE**

When this function returns, contains one of three results: If *pidl* is valid and not the last [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) in the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist), then it contains a pointer to the next **ITEMIDLIST** structure. If the last **ITEMIDLIST** structure is passed, it contains **NULL**, which signals the end of the PIDL. For other values of *pidl*, the return value is meaningless.

## Remarks

For use where STRICT_TYPED_ITEMIDS is defined.

To verify if the return value is **NULL**, use [ILIsEmpty](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilisempty).