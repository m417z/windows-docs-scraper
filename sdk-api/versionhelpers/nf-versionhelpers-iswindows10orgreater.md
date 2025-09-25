# IsWindows10OrGreater function

## Description

Indicates if the current OS version matches, or is greater than, the Windows 10 version.

## Return value

True if the current OS version matches, or is greater than, the Windows 10 version; otherwise, false.

## Remarks

Applications not manifested for Windows 10 return false, even if the current operating system version is Windows 10. To manifest your applications for Windows 10, see [Targeting your application for Windows](https://learn.microsoft.com/windows/desktop/SysInfo/targeting-your-application-at-windows-8-1).

The version helper functions do not differentiate between client and server releases. They return **true** if the current OS version number is equal to or higher than the version of the client named in the call. For example, a call to [IsWindowsXPSP3OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsxpsp3orgreater) will return **true** on Windows Server 2008. Applications that need to distinguish between server and client versions of Windows should call [IsWindowsServer](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsserver).

For situations where a Windows Server version number isn't shared with a Windows client release, you can use [IsWindowsVersionOrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsversionorgreater) to confirm.

#### Examples

The inline functions defined in the **VersionHelpers.h** header file let you verify the operating system version by returning a **Boolean** value when testing for a version of Windows.

For example, if your application requires Windows 10 or later, use the following test.

```cpp
#include <VersionHelpers.h>
…
    if (!IsWindows10OrGreater())
    {
       MessageBox(NULL, "You need at least Windows 10.", "Version Not Supported", MB_OK);
    }

```

## See also

[IsWindows7OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows7orgreater)

[IsWindows7SP1OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows7sp1orgreater)

[IsWindows8OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows8orgreater)

[IsWindows8Point1OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindows8point1orgreater)

[IsWindowsServer](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsserver)

[IsWindowsVistaOrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsvistaorgreater)

[IsWindowsVistaSP1OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsvistasp1orgreater)

[IsWindowsVistaSP2OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsvistasp2orgreater)

[IsWindowsXPOrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsxporgreater)

[IsWindowsXPSP1OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsxpsp1orgreater)

[IsWindowsXPSP2OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsxpsp2orgreater)

[IsWindowsXPSP3OrGreater](https://learn.microsoft.com/windows/desktop/api/versionhelpers/nf-versionhelpers-iswindowsxpsp3orgreater)