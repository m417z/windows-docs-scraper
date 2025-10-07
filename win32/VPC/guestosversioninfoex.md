# GUESTOSVERSIONINFOEX structure

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Contains operating system version information for the guest operating system.

## Members

**dwOSVersionInfoSize**

The size of this data structure, in bytes. Set this member to `sizeof(GUESTOSVERSIONINFOEX)`.

**dwMajorVersion**

The major version number.

**dwMinorVersion**

The minor version number.

**dwBuildNumber**

The build number.

**dwPlatformId**

The operating system platform. This member can be **VER\_PLATFORM\_WIN32\_NT** (2).

**szCSDVersion**

A null-terminated string, such as "Service Pack 3", that indicates the latest Service Pack installed on the system. If no Service Pack has been installed, the string is empty.

**wServicePackMajor**

The major version number of the latest Service Pack installed.

**wServicePackMinor**

The minor version number of the latest Service Pack installed.

**wSuiteMask**

A bitmask that identifies the product suites available on the system. This member can be a combination of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **VER\_SUITE\_BACKOFFICE**

0x00000004 | Microsoft BackOffice components are installed.\ | | **VER\_SUITE\_BLADE**

0x00000400 | Windows Server 2003, Web Edition is installed.\ | | **VER\_SUITE\_COMPUTE\_SERVER**

0x00004000 | Windows Server 2003, Compute Cluster Edition is installed.\ | | **VER\_SUITE\_DATACENTER**

0x00000080 | Windows Server 2008 Datacenter, Windows Server 2003, Datacenter Edition, or Windows 2000 Datacenter Server is installed.\ | | **VER\_SUITE\_ENTERPRISE**

0x00000002 | Windows Server 2008 Enterprise, Windows Server 2003, Enterprise Edition, or Windows 2000 Advanced Server is installed. Refer to the Remarks section for more information about this bit flag.\ | | **VER\_SUITE\_EMBEDDEDNT**

0x00000040 | Windows XP Embedded is installed.\ | | **VER\_SUITE\_PERSONAL**

0x00000200 | Windows Vista Home Premium, Windows Vista Home Basic, or Windows XP Home Edition is installed.\ | | **VER\_SUITE\_SINGLEUSERTS**

0x00000100 | Remote Desktop is supported, but only one interactive session is supported. This value is set unless the system is running in application server mode.\ | | **VER\_SUITE\_SMALLBUSINESS**

0x00000001 | Microsoft Small Business Server was once installed on the system, but may have been upgraded to another version of Windows. Refer to the Remarks section for more information about this bit flag.\ | | **VER\_SUITE\_SMALLBUSINESS\_RESTRICTED**

0x00000020 | Microsoft Small Business Server is installed with the restrictive client license in force. Refer to the Remarks section for more information about this bit flag.\ | | **VER\_SUITE\_STORAGE\_SERVER**

0x00002000 | Windows Storage Server 2003 R2 or Windows Storage Server 2003is installed.\ | | **VER\_SUITE\_TERMINAL**

0x00000010 | Terminal Services is installed. This value is always set.\ If **VER\_SUITE\_TERMINAL** is set but **VER\_SUITE\_SINGLEUSERTS** is not set, the system is running in application server mode.\ | | **VER\_SUITE\_WH\_SERVER**

0x00008000 | Windows Home Server is installed.\ |

**wProductType**

Any additional information about the system. This member can be one of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **VER\_NT\_DOMAIN\_CONTROLLER**

0x0000002 | The system is a domain controller and the operating system is Windows Server 2008 R2, Windows Server 2008, Windows Server 2003 R2, Windows Server 2003, or Windows 2000 Server.\ | | **VER\_NT\_SERVER**

0x0000003 | The operating system is Windows Server 2008 R2, Windows Server 2008, Windows Server 2003 R2, Windows Server 2003, or Windows 2000 Server.\ Note that a server that is also a domain controller is reported as **VER\_NT\_DOMAIN\_CONTROLLER**, not **VER\_NT\_SERVER**.\ | | **VER\_NT\_WORKSTATION**

0x0000001 | The operating system is Windows 7, Windows Vista, Windows XP, or Windows 2000 Professional.\ |

**wReserved**

Reserved for future use.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMGuestOS::GetOsVersionInfo**](https://learn.microsoft.com/windows/win32/vpc/ivmguestos-getosversioninfo)

