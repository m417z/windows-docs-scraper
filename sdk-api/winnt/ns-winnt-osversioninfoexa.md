# OSVERSIONINFOEXA structure

## Description

Contains operating system version information. The information includes major and minor version
numbers, a build number, a platform identifier, and information about product suites and the latest Service Pack
installed on the system. This structure is used with the
[GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) and
[VerifyVersionInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-verifyversioninfoa) functions.

## Members

### `dwOSVersionInfoSize`

The size of this data structure, in bytes. Set this member to
`sizeof(OSVERSIONINFOEX)`.

### `dwMajorVersion`

The major version number of the operating system. For more information, see Remarks.

### `dwMinorVersion`

The minor version number of the operating system. For more information, see Remarks.

### `dwBuildNumber`

The build number of the operating system.

### `dwPlatformId`

The operating system platform. This member can be **VER_PLATFORM_WIN32_NT** (2).

### `szCSDVersion`

A null-terminated string, such as "Service Pack 3", that indicates the latest Service Pack
installed on the system. If no Service Pack has been installed, the string is empty.

### `wServicePackMajor`

The major version number of the latest Service Pack installed on the system. For example, for Service Pack
3, the major version number is 3. If no Service Pack has been installed, the value is zero.

### `wServicePackMinor`

The minor version number of the latest Service Pack installed on the system. For example, for Service Pack
3, the minor version number is 0.

### `wSuiteMask`

A bit mask that identifies the product suites available on the system. This member can be a combination of
the following values.

| Value | Meaning |
| --- | --- |
| **VER_SUITE_BACKOFFICE**<br><br>0x00000004 | Microsoft BackOffice components are installed. |
| **VER_SUITE_BLADE**<br><br>0x00000400 | Windows Server 2003, Web Edition is installed. |
| **VER_SUITE_COMPUTE_SERVER**<br><br>0x00004000 | Windows Server 2003, Compute Cluster Edition is installed. |
| **VER_SUITE_DATACENTER**<br><br>0x00000080 | Windows Server 2008 Datacenter, Windows Server 2003, Datacenter Edition, or Windows 2000 Datacenter Server is installed. |
| **VER_SUITE_ENTERPRISE**<br><br>0x00000002 | Windows Server 2008 Enterprise, Windows Server 2003, Enterprise Edition, or Windows 2000 Advanced Server is installed. Refer to the Remarks section for more information about this bit flag. |
| **VER_SUITE_EMBEDDEDNT**<br><br>0x00000040 | Windows XP Embedded is installed. |
| **VER_SUITE_PERSONAL**<br><br>0x00000200 | Windows Vista Home Premium, Windows Vista Home Basic, or Windows XP Home Edition is installed. |
| **VER_SUITE_SINGLEUSERTS**<br><br>0x00000100 | Remote Desktop is supported, but only one interactive session is supported. This value is set unless the system is running in application server mode. |
| **VER_SUITE_SMALLBUSINESS**<br><br>0x00000001 | Microsoft Small Business Server was once installed on the system, but may have been upgraded to another version of Windows. Refer to the Remarks section for more information about this bit flag. |
| **VER_SUITE_SMALLBUSINESS_RESTRICTED**<br><br>0x00000020 | Microsoft Small Business Server is installed with the restrictive client license in force. Refer to the Remarks section for more information about this bit flag. |
| **VER_SUITE_STORAGE_SERVER**<br><br>0x00002000 | Windows Storage Server 2003 R2 or Windows Storage Server 2003is installed. |
| **VER_SUITE_TERMINAL**<br><br>0x00000010 | Terminal Services is installed. This value is always set.<br><br>If **VER_SUITE_TERMINAL** is set but **VER_SUITE_SINGLEUSERTS** is not set, the system is running in application server mode. |
| **VER_SUITE_WH_SERVER**<br><br>0x00008000 | Windows Home Server is installed. |
| **VER_SUITE_MULTIUSERTS**<br><br>0x00020000 | AppServer mode is enabled. |

### `wProductType`

Any additional information about the system. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_NT_DOMAIN_CONTROLLER**<br><br>0x0000002 | The system is a domain controller and the operating system is Windows Server 2012 , Windows Server 2008 R2, Windows Server 2008, Windows Server 2003, or Windows 2000 Server. |
| **VER_NT_SERVER**<br><br>0x0000003 | The operating system is Windows Server 2012, Windows Server 2008 R2, Windows Server 2008, Windows Server 2003, or Windows 2000 Server.<br><br>Note that a server that is also a domain controller is reported as **VER_NT_DOMAIN_CONTROLLER**, not **VER_NT_SERVER**. |
| **VER_NT_WORKSTATION**<br><br>0x0000001 | The operating system is Windows 8, Windows 7, Windows Vista, Windows XP Professional, Windows XP Home Edition, or Windows 2000 Professional. |

