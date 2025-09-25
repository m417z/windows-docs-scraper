# MIB_IPFORWARDROW structure

## Description

The
**MIB_IPFORWARDROW** structure contains information that describes an IPv4 network route.

## Members

### `dwForwardDest`

Type: **DWORD**

The destination IPv4 address of the route. An
entry with a IPv4 address of 0.0.0.0 is considered a
default route.
This member cannot be set to a multicast (class D) IPv4 address.

### `dwForwardMask`

Type: **DWORD**

The IPv4 subnet mask to use with the
destination IPv4 address before being compared to
the value in the **dwForwardDest** member.

The **dwForwardMask** value should be applied to the destination IPv4 address (logical and operation) before a comparison with the value in the **dwForwardDest** member.

### `dwForwardPolicy`

Type: **DWORD**

The set of conditions that would cause the selection of a multi-path route (the set of
next hops for a given destination). This member is typically in IP TOS format. This encoding of this member is described in
RFC 1354. For more information, see
[http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt).

### `dwForwardNextHop`

Type: **DWORD**

For remote routes, the IPv4 address of the next system en route. Otherwise, this member should be an IPv4 address of 0.0.0.0.

### `dwForwardIfIndex`

Type: **DWORD**

The index of the local interface through which the next hop of this
route should be reached.

### `dwForwardType`

Type: **DWORD**

The route type as described in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt).

This member can be one of the values defined in the *Iprtmib.h* header file.

On Windows Vista and later, the header files were reorganized and this member can be one of the values from the **MIB_IPFORWARD_TYPE** enumeration type defined in the *Ipmib.h* header file. Note that the *Ipmib.h* header is automatically included by the *Iprtrmib.h* header file which is automatically included by the *Iphlpapi.h* header. The *Iprtrmib.h* and *Ipmib.h* header files should never be used directly.

The following list shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **MIB_IPROUTE_TYPE_OTHER**<br><br>1 | Some other type not specified in RFC 1354. |
| **MIB_IPROUTE_TYPE_INVALID**<br><br>2 | An invalid route. This value can result from a route added by an ICMP redirect. |
| **MIB_IPROUTE_TYPE_DIRECT**<br><br>3 | A local route where the next hop is the final destination (a local interface). |
| **MIB_IPROUTE_TYPE_INDIRECT**<br><br>4 | The remote route where the next hop is not the final destination (a remote destination). |

### `ForwardType`

### `dwForwardProto`

Type: **DWORD**

The protocol or routing mechanism that generated the route as described in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt). See
[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers) for a list of possible protocol identifiers used by routing protocols.

This member can be one of the values defined in the *Iprtmib.h* header file. The values for this member can be one of the MIB_IPPROTO_xxx values defined in the *Iprtmib.h* header file or one of the PROTO_IP_xxx values defined in the *routprot.h* header file since these values are the same.

On Windows Vista and later, the header files were reorganized and this member can be one of the values defined in the *Nldef.h* header file. Note that the *Nldef.h* header is automatically included by the *Ipmib.h* header file which is automatically included by the *Iprtrmib.h* header. The *Iphlpapi.h* header automatically includes the *Iprtrmib.h* header file. The *Iprtrmib.h*, *Ipmib.h*, and *Nldef.h* header files should never be used directly.

The following list shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **MIB_IPPROTO_OTHER**<br><br>1 | Some other protocol not specified in RFC 1354. |
| **MIB_IPPROTO_LOCAL**<br><br>2 | A local interface. |
| **MIB_IPPROTO_NETMGMT**<br><br>3 | A static route. This value is used to identify route information for IP routing set through network management such as the Dynamic Host Configuration Protocol (DCHP), the Simple Network Management Protocol (SNMP), or by calls to the [CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry), [DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry), or [SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) functions. |
| **MIB_IPPROTO_ICMP**<br><br>4 | The result of ICMP redirect. |
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

### `ForwardProto`

### `dwForwardAge`

Type: **DWORD**

The number of seconds since the route was
added or modified in the network routing table.

### `dwForwardNextHopAS`

Type: **DWORD**

The autonomous system number of the next hop. When this member is unknown or not relevant to the
protocol or routing mechanism specified in **dwForwardProto**, this value should be set to zero. This value is documented in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

