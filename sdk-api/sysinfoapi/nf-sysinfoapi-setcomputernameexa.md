# SetComputerNameExA function

## Description

Sets a new NetBIOS or DNS name for the local computer. Name changes made by
**SetComputerNameEx** do not take effect until the user restarts the computer.

## Parameters

### `NameType` [in]

The type of name to be set. This parameter can be one of the following values from the
[COMPUTER_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ne-sysinfoapi-computer_name_format) enumeration type.

| Value | Meaning |
| --- | --- |
| **ComputerNamePhysicalDnsDomain** | Sets the primary DNS suffix of the computer. |
| **ComputerNamePhysicalDnsHostname** | Sets the NetBIOS and the Computer Name (the first label of the full DNS name) to the name specified in *lpBuffer*. If the name exceeds MAX_COMPUTERNAME_LENGTH characters, the NetBIOS name is truncated to MAX_COMPUTERNAME_LENGTH characters, not including the terminating null character. |
| **ComputerNamePhysicalNetBIOS** | Sets the NetBIOS name to the name specified in *lpBuffer*. The name cannot exceed MAX_COMPUTERNAME_LENGTH characters, not including the terminating null character. <br><br>Warning: Using this option to set the NetBIOS name breaks the convention of interdependent NetBIOS and DNS names. Applications that use the [DnsHostnameToComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dnshostnametocomputernamea) function to derive the NetBIOS name from the first label of the DNS name will fail if this convention is broken. |

### `lpBuffer` [in]

The new name. The name cannot include control characters, leading or trailing spaces, or any of the following characters: " / \ [ ] : | < > + = ; , ?

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetComputerNameEx** can set the Computer Name (the first label of the full DNS name) or the primary DNS suffix of the local computer. It cannot set a fully qualified DNS name in one call.

If the local computer is a node in a cluster,
**SetComputerNameEx** sets NetBIOS or DNS name of the local computer, not that of the cluster virtual server.

The process that calls the
**SetComputerNameEx** function must have administrator privileges on the local computer.

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The sysinfoapi.h header defines SetComputerNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[COMPUTER_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ne-sysinfoapi-computer_name_format)

[Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names)

[DnsHostnameToComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dnshostnametocomputernamea)

[GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea)

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)