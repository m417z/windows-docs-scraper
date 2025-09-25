# IPV6_ADDRESS_EX structure

## Description

The **IPV6_ADDRESS_EX** structure stores an
IPv6 address.

## Members

### `sin6_port`

The IPv6 port number in network byte order.

### `sin6_flowinfo`

The IPv6 flowinfo value from the IPv6 header in network byte order.

### `sin6_addr`

The IPv6 address in network byte order.

### `sin6_scope_id`

The IPv6 scope ID in network byte order.

## Remarks

The **IPV6_ADDRESS_EX** structure is a member of the
[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structure that is used by the
[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function.

The **IPV6_ADDRESS_EX** structure is defined in public
header files included in the Microsoft Windows Software Development Kit (SDK), but this structure is used by the
[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function on
Windows XP and later.

In the Windows SDK, the
**IPV6_ADDRESS_EX** is structure defined when compiling an
application if the target platform is Windows XP and later
(`NTDDI_VERSION >= NTDDI_XP`,
`_WIN32_WINNT >= 0x0501`, or
`WINVER >= 0x0501`). When compiling an application if the target
platform is not Windows XP and later, the
**IPV6_ADDRESS_EX** structure is undefined.

This structure is defined in the Ipexport.h header file which is automatically included in the Iphlpapi.h
header file. The Ipexport.h header file should never be used directly.

## See also

[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_OPTION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-ip_option_information)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)