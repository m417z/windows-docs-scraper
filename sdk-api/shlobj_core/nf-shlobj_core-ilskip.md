# ILSkip function

## Description

Skips a given number of bytes in a constant, unaligned, relative [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A constant, unaligned, relative PIDL in which bytes are to be skipped.

### `cb`

Type: **UINT**

The number of bytes to skip.

## Return value

Type: **PCUIDLIST_RELATIVE**

When this function returns, if *pidl* and *cb* are valid, contains a constant pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that results after the skip. Otherwise, the value is meaningless.

## Remarks

For use where STRICT_TYPED_ITEMIDS is defined.