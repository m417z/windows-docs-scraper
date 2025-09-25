# MINIDUMP_SYSTEM_INFO structure

## Description

Contains processor and operating system information.

## Members

### `ProcessorArchitecture`

The system's processor architecture. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROCESSOR_ARCHITECTURE_AMD64**<br><br>9 | x64 (AMD or Intel) |
| **PROCESSOR_ARCHITECTURE_ARM**<br><br>5 | ARM |
| **PROCESSOR_ARCHITECTURE_IA64**<br><br>6 | Intel Itanium |
| **PROCESSOR_ARCHITECTURE_INTEL**<br><br>0 | x86 |
| **PROCESSOR_ARCHITECTURE_UNKNOWN**<br><br>0xffff | Unknown processor. |

### `ProcessorLevel`

The system's architecture-dependent processor level.

If **ProcessorArchitecture** is
**PROCESSOR_ARCHITECTURE_INTEL**,
**ProcessorLevel** can be one of the following values.

| Value | Meaning |
| --- | --- |
| 3 | Intel 80386 |
| 4 | Intel 80486 |
| 5 | Intel Pentium |
| 6 | Intel Pentium Pro or Pentium II |

If **ProcessorArchitecture** is
**PROCESSOR_ARCHITECTURE_IA64**, **ProcessorLevel** is set to
1.

### `ProcessorRevision`

The architecture-dependent processor revision.

| Processor | Value |
| --- | --- |
| Intel 80386 or 80486 | A value of the form *xxyz*.<br><br>If *xx* is equal to 0xFF, *y* - 0xA is the model number, and *z* is the stepping identifier. For example, an Intel 80486-D0 system returns 0xFFD0.<br><br>If *xx* is not equal to 0xFF, *xx* + 'A' is the stepping letter and *yz* is the minor stepping. |
| Intel Pentium, Cyrix, or NextGen 586 | A value of the form *xxyy*, where *xx* is the model number and *yy* is the stepping. Display this value of 0x0201 as follows:<br><br>Model *xx*, Stepping *yy* |

### `Reserved0`

This member is reserved for future use and must be zero.

### `NumberOfProcessors`

The number of processors in the system.

### `ProductType`

Any additional information about the system. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_NT_DOMAIN_CONTROLLER**<br><br>0x0000002 | The system is a domain controller. |
| **VER_NT_SERVER**<br><br>0x0000003 | The system is a server. |
| **VER_NT_WORKSTATION**<br><br>0x0000001 | The system is running Windows XP, Windows Vista, Windows 7, or Windows 8. |

### `MajorVersion`

The major version number of the operating system. This member can be 4, 5, or 6.

### `MinorVersion`

The minor version number of the operating system.

### `BuildNumber`

The build number of the operating system.

### `PlatformId`

The operating system platform. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_PLATFORM_WIN32s**<br><br>0 | Not supported |
| **VER_PLATFORM_WIN32_WINDOWS**<br><br>1 | Not supported. |
| **VER_PLATFORM_WIN32_NT**<br><br>2 | The operating system platform is Windows. |

### `CSDVersionRva`

An RVA (from the beginning of the dump) to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) that describes the latest Service
Pack installed on the system. If no Service Pack has been installed, the string is empty.

### `Reserved1`

This member is reserved for future use.

### `SuiteMask`

The bit flags that identify the product suites available on the system. This member can be a combination
of the following values.

| Value | Meaning |
| --- | --- |
| **VER_SUITE_BACKOFFICE**<br><br>0x00000004 | Microsoft BackOffice components are installed. |
| **VER_SUITE_BLADE**<br><br>0x00000400 | Windows Server 2003, Web Edition is installed. |
| **VER_SUITE_COMPUTE_SERVER**<br><br>0x00004000 | Windows Server 2003, Compute Cluster Edition is installed. |
| **VER_SUITE_DATACENTER**<br><br>0x00000080 | Windows Server 2008 R2 Datacenter, Windows Server 2008 Datacenter, or Windows Server 2003, Datacenter Edition is installed. |
| **VER_SUITE_ENTERPRISE**<br><br>0x00000002 | Windows Server 2008 R2 Enterprise, Windows Server 2008 Enterprise, or Windows Server 2003, Enterprise Edition is installed. |
| **VER_SUITE_EMBEDDEDNT**<br><br>0x00000040 | Windows Embedded is installed. |
| **VER_SUITE_PERSONAL**<br><br>0x00000200 | Windows XP Home Edition is installed. |
| **VER_SUITE_SINGLEUSERTS**<br><br>0x00000100 | Remote Desktop is supported, but only one interactive session is supported. This value is set unless the system is running in application server mode. |
| **VER_SUITE_SMALLBUSINESS**<br><br>0x00000001 | Microsoft Small Business Server was once installed on the system, but may have been upgraded to another version of Windows. |
| **VER_SUITE_SMALLBUSINESS_RESTRICTED**<br><br>0x00000020 | Microsoft Small Business Server is installed with the restrictive client license in force. |
| **VER_SUITE_STORAGE_SERVER**<br><br>0x00002000 | Windows Storage Server is installed. |
| **VER_SUITE_TERMINAL**<br><br>0x00000010 | Terminal Services is installed. This value is always set.<br><br>If **VER_SUITE_TERMINAL** is set but **VER_SUITE_SINGLEUSERTS** is not set, the system is running in application server mode. |

### `Reserved2`

This member is reserved for future use.

### `Cpu`

#### X86CpuInfo

The CPU information obtained from the CPUID instruction. This structure is supported only for x86
computers.

##### VendorId

CPUID subfunction 0. The array elements are as follows:

##### VersionInformation

CPUID subfunction 1. Value of EAX.

##### FeatureInformation

CPUID subfunction 1. Value of EDX.

##### AMDExtendedCpuFeatures

CPUID subfunction 80000001. Value of EBX. This member is supported only if the vendor is
"AuthenticAMD".

#### OtherCpuInfo

Other CPU information. This structure is supported only for non-x86 computers.

##### ProcessorFeatures

For a list of possible values, see the
[IsProcessorFeaturePresent](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocessorfeaturepresent)
function.

## See also

[IsProcessorFeaturePresent](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocessorfeaturepresent)

[MINIDUMP_STREAM_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_stream_type)