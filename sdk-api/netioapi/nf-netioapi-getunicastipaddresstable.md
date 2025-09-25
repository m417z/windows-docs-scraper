# GetUnicastIpAddressTable function

## Description

The
**GetUnicastIpAddressTable** function retrieves the unicast IP address table on the local computer.

## Parameters

### `Family` [in]

The address family to retrieve.

Possible values for the address family are listed in the *Winsock2.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and possible values for this member are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET**, **AF_INET6**, and **AF_UNSPEC**.

| Value | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. When this parameter is specified, this function returns the unicast IP address table containing both IPv4 and IPv6 entries. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function returns the unicast IP address table containing only IPv4 entries. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function returns the unicast IP address table containing only IPv6 entries. |

### `Table` [out]

A pointer to a
[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) structure that contains a table of unicast IP address entries on the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Table* parameter or the *Family* parameter was not specified as **AF_INET**, **AF_INET6**, or **AF_UNSPEC**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if no unicast IP address entries as specified in the *Family* parameter were found. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and **AF_INET** was specified in the **Family** parameter. This error is also returned if no IPv6 stack is on the local computer and **AF_INET6** was specified in the **Family** parameter. This error is also returned on versions of Windows where this function is not supported. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetUnicastIpAddressTable** function is defined on Windows Vista and later.

The
**GetUnicastIpAddressTable** function enumerates the unicast IP addresses on a local system and returns this information in an [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) structure.

