# DllGetVersion function

\[This function is no longer supported, so its behavior cannot be guaranteed.\]

The **DllGetVersion** function retrieves the version number of Cabinet.dll using the [**CABINETDLLVERSIONINFO**](https://learn.microsoft.com/windows/win32/devnotes/cabinetdllversioninfo) structure.

## Parameters

*pcdvi*

Pointer to the [**CABINETDLLVERSIONINFO**](https://learn.microsoft.com/windows/win32/devnotes/cabinetdllversioninfo) structure that contains the version information.

## Return value

This function does not return a value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Cabinet.dll |

## See also

[**CABINETDLLVERSIONINFO**](https://learn.microsoft.com/windows/win32/devnotes/cabinetdllversioninfo)

[**GetDllVersion**](https://learn.microsoft.com/windows/win32/devnotes/getdllversion)

