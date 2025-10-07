# DDCCIGetCapabilitiesString function

> [!IMPORTANT]
> This function is used by the monitor configuration API to access functionality in the display driver. Applications should not call this function.

Gets a string that describes the capabilities of a monitor.

## Parameters

*hMonitor* \[in\]

A handle to a physical monitor.

*pszString* \[out\]

A pointer to a buffer that receives the capabilities string. To get the length of the capabilities string, call [**DDCCIGetCapabilitiesStringLength**](https://learn.microsoft.com/windows/win32/monitor/ddccigetcapabilitiesstringlength).

*dwLength* \[in\]

The size of the *pszString* buffer, in characters, including the terminating null character.

## Return value

If the method succeeds, it returns **STATUS\_SUCCESS**. Otherwise, it returns an **NTSTATUS** error code.

## Remarks

Applications should call [**CapabilitiesRequestAndCapabilitiesReply**](https://learn.microsoft.com/windows/desktop/api/LowLevelMonitorConfigurationAPI/nf-lowlevelmonitorconfigurationapi-capabilitiesrequestandcapabilitiesreply) instead of calling this function.

This function has no associated import library. To call this function, you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Gdi32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Gdi32.dll |

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/win32/monitor/monitor-configuration-functions)

