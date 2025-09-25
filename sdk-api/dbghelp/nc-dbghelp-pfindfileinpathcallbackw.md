## Description

An application-defined callback function used with the
[SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath) function.

The **PFINDFILEINPATHCALLBACK** and **PFINDFILEINPATHCALLBACKW** types define a pointer to this callback function.
**SymFindFileInPathProc** is a placeholder for the application-defined function name.

## Parameters

### `fileName` [in]

The name of the file located by [SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath).

### `context` [in]

The user-defined value specified in
[SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath), or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides some context for the callback function.

## Return value

Return **TRUE** to continue searching.

Return **FALSE** to end the search.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath)

## Remarks

> [!NOTE]
> The dbghelp.h header defines PFINDFILEINPATHCALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).