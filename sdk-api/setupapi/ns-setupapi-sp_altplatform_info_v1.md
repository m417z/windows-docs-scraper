# SP_ALTPLATFORM_INFO_V1 structure

## Description

This structure is used to pass information for an alternate platform to
[SetupQueryInfOriginalFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinforiginalfileinformationa).

Setup implicitly uses the **SP_ALTPLATFORM_INFO_V1** structure if USE_SP_ALTPLATFORM_INFO_V1 is set to 1 or if _WIN32_WINNT is less than or equal to 0x500. This version is for use with Windows 2000.

Setup implicitly uses the [SP_ALTPLATFORM_INFO_V2](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v2) structure if USE_SP_ALTPLATFORM_INFO_V1 is 0 or undefined and _WIN32_WINNT is set to 0x501.

## Members

### `cbSize`

Size of this structure, in bytes.

### `Platform`

Operating system. This must be one of the following values.

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

### `Reserved`

Must be set to zero.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SP_ALTPLATFORM_INFO_V2](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v2)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)