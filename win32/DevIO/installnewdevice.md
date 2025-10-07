# InstallNewDevice function

Installs a new device. The user is prompted to select the device.

## Parameters

*hwndParent* \[in\]

A handle to the top-level window to be used for any required user interface.

*ClassGuid* \[in\]

A pointer to a class **GUID**. This parameter is optional. If this parameter is **NULL**, the user starts at the detection choice page. If this parameter is **GUID\_NULL** or **GUID\_DEVCLASS\_UNKNOWN**, the user starts at the class selection page.

*pReboot* \[out\]

A pointer to a variable that receives the reboot status. This parameter can be **DI\_NEEDRESTART** or **DI\_NEEDREBOOT**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to NewDev.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP<br> |
| Minimum supported server<br> | Windows Server 2003<br> |
| DLL<br> | NewDev.dll |

## See also

[Device Management Functions](https://learn.microsoft.com/windows/win32/devio/device-management-functions)

