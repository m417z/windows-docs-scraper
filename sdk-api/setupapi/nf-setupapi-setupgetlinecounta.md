# SetupGetLineCountA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetLineCount** function returns the number of lines in a specified section of an INF file.

## Parameters

### `InfHandle` [in]

Handle to the INF file.

### `Section` [in]

Pointer to a null-terminated string that specifies the section in which you want to count the lines.

## Return value

If *InfHandle* references multiple INF files that have been appended using
[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea), this function returns the sum of the lines in all of the INF files containing the specified section. A return value of 0 specifies an empty section. If the section does not exist, the function returns –1.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupGetLineCount as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).