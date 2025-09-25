## Description

The **wiauDbgDump** function logs a message containing one or more data values.

## Parameters

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgDump** is inserted.

### `fmt`

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

### `...`

## Remarks

The **wiauDbgDump** function typically is used to log a message along with one or more data values, as in the following example:

```cpp
wiauDbgDump("SetBuffer", "Buffer size set to %d bytes.", size);
```

This example, which would be placed in a function named *SetBuffer*, causes the function name and a string describing the size of a buffer to be logged.

## See also

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)