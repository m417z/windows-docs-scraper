# ICMP_ECHO_REPLY32 structure

## Description

The
**ICMP_ECHO_REPLY32** structure describes the data returned in response to an IPv4 echo request on a 64-bit platform.

## Members

### `Address`

Type: **IPAddr**

The replying IPv4 address, in the form of an [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr) structure.

### `Status`

Type: **ULONG**

The status of the echo request, in the form of an **IP_STATUS** code. The possible values for this member are defined in the *Ipexport.h* header file.

| Value | Meaning |
| --- | --- |
| **IP_SUCCESS**<br><br>0 | The status was success. |
| **IP_BUF_TOO_SMALL**<br><br>11001 | The reply buffer was too small. |
| **IP_DEST_NET_UNREACHABLE**<br><br>11002 | The destination network was unreachable. |
| **IP_DEST_HOST_UNREACHABLE**<br><br>11003 | The destination host was unreachable. |
| **IP_DEST_PROT_UNREACHABLE**<br><br>11004 | The destination protocol was unreachable. |
| **IP_DEST_PORT_UNREACHABLE**<br><br>11005 | The destination port was unreachable. |
| **IP_NO_RESOURCES**<br><br>11006 | Insufficient IP resources were available. |
| **IP_BAD_OPTION**<br><br>11007 | A bad IP option was specified. |
| **IP_HW_ERROR**<br><br>11008 | A hardware error occurred. |
| **IP_PACKET_TOO_BIG**<br><br>11009 | The packet was too big. |
| **IP_REQ_TIMED_OUT**<br><br>11010 | The request timed out. |
| **IP_BAD_REQ**<br><br>11011 | A bad request. |
| **IP_BAD_ROUTE**<br><br>11012 | A bad route. |
| **IP_TTL_EXPIRED_TRANSIT**<br><br>11013 | The time to live (TTL) expired in transit. |
| **IP_TTL_EXPIRED_REASSEM**<br><br>11014 | The time to live expired during fragment reassembly. |
| **IP_PARAM_PROBLEM**<br><br>11015 | A parameter problem. |
| **IP_SOURCE_QUENCH**<br><br>11016 | Datagrams are arriving too fast to be processed and datagrams may have been discarded. |
| **IP_OPTION_TOO_BIG**<br><br>11017 | An IP option was too big. |
| **IP_BAD_DESTINATION**<br><br>11018 | A bad destination. |
| **IP_GENERAL_FAILURE**<br><br>11050 | A general failure. This error can be returned for some malformed ICMP packets. |

### `RoundTripTime`

Type: **ULONG**

The round trip time, in milliseconds.

### `DataSize`

Type: **USHORT**

The data size, in bytes, of the reply.

### `Reserved`

Type: **USHORT**

Reserved for system use.

### `Data`

Type: **VOID * POINTER_32**

A pointer to the reply data.

### `Options`

Type: **struct ip_option_information32**

The IP options in the IP header of the reply, in the form of an [IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32) structure.

## Remarks

The **ICMP_ECHO_REPLY32** structure is used by the [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies) function to return the response to an IPv4 echo request on a 64-bit platform. This structure is only defined if _WIN64 is defined.

For IPv4, some of the possible values for the **Status** member are specified in
[RFC 792](https://www.ietf.org/rfc/rfc792.txt).

The [GetIpErrorString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiperrorstring) function can be used to retrieve the IP helper error string for the **IP_STATUS** error code in the **Status** member.

The **ICMP_ECHO_REPLY32** structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

## See also

[GetIpErrorString](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiperrorstring)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[IP_OPTION_INFORMATION32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information32)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)