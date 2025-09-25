# CIShutdown function

## Description

Shuts down the content indexer and closes all open catalogs.

**Note** This function is not supported as of Windows 8.

## Return value

This function does not return a value.

## Remarks

This function does not have an associated header or library file. To use this function, call [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (Query.dll) to obtain a module handle, and then call [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and an architecture-specific function name to get the address of this function. Specify the function name as "**?CIShutdown@@YGXXZ**" for x86 architecture, or as "**?CIShutdown@@YAXXZ**" for x64 architecture.