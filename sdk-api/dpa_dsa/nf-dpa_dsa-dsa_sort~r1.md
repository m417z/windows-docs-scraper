# DSA_Sort function

## Description

Sorts the items in a dynamic structure array (DSA).

## Parameters

### `hdsa`

Type: **HDSA**

A handle to an existing DSA.

### `pfnCompare`

Type: **PFNDACOMPARECONST**

A comparison function pointer.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An additional parameter to be passed to *pfnCmp*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** on success or **FALSE** on failure.

## Remarks

## See also