# NL_ROUTE_PROTOCOL enumeration

## Description

The NL_ROUTE_PROTOCOL enumeration type defines the routing mechanism that an IP route was added with,
as described in RFC 4292.

## Constants

### `RouteProtocolOther:1`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolLocal:2`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolNetMgmt:3`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolIcmp:4`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolEgp:5`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolGgp:6`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolHello:7`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolRip:8`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolIsIs:9`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolEsIs:10`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolCisco:11`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolBbn:12`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolOspf:13`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolBgp:14`

Reserved for system use. Do not use this value in your driver.

### `RouteProtocolIdpr:15`

### `RouteProtocolEigrp:16`

### `RouteProtocolDvmrp:17`

### `RouteProtocolRpl:18`

### `RouteProtocolDhcp:19`

#### - MIB_IPPROTO_BBN

The Bolt, Beranek, and Newman (BBN) Interior Gateway Protocol (IGP) that used the Shortest Path
First (SPF) algorithm. This protocol was an early dynamic routing protocol.

#### - MIB_IPPROTO_BGP

The Border Gateway Protocol (BGP), a dynamic routing protocol.

#### - MIB_IPPROTO_CISCO

The Cisco Interior Gateway Routing Protocol (IGRP), a dynamic routing protocol.

#### - MIB_IPPROTO_EGP

The Exterior Gateway Protocol (EGP), a dynamic routing protocol.

#### - MIB_IPPROTO_ES_IS

The End System-to-Intermediate System (ES-IS) protocol, a dynamic routing protocol. The ES-IS
protocol was developed for use in the Open Systems Interconnection (OSI) protocol suite.

#### - MIB_IPPROTO_GGP

The Gateway-to-Gateway Protocol (GGP), a dynamic routing protocol.

#### - MIB_IPPROTO_HELLO

The Hello protocol, a dynamic routing protocol. This value is a historical entry that is no longer
used and was an early routing protocol that was used by the original ARPANET routers that ran special
software call fuzzball or hellospeak, as described in RFC 891. For more information, see
[DCN Local-Network Protocols](https://www.ietf.org/rfc/rfc891.txt).

#### - MIB_IPPROTO_ICMP

The result of an ICMP redirect.

#### - MIB_IPPROTO_IS_IS

The Intermediate System-to-Intermediate System (IS-IS) protocol, a dynamic routing protocol. The
IS-IS protocol was developed for use in the Open Systems Interconnection (OSI) protocol suite.

#### - MIB_IPPROTO_LOCAL

A local interface.

#### - MIB_IPPROTO_NETMGMT

A static route. This value is used to identify route information for IP routing set through
network management such as the Dynamic Host Configuration Protocol (DCHP) or the Simple Network
Management Protocol (SNMP), or by calls to the
[CreateIpForwardEntry2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546209(v=vs.85)),
[DeleteIpForwardEntry2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546365(v=vs.85)), or
[SetIpForwardEntry2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570773(v=vs.85)) functions.

#### - MIB_IPPROTO_NT_AUTOSTATIC

A Windows-specific entry that is added originally by a routing protocol, but which is now
static.

#### - MIB_IPPROTO_NT_STATIC

A Windows-specific entry that is added as a static route from the routing user interface or a
routing command.

#### - MIB_IPPROTO_NT_STATIC_NON_DOD

A Windows-specific entry that is added as a static route from the routing user interface or a
routing command, except that these routes do not cause Dial On Demand (DOD).

#### - MIB_IPPROTO_OSPF

The Open Shortest Path First (OSPF) protocol, a dynamic routing protocol.

#### - MIB_IPPROTO_OTHER

The routing mechanism was not specified.

#### - MIB_IPPROTO_RIP

The Berkeley Routing Information Protocol (RIP) or RIP-II, a dynamic routing protocol.

## Remarks

For more information about RFC 4292, see the
[IP Forwarding Table MIB](https://www.ietf.org/rfc/rfc4292.txt) memo by the
Network Working Group.

Note that the
Nldef.h header is automatically included by the
Netioapi.h header file. Your driver should never use the
Nldef.h header file directly.