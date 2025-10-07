# GetPhysicalMonitors function

> [!IMPORTANT]
> This function is used by the monitor configuration API to access functionality in the display driver. Applications should not call this function.

Gets the physical monitors associated with a display device.

## Parameters

*pstrDeviceName* \[in\]

A pointer to a [**UNICODE\_STRING**](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) structure that contains the name of the display device, as returned by the [**GetMonitorInfo**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function.

*dwPhysicalMonitorArraySize* \[in\]

The number of elements in the *pdwNumPhysicalMonitorHandlesInArray* array. To get the required size of the array, call [**GetNumberOfPhysicalMonitors**](https://learn.microsoft.com/windows/win32/monitor/getnumberofphysicalmonitors).

*pdwNumPhysicalMonitorHandlesInArray* \[out\]

Receives the number of items that the function copies to the *phPhysicalMonitorArray* array.

*phPhysicalMonitorArray* \[out\]

An array that receives handles to the physical monitors. Each handle must be released by calling [**DestroyPhysicalMonitor**](https://learn.microsoft.com/windows/desktop/api/PhysicalMonitorEnumerationAPI/nf-physicalmonitorenumerationapi-destroyphysicalmonitor).

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Instead of using this function, applications should call one of the following functions:

- [**GetPhysicalMonitorsFromHMONITOR**](https://learn.microsoft.com/windows/desktop/api/PhysicalMonitorEnumerationAPI/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor)
- [**GetPhysicalMonitorsFromIDirect3DDevice9**](https://learn.microsoft.com/windows/desktop/api/PhysicalMonitorEnumerationAPI/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9)

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Gdi32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Gdi32.dll |

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/win32/monitor/monitor-configuration-functions)

