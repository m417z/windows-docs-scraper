## Description

The **RTL_OSVERSIONINFOEXW** structure contains operating system version information.

## Members

### `dwOSVersionInfoSize`

The size, in bytes, of an **RTL_OSVERSIONINFOEXW** structure. This member must be set before the structure is used with [RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion).

### `dwMajorVersion`

The major version number of the operating system. For example, for Windows 2000, the major version number is five. For more information, see the table in Remarks.

### `dwMinorVersion`

The minor version number of the operating system. For example, for Windows 2000, the minor version number is zero. For more information, see the table in Remarks.

### `dwBuildNumber`

The build number of the operating system.

### `dwPlatformId`

The operating system platform. For Win32 on NT-based operating systems, **RtlGetVersion** returns the value VER_PLATFORM_WIN32_NT.

### `szCSDVersion`

The service-pack version string. This member contains a null-terminated string, such as "Service Pack 3", which indicates the latest service pack installed on the system. If no service pack is installed, **RtlGetVersion** might not initialize this string. Initialize *szCSDVersion* to zero (empty string) before the call to **RtlGetVersion**.

### `wServicePackMajor`

The major version number of the latest service pack installed on the system. For example, for Service Pack 3, the major version number is three. If no service pack has been installed, the value is zero.

### `wServicePackMinor`

The minor version number of the latest service pack installed on the system. For example, for Service Pack 3, the minor version number is zero.

### `wSuiteMask`

The product suites available on the system. This member is set to zero or to the bitwise OR of one or more of the following values.

| Value | Meaning |
|---|---|
| VER_SUITE_BACKOFFICE | Microsoft BackOffice components are installed. |
| VER_SUITE_BLADE | Windows Server 2003, Web Edition is installed. |
| VER_SUITE_COMPUTE_SERVER | Windows Server 2003, Compute Cluster Edition is installed. |
| VER_SUITE_DATACENTER | Windows Server 2008 Datacenter, Windows Server 2003, Datacenter Edition, or Windows 2000 Datacenter Server is installed. |
| VER_SUITE_ENTERPRISE | Windows Server 2008 Enterprise, Windows Server 2003, Enterprise Edition, or Windows 2000 Advanced Server is installed. |
| VER_SUITE_EMBEDDEDNT | Windows XP Embedded is installed. |
| VER_SUITE_PERSONAL | Windows Vista Home Premium, Windows Vista Home Basic, or Windows XP Home Edition is installed. |
| VER_SUITE_SINGLEUSERTS | Remote Desktop is supported, but only one interactive session is supported. This value is set unless the system is running in application server mode. |
| VER_SUITE_SMALLBUSINESS (see note) | Microsoft Small Business Server was once installed on the system, but may have been upgraded to another version of Windows. For more information about this flag bit, see the following Remarks section. |
| VER_SUITE_SMALLBUSINESS_RESTRICTED | Microsoft Small Business Server is installed with the restrictive client license in force. For more information about this flag bit, see the following Remarks section. |
| VER_SUITE_STORAGE_SERVER | Windows Storage Server 2003 R2 or Windows Storage Server 2003 is installed. |
| VER_SUITE_TERMINAL | Terminal Services is installed. This value is always set. If VER_SUITE_TERMINAL is set but VER_SUITE_SINGLEUSERTS is not set, the operating system is running in application server mode. |
| VER_SUITE_WH_SERVER | Windows Home Server is installed. |

You should not rely solely on the VER_SUITE_SMALLBUSINESS flag to determine whether Small Business Server is currently installed. Both this flag and the VER_SUITE_SMALLBUSINESS_RESTRICTED flag are set when this product suite is installed. If you upgrade this installation to Windows Server, Standard Edition, the VER_SUITE_SMALLBUSINESS_RESTRICTED flag is cleared, but the VER_SUITE_SMALLBUSINESS flag remains set, which, in this case, indicates that Small Business Server was previously installed on this system. If this installation is further upgraded to Windows Server, Enterprise Edition, the VER_SUITE_SMALLBUSINESS flag remains set.

### `wProductType`

The product type. This member contains additional information about the system. This member can be one of the following values:

| Value | Meaning |
|---|---|
| VER_NT_WORKSTATION | Windows 2000 or later professional version |
| VER_NT_DOMAIN_CONTROLLER | Windows 2000 or later domain controller |
| VER_NT_SERVER | Windows 2000 or later server |

### `wReserved`

Reserved for future use.

## Remarks

The information in this structure includes the major and minor version numbers, the build number, the platform identifier, the installed product suites, and the latest service pack that is installed on the system. This structure is used with the [RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion) and [RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo) routines.

Relying on version information is not always the best way to test whether a feature is available. For guidance, refer to the documentation for the feature you are interested in.

If possible, design the version detection code in your driver to enable the driver to run on future versions of Windows. If your driver requires a particular operating system version, be sure to treat this version as the minimum supported version, and not as the only version on which the driver can run.

The following table summarizes the version information that is returned by supported versions of Windows. Use the information in the "Other" column or build number to distinguish between operating systems with identical version numbers.

| Operating system | Version number | dwMajorVersion | dwMinorVersion | Other |
|---|---|---|---|---|
| Windows 11 | 10.0 | 10 | 0 | **wProductType** == VER_NT_WORKSTATION |
| Windows Server 2022 | 10.0 | 10 | 0 | **wProductType** != VER_NT_WORKSTATION |
| Windows Server 2019 | 10.0 | 10 | 0 | **wProductType** != VER_NT_WORKSTATION |
| Windows 10 (all releases) | 10.0 | 10 | 0 | **wProductType** == VER_NT_WORKSTATION |
| Windows Server 2016 | 10.0 | 10 | 0 | **wProductType** != VER_NT_WORKSTATION |
| Windows Server 2012 R2 | 6.3 | 6 | 3 | **wProductType** != VER_NT_WORKSTATION |
| Windows 8.1 | 6.3 | 6 | 3 | **wProductType** == VER_NT_WORKSTATION |
| Windows 8 | 6.2 | 6 | 2 | **wProductType** == VER_NT_WORKSTATION |
| Windows Server 2012 | 6.2 | 6 | 2 | **wProductType** != VER_NT_WORKSTATION |
| Windows 7 | 6.1 | 6 | 1 | **wProductType** == VER_NT_WORKSTATION |
| Windows Server 2008 R2 | 6.1 | 6 | 1 | **wProductType** != VER_NT_WORKSTATION |
| Windows Server 2008 | 6.0 | 6 | 0 | **wProductType** != VER_NT_WORKSTATION |
| Windows Vista | 6.0 | 6 | 0 | **wProductType** == VER_NT_WORKSTATION |
| Windows Home Server | 5.2 | 5 | 2 | **wSuiteMask** == VER_SUITE_WH_SERVER |
| Windows Server 2003 | 5.2 | 5 | 2 | Not applicable |
| Windows XP Professional x64 Edition (see note) | 5.2 | 5 | 2 | **wProductType** == VER_NT_WORKSTATION |
| Windows XP | 5.1 | 5 | 1 | Not applicable |
| Windows 2000 | 5.0 | 5 | 0 | Not applicable |

Only a 64-bit kernel-mode driver can run on Windows XP Professional x64 Edition. Therefore, a 32-bit kernel-mode driver can safely omit checking for this version of Windows.

## See also

[**RTL_OSVERSIONINFOW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfow)

[RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)

[RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo)