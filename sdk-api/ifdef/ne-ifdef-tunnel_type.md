# TUNNEL_TYPE enumeration

## Description

The TUNNEL_TYPE enumeration type defines the encapsulation method used by a tunnel, as described by
the Internet Assigned Names Authority (IANA).

## Constants

### `TUNNEL_TYPE_NONE:0`

Indicates that a tunnel is not specified.

### `TUNNEL_TYPE_OTHER:1`

Indicates that none of the following tunnel types is specified.

### `TUNNEL_TYPE_DIRECT:2`

Specifies that a packet is encapsulated directly within a normal IP header, with no intermediate
header, and the packet is sent unicast to the remote tunnel endpoint.

### `TUNNEL_TYPE_6TO4:11`

Specifies that an IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate
header, and the packet is sent unicast to the destination determined by the 6to4 protocol.

### `TUNNEL_TYPE_ISATAP:13`

Specifies that an IPv6 packet is encapsulated directly within an IPv4 header, with no intermediate
header, and the packet is sent unicast to the destination determined by the ISATAP protocol.

### `TUNNEL_TYPE_TEREDO:14`

Specifies that the tunnel uses Teredo encapsulation.

### `TUNNEL_TYPE_IPHTTPS:15`

Specifies that the tunnel uses IP over Hypertext Transfer Protocol Secure (HTTPS). This tunnel
type is supported in Windows 7 and later versions of the Windows operating system.

## Remarks

For more information about the tunnel type as described by the Internet Assigned Names Authority
(IANA) see
["IANAifType-MIB DEFINITIONS"](https://www.iana.org/assignments/ianaiftype-mib).