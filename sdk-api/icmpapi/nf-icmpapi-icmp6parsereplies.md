# Icmp6ParseReplies function

## Description

The **Icmp6ParseReplies** function parses the reply buffer provided and returns an IPv6 ICMPv6 echo response reply if found.

## Parameters

### `ReplyBuffer` [in]

A pointer to the buffer passed to
the [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2) function. This parameter is points to an [ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structure to hold the response.

### `ReplySize` [in]

The size, in bytes, of the buffer pointed to by the *ReplyBuffer* parameter.

## Return value

The **Icmp6ParseReplies** function returns 1 on success. In this case, the **Status** member in the [ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structure pointed to by the *ReplyBuffer* parameter will be either **IP_SUCCESS** if the target node responded or **IP_TTL_EXPIRED_TRANSIT**.

If the return value is zero, extended error information is available through
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_GEN_FAILURE** | A general failure occurred. This error is returned if the *ReplyBuffer* parameter is a **NULL** pointer or the *ReplySize*  parameter is zero. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **Icmp6ParseReplies** function is used by IPv6 to parse replies that result from an ICMPv6 echo request. The **Icmp6ParseReplies** function parses a reply buffer previously passed to
the [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2) function. Use the **Icmp6ParseReplies** function only with
the **Icmp6SendEcho2** function.

The **Icmp6ParseReplies** function cannot be used on a reply buffer previously passed to
[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho) or [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2) for IPv4.

For IPv4, use the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile), **IcmpSendEcho**, [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2), [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex), and [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies) functions.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

**IcmpSendEcho**

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)