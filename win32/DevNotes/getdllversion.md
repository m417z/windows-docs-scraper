# GetDllVersion function

\[This function is no longer supported, so its behavior cannot be guaranteed. \]

The **GetDllVersion** function retrieves the version number of Cabinet.dll.

## Parameters

This function has no parameters.

## Return value

The version number of the file (see [VERSIONINFO Resource](https://learn.microsoft.com/windows/win32/menurc/versioninfo-resource)).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Cabinet.dll |

## See also

[**DllGetVersion**](https://learn.microsoft.com/windows/win32/devnotes/dllgetversion)

