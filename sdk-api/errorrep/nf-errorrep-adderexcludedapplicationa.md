# AddERExcludedApplicationA function

## Description

[The AddERExcludedApplication function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [WerAddExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-weraddexcludedapplication) function.]

Excludes the specified application from error reporting.

## Parameters

### `szApplication` [in]

The name of the executable file for the application, including the file name extension. The name cannot contain path information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, see
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function stores the excluded application list under the **HKEY_LOCAL_MACHINE** hive. The calling process must have permissions to write to this registry hive.

> [!NOTE]
> The errorrep.h header defines AddERExcludedApplication as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ReportFault](https://learn.microsoft.com/windows/desktop/api/errorrep/nf-errorrep-reportfault)

[WER Functions](https://learn.microsoft.com/windows/desktop/wer/wer-functions)

[Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer/windows-error-reporting)