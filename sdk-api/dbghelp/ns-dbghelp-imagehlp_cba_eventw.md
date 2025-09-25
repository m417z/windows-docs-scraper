# IMAGEHLP_CBA_EVENTW structure

## Description

Contains information about a debugging event.

## Members

### `severity`

The event severity. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **sevInfo**<br><br>0 | Informational event. |
| **sevProblem**<br><br>1 | Reserved for future use. |
| **sevAttn**<br><br>2 | Reserved for future use. |
| **sevFatal**<br><br>3 | Reserved for future use. |

### `code`

This member is reserved for future use.

### `desc`

A text description of the error.

### `object`

This member is reserved for future use.

## See also

[SymRegisterCallbackProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbol_registered_callback)

[SymbolServerCallback](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psymbolservercallbackproc)

## Remarks

> [!NOTE]
> The dbghelp.h header defines IMAGEHLP_CBA_EVENT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).