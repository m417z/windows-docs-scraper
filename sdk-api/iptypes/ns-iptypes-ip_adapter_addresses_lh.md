# IP_ADAPTER_ADDRESSES_LH structure

## Description

The **IP_ADAPTER_ADDRESSES** structure is the
*header node* for a linked list of addresses for a particular adapter. This structure can simultaneously
be used as part of a linked list of
**IP_ADAPTER_ADDRESSES** structures.

## Members

### `Alignment`

Type: **ULONGLONG**

Reserved. Used by the compiler to align the structure.

### `Length`

Type: **ULONG**

The length, in bytes, of this structure. Note that the length of the
**IP_ADAPTER_ADDRESSES** structure changed on
Windows XP with SP1 and later and also on Windows Vista and later.

### `IfIndex`

Type: **DWORD**

The index of the IPv4 interface with which these addresses are associated. On Windows Server 2003 and Windows XP, this member is zero if IPv4 is
not available on the interface.

### `Next`

Type: **struct _IP_ADAPTER_ADDRESSES***

A pointer to the next adapter addresses structure in the list.

### `AdapterName`

Type: **PCHAR**

An array of characters that contains the name of the adapter with which these addresses are associated.
Unlike an adapter's friendly name, the adapter name specified in **AdapterName** is
permanent and cannot be modified by the user.

### `FirstUnicastAddress`

Type: **PIP_ADAPTER_UNICAST_ADDRESS**