### `wReserved`

Reserved for future use.

## Remarks

Relying on version information is not the best way to test for a feature. Instead, refer to the documentation
for the feature of interest. For more information on common techniques for feature detection, see
[Operating System Version](https://learn.microsoft.com/windows/desktop/SysInfo/operating-system-version).

If you must require a particular operating system, be sure to use it as a minimum supported version, rather
than design the test for the one operating system. This way, your detection code will continue to work on future
versions of Windows.

The following table summarizes the values returned by supported versions of Windows. Use the information in the column labeled "Other" to distinguish between operating systems with identical version numbers.

| Operating system | Version number | **dwMajorVersion** | **dwMinorVersion** | Other |
| --- | --- | --- | --- | --- |
| Windows 10 | 10.0* | 10 | 0 | OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION |
| Windows Server 2016 | 10.0* | 10 | 0 | OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION |
| Windows 8.1 | 6.3* | 6 | 3 | OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION |
| Windows Server 2012 R2 | 6.3* | 6 | 3 | OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION |
| Windows 8 | 6.2 | 6 | 2 | OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION |
| Windows Server 2012 | 6.2 | 6 | 2 | OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION |
| Windows 7 | 6.1 | 6 | 1 | OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION |
| Windows Server 2008 R2 | 6.1 | 6 | 1 | OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION |
| Windows Server 2008 | 6.0 | 6 | 0 | OSVERSIONINFOEX.wProductType != VER_NT_WORKSTATION |
| Windows Vista | 6.0 | 6 | 0 | OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION |
| Windows Server 2003 R2 | 5.2 | 5 | 2 | GetSystemMetrics(SM_SERVERR2) != 0 |
| Windows Home Server | 5.2 | 5 | 2 | OSVERSIONINFOEX.wSuiteMask & VER_SUITE_WH_SERVER |
| Windows Server 2003 | 5.2 | 5 | 2 | GetSystemMetrics(SM_SERVERR2) == 0 |
| Windows XP Professional x64 Edition | 5.2 | 5 | 2 | (OSVERSIONINFOEX.wProductType == VER_NT_WORKSTATION) && (SYSTEM_INFO.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64) |
| Windows XP | 5.1 | 5 | 1 | Not applicable |
| Windows 2000 | 5.0 | 5 | 0 | Not applicable |
| ***** For applications that have been manifested for Windows 8.1 or Windows 10. Applications not manifested for Windows 8.1 or Windows 10 will return the Windows 8 OS version value (6.2). To manifest your applications for Windows 8.1 or Windows 10, refer to [Targeting your application for Windows](https://learn.microsoft.com/windows/desktop/SysInfo/targeting-your-application-at-windows-8-1). | | | | |

You should not rely upon only the **VER_SUITE_SMALLBUSINESS** flag to determine
whether Small Business Server has been installed on the system, as both this flag and the
**VER_SUITE_SMALLBUSINESS_RESTRICTED** flag are set when this product suite is installed. If
you upgrade this installation to Windows Server, Standard Edition, the
**VER_SUITE_SMALLBUSINESS_RESTRICTED** flag will be cleared—however, the
**VER_SUITE_SMALLBUSINESS flag** will remain set. In this case, this indicates that Small
Business Server was once installed on this system. If this installation is further upgraded to Windows Server,
Enterprise Edition, the **VER_SUITE_SMALLBUSINESS** flag will remain set.

If compatibility mode is in effect, the **OSVERSIONINFOEX** structure contains information about the operating system that is selected for [application compatibility](https://learn.microsoft.com/previous-versions/bb757005(v=msdn.10)).

To determine whether a Win32-based application is running on WOW64, call the
[IsWow64Process](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process) function. To determine whether the system is running a 64-bit version of Windows, call the [GetNativeSystemInfo](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo) function.

The [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function provides the
following additional information about the current operating system.

| Product | Setting |
| --- | --- |
| Windows Server 2003 R2 | **SM_SERVERR2** |
| Windows XP Media Center Edition | **SM_MEDIACENTER** |
| Windows XP Starter Edition | **SM_STARTER** |
| Windows XP Tablet PC Edition | **SM_TABLETPC** |

#### Examples

For an example, see
[Getting the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/getting-the-system-version).

> [!NOTE]
> The winnt.h header defines OSVERSIONINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IsWow64Process](https://learn.microsoft.com/windows/desktop/api/wow64apiset/nf-wow64apiset-iswow64process)

[OSVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa)

[Version Helper APIs](https://learn.microsoft.com/windows/desktop/SysInfo/version-helper-apis)