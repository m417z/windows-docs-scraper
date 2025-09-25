# PENUMSOURCEFILETOKENSCALLBACK callback function

## Description

An application-defined callback function used with the
[SymEnumSourceFileTokens](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiletokens) function which enumerates the [source server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) version control information stored in the PDB for a module.

The **PENUMSOURCEFILETOKENSCALLBACK** type defines a pointer to this callback function.
**SymEnumSourceFileTokensProc** is a placeholder for the application-defined function name.

## Parameters

### `token` [in]

A pointer to an opaque data structure that contains the version control information corresponding to a particular individual source file. The usage of this token is detailed below.

### `size` [in]

The size of the data in the *token* parameter.

## Return value

If the function returns **TRUE**, the enumeration will continue.

If the function returns **FALSE**, the enumeration will stop.

## Remarks

An application can use this token to extract a source file from version control by calling [SymGetSourceFileFromToken](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsourcefilefromtoken).

To get individual variables from the token, call [SymGetSourceVarFromToken](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsourcevarfromtoken). The names of the variables differ based on the scripts used to create the tokens. See [Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) for details.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing)

[SymEnumSourceFileTokens](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiletokens)

[SymGetSourceFile](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsourcefile)

[SymGetSourceFileFromToken](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symgetsourcefilefromtoken)