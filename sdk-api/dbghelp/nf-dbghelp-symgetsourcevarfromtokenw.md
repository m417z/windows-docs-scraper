# SymGetSourceVarFromTokenW function

## Description

Retrieves the value associated with the specified variable name from the [Source Server](https://learn.microsoft.com/windows/desktop/Debug/source-server-and-source-indexing) token.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Token` [in]

A pointer to the token.

### `Params` [in, optional]

This parameter is unused.

### `VarName` [in]

The name of the variable token whose value you want to retrieve.

### `Value` [out]

A pointer to a
buffer that receives the value associated with the variable token specified in the *VarName* parameter.

### `Size` [in]

The size of the *Value* buffer, in characters.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymGetSourceVarFromToken as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).