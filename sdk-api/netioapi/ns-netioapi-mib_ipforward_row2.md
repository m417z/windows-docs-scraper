# MIB_IPFORWARD_ROW2 structure

## Description

The
**MIB_IPFORWARD_ROW2** structure stores information about an IP route entry.

## Members

### `InterfaceLuid`

Type: **NET_LUID**

The locally unique identifier (LUID) for the network interface associated with this IP route entry.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The local index value for the network interface associated with this IP route entry. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `DestinationPrefix`

Type: **[IP_ADDRESS_PREFIX](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-ip_address_prefix)**

The IP address prefix for the destination IP address for this route.

### `NextHop`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

For a remote route, the IP address of the next system or gateway en route. If the route is to a local loopback address or an IP address on the local link, the next hop is unspecified (all zeros). For a local loopback route, this member should be an IPv4 address of 0.0.0.0 for an IPv4 route entry or an IPv6 address of 0::0 for an IPv6 route entry.

### `SitePrefixLength`

Type: **UCHAR**

The length, in bits, of the site prefix or network part of the IP address for this route. For an IPv4 route entry, any value greater than 32 is an illegal value. For an IPv6 route entry, any value greater than 128 is an illegal value.
A value of 255 is commonly used to represent an illegal value.

### `ValidLifetime`

Type: **ULONG**

The maximum time, in seconds, that the IP route entry is valid. A value of 0xffffffff is considered to be infinite.

### `PreferredLifetime`

Type: **ULONG**

The preferred time, in seconds, that the IP route entry is valid. A value of 0xffffffff is considered to be infinite.

### `Metric`

Type: **ULONG**

