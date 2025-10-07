# GetNumberOfPhysicalMonitors function

> [!IMPORTANT]
> This function is used by the monitor configuration API to access functionality in the display driver. Applications should not call this function.

Gets the number of phyical monitors associated with a display device.

## Parameters

*pstrDeviceName* \[in\]

A pointer to a [**UNICODE\_STRING**](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the display device, as returned by the [**GetMonitorInfo**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function.

*pdwNumberOfPhysicalMonitors* \[out\]

Receives the number of physical monitors.

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Instead of using this function, applications should call one of the following functions:

- [**GetNumberOfPhysicalMonitorsFromHMONITOR**](https://learn.microsoft.com/windows/desktop/api/PhysicalMonitorEnumerationAPI/nf-physicalmonitorenumerationapi-getnumberofphysicalmonitorsfromhmonitor)
- [**GetNumberOfPhysicalMonitorsFromIDirect3DDevice9**](https://learn.microsoft.com/windows/desktop/api/PhysicalMonitorEnumerationAPI/nf-physicalmonitorenumerationapi-getnumberofphysicalmonitorsfromidirect3ddevice9)

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Gdi32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Gdi32.dll |

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/win32/monitor/monitor-configuration-functions)

