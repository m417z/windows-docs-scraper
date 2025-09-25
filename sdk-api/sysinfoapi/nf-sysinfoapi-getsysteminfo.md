# GetSystemInfo function

## Description

Retrieves information about the current system.

To retrieve accurate information for an application running on WOW64, call the
[GetNativeSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo) function.

## Parameters

### `lpSystemInfo` [out]

A pointer to a
[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info) structure that receives the information.

## See also

[GetNativeSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)