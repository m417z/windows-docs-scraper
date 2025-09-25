# PerUserInit function

## Description

[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Creates [My Documents](https://learn.microsoft.com/windows/desktop/shell/manage) and other special folders, initializes them as needed, and creates the **Send To** shortcut menu item for My Documents.

## Remarks

Applications do not need to call this function because the operating system already does so.

This function does not have an associated header or library file so it must be called by ordinal value. Call [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name Mydocs.dll to obtain a module handle. Then call [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and the ordinal number 7 to use this function.