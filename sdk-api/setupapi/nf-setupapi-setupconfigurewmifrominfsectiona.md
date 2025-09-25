# SetupConfigureWmiFromInfSectionA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupConfigureWmiFromInfSection** function configures the security of the WMI data that is exposed by an INF file when passed to the [DDInstall.WMI] section.

It is used to establish security when the version of SetupAPI on the system does not natively support the WMI security information provided in the DDInstall section of the INF file.

## Parameters

### `InfHandle` [in]

A handle to an open INF file.

### `SectionName` [in]

Name of the section in the INF file that contains WMI security information. This should be in the form of[DDinstall.WMI].

### `Flags` [in]

This parameter can be set as follows.

| Flag | Meaning |
| --- | --- |
| **SCWMI_CLOBBER_SECURITY**<br><br>0x0001 | If and only if this flag is set does the security information passed to this function override any security information set elsewhere in the INF file. If this flag does not exist and no security information exists in the INF file, the security is set. |

## Return value

This function returns WINSETUPAPI BOOL.

## Remarks

In previous SetupAPI versions, WMI information in INF files is exposed to all users, and access could only be limited by correctly writing binary data to a registry key. Current versions read and process WMI security information provided by the DDInstall section of an INF file.

> [!NOTE]
> The setupapi.h header defines SetupConfigureWmiFromInfSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[Specifying a Security Descriptor From an INF File](https://learn.microsoft.com/windows/desktop/SetupApi/specifying-a-security-descriptor-from-an-inf-file)