# DPA_GetPtrIndex function

## Description

[**DPA_GetPtrIndex** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.]

Gets the index of a matching item found in a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

Type: **HDPA**

A handle to an existing DPA.

### `p` [in]

Type: **const void***

A pointer to an item to locate in *hdpa*.

## Return value

Type: **int**

The index of the item pointed to by *pvoid*, if found; otherwise, -1.

## Remarks

**DPA_GetPtrIndex** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 333 from ComCtl32.dll to obtain a function pointer.