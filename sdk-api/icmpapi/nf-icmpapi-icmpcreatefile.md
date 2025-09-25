# IcmpCreateFile function

## Description

The
**IcmpCreateFile** function opens a handle on which IPv4 ICMP echo requests can be issued.

## Return value

The
**IcmpCreateFile** function returns an open handle on success. On failure, the function returns **INVALID_HANDLE_VALUE**. Call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for extended error information.

## Remarks

The **IcmpCreateFile** function is exported from the *Icmp.dll* on Windows 2000. The **IcmpCreateFile** function is exported from the *Iphlpapi.dll* on Windows XP and later. Windows version checking is not recommended to use this function. Applications requiring portability with this function across Windows 2000, Windows XP, Windows Server 2003 and later Windows versions should not statically link to either the *Icmp.lib* or the *Iphlpapi.lib* file. Instead, the application should check for the presence of **IcmpCreateFile** in the *Iphlpapi.dll* with calls to [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Failing that, the application should check for the presence of **IcmpCreateFile** in the *Icmp.dll* with calls to **LoadLibrary** and **GetProcAddress**.

For IPv6, use the [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile), [Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2), and [Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies) functions.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

#### Examples

The following example opens a handle on which ICMP echo requests can be issued.

```cpp
#include <windows.h>
#include <stdio.h>
#include <iphlpapi.h>
#include <icmpapi.h>

// Need to link with Iplhlapi.lib
#pragma comment(lib, "IPHLPAPI.lib")

void main()
{
    HANDLE hIcmpFile;

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
      printf("\tUnable to open handle.\n");
      printf("IcmpCreatefile returned error: %ld\n", GetLastError() );
    }
    else {
      printf("\tHandle created.\n");
      // Need to close the handle when done using it
      IcmpCloseHandle(hIcmpFile);
    }
}

```

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCloseHandle](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpclosehandle)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

**IcmpSendEcho**

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)