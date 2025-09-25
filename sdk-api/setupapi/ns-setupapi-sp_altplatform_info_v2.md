# SP_ALTPLATFORM_INFO_V2 structure

## Description

The **SP_ALTPLATFORM_INFO_V2** structure is used to pass information for an alternate platform to
[SetupQueryInfOriginalFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinforiginalfileinformationa).

Setup uses the **SP_ALTPLATFORM_INFO_V2** structure if USE_SP_ALTPLATFORM_INFO_V1 is 0 or undefined and _WIN32_WINNT is set to 0x501. **FirstValidatedMajorVersion** and **FirstValidatedMinorVersion** are only available with **SP_ALTPLATFORM_INFO_V2** and for use with Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP.

Setup uses the [SP_ALTPLATFORM_INFO_V1](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v1) structure if USE_SP_ALTPLATFORM_INFO_V1 is set to 1 or if _WIN32_WINNT is less than or equal to 0x500. **FirstValidatedMajorVersion** and **FirstValidatedMinorVersion** are not available with **SP_ALTPLATFORM_INFO_V1**.

## Members

### `cbSize`

Size of this structure, in bytes.

### `Platform`

Operating system. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **VER_PLATFORM_WIN32_WINDOWS** | Legacy operating systems. |
| **VER_PLATFORM_WIN32_NT** | Windows Server 2008, Windows Vista, Windows Server 2003, Windows XP, or Windows 2000. |

### `MajorVersion`

Major version of the operating system.

### `MinorVersion`

Minor version of the operating system.

### `ProcessorArchitecture`

Processor architecture. This must be PROCESSOR_ARCHITECTURE_INTEL, PROCESSOR_ARCHITECTURE_ALPHA, PROCESSOR_ARCHITECTURE_IA64, PROCESSOR_ARCHITECTURE_ALPHA64.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Reserved`

### `DUMMYUNIONNAME.Flags`

 For Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP, this member must be set to SP_ALTPLATFORM_FLAGS_VERSION_RANGE to use **FirstValidatedMajorVersion** and **FirstValidatedMinorVersion**. This member must be set to zero for Windows 2000.

### `FirstValidatedMajorVersion`

Major version of the oldest previous operating system for which this package's digital signature is valid. For example, if the alternate platform is VER_PLATFORM_WIN32_NT, version 5.1, and you want a driver package signed with a 5.0 osattr to also be valid, set MajorVersion to 5, MinorVersion to 1, **FirstValidatedMajorVersion** to 5, and **FirstValidatedMinorVersion** 0. To validate packages signed for any previous operating system, specify 0 for these fields. To only validate against the target alternate platform, specify the same values as those in the MajorVersion and MinorVersion fields. Available with Windows XP or later only. The Flags member must be set to SP_ALTPLATFORM_FLAGS_VERSION_RANGE to use **FirstValidatedMajorVersion**.

### `FirstValidatedMinorVersion`

Minor version of the oldest previous operating system for which this package's digital signature is valid. For information see **FirstValidatedMajorVersion**. Available with Windows Server 2003 or Windows XP. The **Flags** member must be set to SP_ALTPLATFORM_FLAGS_VERSION_RANGE to use **FirstValidatedMinorVersion**.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SP_ALTPLATFORM_INFO_V1](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v1)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)