# IP_OPTION_INFORMATION32 structure

## Description

The
**IP_OPTION_INFORMATION32** structure describes the options to be included in the header of an IP packet on a 64-bit platform.

## Members

### `Ttl`

Type: **UCHAR**

The Time to Live field in an IPv4 packet header. This is the Hop Limit field in an IPv6 header.

### `Tos`

Type: **UCHAR**

The type of service field in an IPv4 header. This member is currently silently ignored.

### `Flags`

Type: **UCHAR**

The Flags field. In IPv4, this is the Flags field in the IPv4 header. In IPv6, this field is represented by options headers.

For IPv4, the possible values for the **Flags** member are a combination of the following values defined in the *Ipexport.h* header file:

| Value | Meaning |
| --- | --- |
| **IP_FLAG_REVERSE**<br><br>0x01 | This value causes the IP packet to add in an IP routing header with the source. This value is only applicable on Windows Vista and later. |
| **IP_FLAG_DF**<br><br>0x02 | This value indicates that the packet should not be fragmented. |

### `OptionsSize`

Type: **UCHAR**

The size, in bytes, of IP options data.

### `OptionsData`

Type: **UCHAR * POINTER_32**

A pointer to options data.

## Remarks

The **IP_OPTION_INFORMATION32** structure is used to describe the options to be included in the header of an IP packet on a 64-bit platform. The **IP_OPTION_INFORMATION32** structure is only defined if _WIN64 is defined.

The values in the **TTL**, **TOS** and **Flags** members are carried in specific fields in the IP header.

The bytes in the **OptionsData** member are carried in the options area that follows the standard IP header.

With the exception of source route options for IPv4, the options data must be in the format to be transmitted on the wire as specified in
[RFC 791](https://www.ietf.org/rfc/rfc791.txt). An IPv4 source route option should contain the full route, first hop through final destination, in the route data. The first hop is pulled out of the data and the option is reformatted accordingly. Otherwise, the route option should be formatted as specified in
[RFC 791](https://www.ietf.org/rfc/rfc791.txt).

For use with IPv6, the options data must be in the format to be transmitted on the wire as specified in
[RFC 2460](https://www.ietf.org/rfc/rfc2460.txt).

The **IP_OPTION_INFORMATION32** structure is a member of the [ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32) structure used by the by the [IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho), [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2), and [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2) functions.

This structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

## See also

[ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)