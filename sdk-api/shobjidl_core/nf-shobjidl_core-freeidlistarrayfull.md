# FreeIDListArrayFull function

## Description

Releases the memory space for the pointer to an item identifier list (PIDL) array. This releases both the PIDLIST_ABSOLUTEs within the array and the array itself.

## Parameters

### `ppidls` [in]

Type: **PIDLIST_ABSOLUTE***

A pointer to the PIDL list, stored as an array of *cItems* elements.

### `cItems`

Type: **UINT**

The number of items in the array.