The unicast IP address entries are returned in a [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) structure in the buffer pointed to by the *Table* parameter. The **MIB_UNICASTIPADDRESS_TABLE** structure contains a unicast IP address entry count and an array of [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structures for each unicast IP address entry. When these returned structures are no longer required, free the memory by calling the **FreeMibTable**.

The *Family* parameter must be initialized to either **AF_INET**, **AF_INET6**, or **AF_UNSPEC**.

Note that the returned [MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table) structure pointed to by the *Table* parameter may contain padding for alignment between the **NumEntries** member and the first [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) array entry in the **Table** member of the **MIB_UNICASTIPADDRESS_TABLE** structure. Padding for alignment may also be present between the **MIB_UNICASTIPADDRESS_ROW** array entries. Any access to a **MIB_UNICASTIPADDRESS_ROW** array entry should assume padding may exist.

#### Examples

The following example retrieves a unicast IP address table and prints some values from each of the retrieved [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structures.

```cpp

#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h.>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <ws2ipdef.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Iphlpapi.lib and Ws2_32.lib
#pragma comment (lib, "iphlpapi.lib")
#pragma comment (lib, "Ws2_32.lib")

int __cdecl wmain()
{

    // Declare and initialize variables

    unsigned int i;

    DWORD Result = 0;

    WCHAR Ipv4String[16] = { 0 };
    WCHAR Ipv6String[46] = { 0 };

    PMIB_UNICASTIPADDRESS_TABLE pipTable = NULL;

    Result = GetUnicastIpAddressTable(AF_UNSPEC, &pipTable);
    if (Result != NO_ERROR) {
        wprintf(L"GetUnicastIpAddressTable returned error: %ld\n", Result);
        exit(1);
    }
    // Print some variables from the rows in the table
    wprintf(L"Number of table entries: %d\n\n", pipTable->NumEntries);

    for (i = 0; i < pipTable->NumEntries; i++) {
        wprintf(L"AddressFamily[%d]:\t\t ", i);

        switch (pipTable->Table[i].Address.si_family) {
        case AF_INET:
            wprintf(L"IPv4\n");
            if (InetNtopW
                (AF_INET, &pipTable->Table[i].Address.Ipv4.sin_addr, Ipv4String,
                 16) != NULL)
                wprintf(L"IPv4 Address:\t\t\t %ws\n", Ipv4String);
            break;
        case AF_INET6:
            wprintf(L"IPv6\n");
            if (InetNtopW
                (AF_INET6, &pipTable->Table[i].Address.Ipv6.sin6_addr,
                 Ipv6String, 46) != NULL)
                wprintf(L"IPv6 Address:\t\t\t %ws\n", Ipv6String);
            break;
        default:
            wprintf(L"Other: %d\n", pipTable->Table[i].Address.si_family);
            break;
        }

        wprintf(L"Interface LUID NetLuidIndex[%d]:  %lu\n",
               i, pipTable->Table[i].InterfaceLuid.Info.NetLuidIndex);
        wprintf(L"Interface LUID IfType[%d]:\t ", i);
        switch (pipTable->Table[i].InterfaceLuid.Info.IfType) {
        case IF_TYPE_OTHER:
            wprintf(L"Other\n");
            break;
        case IF_TYPE_ETHERNET_CSMACD:
            wprintf(L"Ethernet\n");
            break;
        case IF_TYPE_ISO88025_TOKENRING:
            wprintf(L"Token ring\n");
            break;
        case IF_TYPE_PPP:
            wprintf(L"PPP\n");
            break;
        case IF_TYPE_SOFTWARE_LOOPBACK:
            wprintf(L"Software loopback\n");
            break;
        case IF_TYPE_ATM:
            wprintf(L"ATM\n");
            break;
        case IF_TYPE_IEEE80211:
            wprintf(L"802.11 wireless\n");
            break;
        case IF_TYPE_TUNNEL:
            wprintf(L"Tunnel encapsulation\n");
            break;
        case IF_TYPE_IEEE1394:
            wprintf(L"IEEE 1394 (Firewire)\n");
            break;
        default:
            wprintf(L"Unknown: %d\n",
                   pipTable->Table[i].InterfaceLuid.Info.IfType);
            break;
        }

        wprintf(L"Interface Index[%d]:\t\t %lu\n",
               i, pipTable->Table[i].InterfaceIndex);

        wprintf(L"Prefix Origin[%d]:\t\t ", i);
        switch (pipTable->Table[i].PrefixOrigin) {
        case IpPrefixOriginOther:
            wprintf(L"IpPrefixOriginOther\n");
            break;
        case IpPrefixOriginManual:
            wprintf(L"IpPrefixOriginManual\n");
            break;
        case IpPrefixOriginWellKnown:
            wprintf(L"IpPrefixOriginWellKnown\n");
            break;
        case IpPrefixOriginDhcp:
            wprintf(L"IpPrefixOriginDhcp\n");
            break;
        case IpPrefixOriginRouterAdvertisement:
            wprintf(L"IpPrefixOriginRouterAdvertisement\n");
            break;
        case IpPrefixOriginUnchanged:
            wprintf(L"IpPrefixOriginUnchanged\n");
            break;
        default:
            wprintf(L"Unknown: %d\n", pipTable->Table[i].PrefixOrigin);
            break;
        }

        wprintf(L"Suffix Origin[%d]:\t\t ", i);
        switch (pipTable->Table[i].SuffixOrigin) {
        case IpSuffixOriginOther:
            wprintf(L"IpSuffixOriginOther\n");
            break;
        case IpSuffixOriginManual:
            wprintf(L"IpSuffixOriginManual\n");
            break;
        case IpSuffixOriginWellKnown:
            wprintf(L"IpSuffixOriginWellKnown\n");
            break;
        case IpSuffixOriginDhcp:
            wprintf(L"IpSuffixOriginDhcp\n");
            break;
        case IpSuffixOriginLinkLayerAddress:
            wprintf(L"IpSuffixOriginLinkLayerAddress\n");
            break;
        case IpSuffixOriginRandom:
            wprintf(L"IpSuffixOriginRandom\n");
            break;
        case IpSuffixOriginUnchanged:
            wprintf(L"IpSuffixOriginUnchanged\n");
            break;
        default:
            wprintf(L"Unknown: %d\n", pipTable->Table[i].SuffixOrigin);
            break;
        }

        wprintf(L"Valid Lifetime[%d]:\t\t 0x%x (%u)\n", i,
               pipTable->Table[i].ValidLifetime,
               pipTable->Table[i].ValidLifetime);

        wprintf(L"Preferred Lifetime[%d]:\t\t 0x%x (%u)\n", i,
               pipTable->Table[i].PreferredLifetime,
               pipTable->Table[i].PreferredLifetime);

        wprintf(L"OnLink PrefixLength[%d]:\t\t %lu\n", i,
               pipTable->Table[i].OnLinkPrefixLength);

        wprintf(L"Skip As Source[%d]:\t\t ", i);
        if (pipTable->Table[i].SkipAsSource)
            wprintf(L"Yes\n");
        else
            wprintf(L"No\n");

        wprintf(L"Dad State[%d]:\t\t\t ", i);
        switch (pipTable->Table[i].DadState) {
        case IpDadStateInvalid:
            wprintf(L"IpDadStateInvalid\n");
            break;
        case IpDadStateTentative:
            wprintf(L"IpDadStateTentative\n");
            break;
        case IpDadStateDuplicate:
            wprintf(L"IpDadStateDuplicate\n");
            break;
        case IpDadStateDeprecated:
            wprintf(L"IpDadStateDeprecated\n");
            break;
        case IpDadStatePreferred:
            wprintf(L"IpDadStatePreferred\n");
            break;
        default:
            wprintf(L"Unknown: %d\n", pipTable->Table[i].DadState);
            break;
        }

        wprintf(L"\n");
    }

    if (pipTable != NULL) {
        FreeMibTable(pipTable);
        pipTable = NULL;
    }

    exit(0);
}

```

## See also

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteunicastipaddressentry)

**FreeMibTable**

[GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry)

[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)

[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setunicastipaddressentry)