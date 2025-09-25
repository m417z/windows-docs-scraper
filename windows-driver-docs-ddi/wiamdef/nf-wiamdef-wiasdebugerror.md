# wiasDebugError function

## Description

The **wiasDebugError** function is obsolete.

Use the [WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error) macro instead.

**wiasDebugError** prints a debug error string in the Device Manager debug console. The output color is always red.

## Parameters

### `hInstance`

The handle of calling module.

### `pszFormat`

### `...`

####### - pszFormat, ...

Specifies a variable argument list, which starts with an ANSI format string containing the message and any format specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## See also

[WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error)

[WIAS_LERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lerror)