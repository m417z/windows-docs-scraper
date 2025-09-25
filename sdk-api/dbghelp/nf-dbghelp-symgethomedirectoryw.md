# SymGetHomeDirectoryW function

## Description

Retrieves the home directory used by Dbghelp.

## Parameters

### `type` [in]

The directory to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **hdBase**<br><br>0 | The home directory. |
| **hdSrc**<br><br>2 | The source directory. |
| **hdSym**<br><br>1 | The symbol directory. |

### `dir` [out]

A pointer to a string that receives the directory.

### `size` [in]

The size of the output buffer, in characters.

## Return value

If the function succeeds, the return value is a pointer to the *dir* parameter.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymGetHomeDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymSetHomeDirectory](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsethomedirectory)