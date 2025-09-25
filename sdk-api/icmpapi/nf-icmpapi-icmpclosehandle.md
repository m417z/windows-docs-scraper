# IcmpCloseHandle function

## Description

The
**IcmpCloseHandle** function closes a handle opened by a call to
the [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile) or [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile) functions.

## Parameters

### `IcmpHandle` [in]

The handle to close. This handle must have been returned by a call to [IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile) or [Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile).

## Return value

If the handle is closed successfully the return value is **TRUE**, otherwise **FALSE**. Call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for extended error information.

## Remarks

The **IcmpCloseHandle** function is exported from the *Icmp.dll* on Windows 2000. The **IcmpCloseHandle** function is exported from the *Iphlpapi.dll* on Windows XP and later. Windows version checking is not recommended to use this function. Applications requiring portability with this function across Windows 2000, Windows XP, Windows Server 2003 and later Windows versions should not statically link to either the *Icmp.lib* or the *Iphlpapi.lib* file. Instead, the application should check for the presence of **IcmpCloseHandle** in the *Iphlpapi.dll* with calls to [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Failing that, the application should check for the presence of **IcmpCloseHandle** in the *Icmp.dll* with calls to **LoadLibrary** and **GetProcAddress**.

Note that the include directive for *Iphlpapi.h* header file must be placed before the *Icmpapi.h* header file.

#### Examples

The following example opens and closes a handle on which ICMP echo requests can be issued.

```cpp
#include <windows.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")

void main()
{
    HANDLE hIcmpFile;
    BOOL bRetVal;

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE)
      printf("IcmpCreateFile failed with error: %ld\n", GetLastError() );
    else
    {
      printf("\tHandle created.\n");

      bRetVal = IcmpCloseHandle(hIcmpFile);
      if (bRetVal)
          printf("\tHandle was closed\n");
      else
          printf("IcmpCloseHandle failed with error: %ld\n", GetLastError() );
    }
}

```

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[Icmp6CreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6createfile)

[Icmp6ParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6parsereplies)

[Icmp6SendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmp6sendecho2)

[IcmpCreateFile](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpcreatefile)

[IcmpParseReplies](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpparsereplies)

**IcmpSendEcho**

[IcmpSendEcho2](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2)

[IcmpSendEcho2Ex](https://learn.microsoft.com/windows/desktop/api/icmpapi/nf-icmpapi-icmpsendecho2ex)