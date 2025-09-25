# IMAGEHLP_CBA_EVENT structure

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