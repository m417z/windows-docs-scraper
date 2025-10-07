# RtlGetFunctionTableListHead function

\[This function may be changed or removed from Windows without further notice.\]

Enables a debugger to examine dynamic function table information.

## Parameters

This function has no parameters.

## Return value

Returns a pointer to the head of the function table linked list. Nodes in this list are of type [**DYNAMIC\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/devnotes/dynamic_function_table_type). A debugger can walk all the entries in this list to find all of the function tables in a target process.

## Remarks

Note that the Windows Driver Kit (WDK) header file Ntdef.h is required for some definitions. The associated import library, Ntdll.lib, is available in the WDK. You can also use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

