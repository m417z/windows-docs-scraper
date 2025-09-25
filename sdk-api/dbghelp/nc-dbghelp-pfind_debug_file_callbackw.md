# PFIND_DEBUG_FILE_CALLBACKW callback function

## Description

An application-defined callback function used with the
[FindDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-finddebuginfofileex) function. It verifies whether the symbol file located by
**FindDebugInfoFileEx** is the correct symbol file.

The **PFIND_DEBUG_FILE_CALLBACK** and **PFIND_DEBUG_FILE_CALLBACKW** types define a pointer to this callback function.
**FindDebugInfoFileProc** is a placeholder for the application-defined function name.

## Parameters

### `FileHandle` [in]

A handle to the symbol file.

### `FileName` [in]

The name of the symbol file.

### `CallerData` [in]

Optional user-defined data. This parameter can be **NULL**.

## Return value

If the symbol file is valid, return **TRUE**. Otherwise, return **FALSE**.

## Remarks

One way to verify the symbol file is to compare its timestamp to the timestamp in the image. To retrieve the timestamp of the image, use the
[GetTimestampForLoadedLibrary](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-gettimestampforloadedlibrary) function. To retrieve the timestamp of the symbol file, use the
[SymGetModuleInfo64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmoduleinfo) function.

> [!NOTE]
> The dbghelp.h header defines PFIND_DEBUG_FILE_CALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindDebugInfoFileEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-finddebuginfofileex)

[GetTimestampForLoadedLibrary](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-gettimestampforloadedlibrary)

[SymGetModuleInfo64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetmoduleinfo)