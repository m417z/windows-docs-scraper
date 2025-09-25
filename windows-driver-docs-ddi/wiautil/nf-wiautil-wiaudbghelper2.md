# wiauDbgHelper2 function

## Description

The **wiauDbgHelper2** function writes a message to a log file, or debugger, or both.

## Parameters

### `prefix`

Pointer to a string containing a prefix (such as "ERROR " or "WARN ") associated with the message.

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgHelper2** is inserted.

### `fmt`

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output. The text should be prefixed with the full name of the method or function generating the message in the format of "class::method, message-text".

### `...`

####### - fmt, ...

## Remarks

The **wiauDbgHelper2** function enables those using it to write **printf**-style messages, with variable argument lists, to a log file or debugger. The following example demonstrates how this function might be used:

```cpp
wiauDbgHelper2("ERROR", "MyFunc", "Buffer size too small - %d bytes", BufSize);
```

## See also

[wiauDbgDump](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgdump)

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)

[wiauDbgHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbghelper)

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)