# SetupWriteTextLogError function

## Description

The **SetupWriteTextLogError** function writes information about a SetupAPI-specific error or a Win32 system error to a [SetupAPI text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs).

## Parameters

### `LogToken` [in]

A [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens) that is either a system-defined log token or was returned by [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken).

### `Category` [in]

A value of type DWORD that indicates the event category for the log entry. The event categories that can be specified for a log entry are the same as those that can be enabled for a text log. For a list of event categories, see [Enabling Event Categories for a SetupAPI Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/enabling-event-categories-for-a-text-log).

### `LogFlags` [in]

A value of type DWORD that is a bitwise OR of flag values, which specify the following:

* The event level for the log entry. The event levels that can be specified for a log entry are the same as those that can be enabled for a text log. For a list of event level flags, see [Setting the Event Level for a Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/setting-the-event-level-for-a-text-log).
* Whether to include a time stamp in the log entry. The time stamp flag value is TXTLOG_TIMESTAMP.
* The change, if any, to the indentation depth of the section and the current log entry. For information about how to use the indentation flags, see [Writing Indented Log Entries](https://learn.microsoft.com/windows-hardware/drivers/install/writing-indented-log-entries).

### `Error` [in]

A SetupAPI-specific error code or a Win32 error code. The SetupAPI-specific error codes are listed in *Setupapi.h*. The Win32 error codes are listed in *Winerror.h*.

### `MessageStr` [in]

A pointer to a NULL-terminated constant string that contains a **printf**-compatible format string, which specifies the formatted message to include in the log entry.

### `...`

A comma-separated parameter list that matches the format specifiers in the format string that is supplied by *MessageStr*.

## Return value

None

## Remarks

If an installation application has a SetupAPI-specific error code or a Win32 error code that is associated with an installation error, the application can call **SetupWriteTextLogError** instead of [SetupWriteTextLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlog) to write two entries into a text log. The first entry will be the same as that written by **SetupWriteTextLog** and the second entry will log the error code and a user-friendly description of the error.

The log token, event category, and flags that a caller supplies affect the operation of **SetupWriteTextLogError** is the same manner as that described for **SetupWriteTextLog**.

**SetupWriteTextLogError** writes the first log entry in the following format:

*entry-prefix* *time_stamp category**indentation* *formatted-message*

**SetupWriteTextLogError** writes the second log entry in the following format:

*entry-prefix* *time_stamp* *category*
*indentation*
**Error:** *error-numbererror-description*

Where:

* The *entry-prefix*, *time-stamp*, *category*, *indentation*, and *formatted-message* fields are the same as those described in [Format of a Text Log Section Body](https://learn.microsoft.com/windows-hardware/drivers/install/format-of-a-text-log-section-body).
* The *error-number* field contains the error number.
* The *error-description* field contains a user-friendly description of the error.

For general information about writing log entries in the SetupAPI text logs, see [SetupAPI Logging (Windows Vista)](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-logging--windows-vista-and-later-).

For more information about the operation of **SetupWriteTextLogError**, see [Calling SetupWriteTextLogError](https://learn.microsoft.com/windows-hardware/drivers/install/calling-setupwritetextlogerror).

For more information about log tokens, see [Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens).

For more information about using log tokens, see [Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread).

## See also

[SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken)

[SetupWriteTextLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlog)