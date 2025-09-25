# GetNativeSystemInfo function

## Description

Retrieves information about the current system to an application running under [WOW64](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications). If the function is called from a 64-bit application, it is equivalent to the [GetSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) function. If the function is called from an x86 or x64 application running on a 64-bit system that does not have an Intel64 or x64 processor (such as ARM64), it will return information as if the system is x86 only if x86 emulation is supported (or x64 if x64 emulation is also supported).

## Parameters

### `lpSystemInfo` [out]

A pointer to a
[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info) structure that receives the information.

## Remarks

To determine if a Win32-based application is running under WOW64 (or if a 64-bit system does not have an Intel64 or x64 processor), call the
[IsWow64Process2](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process2) function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [Getting the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/getting-the-system-version).

## See also

[IsWow64Process](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process)

[SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)