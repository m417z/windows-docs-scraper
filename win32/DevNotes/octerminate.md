# OcTerminate function

Closes the OC manager.

## Parameters

*OcManagerContext* \[in, out\]

On input, contains the OC manager context pointer returned by [**OcInitialize**](https://learn.microsoft.com/windows/win32/devnotes/ocinitialize). On output, receives **NULL**.

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | OcManage.dll |

## See also

[**OcInitialize**](https://learn.microsoft.com/windows/win32/devnotes/ocinitialize)

