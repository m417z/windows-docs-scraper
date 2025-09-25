# SetupQueryInfOriginalFileInformationA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueryInfOriginalFileInformation** function returns the original name of an OEM INF file.

## Parameters

### `InfInformation` [in]

Pointer to an
[SP_INF_INFORMATION](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_inf_information) structure returned from a call to the
[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa) function.

### `InfIndex` [in]

Index of the constituent INF file name to retrieve. This index can be in the range [0, *InfInformation.InfCount*). Meaning that the values zero through, but not including, *InfInformation.InfCount* are valid.

### `AlternatePlatformInfo` [in]

Optional pointer to an
[SP_ALTPLATFORM_INFO_V1](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v1) or [SP_ALTPLATFORM_INFO_V2](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v2) structure used to pass information for an alternate platform to
**SetupQueryInfOriginalFileInformation**.

### `OriginalFileInfo` [out]

Pointer to an
[SP_ORIGINAL_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_original_file_info_a) structure that receives the original INF file name and catalog file information returned by
**SetupQueryInfOriginalFileInformation**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupQueryInfOriginalFileInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).