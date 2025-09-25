# IcmpParseReplies function

## Description

The
**IcmpParseReplies** function parses the reply buffer provided and returns the number of ICMP echo request responses found.

## Parameters

### `ReplyBuffer` [in]

The buffer passed to
[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2). This is rewritten to hold an array of
[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply) structures, its type is **PICMP_ECHO_REPLY**.

On a 64-bit platform, this buffer is rewritten to hold an array of [ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32) structures, its type is **PICMP_ECHO_REPLY32**.

### `ReplySize` [in]

The size, in bytes, of the buffer pointed to by the *ReplyBuffer* parameter.

## Return value

The
**IcmpParseReplies** function returns the number of ICMP responses found on success. The function returns zero on error. Call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional error information.

## Remarks

The **IcmpParseReplies** function should not be used on a reply buffer previously passed to
[IcmpSendEcho](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho). The
**IcmpSendEcho** function parses that buffer before returning to the user. Use this function only with
[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2).

The **IcmpParseReplies** function is exported from the *Icmp.dll* on Windows 2000. The **IcmpParseReplies** function is exported from the *Iphlpapi.dll* on Windows XP and later. Windows version checking is not recommended to use this function. Applications requiring portability with this function across Windows 2000, Windows XP, Windows Server 2003 and later Windows versions should not statically link to either the *Icmp.lib* or the *Iphlpapi.lib* file. Instead, the application should check for the presence of **IcmpParseReplies** in the *Iphlpapi.dll* with calls to [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Failing that, the application should check for the presence of **IcmpParseReplies** in the *Icmp.dll* with calls to **LoadLibrary** and **GetProcAddress**.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[ICMP_ECHO_REPLY](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply)

[ICMP_ECHO_REPLY32](https://learn.microsoft.com/windows/desktop/api/ipexport/ns-ipexport-icmp_echo_reply32)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

**IcmpSendEcho**

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)