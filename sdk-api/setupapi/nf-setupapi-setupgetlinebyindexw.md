# SetupGetLineByIndexW function

## Description

[This function is available for use in the operating systems indicated in the
Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used
for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI
continues to be used for installing device drivers.]

The **SetupGetLineByIndex** function locates a line by its index value in the
specified section in the INF file.

## Parameters

### `InfHandle` [in]

Handle to the INF file.

### `Section` [in]

Pointer to a null-terminated string specifying the section of the INF file to search.

### `Index` [in]

Index of the line to be located. The total number of lines in a particular section can be found with a
call to [SetupGetLineCount](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinecounta).

### `Context` [in, out]

Pointer to a variable that receives the context information for the found line.

## Return value

If the function succeeds, the return value is a nonzero value. If the function fails, the return value is
zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *InfHandle* references multiple INF files that have been appended together using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea), this function
searches across the specified section in all files referenced by the HINF to locate the indexed line.

> [!NOTE]
> The setupapi.h header defines SetupGetLineByIndex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupFindFirstLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindfirstlinea)

[SetupFindNextLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextline)

[SetupFindNextMatchLine](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupfindnextmatchlinea)