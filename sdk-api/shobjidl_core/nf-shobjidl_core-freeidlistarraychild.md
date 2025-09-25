# FreeIDListArrayChild function

## Description

Releases the memory space for the array of pointers to child item IDs. This releases both the PITEMID_CHILDs within the array and the array itself.

## Parameters

### `ppidls` [in]

Type: **PITEMID_CHILD***

A pointer to the PIDL list, stored as an array of *cItems* elements.

### `cItems`

Type: **UINT**

The number of items in the array.