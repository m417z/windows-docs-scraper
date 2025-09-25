# SymGetSymbolFile function

## Description

Locates a symbol file in the specified symbol path.

## Parameters

### `hProcess` [in, optional]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

If this handle is 0, *SymPath* cannot be **NULL**. Use this option to load a symbol file without calling [SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymCleanup](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symcleanup).

### `SymPath` [in, optional]

The symbol path. If this parameter is **NULL** or an empty string, the function uses the symbol path set using the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

### `ImageFile` [in]

The name of the image file.

### `Type` [in]

The type of symbol file. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **sfImage**<br><br>0 | A .exe or .dll file. |
| **sfDbg**<br><br>1 | A .dbg file. |
| **sfPdb**<br><br>2 | A .pdb file. |
| **sfMpd**<br><br>3 | Reserved. |

### `SymbolFile` [out]

A pointer to a null-terminated string that receives the name of the symbol file.

### `cSymbolFile` [in]

The size of the *SymbolFile* buffer, in characters.

### `DbgFile` [out]

A pointer to a buffer that receives the fully qualified path to the symbol file. This buffer must be at least MAX_PATH characters.

### `cDbgFile` [in]

The size of the *DbgFile* buffer, in characters.

## Return value

If the server locates a valid symbol file, it returns **TRUE**; otherwise, it returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns a value that indicates why the symbol file was not returned.

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)