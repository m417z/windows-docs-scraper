# PENUMDIRTREE_CALLBACKW callback function

## Description

An application-defined callback function used with the
[EnumDirTree](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumdirtree) function. It is called every time a match is found.

The **PENUMDIRTREE_CALLBACK** and **PENUMDIRTREE_CALLBACKW** types define a pointer to this callback function.
*EnumDirTreeProc* is a placeholder for the application-defined function name.

## Parameters

### `FilePath` [in]

A pointer to a buffer that receives the full path of the file that is found.

### `CallerData` [in, optional]

A user-defined value specified in
[EnumDirTree](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumdirtree), or **NULL**. Typically, this parameter is used by an application to pass a pointer to a data structure that enables the callback function to establish some context.

## Return value

To continue enumeration, the callback function must return **FALSE**.

To stop enumeration, the callback function must return **TRUE**.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[EnumDirTree](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-enumdirtree)

## Remarks

> [!NOTE]
> The dbghelp.h header defines PENUMDIRTREE_CALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).