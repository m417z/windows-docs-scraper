# WlanAllocateMemory function

## Description

The **WlanAllocateMemory** function allocates memory. Any memory passed to other Native Wifi functions must be allocated with this function.

## Parameters

### `dwMemorySize` [in]

Amount of memory being requested, in bytes.

## Return value

If the call is successful, the function returns a pointer to the allocated memory.

If the memory could not be allocated for any reason or if the *dwMemorySize* parameter is 0, the returned pointer is **NULL**.

An application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain extended error information.

## See also

[WlanFreeMemory](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanfreememory)