# GetVersionExA function

## Description

**GetVersionExA** may be altered or unavailable for releases after Windows 8.1. Instead, use the [Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis). For Windows 10 apps, please see [Targeting your applications for Windows](https://learn.microsoft.com/windows/win32/sysinfo/targeting-your-application-at-windows-8-1).

With the release of Windows 8.1, the behavior of the **GetVersionEx** API has changed in the value it will return for the operating system version. The value returned by the **GetVersionEx** function now depends on how the application is manifested.

Applications not manifested for Windows 8.1 or Windows 10 will return the Windows 8 OS version value (6.2). Once an application is manifested for a given operating system version, **GetVersionEx** will always return the version that the application is manifested for in future releases. To manifest your applications for Windows 8.1 or Windows 10, refer to [Targeting your application for Windows](https://learn.microsoft.com/windows/desktop/SysInfo/targeting-your-application-at-windows-8-1).

## Parameters

### `lpVersionInformation` [in, out]

An
[OSVERSIONINFOA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa) or [OSVERSIONINFOEXA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) structure that receives the operating system information.

Before calling the
**GetVersionEx** function, set the **dwOSVersionInfoSize** member of the structure as appropriate to indicate which data structure is being passed to this function.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The function fails if you specify an invalid value for the **dwOSVersionInfoSize** member of the
[OSVERSIONINFOA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa) or
[OSVERSIONINFOEXA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa) structure.

## Remarks

Identifying the current operating system is usually not the best way to determine whether a particular operating system feature is present. This is because the operating system may have had new features added in a redistributable DLL. Rather than using
**GetVersionEx** to determine the operating system platform or version number, test for the presence of the feature itself. For more information, see
[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version).

The [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function provides additional information about the current operating system.

| Product | Setting |
| --- | --- |
| Windows XP Media Center Edition | SM_MEDIACENTER |
| Windows XP Starter Edition | SM_STARTER |
| Windows XP Tablet PC Edition | SM_TABLETPC |
| Windows Server 2003 R2 | SM_SERVERR2 |

To check for specific operating systems or operating system features, use the [IsOS](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-isos) function. The [GetProductInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getproductinfo) function retrieves the product type.

To retrieve information for the operating system on a remote computer, use the [NetWkstaGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstagetinfo) function, the [Win32_OperatingSystem](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-operatingsystem) WMI class, or the [OperatingSystem](https://learn.microsoft.com/windows/desktop/ADSI/iadscomputer-property-methods) property of the **IADsComputer** interface.

To compare the current system version to a required version, use the
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) function instead of using
**GetVersionEx** to perform the comparison yourself.

If compatibility mode is in effect, the **GetVersionEx** function reports the operating system as it identifies itself, which may not be the operating system that is installed. For example, if compatibility mode is in effect, **GetVersionEx** reports the operating system that is selected for [application compatibility](https://learn.microsoft.com/previous-versions/bb757005(v=msdn.10)).

#### Examples

When using the
**GetVersionEx** function to determine whether your application is running on a particular version of the operating system, check for version numbers that are greater than or equal to the desired version numbers. This ensures that the test succeeds for later versions of the operating system. For example, if your application requires Windows XP or later, use the following test.

```cpp
#include <windows.h>
#include <stdio.h>

void main()
{
    OSVERSIONINFO osvi;
    BOOL bIsWindowsXPorLater;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    GetVersionEx(&osvi);

    bIsWindowsXPorLater =
       ( (osvi.dwMajorVersion > 5) ||
       ( (osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion >= 1) ));

    if(bIsWindowsXPorLater)
        printf("The system meets the requirements.\n");
    else printf("The system does not meet the requirements.\n");
}

```

For an example that identifies the current operating system, see
[Getting the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/getting-the-system-version).

> [!NOTE]
> The sysinfoapi.h header defines GetVersionEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetVersion](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversion)

[OSVERSIONINFOA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa)

[OSVERSIONINFOEXA](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoexa)

[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)

[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa)

[Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis)