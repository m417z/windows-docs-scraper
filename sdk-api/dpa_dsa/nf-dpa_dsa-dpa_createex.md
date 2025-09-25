# DPA_CreateEx function

## Description

Creates a dynamic pointer array (DPA) using a given specified size and heap location.

## Parameters

### `cpGrow` [in]

Type: **int**

The number of elements by which the array should be expanded, if the DPA needs to be enlarged.

### `hheap` [in, optional]

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the heap where the array is stored.

## Return value

Type: **HDPA**

Returns a handle to a DPA if successful, or **NULL** if the call fails.

## Remarks

**DPA_CreateEx** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 340 from ComCtl32.dll to obtain a function pointer.

## See also

[DPA_Create](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_create)