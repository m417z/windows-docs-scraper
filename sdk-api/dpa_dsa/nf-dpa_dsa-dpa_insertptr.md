# DPA_InsertPtr function

## Description

[**DPA_InsertPtr** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Inserts a new item at a specified position in a dynamic pointer array (DPA). If necessary, the DPA expands to accommodate the new item.

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `i`

Type: **int**

Tbe position where new item is to be inserted.

### `p`

Type: **void***

A pointer to the item that is to be inserted.

## Return value

Type: **int**

Returns the index of the new item or `-1`, if the insertion fails.