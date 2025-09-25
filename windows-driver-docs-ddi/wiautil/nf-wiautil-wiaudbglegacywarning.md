# wiauDbgLegacyWarning function

## Description

The **wiauDbgLegacyWarning** function logs a warning message.

## Parameters

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

The **wiauDbgLegacyWarning** function is identical to the [wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning) function except that the latter has a parameter used to identify the function or method that is active when the function is called.

## See also

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)