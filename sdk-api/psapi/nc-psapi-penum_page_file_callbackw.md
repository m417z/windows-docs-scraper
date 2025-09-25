# PENUM_PAGE_FILE_CALLBACKW callback function

## Description

An application-defined callback function used with the
[EnumPageFiles](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumpagefilesw) function.

The **PENUM_PAGE_FILE_CALLBACK** type defines a pointer to this callback function.
**EnumPageFilesProc** is a placeholder for the application-defined function name.

## Parameters

### `pContext` [in]

The user-defined data passed from
[EnumPageFiles](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumpagefilesw).

### `pPageFileInfo` [in]

A pointer to an
[ENUM_PAGE_FILE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-enum_page_file_information) structure.

### `lpFilename` [in]

The name of the pagefile.

## Return value

To continue enumeration, the callback function must return TRUE.

To stop enumeration, the callback function must return FALSE.

## See also

[ENUM_PAGE_FILE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-enum_page_file_information)

[EnumPageFiles](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumpagefilesw)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)

## Remarks

> [!NOTE]
> The psapi.h header defines PENUM_PAGE_FILE_CALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).