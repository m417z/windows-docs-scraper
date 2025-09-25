# DSA_Sort function

## Description

Sorts the items in a dynamic structure array (DSA).

## Parameters

### `pdsa` [in]

Type: **HDSA**

A handle to an existing DSA.

### `pfnCompare` [in]

Type: **[PFNDACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare)**

A comparison function pointer. See [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare) for the comparison function prototype.

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An additional parameter to be passed to *pfnCmp*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** on success or **FALSE** on failure.