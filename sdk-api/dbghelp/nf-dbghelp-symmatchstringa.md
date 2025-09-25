# SymMatchStringA function

## Description

Compares the specified string to the specified wildcard expression.

## Parameters

### `string` [in]

The string, such as a symbol name, to be compared to the *expression* parameter.

### `expression` [in]

The wildcard expression to compare to the *string* parameter. The wildcard expression supports the inclusion of the * and ? characters. * matches any string and ? matches any single character.

### `fCase` [in]

A variable that indicates whether or not the comparison is to be case sensitive.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

> [!NOTE]
> The dbghelp.h header defines SymMatchString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)