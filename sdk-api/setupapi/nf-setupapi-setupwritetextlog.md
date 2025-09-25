# SetupWriteTextLog function

## Description

The **SetupWriteTextLog** function writes a log entry in a [SetupAPI text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs).

## Parameters

### `LogToken` [in]

A [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens) that is either a system-defined log token or was returned by [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken).

### `Category` [in]

A DWORD-typed value that indicates the event category for the log entry. The event categories that can be specified for a log entry are the same as those that can be enabled for a text log. For a list of event categories, see [Enabling Event Categories for a SetupAPI Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/enabling-event-categories-for-a-text-log).

### `Flags` [in]

A DWORD-typed value that is a bitwise OR of flag values, which specify the following:

* The event level for the log entry. The event levels that can be specified for a log entry are the same as those that can be enabled for a text log. For a list of event level flags, see [Setting the Event Level for a SetupAPI Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/setting-the-event-level-for-a-text-log).
* Whether to include a time stamp in the log entry. The time stamp flag value is TXTLOG_TIMESTAMP.
* The change, if any, to the indentation depth of the section and the current log entry. For information about how to use the indentation flags, see [Writing Indented Log Entries](https://learn.microsoft.com/windows-hardware/drivers/install/writing-indented-log-entries).

### `MessageStr` [in]

A pointer to a NULL-terminated constant string that contains a **printf**-compatible format string, which specifies the formatted message to include in the log entry. The comma-separated parameter list that follows *MessageStr* must match the format specifiers in the format string.

### `...`

A comma-separated parameter list that matches the format specifiers in the format string that is supplied by *MessageStr*.

## Return value

None

## Remarks

If the value of *LogToken* was returned by a call to [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken) and the corresponding text log section can be found, **SetupWriteTextLog** writes the log entry in that text log section. If **SetupWriteTextLog** cannot locate the section, **SetupWriteTextLog** writes the log entry in the corresponding text log, but does not include the log entry in a section.

If the value of *LogToken* is one of the system-defined log tokens listed in the following table, **SetupWriteTextLog** performs the write operation that is indicated for that log token.

| System-defined log token | Write operation |
| --- | --- |
| LOGTOKEN_NOLOG | The log entry is not written to any text log. |
| LOG_TOKEN_UNSPECIFIED | The log entry is written to the application installation text log. The log entry is not included in a [text log section](https://learn.microsoft.com/windows-hardware/drivers/install/format-of-a-text-log-section). |
| LOGTOKEN_SETUPAPI_APPLOG | The log entry is written to the application installation text log. The log entry is not included in a text log section. |
| LOGTOKEN_SETUPAPI_DEVLOG | The log entry is written to the device installation text log. The log entry is not included in a text log section. |

**Note** Setting the value of *LogToken* to one of the system-defined log tokens does not change the value of the current log token for the thread.

In addition, **SetupWriteTextLog** does not write a log entry when any of the following are true:

* The [event level set for the text log](https://learn.microsoft.com/windows-hardware/drivers/install/setting-the-event-level-for-a-text-log) is less than the event level that is specified for the log entry.
* The event category for the log entry is not enabled for the text log. For more information about event categories, see [Enabling Event Categories for a Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/enabling-event-categories-for-a-text-log).

The maximum length, in characters, of a log entry is 336.

To write information about a SetupAPI-specific error or a Win32 error in a text log, an application can use [SetupWriteTextLogError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlogerror).

For general information about writing log entries in the SetupAPI text logs, see [SetupAPI Logging (Windows Vista and Later)](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-logging--windows-vista-and-later-).

For more information about the operation of **SetupWriteTextLog**, see [Calling SetupWriteTextLog](https://learn.microsoft.com/windows-hardware/drivers/install/calling-setupwritetextlog).

For more information about log tokens, see [Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens).

For more information about using log tokens, see [Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread).

## See also

[SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken)

[SetupWriteTextLogError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlogerror)