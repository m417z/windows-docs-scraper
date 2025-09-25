# DLLGETVERSIONPROC callback function

## Description

Implemented by many of the Windows Shell DLLs to allow applications to obtain DLL-specific version information.

## Parameters

### -param

#### - pdvi

Type: **[DLLVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo)***

A pointer to a [DLLVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo) structure that receives the version information. The **cbSize** member must be filled in before you call this function.

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). DLLs that are shipped with Windows 2000 or later systems may return a [DLLVERSIONINFO2](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo2) structure. To maintain backward compatibility, the first member of a **DLLVERSIONINFO2** structure is a [DLLVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/shlwapi/ns-shlwapi-dllversioninfo) structure.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is exported by name from each DLL that implements it. Currently, most of the Windows Shell and controls DLLs implement **DllGetVersion**. These include, but are not limited to, Shell32.dll, Comctl32.dll, Shdocvw.dll, and Shlwapi.dll.

To call this function, use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to obtain the function pointer. The DLLGETVERSIONPROC type is used as the data type to define a pointer to a **DllGetVersion** function. Use the pointer when calling the function dynamically by loading the library and getting the function's address. See [Shell and Shlwapi DLL Versions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) for a detailed discussion of the different file versions, and how to use **DllGetVersion**.