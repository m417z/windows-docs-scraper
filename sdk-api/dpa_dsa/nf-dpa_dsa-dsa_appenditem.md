# DSA_AppendItem macro

## Syntax

```cpp
int DSA_AppendItem(
  [in] HDSA hdsa,
  [in] void *pitem
);
```

## Return value

Type: **int**

Returns the index of the new item if the append action succeeds, or `-1` if the append action fails.

## Description

Appends a new item to the end of a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

A handle to the DSA in which to insert the item.

### `pitem` [in]

A pointer to the item that is to be inserted.

## Remarks

**Note** This macro wraps the [DSA_InsertItem](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_insertitem) function.

The actual data pointed to by *pItem* is copied into the DSA. Subsequent actions performed on that item do not affect the original copy.