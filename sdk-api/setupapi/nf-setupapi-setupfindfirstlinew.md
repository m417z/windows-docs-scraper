# SetupFindFirstLineW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupFindFirstLine** function locates a line in the specified section of an INF file. If the *Key* parameter is **NULL**,
**SetupFindFirstLine** returns the first line of the section.

## Parameters

### `InfHandle` [in]

Handle to the INF file to query.

### `Section` [in]

Pointer to a **null**-terminated string specifying the section of the INF files to search in.

### `Key` [in]

Optional pointer to a **null**-terminated string specifying the key to search for within the section. The **null**-terminated string should not exceed the size of the destination buffer. This parameter can be **NULL**. If *Key* is **NULL**, the first line in the section is returned.

### `Context` [in, out]

Pointer to a structure that receives the context information used internally by the INF handle. Applications must not overwrite values in this structure.

## Return value

If the function could not find a line, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *InfHandle* parameter references multiple INF files that have been appended together using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea), the
**SetupFindFirstLine** function searches across the specified section in all of the files referenced by the specified HINF.

> [!NOTE]
> The setupapi.h header defines SetupFindFirstLine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline)

[SetupFindNextMatchLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextmatchlinea)

[SetupGetLineByIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinebyindexa)