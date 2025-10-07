# GetPhysicalMonitorDescription function

> [!IMPORTANT]
> This function is used by the monitor configuration API to access functionality in the display driver. Applications should not call this function.

Gets a description of a physical monitor.

## Parameters

*hMonitor* \[in\]

A handle to a physical monitor.

*dwPhysicalMonitorDescriptionSizeInChars* \[in\]

The number of characters in the *szPhysicalMonitorDescription* array.

*szPhysicalMonitorDescription* \[out\]

A pointer to an array that receives the description. The number of elements in the array should be at least **PHYSICAL\_MONITOR\_DESCRIPTION\_SIZE**.

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

