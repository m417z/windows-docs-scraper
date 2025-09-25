# DSA_GetItem function

## Description

Gets an element from a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to the DSA containing the element.

### `i` [in]

Type: **int**

The index of the element to be retrieved (zero-based).

### `pitem` [out]

Type: **void***

A pointer to a buffer which is filled with a copy of the specified element of the DSA.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

**DSA_GetItem** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 322 from ComCtl32.dll to obtain a function pointer.

Using the element pointer that this function retrieves, you can modify the data in that element directly. However, be aware that a subsequent insert or destroy operation could cause this pointer value to become invalid or to point to a different element.

## See also

[DSA_GetItemPtr](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_getitemptr)