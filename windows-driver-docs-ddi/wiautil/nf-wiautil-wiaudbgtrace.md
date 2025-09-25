# wiauDbgTrace function

## Description

The **wiauDbgTrace** function logs a trace message.

## Parameters

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgTrace** is inserted.

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the trace message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## See also

[wiauDbgDump](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgdump)

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)