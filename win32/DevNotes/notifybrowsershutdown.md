# NotifyBrowserShutdown function

Frees Java class loaders that may have been consumed while browsing the applets.

## Parameters

*lpvReserved*

This parameter is not used.

## Return value

If the function succeeds, the return value is **S\_OK**. Otherwise, the return value is an error code.

## Remarks

When the count of browser windows reaches zero in integrated Web mode, this function frees the Java class loaders. When the user starts browsing applets again, the Java VM will download the latest class files.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Msjava.dll |

