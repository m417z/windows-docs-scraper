# wiauDbgFlags function

## Description

The **wiauDbgFlags** function determines whether a particular debugging flag is set.

## Parameters

### `flags`

Is a set of flags that control which information is placed in the log file or displayed in the debugger. See the *flags* parameter of [wiauDbgSetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgsetflags) for a list of the flag values.

### `prefix`

Pointer to a string containing a prefix (such as "ERROR " or "WARN ").

### `fname`

Pointer to a string containing the name of the function or method into which the call to **wiauDbgDump** is inserted.

### `fmt`

### `...`

####### - fmt, ...

Pointer to a format string that specifies a variable argument list, which starts with an ANSI format string containing the message and any conversion specifiers. The ellipsis (...) specifies a variable number of arguments that are to be output.

## Remarks

If message logging to log file, or debugger, or both is enabled and the particular flag in the *flags* parameter is enabled, this function logs a message containing the strings pointed to by the *prefix*, *fname*, and *fmt* parameters.

## See also

[wiauDbgSetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgsetflags)