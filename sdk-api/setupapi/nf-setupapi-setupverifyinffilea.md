# SetupVerifyInfFileA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetupVerifyInfFile** function verifies the digital signature of the specified INF file by using its corresponding catalog. The verification can be performed against an alternate platform.

## Parameters

### `InfName` [in]

The name of the INF file to be verified. This name may include a path.

### `AltPlatformInfo` [in]

An optional pointer to a
[SP_ALTPLATFORM_INFO_V2](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v2) structure that contains information about the alternate platform to use when validating the INF file. This parameter can be Null.

### `InfSignerInfo` [out]

A pointer to an [SP_INF_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_signer_info_v1_a) structure that receives information about the INF digital signature, that is, if it is signed.

## Return value

This function returns WINSETUPAPI BOOL.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupVerifyInfFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).