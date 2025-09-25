# wiauDbgLegacyError function

## Description

The **wiauDbgLegacyError** function logs an error message.

## Parameters

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

The **wiauDbgLegacyError** function is identical to the [wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror) function except that the latter function has an additional parameter used to identify the function or method that is active when the function is called.

## See also

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)