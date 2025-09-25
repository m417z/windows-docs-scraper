# DSA_InsertItem function

## Description

[**DSA_InsertItem** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Inserts a new item into a dynamic structure array (DSA). If necessary, the DSA expands to accommodate the new item.

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to the DSA in which to insert the item.

### `i` [in]

Type: **int**

The position in the DSA where new item is to be inserted, or DSA_APPEND to insert the item at the end of the array.

### `pitem` [in]

Type: **void***

A pointer to the item that is to be inserted.

## Return value

Type: **int**

Returns the index of the new item if the insertion succeeds, or DSA_ERR (`-1`) if the insertion fails.

## Remarks

The actual data pointed to by *pItem* is copied into the DSA. Subsequent actions performed on that item do not affect the original copy.