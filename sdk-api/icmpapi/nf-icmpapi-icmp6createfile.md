# Icmp6CreateFile function

## Description

The
**Icmp6CreateFile** function opens a handle on which IPv6 ICMP echo requests can be issued.

## Return value

The
**Icmp6CreateFile** function returns an open handle on success. On failure, the function returns **INVALID_HANDLE_VALUE**. Call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for extended error information.

## Remarks

The
**Icmp6CreateFile** function opens a handle on which IPv6 ICMP echo requests can be issued. The [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2) function is used to send the IPv6 ICMP echo requests. The [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) function is used to parse the IPv6 ICMP replies. The [IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle) function is used to close the ICMP handle opened by the **Icmp6CreateFile** function.

For IPv4, use the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile) function.

For IPv4, use the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile), **IcmpSendEcho**, [IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2), [IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex), and [IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies) functions.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

#### Examples

The following example opens a handle on which IPv6 ICMP echo requests can be issued.

```cpp
#include <windows.h>
#include <stdio.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#pragma comment(lib, "IPHLPAPI.lib")

void main()
{
    HANDLE hIcmpFile;

    hIcmpFile = Icmp6CreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
      printf("\tUnable to open handle.\n");
      printf("Icmp6Createfile returned error: %ld\n", GetLastError() );
    }
    else
      printf("\tHandle created.\n");
}

```

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

**IcmpSendEcho**

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)