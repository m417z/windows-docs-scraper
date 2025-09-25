# GetUnicastIpAddressEntry function

## Description

The
**GetUnicastIpAddressEntry** function retrieves information for an existing unicast IP address entry on the local computer.

## Parameters

### `Row` [in, out]

A pointer to a
[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry for a unicast IP address entry. On successful return, this structure will be updated with the properties for an existing unicast IP address.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter is not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if a **NULL** pointer is passed in the *Row* parameter, the **Address** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) pointed to by the *Row* parameter is not set to a valid unicast IPv4 or IPv6 address, or both the **InterfaceLuid** and **InterfaceIndex** members of the **MIB_UNICASTIPADDRESS_ROW** pointed to by the *Row* parameter are unspecified. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter does not match the IP address specified in the **Address** member in the **MIB_UNICASTIPADDRESS_ROW** structure. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv4 stack is on the local computer and an IPv4 address is specified in the **Address** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter. This error is also returned if no IPv6 stack is on the local computer and an IPv6 address is specified in the **Address** member. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetUnicastIpAddressEntry** function is defined on Windows Vista and later.

The **GetUnicastIpAddressEntry** function is normally used to retrieve an existing [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry to be modified. An application can then change the members in the **MIB_UNICASTIPADDRESS_ROW** entry it wishes to modify, and then call the [SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function.

On input, the **Address** member in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter must be initialized to a valid unicast IPv4 or IPv6 address. The **si_family** member of the **SOCKADDR_INET** structure in the **Address** member must be initialized to either **AF_INET** or **AF_INET6** and the related **Ipv4** or **Ipv6** member of the **SOCKADDR_INET** structure must be set to a valid unicast IP address. In addition, at least one of the following members in the **MIB_UNICASTIPADDRESS_ROW** structure pointed to the *Row* parameter must be initialized: the **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value is set for the **InterfaceLuid** member (the value of this member is set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output when the call is successful, **GetUnicastIpAddressEntry** retrieves the other properties for the unicast IP address and fills out the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by the *Row* parameter.

The [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) function can be called to enumerate the unicast IP address entries on a local computer.

#### Examples

The following example retrieves a unicast IP address entry specified on the command line and prints some values from the retrieved [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure.

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

void PrintUnicastIpAddress(PMIB_UNICASTIPADDRESS_ROW pIpRow);

int __cdecl wmain(int argc, WCHAR **argv)
{

    // Declare and initialize variables

    ULONG Result = 0;
    ULONG ifIndex;

    // default to unspecified address family
    ULONG addressFamily = AF_UNSPEC;

    IN_ADDR Ipv4Addr;
    IN6_ADDR Ipv6Addr;

    MIB_UNICASTIPADDRESS_ROW ipRow = {0};

    // Validate the parameters
    if (argc < 4) {
        wprintf(L"usage: %s <AddressFamily> <IPAddress> <InterfaceIndex>\n", argv[0]);
        wprintf(L"   Gets the UnicastIpAddressEntry for an AddressFamily,\n");
        wprintf(L"     Interface Index, and IP address\n");
        wprintf(L"   Examples\n");
        wprintf(L"     Get the IPv4 loopback at interface index=1\n");
        wprintf(L"       %s 4 127.0.0.1 1\n", argv[0]);
        wprintf(L"     Get the IPv6 loopback at interface index=1\n");
        wprintf(L"       %s 6 ::1 1\n", argv[0]);
        exit(1);
    }

    if (_wtoi(argv[1]) == 4) {
        addressFamily = AF_INET;
        if (InetPtonW(addressFamily, argv[2], &Ipv4Addr) != 1) {
            wprintf(L"Unable to parse IPv4 address string: %s\n", argv[3]);
            exit(1);
        }
    } else if (_wtoi(argv[1]) == 6) {
        addressFamily = AF_INET6;
        if (InetPton(addressFamily, argv[2], &Ipv6Addr) != 1) {
            wprintf(L"Unable to parse IPv6 address string: %s\n", argv[3]);
            exit(1);
        }
    }

    ifIndex = _wtoi(argv[3]);

    ipRow.Address.si_family = (ADDRESS_FAMILY) addressFamily;
    ipRow.InterfaceIndex = ifIndex;

    if (addressFamily == AF_INET) {
        ipRow.Address.si_family = AF_INET;
        memcpy(&ipRow.Address.Ipv4.sin_addr, &Ipv4Addr, sizeof (IN_ADDR));
    }
    if (addressFamily == AF_INET6) {
        ipRow.Address.si_family = AF_INET6;
        memcpy(&ipRow.Address.Ipv6.sin6_addr, &Ipv6Addr, sizeof (IN6_ADDR));
    }

    Result = GetUnicastIpAddressEntry(&ipRow);
    if (Result != NO_ERROR) {
        wprintf(L"GetUnicastIpAddressEntry returned error: %lu\n", Result);
        exit(1);
    }
    PrintUnicastIpAddress(&ipRow);

    exit(0);
}

void PrintUnicastIpAddress(PMIB_UNICASTIPADDRESS_ROW pipRow)
{

    WCHAR Ipv4String[16] = { 0 };
    WCHAR Ipv6String[46] = { 0 };

    // Print some variables from the rows in the table
    wprintf(L"AddressFamily:\t\t\t ");
    switch (pipRow->Address.si_family) {
    case AF_INET:
        wprintf(L"IPv4\n");
        if (InetNtop(AF_INET, &pipRow->Address.Ipv4.sin_addr, Ipv4String, 16) !=
            NULL)
            wprintf(L"IPv4 Address:\t\t\t %ws\n", Ipv4String);
        break;
    case AF_INET6:
        wprintf(L"IPv6\n");
        if (InetNtop(AF_INET6, &pipRow->Address.Ipv6.sin6_addr, Ipv6String, 46)
            != NULL)
            wprintf(L"IPv6 Address:\t\t\t %s\n", Ipv6String);
        break;
    default:
        wprintf(L"Other: %d\n", pipRow->Address.si_family);
        break;
    }

    wprintf(L"Interface LUID NetLuidIndex:\t %lu\n",
           pipRow->InterfaceLuid.Info.NetLuidIndex);
    wprintf(L"Interface LUID IfType:\t\t ");
    switch (pipRow->InterfaceLuid.Info.IfType) {
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
        wprintf(L"Unknown: %d\n", pipRow->InterfaceLuid.Info.IfType);
        break;
    }

    wprintf(L"Interface Index:\t\t %lu\n", pipRow->InterfaceIndex);

    wprintf(L"Prefix Origin:\t\t\t ");
    switch (pipRow->PrefixOrigin) {
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
        wprintf(L"Unknown: %d\n", pipRow->PrefixOrigin);
        break;
    }

    wprintf(L"Suffix Origin:\t\t\t ");
    switch (pipRow->SuffixOrigin) {
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
        wprintf(L"Unknown: %d\n", pipRow->SuffixOrigin);
        break;
    }

    wprintf(L"Valid Lifetime:\t\t\t 0x%x (%u)\n",
           pipRow->ValidLifetime, pipRow->ValidLifetime);

    wprintf(L"Preferred Lifetime:\t\t 0x%x (%u)\n",
           pipRow->PreferredLifetime, pipRow->PreferredLifetime);

    wprintf(L"OnLink PrefixLength:\t\t %lu\n", pipRow->OnLinkPrefixLength);

    wprintf(L"Skip As Source:\t\t\t ");
    if (pipRow->SkipAsSource)
        wprintf(L"Yes\n");
    else
        wprintf(L"No\n");

    wprintf(L"Dad State:\t\t\t ");
    switch (pipRow->DadState) {
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
        wprintf(L"Unknown: %d\n", pipRow->DadState);
        break;
    }

    wprintf(L"\n");
}

```

## See also

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteunicastipaddressentry)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry)

[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)

[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setunicastipaddressentry)