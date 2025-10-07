# LinkWindow\_UnregisterClass function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.\]

Unregisters a window class registered by [**LinkWindow\_RegisterClass**](https://learn.microsoft.com/windows/win32/shell/linkwindow-registerclass).

## Parameters

This function has no parameters.

## Return value

Type: **BOOL**

Returns **TRUE** if the operation was successful; **FALSE** otherwise.

## Remarks

This function does not have an associated header or library file so it must be called by ordinal value. Call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name Shell32.dll to obtain a module handle. Then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and the ordinal number 259 to use this function.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll (version 5.0 or later) |

## See also

[Overview of SysLink Controls](https://learn.microsoft.com/windows/win32/controls/syslink-overview)

