# DPA_Search function

## Description

[**DPA_Search** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Finds an item in a dynamic pointer array (DPA).

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `pFind`

Type: **void***

A pointer to search for.

### `iStart`

Type: **int**

The index at which to start search.

### `pfnCompare`

Type: **[PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare)**

A comparison function pointer. See [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare) for the comparison function prototype.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An additional parameter to be passed to *pfnCmp*.

### `options`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This parameter may be one or more of the following.

| Value | Meaning |
| --- | --- |
| **DPAS_SORTED** | Indicates that the DPA is sorted. |
| **DPAS_INSERTBEFORE** | This value is only valid in conjunction with DPAS_SORTED. If the item is not found, return the position where the item is expected to be found in the sorted DPA. |
| **DPAS_INSERTAFTER** | This value is only valid in conjunction with DPAS_SORTED. If the item is not found, return the position where the item is expected to be found in the sorted DPA. |

## Return value

Type: **int**

Returns the index where the item was found in the DPA or `-1` if the item was not found.