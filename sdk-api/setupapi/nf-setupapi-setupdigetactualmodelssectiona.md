# SetupDiGetActualModelsSectionA function

## Description

The **SetupDiGetActualModelsSection** function retrieves the appropriate decorated [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section) to use when installing a device from a device INF file.

## Parameters

### `Context` [in]

A pointer to an INF file context that specifies a *manufacturer-identifier* entry in an [INF Manufacturer section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-manufacturer-section) of an INF file. The *manufacturer-identifier* entry specifies an INF *Models* section name and optionally specifies *TargetOSVersion* decorations for the *Models* section name. For information about INF files and an INF file context, see the Platform SDK topics on [using INF files](https://learn.microsoft.com/windows/win32/setupapi/using-inf-files) and the [INFCONTEXT structure](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-infcontext).

### `AlternatePlatformInfo` [in, optional]

A pointer to an [SP_ALTPLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_altplatform_info_v2) structure that supplies information about a Windows version and processor architecture. The **cbSize** member of this structure must be set to **sizeof(**SP_ALTPLATFORM_INFO_V2**)**. This parameter is optional and can be set to **NULL**.

### `InfSectionWithExt` [out, optional]

A pointer to a buffer that receives a string that contains the decorated INF *Models* section name and a NULL terminator. If *AlternatePlatformInfo* is not supplied, the decorated INF *Models* section name applies to the current platform; otherwise the name applies to the specified alternative platform. This parameter is optional and can be set to **NULL**. If this parameter is **NULL**, the function returns **TRUE** and sets *RequiredSize* to the size, in characters, that is required to return the decorated *Models* section name and a terminating NULL character.

### `InfSectionWithExtSize` [in]

 The size, in characters, of the *DecoratedModelsSection*  buffer. If *DecoratedModelsSection* is **NULL**, this parameter must be set to zero.

### `RequiredSize` [out, optional]

A pointer to a DWORD-type variable that receives the size, in characters, of the *DecoratedModelsSection* buffer that is required to retrieve the decorated *Models* section name and a terminating NULL character. This parameter is optional and can be set to **NULL**.

### `Reserved`

Reserved for internal system use. This parameter must be set to **NULL**.

## Return value

**SetupDiGetActualModelsSection** returns **TRUE** if the operation succeeds. Otherwise, the function returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiGetActualModelsSection** determines which *TargetOSVersion* fields in the *manufacturer-identifier* entry (supplied by *Context*) apply to the current platform, if *AlternatePlatformInfo* is not supplied, or to an alternative platform, if alternative platform information is supplied. **SetupDiGetActualModelsSection** selects the most appropriate platform based on all the *TargetOSVersion* fields, appends the *TargetOSVersion* string to the INF *Models* section name, and returns the decorated INF *Models* section name to the caller. In a *manufacturer-identifier* entry, the operating system major version is specified by the *OSMajorVersion* field and the operating system minor version is specified by the *OSMinorVersion* field.

For information about retrieving an [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) for a device, see [SetupDiGetActualSectionToInstall](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetactualsectiontoinstalla).

> [!NOTE]
> The setupapi.h header defines SetupDiGetActualModelsSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INF DDInstall Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section)

[SP_ALTPLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_altplatform_info_v2)

[SetupDiGetActualSectionToInstall](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetactualsectiontoinstalla)