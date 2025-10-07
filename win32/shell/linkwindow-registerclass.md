# LinkWindow\_RegisterClass function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. Use [**InitCommonControlsEx**](https://learn.microsoft.com/windows/win32/api/commctrl/nf-commctrl-initcommoncontrolsex) instead.\]

Registers a window class that allows for the [SysLink](https://learn.microsoft.com/windows/win32/controls/syslink-overview) common control to be used in a window.

## Parameters

This function has no parameters.

## Return value

Type: **BOOL**

Returns **TRUE** if registration was successful; **FALSE** otherwise.

## Remarks

This function does not have an associated header or library file so it must be called by ordinal value. Call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name Shell32.dll to obtain a module handle. Then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and the ordinal number 258 to use this function.

Use [**LinkWindow\_UnregisterClass**](https://learn.microsoft.com/windows/win32/shell/linkwindow-unregisterclass) to unregister the class after use.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll (version 5.0 or later) |

## See also

[Overview of SysLink Controls](https://learn.microsoft.com/windows/win32/controls/syslink-overview)

