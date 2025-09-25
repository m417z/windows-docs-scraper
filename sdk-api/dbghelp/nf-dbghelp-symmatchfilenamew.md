# SymMatchFileNameW function

## Description

Compares a string to a file name and path.

## Parameters

### `FileName` [in]

The file name to be compared to the *Match* parameter.

### `Match` [in]

The string to be compared to the *FileName* parameter.

### `FileNameStop` [out, optional]

A pointer to a string buffer that receives a pointer to the location in *FileName* where matching stopped. For a complete match, this value can be one character before *FileName*. This value can also be **NULL**.

### `MatchStop` [out, optional]

A pointer to a string buffer that receives a pointer to the location in *Match* where matching stopped. For a complete match, this value may be one character before *Match*. This value may be **NULL**.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because the match string can be a suffix of the complete file name, this function can be used to match a plain file name to a fully qualified file name.

Matching begins from the end of both strings and proceeds backward. Matching is case-insensitive and equates a backslash (\\) with a forward slash (/).

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymMatchFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)