The route metric offset value for this IP route entry. Note the actual route metric used to compute the route preference is the summation of interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure and the route metric offset specified in this member. The semantics of this metric are determined by the routing protocol specified in the **Protocol** member. If this metric is not used, its value should be set to -1. This value is documented in RFC 4292.
For more information, see [http://www.ietf.org/rfc/rfc4292.txt](https://www.ietf.org/rfc/rfc4292.txt).

### `Protocol`

Type: **NL_ROUTE_PROTOCOL**

The routing mechanism how this IP route was added. This member can be one of the values from the **NL_ROUTE_PROTOCOL** enumeration type defined in the *Nldef.h* header file. The member is described in RFC 4292. For more information, see [http://www.ietf.org/rfc/rfc4292.txt](https://www.ietf.org/rfc/rfc4292.txt).

Note that the *Nldef.h* header is automatically included by the *Ipmib.h* header file which is automatically included by the *Iprtrmib.h* header. The *Iphlpapi.h* header automatically includes the *Iprtrmib.h* header file. The *Iprtrmib.h*, *Ipmib.h*, and *Nldef.h* header files should never be used directly.

The following list shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **MIB_IPPROTO_OTHER**<br><br>1 | The routing mechanism was not specified. |
| **MIB_IPPROTO_LOCAL**<br><br>2 | A local interface. |
| **MIB_IPPROTO_NETMGMT**<br><br>3 | A static route. This value is used to identify route information for IP routing set through network management such as the Dynamic Host Configuration Protocol (DCHP), the Simple Network Management Protocol (SNMP), or by calls to the [CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2), [DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2), or [SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2) functions. |
| **MIB_IPPROTO_ICMP**<br><br>4 | The result of an ICMP redirect. |
| **MIB_IPPROTO_EGP**<br><br>5 | The Exterior Gateway Protocol (EGP), a dynamic routing protocol. |
| **MIB_IPPROTO_GGP**<br><br>6 | The Gateway-to-Gateway Protocol (GGP), a dynamic routing protocol. |
| **MIB_IPPROTO_HELLO**<br><br>7 | The Hellospeak protocol, a dynamic routing protocol. This is a historical entry no longer in use and was an early routing protocol used by the original ARPANET routers that ran special software called the Fuzzball routing protocol, sometimes called Hellospeak, as described in RFC 891 and RFC 1305. For more information, see [http://www.ietf.org/rfc/rfc891.txt](https://www.ietf.org/rfc/rfc891.txt) and [http://www.ietf.org/rfc/rfc1305.txt](http://tools.ietf.org/html/rfc1305). |
| **MIB_IPPROTO_RIP**<br><br>8 | The Berkeley Routing Information Protocol (RIP) or RIP-II, a dynamic routing protocol. |
| **MIB_IPPROTO_IS_IS**<br><br>9 | The Intermediate System-to-Intermediate System (IS-IS) protocol, a dynamic routing protocol. The IS-IS protocol was developed for use in the Open Systems Interconnection (OSI) protocol suite. |
| **MIB_IPPROTO_ES_IS**<br><br>10 | The End System-to-Intermediate System (ES-IS) protocol, a dynamic routing protocol. The ES-IS protocol was developed for use in the Open Systems Interconnection (OSI) protocol suite. |
| **MIB_IPPROTO_CISCO**<br><br>11 | The Cisco Interior Gateway Routing Protocol (IGRP), a dynamic routing protocol. |
| **MIB_IPPROTO_BBN**<br><br>12 | The Bolt, Beranek, and Newman (BBN) Interior Gateway Protocol (IGP) that used the Shortest Path First (SPF) algorithm. This was an early dynamic routing protocol. |
| **MIB_IPPROTO_OSPF**<br><br>13 | The Open Shortest Path First (OSPF) protocol, a dynamic routing protocol. |
| **MIB_IPPROTO_BGP**<br><br>14 | The Border Gateway Protocol (BGP), a dynamic routing protocol. |
| **MIB_IPPROTO_NT_AUTOSTATIC**<br><br>10002 | A Windows specific entry added originally by a routing protocol, but which is now static. |
| **MIB_IPPROTO_NT_STATIC**<br><br>10006 | A Windows specific entry added as a static route from the routing user interface or a routing command. |
| **MIB_IPPROTO_NT_STATIC_NON_DOD**<br><br>10007 | A Windows specific entry added as a static route from the routing user interface or a routing command, except these routes do not cause Dial On Demand (DOD). |

### `Loopback`

Type: **BOOLEAN**

A value that specifies if the route is a loopback route (the gateway is on the local host).

### `AutoconfigureAddress`

Type: **BOOLEAN**

A value that specifies if the IP address is autoconfigured.

### `Publish`

Type: **BOOLEAN**

A value that specifies if the route is published.

### `Immortal`

Type: **BOOLEAN**

A value that specifies if the route is immortal.

### `Age`

Type: **ULONG**

The number of seconds since the route was
added or modified in the network routing table.

### `Origin`

Type: **NL_ROUTE_ORIGIN**

The origin of the route. This member can be one of the values from the **NL_ROUTE_ORIGIN** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **NlroManual**<br><br>0 | A result of manual configuration. |
| **NlroWellKnown**<br><br>1 | A well-known route. |
| **NlroDHCP**<br><br>2 | A result of DHCP configuration. |
| **NlroRouterAdvertisement**<br><br>3 | The result of router advertisement. |
| **Nlro6to4**<br><br>4 | A result of 6to4 tunneling. |

## Remarks

The **MIB_IPFORWARD_ROW2** structure is defined on Windows Vista and later.

The **GetIpForwardTable2** function enumerates the IP route entries on a local system and returns this information in a [MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2) structure as an array of **MIB_IPFORWARD_ROW2** entries.

The **GetIpForwardEntry2** function retrieves a single IP route entry and returns this information in a **MIB_IPFORWARD_ROW2** structure.

An entry with the **Prefix** and the **PrefixLength** members of the [IP_ADDRESS_PREFIX](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-ip_address_prefix) set to zero in the **DestinationPrefix** member in the
**MIB_IPFORWARD_ROW2** structure is considered a
default route. The [MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2) may contain multiple **MIB_IPFORWARD_ROW2** entries with the **Prefix** and the **PrefixLength** members of the **IP_ADDRESS_PREFIX** set to zero in the **DestinationPrefix** member when there are multiple network adapters installed.

The **Metric** member of a **MIB_IPFORWARD_ROW2** entry is a value that is assigned to an IP route for a particular network interface that identifies the cost that is associated with using that route. For example, the metric can be valued in terms of link speed, hop count, or time delay. Automatic metric is a feature on Windows XP and later that automatically configures the metric for the local routes that are based on link speed. The automatic metric feature is enabled by default (the **UseAutomaticMetric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure is set to **TRUE**) on Windows XP and later. It can also be manually configured to assign a specific metric to an IP route.

The route metric specified in the **Metric** member of the **MIB_IPFORWARD_ROW2** structure represents just the route metric offset. The complete metric is a combination of this route metric offset added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[CreateIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipforwardentry2)

[DeleteIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteipforwardentry2)

[GetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardentry2)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[IP_ADDRESS_PREFIX](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-ip_address_prefix)

[MIB_IPFORWARD_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipforward_table2)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)

[SetIpForwardEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipforwardentry2)