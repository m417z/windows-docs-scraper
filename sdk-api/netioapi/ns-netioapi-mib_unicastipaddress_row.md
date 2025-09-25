# MIB_UNICASTIPADDRESS_ROW structure

## Description

The
**MIB_UNICASTIPADDRESS_ROW** structure stores information about a unicast IP address.

## Members

### `Address`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The unicast IP address. This member can be an IPv6 address or an IPv4 address.

### `InterfaceLuid`

Type: **NET_LUID**

The locally unique identifier (LUID) for the network interface associated with this IP address.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The local index value for the network interface associated with this IP address. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `PrefixOrigin`

Type: **NL_PREFIX_ORIGIN**

The origin of the prefix or network part of IP the address. This member can be one of the values from the **NL_PREFIX_ORIGIN** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **IpPrefixOriginOther**<br><br>0 | The IP address prefix was configured using a source other than those defined in this enumeration. This value is applicable to an IPv6 or IPv4 address. |
| **IpPrefixOriginManual**<br><br>1 | The IP address prefix was configured manually. This value is applicable to an IPv6 or IPv4 address. |
| **IpPrefixOriginWellKnown**<br><br>2 | The IP address prefix was configured using a well-known address. This value is applicable to an IPv6 link-local address or an IPv6 loopback address. |
| **IpPrefixOriginDhcp**<br><br>3 | The IP address prefix was configured using DHCP. This value is applicable to an IPv4 address configured using DHCP or an IPv6 address configured using DHCPv6. |
| **IpPrefixOriginRouterAdvertisement**<br><br>4 | The IP address prefix was configured using router advertisement. This value is applicable to an anonymous IPv6 address that was generated after receiving a router advertisement. |
| **IpPrefixOriginUnchanged**<br><br>16 | The IP address prefix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP prefix origin should be unchanged. |

### `SuffixOrigin`

Type: **NL_SUFFIX_ORIGIN**

The origin of the suffix or host part of IP the address. This member can be one of the values from the **NL_SUFFIX_ORIGIN** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **IpSuffixOriginOther**<br><br>0 | The IP address suffix was configured using a source other than those defined in this enumeration. This value is applicable to an IPv6 or IPv4 address. |
| **IpSuffixOriginManual**<br><br>1 | The IP address suffix was configured manually. This value is applicable to an IPv6 or IPv4 address. |
| **IpSuffixOriginWellKnown**<br><br>2 | The IP address suffix was configured using a well-known address. This value is applicable to an IPv6 link-local address or an IPv6 loopback address. |
| **IpSuffixOriginDhcp**<br><br>3 | The IP address suffix was configured using DHCP. This value is applicable to an IPv4 address configured using DHCP or an IPv6 address configured using DHCPv6. |
| **IpSuffixOriginLinkLayerAddress**<br><br>4 | The IP address suffix was the link local address. This value is applicable to an IPv6 link-local address or an IPv6 address where the network part was generated based on a router advertisement and the host part was based on the MAC hardware address. |
| **IpSuffixOriginRandom**<br><br>5 | The IP address suffix was generated randomly. This value is applicable to an anonymous IPv6 address where the host part of the address was generated randomly from the MAC hardware address after receiving a router advertisement. |
| **IpSuffixOriginUnchanged**<br><br>16 | The IP address suffix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP suffix origin should be unchanged. |

### `ValidLifetime`

Type: **ULONG**

The maximum time, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

### `PreferredLifetime`

Type: **ULONG**

The preferred time, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

### `OnLinkPrefixLength`

Type: **UINT8**

The length, in bits, of the prefix or network part of the IP address. For a unicast IPv4 address, any value greater than 32 is an illegal value. For a unicast IPv6 address, any value greater than 128 is an illegal value. A value of 255 is commonly used to represent an illegal value.

### `SkipAsSource`

Type: **BOOLEAN**

This member specifies if the address can be used as an IP source address.

### `DadState`

Type: **NL_DAD_STATE**

The duplicate Address detection (DAD) state. Duplicate address detection is applicable to both IPv6 and IPv4 addresses. This member can be one of the values from the **NL_DAD_STATE** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **IpDadStateInvalid**<br><br>0 | The DAD state is invalid. |
| **IpDadStateTentative**<br><br>1 | The DAD state is tentative. |
| **IpDadStateDuplicate**<br><br>2 | A duplicate IP address has been detected. |
| **IpDadStateDeprecated**<br><br>3 | The IP address has been deprecated. |
| **IpDadStatePreferred**<br><br>4 | The IP address is the preferred address. |

### `ScopeId`

Type: **SCOPE_ID**

The scope ID of the IP address. This member is applicable only to an IPv6 address. This member cannot be set. It is automatically determined by the interface on which the address was added.

### `CreationTimeStamp`

Type: **LARGE_INTEGER**

The time stamp when the IP address was created.

## Remarks

The **MIB_UNICASTIPADDRESS_ROW** structure is defined on Windows Vista and later.

The **SkipAsSource** member of the **MIB_UNICASTIPADDRESS_ROW** structure affects the operation of the [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo), [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow), and [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) functions in Windows sockets. If the *pNodeName* parameter passed to the **getaddrinfo** or **GetAddrInfoW** functions or the *pName* parameter passed to the **GetAddrInfoEx** function points to a computer name, all permanent addresses for the computer that can be used as a source address are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to false in the **MIB_UNICASTIPADDRESS_ROW** structure.

If the *pNodeName* or *pName* parameter refers to a cluster virtual server name, only virtual server addresses are returned. On Windows Vista and later, these addresses would include all unicast IP addresses returned by the [GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable) or [GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry) functions in which the **SkipAsSource** member is set to true in the **MIB_UNICASTIPADDRESS_ROW** structure. See [Windows Clustering](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/windows-clustering) for more information about clustering.

Windows 7 with Service Pack 1 (SP1) and Windows Server 2008 R2 with Service Pack 1 (SP1) add support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes the behavior such that if the **SkipAsSource** member in the **MIB_UNICASTIPADDRESS_ROW** structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

A hotfix is available for Windows 7 and Windows Server 2008 R2 that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes the behavior such that if the **SkipAsSource** member in the **MIB_UNICASTIPADDRESS_ROW** structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS. For more information, see Knowledge Base (KB) [2386184](https://support.microsoft.com/kb/2386184).

A similar hotfix is also available for Windows Vista with Service Pack 2 (SP2) and Windows Server 2008 with Service Pack 2 (SP2) that adds support to Netsh.exe for setting the SkipAsSource attribute on an IP address. This hotfix also changes behavior such that if the **SkipAsSource** member in the **MIB_UNICASTIPADDRESS_ROW** structure is set to false, the IP address will be registered in DNS. If the **SkipAsSource** member is set to true, the IP address is not registered in DNS.

#### Examples

The following example retrieves a unicast IP address table and prints some values from each of the retrieved **MIB_UNICASTIPADDRESS_ROW** structures.

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

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)

[InitializeUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-initializeunicastipaddressentry)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)

[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setunicastipaddressentry)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)