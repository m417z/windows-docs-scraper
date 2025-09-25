## Description

The **wiauDbgErrorHr** function logs a message containing an HRESULT and its error message string.

## Parameters

### `hr`

Specifies the HRESULT that is to be logged.

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgDump** is inserted.

### `fmt`

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

### `...`

Additional parameters.

## Remarks

The **wiauDbgErrorHr** function typically logs two lines to the log file, or debugger, or both. The first line contains the text of the *fmt* parameter, including data, if provided. The second line contains the HRESULT and the message string associated with that HRESULT. The following example shows how this function might be called:

```cpp
wiauDbgErrorHr(hr, "AllocateBuffer", "Buffer size is %d bytes", size);
```

## See also

[wiauDbgDump](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgdump)

[wiauDbgError](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerror)

[wiauDbgTrace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgtrace)

[wiauDbgWarning](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgwarning)