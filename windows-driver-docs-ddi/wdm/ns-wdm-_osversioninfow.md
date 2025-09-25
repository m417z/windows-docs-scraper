# _OSVERSIONINFOW structure

## Description

The **RTL_OSVERSIONINFOW** structure contains operating system version information. The information includes major and minor version numbers, a build number, a platform identifier, and descriptive text about the operating system. The **RTL_OSVERSIONINFOW** structure is used with [RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion).

## Members

### `dwOSVersionInfoSize`

The size in bytes of an **RTL_OSVERSIONINFOW** structure. This member must be set before the structure is used with [RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion).

### `dwMajorVersion`

The major version number of the operating system. For example, for Windows 2000, the major version number is five. For more information, see [RTL_OSVERSIONINFOEXW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfoexw).

### `dwMinorVersion`

The minor version number of the operating system. For example, for Windows 2000 the minor version number is zero. For more information, see [RTL_OSVERSIONINFOEXW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfoexw).

### `dwBuildNumber`

The build number of the operating system.

### `dwPlatformId`

The operating system platform. For Microsoft Win32 on NT-based operating systems, **RtlGetVersion** returns the value VER_PLATFORM_WIN32_NT.

### `szCSDVersion`

The service-pack version string. This member contains a null-terminated string, such as "Service Pack 3", which indicates the latest service pack installed on the system. If no service pack is installed, **RtlGetVersion** might not initialize this string. Initialize *szCSDVersion* to zero (empty string) before the call to **RtlGetVersion**.

## Remarks

For a list of the major and minor version numbers for the various versions of Windows, see [RTL_OSVERSIONINFOEXW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfoexw).

## See also

[RTL_OSVERSIONINFOEXW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfoexw)

[RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)

[RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo)