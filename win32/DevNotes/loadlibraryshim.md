# LoadLibraryShim function

Loads a specified version of a .NET Framework library DLL.

## Parameters

*szDllName* \[in\]

The name of the DLL to be loaded from the .NET Framework.

*szVersion* \[in\]

The version of the DLL to be loaded. If *szVersion* is **NULL**, the latest version of the specified DLL is loaded.

*pvReserved*

Reserved.

*phModDll* \[out\]

A handle to the module.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is used to load library DLLs that are included in the .NET Framework redistributable package, not user-generated DLLs.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Mscoree.dll |