### `dwForwardMetric1`

Type: **DWORD**

The primary routing metric value for this route. The semantics of this metric are determined by
the routing protocol specified in the **dwForwardProto** member. If this metric is not
used, its value should be set to -1. This value is documented in
in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

### `dwForwardMetric2`

Type: **DWORD**

An alternate routing metric value for this route. The semantics of this metric are determined by
the routing protocol specified in the **dwForwardProto** member. If this metric is not
used, its value should be set to -1. This value is documented in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

### `dwForwardMetric3`

Type: **DWORD**

An alternate routing metric value for this route. The semantics of this metric are determined by
the routing protocol specified in the **dwForwardProto** member. If this metric is not
used, its value should be set to -1. This value is documented in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

### `dwForwardMetric4`

Type: **DWORD**

An alternate routing metric value for this route. The semantics of this metric are determined by
the routing protocol specified in the **dwForwardProto** member. If this metric is not
used, its value should be set to -1. This value is documented in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

### `dwForwardMetric5`

Type: **DWORD**

An alternate routing metric value for this route. The semantics of this metric are determined by
the routing protocol specified in the **dwForwardProto** member. If this metric is not
used, its value should be set to -1. This value is documented in
RFC 1354. For more information, see [http://www.ietf.org/rfc/rfc1354.txt](https://www.ietf.org/rfc/rfc1354.txt)

## Remarks

The [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function enumerates the IPv4 route entries on a local system and returns this information in a [MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable) structure that contains an array of **MIB_IPFORWARDROW** structure entries.

The **dwForwardDest**, **dwForwardMask**, and **dwForwardNextHop** members of the
**MIB_IPFORWARDROW** structure represent IPv4 addresses in network byte order.

The **dwForwardProto** member of the
**MIB_IPFORWARDROW** structure specifies the protocol or routing mechanism that generated the route. Routing protocol identifiers are used to identify route information for the specified routing protocol. For example, **MIB_IPPROTO_NETMGMT** is used to identify route information for IP routing set through network management such as the Dynamic Host Configuration Protocol (DCHP), the Simple Network Management Protocol (SNMP), or by calls to the [CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry), [DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry)
, or [SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry) functions. See
[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers) for a list of possible protocols and routing mechanisms.

An IPv4 address of 0.0.0.0 in the **dwForwardDest** member of the
**MIB_IPFORWARDROW** structure is considered a
default route. The [MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable) may contain multiple **MIB_IPFORWARDROW** entries with the **dwForwardDest** member set to 0.0.0.0 when there are multiple network adapters installed.

When **dwForwardAge** is set to **INFINITE**, the route will not be removed based on a timeout
value. Any other value for **dwForwardAge** specifies the number of seconds since the route was added or modified in the network routing table.

On Windows Server 2003 or
Windows 2000 Server when the Routing and Remote Access Service (RRAS) is running, the **MIB_IPFORWARDROW** entries returned have the **dwForwardType** and **dwForwardAge** members set to zero.

On Windows Vista and Windows Server 2008, the route metric specified in the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure represents a combination of the route metric added to the interface metric specified in the **Metric** member of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure of the associated interface. So the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be equal to or greater than **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. If an application would like to set the route metric to 0, then the **dwForwardMetric1** member of the **MIB_IPFORWARDROW** structure should be set equal to the value of the interface metric specified in the **Metric** member of the associated **MIB_IPINTERFACE_ROW** structure. An application can retrieve the interface metric by calling the [GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry) function.

A number of members of the **MIB_IPFORWARDROW** structure are not currently used by IPv4 routing. These members include **dwForwardPolicy**, **dwForwardNextHopAS**, **dwForwardMetric2**, **dwForwardMetric3**, **dwForwardMetric4**, and **dwForwardMetric5**.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

#### Examples

To view an example that retrieves the [MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable) structure and then prints out the **MIB_IPFORWARDROW** structure entries in this table, see the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function.

## See also

[CreateIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipforwardentry)

[DeleteIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipforwardentry)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[MIB_IPFORWARDTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardtable)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[SetIpForwardEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipforwardentry)