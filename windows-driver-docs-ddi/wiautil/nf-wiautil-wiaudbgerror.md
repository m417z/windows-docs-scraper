# wiauDbgError function

## Description

The **wiauDbgError** function logs an error message.

## Parameters

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgDump** is inserted.

### `fmt`

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

### `...`

####### - fmt, ...

## Remarks

The **wiauDbgError** typically is used to display an error message with no data, such as in the following example:

```cpp
wiauDbgError("Read", "Attempting to read past end of buffer");
```

## See also

[wiauDbgDump](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgdump)

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)