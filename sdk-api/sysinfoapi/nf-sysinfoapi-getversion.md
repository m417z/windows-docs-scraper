# GetVersion function

## Description

**GetVersion** may be altered or unavailable for releases after Windows 8.1. Instead, use the [Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis). For Windows 10 apps, please see [Targeting your applications for Windows](https://learn.microsoft.com/windows/win32/sysinfo/targeting-your-application-at-windows-8-1).

With the release of Windows 8.1, the behavior of the **GetVersion** API has changed in the value it will return for the operating system version. The value returned by the **GetVersion** function now depends on how the application is manifested.

Applications not manifested for Windows 8.1 or Windows 10 will return the Windows 8 OS version value (6.2). Once an application is manifested for a given operating system version, **GetVersion** will always return the version that the application is manifested for in future releases. To manifest your applications for Windows 8.1 or Windows 10, refer to [Targeting your application for Windows](https://learn.microsoft.com/windows/desktop/SysInfo/targeting-your-application-at-windows-8-1).

## Return value

If the function succeeds, the return value includes the major and minor version numbers of the operating system in the low-order word, and information about the operating system platform in the high-order word.

For all platforms, the low-order word contains the version number of the operating system. The low-order byte of this word specifies the major version number, in hexadecimal notation. The high-order byte specifies the minor version (revision) number, in hexadecimal notation. The high-order bit is zero, the next 7 bits represent the build number, and the low-order byte is 5.

## Remarks

The
[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) function was developed because many existing applications err when examining the packed **DWORD** value returned by
**GetVersion**, transposing the major and minor version numbers.
**GetVersionEx** forces applications to explicitly examine each element of version information.
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) eliminates further potential for error by comparing the required system version with the current system version for you.

#### Examples

The following code fragment illustrates how to extract information from the
**GetVersion** return value: [OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)

```cpp
#include <windows.h>
#include <stdio.h>

void main()
{
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;

    dwVersion = GetVersion();

    // Get the Windows version.

    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    // Get the build number.

    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    printf("Version is %d.%d (%d)\n",
                dwMajorVersion,
                dwMinorVersion,
                dwBuild);
}

```

## See also

- [GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa)
- [OSVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa)
- [OSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)
- [Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version)
- [System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)
- [VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa)
- [Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis)