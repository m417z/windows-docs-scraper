# SetupFindNextLine function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupFindNextLine** returns the location of the next line in an INF file section relative to *ContextIn.Line*.

## Parameters

### `ContextIn` [in]

Pointer to the INF file context retrieved by a call to the
[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea) function.

### `ContextOut` [out]

Pointer to a variable in which this function returns the context of the found line. *ContextOut* can point to *ContextIn* if the caller wishes.

## Return value

If this function finds the next line, the return value is a nonzero value. Otherwise, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *ContextIn.Line* references multiple INF files that have been appended together using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea), this function searches across the specified section in all files referenced by the HINF to locate the next line.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea)

[SetupFindNextMatchLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextmatchlinea)

[SetupGetLineByIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinebyindexa)