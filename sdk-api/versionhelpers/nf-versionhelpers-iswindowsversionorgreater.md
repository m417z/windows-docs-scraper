# IsWindowsVersionOrGreater function

## Description

**Important** You should only use this function if the other provided
[Version Helper functions](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis) do not fit within your
scenarios.

Indicates if the current OS version matches, or is greater than, the provided version
information. This function is useful in confirming a version of Windows Server that
doesn't share a version number with a client release.

## Parameters

### `wMajorVersion`

The major OS version number.

### `wMinorVersion`

The minor OS version number.

### `wServicePackMajor`

The major Service Pack version number.

## Return value

**TRUE** if the specified version matches, or is greater than, the version of the
current Windows OS; otherwise, **FALSE**.

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