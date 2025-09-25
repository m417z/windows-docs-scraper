# wiauDbgLegacyTrace function

## Description

The **wiauDbgLegacyTrace** function logs a trace message.

## Parameters

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

The **wiauDbgLegacyTrace** function is identical to the [wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace) function except that the latter has a parameter used to identify the function or method that is active when the function is called.

## See also

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)