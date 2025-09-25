# DPA_Sort function

## Description

[**DPA_Sort** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Sorts the items in a Dynamic Pointer Array (DPA).

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `pfnCompare`

Type: **[PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare)**

A comparison function pointer. See [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare) for the comparison function prototype.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An additional parameter to be passed to *pfnCmp*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** on success or **FALSE** on failure.