# DSA_SetItem function

## Description

[**DSA_SetItem** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.]

Sets the contents of an element in a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to an existing DSA that contains the element.

### `i` [in]

Type: **int**

The zero-based index of the item to set.

### `pitem` [in]

Type: **void***

A pointer to the item that will replace the specified item in the array.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if successful; otherwise, **FALSE**.

## Remarks

**DSA_SetItem** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 325 from ComCtl32.dll to obtain a function pointer.