# SetupSetFileQueueAlternatePlatformW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupSetFileQueueAlternatePlatform** function associates the file queue with a target platform that is different from the platform running the function. This is done to enable for non-native signature verification.

## Parameters

### `QueueHandle` [in]

Handle to an open setup file queue.

### `AlternatePlatformInfo` [in]

Optional pointer to an [SP_ALTPLATFORM_INFO](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v1) structure passing information about the alternate platform. On Windows 2000, the **cbSize** member of this structure must be set to sizeof(SP_ALTPLATFORM_INFO_V1). On Windows Server 2003 or Windows XP, the **cbSize** member of this structure must be set to sizeof(SP_ALTPLATFORM_INFO_V2).

### `AlternateDefaultCatalogFile` [in]

Pointer to a **null**-terminated string that specifies a catalog that validates any INF files. This parameter may be **NULL**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SP_ALTPLATFORM_INFO_V1](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v1)

[SP_ALTPLATFORM_INFO_V2](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_altplatform_info_v2)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupSetFileQueueAlternatePlatform as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).