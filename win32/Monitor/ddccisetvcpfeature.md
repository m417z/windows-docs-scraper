# DDCCISetVCPFeature function

> [!IMPORTANT]
> This function is used by the monitor configuration API to access functionality in the display driver. Applications should not call this function.

Sets the value of a Virtual Control Panel (VCP) code for a monitor.

## Parameters

*hMonitor* \[in\]

A handle to a physical monitor.

*dwVCPCode* \[in\]

The VCP code to set.

*dwNewValue* \[in\]

The value of the VCP code.

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Applications should call [**SetVCPFeature**](https://learn.microsoft.com/windows/desktop/api/LowLevelMonitorConfigurationAPI/nf-lowlevelmonitorconfigurationapi-setvcpfeature) instead of calling this function.

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Gdi32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Gdi32.dll |

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/win32/monitor/monitor-configuration-functions)

