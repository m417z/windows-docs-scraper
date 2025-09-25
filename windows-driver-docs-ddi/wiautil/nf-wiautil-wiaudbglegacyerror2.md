# wiauDbgLegacyError2 function

## Description

The **wiauDbgLegacyError2** function logs an error message.

## Parameters

### `hInstance`

Specifies the handle to the DLL instance.

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers.

## Remarks

The **wiauDbgLegacyError2** function is identical to the [wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror) function except that the former has a parameter that specifies the handle to the DLL instance and the latter has a parameter used to identify the function or method that is active when the function is called.

## See also

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)