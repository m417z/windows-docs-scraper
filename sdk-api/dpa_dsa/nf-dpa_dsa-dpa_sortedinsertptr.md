# DPA_SortedInsertPtr macro

## Syntax

```cpp
int DPA_SortedInsertPtr(
   HDPA          hdpa,
   void          *pFind,
   int           iStart,
   PFNDPACOMPARE pfnCompare,
   LPARAM        lParam,
   UINT          options,
   void          *pitem
);
```

## Return value

Type: **int**

Returns the index of the new item, or `-1` if the insert action fails.

## Description

Inserts a new item before or after a specified existing item.

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `pFind`

Type: **void***

An item pointer which is used to determine the insertion point for the new item (see Remarks).

### `iStart`

Type: **int**

The index in the DPA at which to begin searching for *pFind*.

### `pfnCompare`

Type: **[PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare)**

A pointer to the comparison function. See [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare) or [PFNDPACOMPARECONST](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompareconst) for the comparison function prototype.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An additional parameter used to pass information to the comparison function pointed to by *pfnCompare*.

### `options`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The insertion point. Must be one of the following values.

| Value | Meaning |
| --- | --- |
| **DPAS_INSERTBEFORE** | Insert the new item before the *pFind* item. |
| **DPAS_INSERTAFTER** | Insert the new item after the *pFind* item. |

### `pitem`

Type: **void***

A pointer to the item that is to be inserted.

## Remarks

**Note** This macro wraps the [DPA_InsertPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_insertptr) and [DPA_Search](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_search) functions.

The DPAS_SORTED flag is included in *options* by default to indicate that the DPA is sorted.

See function [DPA_Search](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_search) for additional information on how the *pFind* item is located. The new item is inserted before or after the *pFind* item according to the *options* parameter. The *pFind* parameter need not exist in the DPA. If it does not exist in the DPA, then the new item is inserted where *pFind* would have been had it been inserted in the DPA in sorted order.