A pointer to the first
[IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure in a
linked list of IP unicast addresses for the adapter.

### `FirstAnycastAddress`

Type: **PIP_ADAPTER_ANYCAST_ADDRESS**

A pointer to the first
[IP_ADAPTER_ANYCAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_anycast_address_xp) structure in a
linked list of IP anycast addresses for the adapter.

### `FirstMulticastAddress`

Type: **PIP_ADAPTER_MULTICAST_ADDRESS**

A pointer to the first
[IP_ADAPTER_MULTICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_multicast_address_xp) structure
in a list of IP multicast addresses for the adapter.

### `FirstDnsServerAddress`

Type: **PIP_ADAPTER_DNS_SERVER_ADDRESS**

A pointer to the first
[IP_ADAPTER_DNS_SERVER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_dns_server_address_xp) structure
in a linked list of DNS server addresses for the adapter.

### `DnsSuffix`

Type: **PWCHAR**

The Domain Name System (DNS) suffix associated with this adapter.

### `Description`

Type: **PWCHAR**

A description for the adapter. This member is read-only.

### `FriendlyName`

Type: **PWCHAR**

A user-friendly name for the adapter. For example: "Local Area Connection 1." This name appears in contexts
such as the **ipconfig** command line program and the Connection folder. This member is read
only and can't be modified using any IP Helper functions.

This member is the ifAlias field used by NDIS as described in
[RFC 2863](https://www.ietf.org/rfc/rfc2863.txt). The ifAlias field can be set by an
NDIS interface provider when the NDIS driver is installed. For NDIS miniport drivers, this field is set by
NDIS.

### `PhysicalAddress`

Type: **BYTE[MAX_ADAPTER_ADDRESS_LENGTH]**

The Media Access Control (MAC) address for the adapter. For example, on an Ethernet network this member
would specify the Ethernet hardware address.

### `PhysicalAddressLength`

Type: **DWORD**

The length, in bytes, of the address specified in the **PhysicalAddress** member.
For interfaces that do not have a data-link layer, this value is zero.

### `Flags`

Type: **DWORD**

A set of flags specifying various settings for the adapter. These values are defined in the
*Iptypes.h* header file. Combinations of these flag bits are possible.

| Flag | Meaning |
| --- | --- |
| **IP_ADAPTER_DDNS_ENABLED**<br><br>0x0001 | Dynamic DNS is enabled on this adapter. |
| **IP_ADAPTER_REGISTER_ADAPTER_SUFFIX**<br><br>0x0002 | Register the DNS suffix for this adapter. |
| **IP_ADAPTER_DHCP_ENABLED**<br><br>0x0004 | The Dynamic Host Configuration Protocol (DHCP) is enabled on this adapter. |
| **IP_ADAPTER_RECEIVE_ONLY**<br><br>0x0008 | The adapter is a receive-only adapter. |
| **IP_ADAPTER_NO_MULTICAST**<br><br>0x0010 | The adapter is not a multicast recipient. |
| **IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG**<br><br>0x0020 | The adapter contains other IPv6-specific stateful configuration information. |
| **IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED**<br><br>0x0040 | The adapter is enabled for NetBIOS over TCP/IP.<br><br>**Note** This flag is only supported on Windows Vista and later when the application has been compiled for a target platform with an NTDDI version equal or greater than **NTDDI_LONGHORN**. This flag is defined in the **IP_ADAPTER_ADDRESSES_LH** structure as the **NetbiosOverTcpipEnabled** bitfield. |
| **IP_ADAPTER_IPV4_ENABLED**<br><br>0x0080 | The adapter is enabled for IPv4.<br><br>**Note** This flag is only supported on Windows Vista and later when the application has been compiled for a target platform with an NTDDI version equal or greater than **NTDDI_LONGHORN**. This flag is defined in the **IP_ADAPTER_ADDRESSES_LH** structure as the **Ipv4Enabled** bitfield. |
| **IP_ADAPTER_IPV6_ENABLED**<br><br>0x0100 | The adapter is enabled for IPv6.<br><br>**Note** This flag is only supported on Windows Vista and later when the application has been compiled for a target platform with an NTDDI version equal or greater than **NTDDI_LONGHORN**. This flag is defined in the **IP_ADAPTER_ADDRESSES_LH** structure as the **Ipv6Enabled** bitfield. |
| **IP_ADAPTER_IPV6_MANAGE_ADDRESS_CONFIG**<br><br>0x0200 | The adapter is enabled for IPv6 managed address configuration.<br><br>**Note** This flag is only supported on Windows Vista and later when the application has been compiled for a target platform with an NTDDI version equal or greater than **NTDDI_LONGHORN**. This flag is defined in the **IP_ADAPTER_ADDRESSES_LH** structure as the **Ipv6ManagedAddressConfigurationSupported** bitfield. |

### `DdnsEnabled`

### `RegisterAdapterSuffix`

### `Dhcpv4Enabled`

### `ReceiveOnly`

### `NoMulticast`

### `Ipv6OtherStatefulConfig`

### `NetbiosOverTcpipEnabled`

### `Ipv4Enabled`

### `Ipv6Enabled`

### `Ipv6ManagedAddressConfigurationSupported`

### `Mtu`

Type: **DWORD**

The maximum transmission unit (MTU) size, in bytes.

### `IfType`

Type: **DWORD**

The interface type as defined by the Internet Assigned Names Authority (IANA). Possible values for the
interface type are listed in the *Ipifcons.h* header file.

The table below lists common values for the interface type although many other values are possible.

| Value | Meaning |
| --- | --- |
| **IF_TYPE_OTHER**<br><br>1 | Some other type of network interface. |
| **IF_TYPE_ETHERNET_CSMACD**<br><br>6 | An Ethernet network interface. |
| **IF_TYPE_ISO88025_TOKENRING**<br><br>9 | A token ring network interface. |
| **IF_TYPE_PPP**<br><br>23 | A PPP network interface. |
| **IF_TYPE_SOFTWARE_LOOPBACK**<br><br>24 | A software loopback network interface. |
| **IF_TYPE_ATM**<br><br>37 | An ATM network interface. |
| **IF_TYPE_IEEE80211**<br><br>71 | An IEEE 802.11 wireless network interface. <br><br>On Windows Vista and later, wireless network cards are reported as **IF_TYPE_IEEE80211**. On earlier versions of Windows, wireless network cards are reported as **IF_TYPE_ETHERNET_CSMACD**. <br><br>On Windows XP with SP3 and on Windows XP with SP2 x86 with the Wireless LAN API for Windows XP with SP2 installed, the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function can be used to enumerate wireless interfaces on the local computer. |
| **IF_TYPE_TUNNEL**<br><br>131 | A tunnel type encapsulation network interface. |
| **IF_TYPE_IEEE1394**<br><br>144 | An IEEE 1394 (Firewire) high performance serial bus network interface. |

### `OperStatus`

Type: **IF_OPER_STATUS**

The operational status for the interface as defined in RFC 2863. For more information, see
[http://www.ietf.org/rfc/rfc2863.txt](https://www.ietf.org/rfc/rfc2863.txt). This
member can be one of the values from the **IF_OPER_STATUS** enumeration type defined in
the *Iftypes.h* header file. On Windows Vista and later, the header files
were reorganized and this enumeration is defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **IfOperStatusUp**<br><br>1 | The interface is up and able to pass packets. |
| **IfOperStatusDown**<br><br>2 | The interface is down and not in a condition to pass packets. The **IfOperStatusDown** state has two meanings, depending on the value of **AdminStatus** member. If **AdminStatus** is not set to **NET_IF_ADMIN_STATUS_DOWN** and **ifOperStatus** is set to **IfOperStatusDown** then a fault condition is presumed to exist on the interface. If **AdminStatus** is set to **IfOperStatusDown**, then **ifOperStatus** will normally also be set to **IfOperStatusDown** or **IfOperStatusNotPresent** and there is not necessarily a fault condition on the interface. |
| **IfOperStatusTesting**<br><br>3 | The interface is in testing mode. |
| **IfOperStatusUnknown**<br><br>4 | The operational status of the interface is unknown. |
| **IfOperStatusDormant**<br><br>5 | The interface is not actually in a condition to pass packets (it is not up), but is in a pending state, waiting for some external event. For on-demand interfaces, this new state identifies the situation where the interface is waiting for events to place it in the **IfOperStatusUp** state. |
| **IfOperStatusNotPresent**<br><br>6 | A refinement on the **IfOperStatusDown** state which indicates that the relevant interface is down specifically because some component (typically, a hardware component) is not present in the managed system. |
| **IfOperStatusLowerLayerDown**<br><br>7 | A refinement on the **IfOperStatusDown** state. This new state indicates that this interface runs on top of one or more other interfaces and that this interface is down specifically because one or more of these lower-layer interfaces are down. |

### `Ipv6IfIndex`

Type: **DWORD**

The interface index for the IPv6 IP address. This member is zero if IPv6 is not available on the interface.

**Note** This structure member is only available on Windows XP with SP1 and later.

### `ZoneIndices`

Type: **DWORD[16]**

An array of scope IDs for each scope level used for composing
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structures. The
[SCOPE_LEVEL](https://learn.microsoft.com/windows/desktop/api/ws2def/ne-ws2def-scope_level) enumeration is used to index the array. On
IPv6, a single interface may be assigned multiple IPv6 multicast addresses based on a scope ID.

**Note** This structure member is only available on Windows XP with SP1 and later.

### `FirstPrefix`

Type: **PIP_ADAPTER_PREFIX**

A pointer to the first [IP_ADAPTER_PREFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_prefix_xp)
structure in a linked list of IP adapter prefixes for the adapter.

**Note** This structure member is only available on Windows XP with SP1 and later.

### `TransmitLinkSpeed`

Type: **ULONG64**

The current speed in bits per second of the transmit link for the adapter.

**Note** This structure member is only available on Windows Vista and later.

### `ReceiveLinkSpeed`

Type: **ULONG64**

The current speed in bits per second of the receive link for the adapter.

**Note** This structure member is only available on Windows Vista and later.

### `FirstWinsServerAddress`

Type: **PIP_ADAPTER_WINS_SERVER_ADDRESS_LH**

A pointer to the first
[IP_ADAPTER_WINS_SERVER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_wins_server_address_lh) structure in a linked list of Windows Internet Name Service (WINS) server
addresses for the adapter.

**Note** This structure member is only available on Windows Vista and later.

### `FirstGatewayAddress`

Type: **PIP_ADAPTER_GATEWAY_ADDRESS_LH**

A pointer to the first [IP_ADAPTER_GATEWAY_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_gateway_address_lh) structure in a linked
list of gateways for the adapter.

**Note** This structure member is only available on Windows Vista and later.

### `Ipv4Metric`

Type: **ULONG**

The IPv4 interface metric for the adapter address. This member is only applicable to an IPv4 adapter
address.

The actual route metric used to compute the route preferences for IPv4 is the summation of the route metric
offset specified in the **Metric** member of the
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure and the interface
metric specified in this member for IPv4.

**Note** This structure member is only available on Windows Vista and later.

### `Ipv6Metric`

Type: **ULONG**

The IPv6 interface metric for the adapter address. This member is only applicable to an IPv6 adapter
address.

The actual route metric used to compute the route preferences for IPv6 is the summation of the route metric
offset specified in the **Metric** member of the
[MIB_IPFORWARD_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_row2) structure and the interface
metric specified in this member for IPv4.

**Note** This structure member is only available on Windows Vista and later.

### `Luid`

Type: **IF_LUID**

The interface LUID for the adapter address.

**Note** This structure member is only available on Windows Vista and later.

### `Dhcpv4Server`

Type: **[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)**

The IPv4 address of the DHCP server for the adapter address. This member is only applicable to an IPv4
adapter address configured using DHCP.

**Note** This structure member is only available on Windows Vista and later.

### `CompartmentId`

Type: **NET_IF_COMPARTMENT_ID**

The routing compartment ID for the adapter address.

**Note** This structure member is only available on Windows Vista and later. This member is not
currently supported and is reserved for future use.

### `NetworkGuid`

Type: **NET_IF_NETWORK_GUID**

The **GUID** that is associated with the network that the interface belongs to.

If
the interface provider cannot provide the network GUID, this member can be a zero **GUID**.
In this case, the interface was registered by NDIS in the default network.

**Note** This structure member is only available on Windows Vista and later.

### `ConnectionType`

Type: **NET_IF_CONNECTION_TYPE**

The interface connection type for the adapter address.

This member can be one of the values from the **NET_IF_CONNECTION_TYPE** enumeration
type defined in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **NET_IF_CONNECTION_DEDICATED**<br><br>1 | The connection type is dedicated. The connection comes up automatically when media sense is **TRUE**. For example, an Ethernet connection is dedicated. |
| **NET_IF_CONNECTION_PASSIVE**<br><br>2 | The connection type is passive. The remote end must bring up the connection to the local station. For example, a RAS interface is passive. |
| **NET_IF_CONNECTION_DEMAND**<br><br>3 | The connection type is demand-dial. A connection of this type comes up in response to a local action (sending a packet, for example). |
| **NET_IF_CONNECTION_MAXIMUM**<br><br>4 | The maximum possible value for the **NET_IF_CONNECTION_TYPE** enumeration type. This is not a legal value for **ConnectionType** member. |

**Note** This structure member is only available on Windows Vista and later.

### `TunnelType`

Type: **TUNNEL_TYPE**

The encapsulation method used by a tunnel if the adapter address is a tunnel.

**Note** This structure member is only available on Windows Vista and later.

The tunnel type is defined by the Internet Assigned Names Authority (IANA). For more information, see
[http://www.iana.org/assignments/ianaiftype-mib](https://www.iana.org/assignments/ianaiftype-mib).
This member can be one of the values from the **TUNNEL_TYPE** enumeration type defined
in the *Ifdef.h* header file.

| Value | Meaning |
| --- | --- |
| **TUNNEL_TYPE_NONE**<br><br>0 | Not a tunnel. |
| **TUNNEL_TYPE_OTHER**<br><br>1 | None of the following tunnel types. |
| **TUNNEL_TYPE_DIRECT**<br><br>2 | A packet is encapsulated directly within a normal IP header, with no intermediate header, and unicast to the remote tunnel endpoint. |
| **TUNNEL_TYPE_6TO4**<br><br>11 | An IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate header, and unicast to the destination determined by the 6to4 protocol. |
| **TUNNEL_TYPE_ISATAP**<br><br>13 | An IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate header, and unicast to the destination determined by the ISATAP protocol. |
| **TUNNEL_TYPE_TEREDO**<br><br>14 | Teredo encapsulation for IPv6 packets. |
| **TUNNEL_TYPE_IPHTTPS**<br><br>15 | IP over HTTPS encapsulation for IPv6 packets.<br><br>**Note** This enumeration value is only available on Windows 7, Windows Server 2008 R2, and later. |

### `Dhcpv6Server`

Type: **[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)**

The IPv6 address of the DHCPv6 server for the adapter address. This member is only applicable to an IPv6
adapter address configured using DHCPv6. This structure member is not currently supported and is reserved for future use.

**Note** This structure member is only available on Windows Vista and later.

### `Dhcpv6ClientDuid`

Type: **BYTE[MAX_DHCPV6_DUID_LENGTH]**

The DHCP unique identifier (DUID) for the DHCPv6 client. This member is only applicable to an IPv6 adapter
address configured using DHCPv6.

**Note** This structure member is only available on Windows Vista and later.

### `Dhcpv6ClientDuidLength`

Type: **ULONG**

The length, in bytes, of the DHCP unique identifier (DUID) for the DHCPv6 client. This member is only
applicable to an IPv6 adapter address configured using DHCPv6.

**Note** This structure member is only available on Windows Vista and later.

### `Dhcpv6Iaid`

Type: **ULONG**

The identifier for an identity association chosen by the DHCPv6 client. This member is only applicable to
an IPv6 adapter address configured using DHCPv6.

**Note** This structure member is only available on Windows Vista and later.

### `FirstDnsSuffix`

Type: **PIP_ADAPTER_DNS_SUFFIX**

A pointer to the first [IP_ADAPTER_DNS_SUFFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_dns_suffix) structure in a linked list of
DNS suffixes for the adapter.

**Note** This structure member is only available on Windows Vista with SP1and later and on Windows Server 2008 and later.

## Remarks

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function retrieves
information for IPv4 and IPv6 addresses and returns this information as a linked list of
**IP_ADAPTER_ADDRESSES** structures

The adapter index values specified in the **IfIndex** and **Ipv6IfIndex** members may change when an adapter is
disabled and then enabled, or under other circumstances, and should not be considered persistent.

The values for the **IfType** member are defined in the
*Ipifcons.h* header file. Only the possible values listed in the description of the
**IfType** member are currently supported.

The size of the **IP_ADAPTER_ADDRESSES** structure
changed on Windows XP with SP1 and later. The size of the
**IP_ADAPTER_ADDRESSES** structure also changed on
Windows Vista and later. The size of the
**IP_ADAPTER_ADDRESSES** structure also changed on
Windows Vista with SP1and later and onWindows Server 2008 and later. The **Length** member should be used to determine
which version of the **IP_ADAPTER_ADDRESSES**
structure is being used.

The version of the **IP_ADAPTER_ADDRESSES**
structure on Windows XP with SP1 and later has the following new members added:
**Ipv6IfIndex**, **ZoneIndices**, and
**FirstPrefix**.

The version of the **IP_ADAPTER_ADDRESSES**
structure on Windows Vista and later has the following new members added:
**TransmitLinkSpeed**, **ReceiveLinkSpeed**,
**FirstWinsServerAddress**, **FirstGatewayAddress**,
**Ipv4Metric**, **Ipv6Metric**, **Luid**,
**Dhcpv4Server**, **CompartmentId**,
**NetworkGuid**, **ConnectionType**,
**TunnelType**, **Dhcpv6Server**,
**Dhcpv6ClientDuid**, **Dhcpv6ClientDuidLength**, and
**Dhcpv6Iaid**.

The version of the **IP_ADAPTER_ADDRESSES**
structure on Windows Vista with SP1and later and on Windows Server 2008 and later has the following new member added:
**FirstDnsSuffix**.

The **Ipv4Metric** and **Ipv6Metric** members are used to
prioritize route metrics for routes connected to multiple interfaces on the local computer.

The order of linked [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structures pointed to by the **FirstUnicastAddress**
member that are returned by the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function does not reflect the order that IP addresses were added to an adapter and may vary between versions of Windows. Similarly, the order of linked **IP_ADAPTER_ANYCAST_ADDRESS** structures pointed to by the **FirstAnycastAddress**
member and the order of linked **IP_ADAPTER_MULTICAST_ADDRESS** structures pointed to by the **FirstMulticastAddress**
member do not reflect the order that IP addresses were added to an adapter and may vary between versions of Windows.

 In addition, the linked [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structures pointed to by the **FirstUnicastAddress**
member and the linked [IP_ADAPTER_PREFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_prefix_xp) structures pointed to by the **FirstPrefix**
member are maintained as separate internal linked lists by the operating system. As a result, the order of linked **IP_ADAPTER_UNICAST_ADDRESS** structures pointed to by the **FirstUnicastAddress**
member does not have any relationship with the order of linked **IP_ADAPTER_PREFIX** structures pointed to by the **FirstPrefix**
member.

On Windows Vista and later, the linked [IP_ADAPTER_PREFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_prefix_xp) structures pointed to by the **FirstPrefix**
member include three IP adapter prefixes for each IP address assigned to the adapter. These include the host IP address prefix, the subnet IP address prefix, and the subnet broadcast IP address prefix. In addition, for each adapter there is a multicast address prefix and a broadcast address prefix.

On Windows XP with SP1 and later prior to Windows Vista, the linked [IP_ADAPTER_PREFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_prefix_xp) structures pointed to by the **FirstPrefix**
member include only a single IP adapter prefix for each IP address assigned to the adapter.

In the Windows SDK, the version of the structure for use on Windows Vista and later is defined as
**IP_ADAPTER_ADDRESSES_LH**. In the
Microsoft Windows Software Development Kit (SDK), the version of this structure to be used on earlier systems including
Windows XP with SP1 and later is defined as
**IP_ADAPTER_ADDRESSES_XP**. When compiling an
application if the target platform is Windows Vista and later
(`NTDDI_VERSION >= NTDDI_LONGHORN`,
`_WIN32_WINNT >= 0x0600`, or
`WINVER >= 0x0600`), the
**IP_ADAPTER_ADDRESSES_LH** structure is typedefed to
the **IP_ADAPTER_ADDRESSES** structure. When compiling an application if the target
platform is not Windows Vista and later, the
**IP_ADAPTER_ADDRESSES_XP** structure is typedefed to
the **IP_ADAPTER_ADDRESSES** structure.

The [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure is used in the
**IP_ADAPTER_ADDRESSES** structure. On the
Windows SDK released for Windows Vista and later, the organization of header files has
changed and the **SOCKET_ADDRESS** structure is defined
in the *Ws2def.h* header file which is automatically included by the
*Winsock2.h* header file. On the Platform Software Development Kit (SDK) released for
Windows Server 2003 and Windows XP, the
**SOCKET_ADDRESS** structure is declared in the
*Winsock2.h* header file. In order to use the
**IP_ADAPTER_ADDRESSES** structure, the
*Winsock2.h* header file must be included before the
*Iphlpapi.h* header file.

#### Examples

This example retrieves the **IP_ADAPTER_ADDRESSES** structure for the adapters associated with the system and prints some members for each adapter interface.

```cpp
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main(int argc, char **argv)
{

    /* Declare and initialize variables */

    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    unsigned int i = 0;

    // Set the flags to pass to GetAdaptersAddresses
    ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

    // default to unspecified address family (both)
    ULONG family = AF_UNSPEC;

    LPVOID lpMsgBuf = NULL;

    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
    ULONG outBufLen = 0;

    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
    PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
    PIP_ADAPTER_ANYCAST_ADDRESS pAnycast = NULL;
    PIP_ADAPTER_MULTICAST_ADDRESS pMulticast = NULL;
    IP_ADAPTER_DNS_SERVER_ADDRESS *pDnServer = NULL;
    IP_ADAPTER_PREFIX *pPrefix = NULL;

    if (argc != 2) {
        printf(" Usage: getadapteraddresses family\n");
        printf("        getadapteraddresses 4 (for IPv4)\n");
        printf("        getadapteraddresses 6 (for IPv6)\n");
        printf("        getadapteraddresses A (for both IPv4 and IPv6)\n");
        exit(1);
    }

    if (atoi(argv[1]) == 4)
        family = AF_INET;
    else if (atoi(argv[1]) == 6)
        family = AF_INET6;

    outBufLen = sizeof (IP_ADAPTER_ADDRESSES);
    pAddresses = (IP_ADAPTER_ADDRESSES *) MALLOC(outBufLen);

    // Make an initial call to GetAdaptersAddresses to get the
    // size needed into the outBufLen variable
    if (GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen)
        == ERROR_BUFFER_OVERFLOW) {
        FREE(pAddresses);
        pAddresses = (IP_ADAPTER_ADDRESSES *) MALLOC(outBufLen);
    }

    if (pAddresses == NULL) {
        printf("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
        exit(1);
    }
    // Make a second call to GetAdaptersAddresses to get the
    // actual data we want
    printf("Memory allocated for GetAdapterAddresses = %d bytes\n", outBufLen);
    printf("Calling GetAdaptersAddresses function with family = ");
    if (family == AF_INET)
        printf("AF_INET\n");
    if (family == AF_INET6)
        printf("AF_INET6\n");
    if (family == AF_UNSPEC)
        printf("AF_UNSPEC\n\n");

    dwRetVal =
        GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

    if (dwRetVal == NO_ERROR) {
        // If successful, output some information from the data we received
        pCurrAddresses = pAddresses;
        while (pCurrAddresses) {
            printf("\tLength of the IP_ADAPTER_ADDRESS struct: %ld\n",
                   pCurrAddresses->Length);
            printf("\tIfIndex (IPv4 interface): %u\n", pCurrAddresses->IfIndex);
            printf("\tAdapter name: %s\n", pCurrAddresses->AdapterName);

            pUnicast = pCurrAddresses->FirstUnicastAddress;
            if (pUnicast != NULL) {
                for (i = 0; pUnicast != NULL; i++)
                    pUnicast = pUnicast->Next;
                printf("\tNumber of Unicast Addresses: %d\n", i);
            } else
                printf("\tNo Unicast Addresses\n");

            pAnycast = pCurrAddresses->FirstAnycastAddress;
            if (pAnycast) {
                for (i = 0; pAnycast != NULL; i++)
                    pAnycast = pAnycast->Next;
                printf("\tNumber of Anycast Addresses: %d\n", i);
            } else
                printf("\tNo Anycast Addresses\n");

            pMulticast = pCurrAddresses->FirstMulticastAddress;
            if (pMulticast) {
                for (i = 0; pMulticast != NULL; i++)
                    pMulticast = pMulticast->Next;
                printf("\tNumber of Multicast Addresses: %d\n", i);
            } else
                printf("\tNo Multicast Addresses\n");

            pDnServer = pCurrAddresses->FirstDnsServerAddress;
            if (pDnServer) {
                for (i = 0; pDnServer != NULL; i++)
                    pDnServer = pDnServer->Next;
                printf("\tNumber of DNS Server Addresses: %d\n", i);
            } else
                printf("\tNo DNS Server Addresses\n");

            printf("\tDNS Suffix: %wS\n", pCurrAddresses->DnsSuffix);
            printf("\tDescription: %wS\n", pCurrAddresses->Description);
            printf("\tFriendly name: %wS\n", pCurrAddresses->FriendlyName);

            if (pCurrAddresses->PhysicalAddressLength != 0) {
                printf("\tPhysical address: ");
                for (i = 0; i < pCurrAddresses->PhysicalAddressLength;
                     i++) {
                    if (i == (pCurrAddresses->PhysicalAddressLength - 1))
                        printf("%.2X\n",
                               (int) pCurrAddresses->PhysicalAddress[i]);
                    else
                        printf("%.2X-",
                               (int) pCurrAddresses->PhysicalAddress[i]);
                }
            }
            printf("\tFlags: %ld\n", pCurrAddresses->Flags);
            printf("\tMtu: %lu\n", pCurrAddresses->Mtu);
            printf("\tIfType: %ld\n", pCurrAddresses->IfType);
            printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);
            printf("\tIpv6IfIndex (IPv6 interface): %u\n",
                   pCurrAddresses->Ipv6IfIndex);
            printf("\tZoneIndices (hex): ");
            for (i = 0; i < 16; i++)
                printf("%lx ", pCurrAddresses->ZoneIndices[i]);
            printf("\n");

            pPrefix = pCurrAddresses->FirstPrefix;
            if (pPrefix) {
                for (i = 0; pPrefix != NULL; i++)
                    pPrefix = pPrefix->Next;
                printf("\tNumber of IP Adapter Prefix entries: %d\n", i);
            } else
                printf("\tNo IP Adapter Prefix entries\n");

            printf("\n");

            pCurrAddresses = pCurrAddresses->Next;
        }
    } else {
        printf("Call to GetAdaptersAddresses failed with error: %d\n",
               dwRetVal);
        if (dwRetVal == ERROR_NO_DATA)
            printf("\tNo addresses were found for the requested parameters\n");
        else {

            if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),   // Default language
                              (LPTSTR) & lpMsgBuf, 0, NULL)) {
                printf("\tError: %s", lpMsgBuf);
                LocalFree(lpMsgBuf);
                FREE(pAddresses);
                exit(1);
            }
        }
    }
    FREE(pAddresses);
    return 0;
}

```

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[IF_OPER_STATUS](https://learn.microsoft.com/windows/desktop/api/ifdef/ne-ifdef-if_oper_status)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_ANYCAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_anycast_address_xp)

[IP_ADAPTER_DNS_SERVER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_dns_server_address_xp)

[IP_ADAPTER_DNS_SUFFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_dns_suffix)

[IP_ADAPTER_GATEWAY_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_gateway_address_lh)

[IP_ADAPTER_MULTICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_multicast_address_xp)

[IP_ADAPTER_PREFIX](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_prefix_xp)

[IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh)

[IP_ADAPTER_WINS_SERVER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_wins_server_address_lh)

[SCOPE_LEVEL](https://learn.microsoft.com/windows/desktop/api/ws2def/ne-ws2def-scope_level)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)