# wiauDbgSetFlags macro

## Description

The **wiauDbgSetFlags** function sets debugging flags.

## Parameters

### `a`

- **flags** - A set of flags that control message logging. This parameter can be set to a combination of the following values:

 | Value | Description |
| --- | --- |
| WIAUDBG_BREAK_ON_ERRORS | Call **DebugBreak** when an error occurs. |
| WIAUDBG_DONT_LOG | Do not log to either log file or debugger. |
| WIAUDBG_DONT_LOG_TO_DEBUGGER | Do not log to debugger. |
| WIAUDBG_DONT_LOG_TO_FILE | Do not log to log file. |
| WIAUDBG_DUMP | Log data. |
| WIAUDBG_ERRORS | Log error messages. |
| WIAUDBG_FNS | Log function entries and exits. |
| WIAUDBG_PRINT_INFO | Log thread, file, and line number. |
| WIAUDBG_PRINT_TIME | Log current time. |
| WIAUDBG_TRACES | Log trace messages. |
| WIAUDBG_WARNINGS | Log warning messages. |

## See also

[wiauDbgFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgflags)