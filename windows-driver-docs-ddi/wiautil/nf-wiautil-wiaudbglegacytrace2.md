# wiauDbgLegacyTrace2 function

## Description

The **wiauDbgLegacyTrace2** function logs a trace message.

## Parameters

### `hInstance`

Specifies the handle to the DLL instance.

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

The **wiauDbgLegacyTrace2** function is identical to the [wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace) function except that the former has a parameter that specifies the handle to the DLL instance and the latter has a parameter used to identify the function or method that is active when the function is called.

## See also

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)