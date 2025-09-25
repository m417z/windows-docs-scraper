# DSA_DeleteItem function

## Description

[**DSA_DeleteItem** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.]

Deletes an item from a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to an existing DSA.

### `i` [in]

Type: **int**

The zero-based index of the item to delete.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the item was successfully deleted; otherwise, **FALSE**.

## Remarks

**DSA_DeleteItem** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 326 from ComCtl32.dll to obtain a function pointer.