## Description

An application-defined callback function used with the
[SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath) function.

The **PFINDFILEINPATHCALLBACK** and **PFINDFILEINPATHCALLBACKW** types define a pointer to this callback function.
**SymFindFileInPathProc** is a placeholder for the application-defined function name.

## Parameters

### `filename` [in]

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