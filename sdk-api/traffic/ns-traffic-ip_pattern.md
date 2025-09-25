# IP_PATTERN structure

## Description

The
**IP_PATTERN** structure applies a specific pattern or corresponding mask for the IP protocol. The
**IP_PATTERN** structure designation is used by the traffic control interface in the application of packet filters.

## Members

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

### `SrcAddr`

Source address.

### `DstAddr`

Destination address.

### `S_un`

### `S_un.S_un_ports`

##### S_un_ports.s_srcport,s_dstport

Source port and destination port.

### `S_un.S_un_ports.s_srcport`

### `S_un.S_un_ports.s_dstport`

### `S_un.S_un_icmp`

##### S_un_icmp.s_type,s_code

ICMP message type and ICMP message code.

### `S_un.S_un_icmp.s_type`

### `S_un.S_un_icmp.s_code`

### `S_un.S_un_icmp.filler`

### `S_un.S_Spi`

Service provider interface.

### `ProtocolId`

Protocol identifier.

### `Reserved3`

Reserved for future use.

## Remarks

The following macros are defined in Traffic.h to make it easier to reference the members of the union:

``` syntax
#define tcSrcPort S_un.S_un_ports.s_srcport
#define tcDstPort S_un.S_un_ports.s_dstport
#define tcIcmpType        S_un.S_un_icmp.s_type
#define tcIcmpCode        S_un.S_un_icmp.s_code
#define tcSpi             S_un.S_Spi
```

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)