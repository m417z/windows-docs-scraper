# TestClose function

Closes a test handle.

## Parameters

### test

The test handle returned from [TestCreate](https://learn.microsoft.com/windows/win32/devnotes/tip-testcreate-function) or [TestOpen](https://learn.microsoft.com/windows/win32/devnotes/tip-testopen-function).

## Return value

None.

## Remarks

This function has no associated import library or header file; it must be invoked using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows Build 22000 |
| Minimum supported server | Windows Server 2022 |
| Header | None |
| DLL | kernelbase.dll |

