## Description

Retrieves a NetBIOS or DNS name associated with the local computer. The names are established at system startup, when the system reads them from the registry.

## Parameters

### `NameType` [in]

The type of name to be retrieved. This parameter is a value from the
[COMPUTER_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ne-sysinfoapi-computer_name_format) enumeration type. The following table provides additional information.

| Value | Meaning |
| --- | --- |
| **ComputerNameDnsDomain** | The name of the DNS domain assigned to the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the DNS domain name of the cluster virtual server. |
| **ComputerNameDnsFullyQualified** | The fully qualified DNS name that uniquely identifies the local computer. This name is a combination of the DNS host name and the DNS domain name, using the form *HostName*.*DomainName*. If the local computer is a node in a cluster, *lpBuffer* receives the fully qualified DNS name of the cluster virtual server. |
| **ComputerNameDnsHostname** | The DNS host name of the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the DNS host name of the cluster virtual server. |
| **ComputerNameNetBIOS** | The NetBIOS name of the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the NetBIOS name of the cluster virtual server. |
| **ComputerNamePhysicalDnsDomain** | The name of the DNS domain assigned to the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the DNS domain name of the local computer, not the name of the cluster virtual server. |
| **ComputerNamePhysicalDnsFullyQualified** | The fully qualified DNS name that uniquely identifies the computer. If the local computer is a node in a cluster, *lpBuffer* receives the fully qualified DNS name of the local computer, not the name of the cluster virtual server. <br><br>The fully qualified DNS name is a combination of the DNS host name and the DNS domain name, using the form *HostName*.*DomainName*. |
| **ComputerNamePhysicalDnsHostname** | The DNS host name of the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the DNS host name of the local computer, not the name of the cluster virtual server. |
| **ComputerNamePhysicalNetBIOS** | The NetBIOS name of the local computer. If the local computer is a node in a cluster, *lpBuffer* receives the NetBIOS name of the local computer, not the name of the cluster virtual server. |

### `lpBuffer` [out]

A pointer to a buffer that receives the computer name or the cluster virtual server name.

The length of the name may be greater than MAX_COMPUTERNAME_LENGTH characters because DNS allows longer names. To ensure that this buffer is large enough, set this parameter to **NULL** and use the required buffer size returned in the *lpnSize* parameter.

### `nSize` [in, out]

On input, specifies the size of the buffer, in **TCHARs**. On output, receives the number of **TCHARs** copied to the destination buffer, not including the terminating **null** character.

If the buffer is too small, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_MORE_DATA. This parameter receives the size of the buffer required, including the terminating **null** character.

If *lpBuffer* is **NULL**, this parameter must be zero.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The *lpBuffer* buffer is too small. The *lpnSize* parameter contains the number of bytes required to receive the name. |

## Remarks

If group policy is not set for the local machine, the
**GetComputerNameEx** function retrieves the NetBIOS or DNS names established at system startup. If group policy is set, the function returns the primary domain name set by group policy. Name changes made by the
[SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea) or
[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) functions do not take effect until the user restarts the computer.

If the local computer is not configured to use DNS names, **GetComputerNameEx** will not return DNS information. To configure the computer to do this, follow the steps outlined in the operating system help and change the primary DNS suffix of the computer, then restart the computer.

The behavior of this function can be affected if the local computer is a node in a cluster. For more information, see [ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname) and [UseNetworkName](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/generic-applications-usenetworkname).

If you are working with environments that use different DNS layouts, where the computer's FQDN does not match the FQDN of its domain, use [LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) instead.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

```cpp
#define _WIN32_WINNT 0x0500

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(void)
{
    TCHAR buffer[256] = TEXT("");
    TCHAR szDescription[8][32] = {TEXT("NetBIOS"),
        TEXT("DNS hostname"),
        TEXT("DNS domain"),
        TEXT("DNS fully-qualified"),
        TEXT("Physical NetBIOS"),
        TEXT("Physical DNS hostname"),
        TEXT("Physical DNS domain"),
        TEXT("Physical DNS fully-qualified")};
    int cnf = 0;
    DWORD dwSize = _countof(buffer);

    for (cnf = 0; cnf < ComputerNameMax; cnf++)
    {
        if (!GetComputerNameEx((COMPUTER_NAME_FORMAT)cnf, buffer, &dwSize))
        {
            _tprintf(TEXT("GetComputerNameEx failed (%d)\n"), GetLastError());
            return;
        }
        else _tprintf(TEXT("%s: %s\n"), szDescription[cnf], buffer);

        dwSize = _countof(buffer);
        ZeroMemory(buffer, dwSize);
    }
}

```

> [!NOTE]
> The sysinfoapi.h header defines GetComputerNameEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[COMPUTER_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ne-sysinfoapi-computer_name_format)

[Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names)

[GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea)

[ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname)

[ResUtilSetResourceServiceEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceserviceenvironment)

[ResUtilSetResourceServiceStartParameters](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceservicestartparameters)

[SetComputerName](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernamea)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)