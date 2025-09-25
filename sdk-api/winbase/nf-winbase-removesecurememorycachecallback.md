# RemoveSecureMemoryCacheCallback function

## Description

Unregisters a callback function that was previously registered with the [AddSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addsecurememorycachecallback) function.

## Parameters

### `pfnCallBack` [in]

A pointer to the application-defined [SecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-psecure_memory_cache_callback) function to remove.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[AddSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addsecurememorycachecallback)

[SecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-psecure_memory_cache_callback)