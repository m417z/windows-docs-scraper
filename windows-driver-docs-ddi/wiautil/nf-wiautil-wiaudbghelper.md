# wiauDbgHelper macro

## Description

The **wiauDbgHelper** function formats a message and writes it to a log file, or debugger, or both.

## Parameters

### `a`

### `b`

### `c`

### `d`

- **fmt [in]** - Pointer to a string that controls how an item or items in a variable argument list is to be formatted.

- **fname [in]** - Pointer to a string containing the name of the function or method into which the call to **wiauDbgHelper** is inserted.

- **marker** - Marks the beginning of a variable argument list.

- **prefix [in]** - Pointer to a string containing a prefix (such as "ERROR " or "WARN ") associated with the message.

## Remarks

The **wiauDbgHelper** function is a general-purpose function that is used internally by many of the other **wiauDbg*Xxx*** functions. While it can be used in WIA minidrivers, there are other limited-purpose functions provided that are more convenient to use.

## See also

[wiauDbgDump](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgdump)

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)