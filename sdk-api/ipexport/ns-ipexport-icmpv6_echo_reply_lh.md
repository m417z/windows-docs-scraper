# ICMPV6_ECHO_REPLY_LH structure

## Description

The
**ICMPV6_ECHO_REPLY** structure describes the data returned in response to an IPv6 echo request.

## Members

### `Address`

Type: **IPV6_ADDRESS_EX**

The replying IPv6 address, in the form of an [IPV6_ADDRESS_EX](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ipv6_address_ex) structure.

### `Status`

Type: **ULONG**

The status of the echo request, in the form of an **IP_STATUS** code. The possible values for this member are defined in the *Ipexport.h* header file.

| Value | Meaning |
| --- | --- |
| **IP_SUCCESS**<br><br>0 | The status was success. |
| **IP_BUF_TOO_SMALL**<br><br>11001 | The reply buffer was too small. |
| **IP_DEST_NET_UNREACHABLE**<br><br>11002 | The destination network was unreachable. In IPv6 terminology, this status value is also defined as **IP_DEST_NO_ROUTE**. |
| **IP_DEST_HOST_UNREACHABLE**<br><br>11003 | The destination host was unreachable. In IPv6 terminology, this status value is also defined as **IP_DEST_ADDR_UNREACHABLE**. |
| **IP_DEST_PROT_UNREACHABLE**<br><br>11004 | The destination protocol was unreachable. In IPv6 terminology, this status value is also defined as **IP_DEST_PROHIBITED**. |
| **IP_DEST_PORT_UNREACHABLE**<br><br>11005 | The destination port was unreachable. |
| **IP_NO_RESOURCES**<br><br>11006 | Insufficient IP resources were available. |
| **IP_BAD_OPTION**<br><br>11007 | A bad IP option was specified. |
| **IP_HW_ERROR**<br><br>11008 | A hardware error occurred. |
| **IP_PACKET_TOO_BIG**<br><br>11009 | The packet was too big. |
| **IP_REQ_TIMED_OUT**<br><br>11010 | The request timed out. |
| **IP_BAD_REQ**<br><br>11011 | A bad request. |
| **IP_BAD_ROUTE**<br><br>11012 | A bad route. |
| **IP_TTL_EXPIRED_TRANSIT**<br><br>11013 | The hop limit for IPv6 expired in transit. In IPv6 terminology, this status value is also defined as **IP_HOP_LIMIT_EXCEEDED**. |
| **IP_TTL_EXPIRED_REASSEM**<br><br>11014 | The hop limit for IPv6 expired during fragment reassembly. In IPv6 terminology, this status value is also defined as **IP_REASSEMBLY_TIME_EXCEEDED**. |
| **IP_PARAM_PROBLEM**<br><br>11015 | A parameter problem. In IPv6 terminology, this status value is also defined as **IP_PARAMETER_PROBLEM**. |
| **IP_SOURCE_QUENCH**<br><br>11016 | Datagrams are arriving too fast to be processed and datagrams may have been discarded. |
| **IP_OPTION_TOO_BIG**<br><br>11017 | An IP option was too big. |
| **IP_BAD_DESTINATION**<br><br>11018 | A bad destination. |
| **IP_DEST_UNREACHABLE**<br><br>11040 | The destination was unreachable. |
| **IP_TIME_EXCEEDED**<br><br>11041 | The time was exceeded. |
| **IP_BAD_HEADER**<br><br>11042 | A bad IP header was encountered. |
| **IP_UNRECOGNIZED_NEXT_HEADER**<br><br>11043 | An unrecognized next header was encountered. |
| **IP_ICMP_ERROR**<br><br>11044 | An ICMP error occurred. |
| **IP_DEST_SCOPE_MISMATCH**<br><br>11045 | A destination scope ID mismatch occurred. |
| **IP_GENERAL_FAILURE**<br><br>11050 | A general failure. This error can be returned for some malformed ICMP packets. |

### `RoundTripTime`

Type: **unsigned int**

The round trip time, in milliseconds.

## Remarks

The **ICMPV6_ECHO_REPLY** structure is used by the [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function to return the response to an IPv6 echo request. The reply data that contains the message body from the ICMPV6 response follows the **ICMPV6_ECHO_REPLY** structure in memory.

For IPv6, some of the possible values for the **Status** member are specified in
RFC 2163. For more information, see [www.ietf.org/rfc/rfc2463.txt](http://tools.ietf.org/html/rfc2463).

The [GetIpErrorString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiperrorstring) function can be used to retrieve the IP helper error string for the **IP_STATUS** error code in the **Status** member.

The **ICMPV6_ECHO_REPLY** structure is defined in public header files included in the Microsoft Windows Software Development Kit (SDK), but this structure is used by the [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function on Windows XP and later.

In the Windows SDK, the **ICMPV6_ECHO_REPLY_LH** structure is defined when compiling an
application if the target platform is Windows XP and later
(`NTDDI_VERSION >= NTDDI_XP`,
`_WIN32_WINNT >= 0x0501`, or
`WINVER >= 0x0501`). The **ICMPV6_ECHO_REPLY_LH** structure is typedefed to the **ICMPV6_ECHO_REPLY** structure. When compiling an application if the target
platform is not Windows XP and later, the
**ICMPV6_ECHO_REPLY** structure is undefined.

This structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

## See also

[GetIpErrorString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiperrorstring)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IPV6_ADDRESS_EX](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ipv6_address_ex)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)