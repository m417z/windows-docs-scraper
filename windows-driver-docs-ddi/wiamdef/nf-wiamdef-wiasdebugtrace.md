# wiasDebugTrace function

## Description

The **wiasDebugTrace** function is obsolete. Use the [WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace) macro instead.

This function prints a debug trace string in the Device Manager debug console.

## Parameters

### `hInstance`

Te handle of calling module.

### `pszFormat`

### `...`

####### - pszFormat, ...

Specifies a variable argument list, which starts with an ANSI format string containing the message and any format specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

To enable tracing in free builds, drivers must define the WIAS_DEBUG macro. Tracing is enabled by default in checked and debug builds of the operating system.

## See also

[WIAS_LTRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_ltrace)

[WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace)