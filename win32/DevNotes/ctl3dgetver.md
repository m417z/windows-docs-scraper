# Ctl3dGetVer function

Indicates the version of CTL3D that is currently running.

## Parameters

This function has no parameters.

## Return value

Returns a value that contains the major version number in the high-order byte and the minor version number in the low-order byte.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

