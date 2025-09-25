# GetIpErrorString function

## Description

The **GetIpErrorString** function retrieves an IP Helper error string.

## Parameters

### `ErrorCode` [in]

The error code to be retrieved. The possible values for this parameter are defined in the *Ipexport.h* header file.

### `Buffer` [out]

A pointer to the buffer that contains the error code string if the function returns with NO_ERROR.

### `Size` [in, out]

A pointer to a **DWORD** that specifies the length, in characters, of the buffer pointed to by *Buffer* parameter, excluding the terminating null (i.e. the size of Buffer in characters, minus one).

## Return value

Returns NO_ERROR upon success.

If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

The **GetIpErrorString** function can be used to retrieve an IP Helper error string for an IP error code. The **IP_STATUS** error code passed in the *ErrorCode* parameter is returned in the **Status** member of the [ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply), [ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32), and [ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh) structures used by the ICMP and ICMPv6 functions. The functions that use these structures include [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies), [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2), [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies),
[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho), [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2), and [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex).

The syntax for the **GetIpErrorString** function was slightly changed on the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later. The data type for the *Buffer* parameter was changed from **PWCHAR** to **PWSTR**.

## See also

[ICMPV6_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmpv6_echo_reply_lh)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho)

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)