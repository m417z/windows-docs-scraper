# SetupFindNextMatchLineW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupFindNextMatchLine** function returns the location of the next line in an INF file relative to *ContextIn.Line* that matches a specified key.

## Parameters

### `ContextIn` [in]

Pointer to an INF file context, as retrieved by a call to the
[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea) function.

### `Key` [in]

If this optional parameter is specified, it supplies a key to match. This parameter should be a null-terminated string. This parameter can be Null. If *Key* is not specified, the
**SetupFindNextMatchLine** function is equivalent to the
[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline) function.

### `ContextOut` [in, out]

Pointer to a variable in which this function returns the context of the found line. *ContextOut* can point to *ContextIn* if the caller wishes.

## Return value

The function returns a nonzero value if it finds a matching line. Otherwise, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *ContextIn.Inf* references multiple INF files that have been appended together using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea), the
**SetupFindNextMatchLine** function searches across the specified section in all files referenced by the HINF to locate the next matching line.

> [!NOTE]
> The setupapi.h header defines SetupFindNextMatchLine as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea)

[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline)

[SetupGetLineByIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinebyindexa)