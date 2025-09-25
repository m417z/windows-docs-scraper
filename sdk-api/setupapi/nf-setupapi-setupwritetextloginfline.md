# SetupWriteTextLogInfLine function

## Description

The **SetupWriteTextLogInfLine** function writes a log entry in a [SetupAPI text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs) that contains the text of a specified INF file line.

## Parameters

### `LogToken` [in]

A [log token](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens) that is either a system-defined log token or was returned by [SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken).

### `Flags` [in]

A value of type DWORD that is a bitwise OR of flag values, which specify the following:

* The event level for the log entry. The event levels that can be specified for a log entry are the same as those that can be enabled for a text log. For a list of event level flags, see [Setting the Event Level for a SetupAPI Text Log](https://learn.microsoft.com/windows-hardware/drivers/install/setting-the-event-level-for-a-text-log).
* Whether to include a time stamp in the log entry. The time stamp flag value is TXTLOG_TIMESTAMP.
* The change, if any, to the indentation depth of the section and the current log entry. For information about how to use the indentation flags, see [Writing Indented Log Entries](https://learn.microsoft.com/windows-hardware/drivers/install/writing-indented-log-entries).

### `InfHandle` [in]

A handle to the INF file that includes the line of text to be written to the text log. A handle to an INF file is obtained by calling **SetupOpenInfFile**, which is documented in the Platform SDK.

### `Context` [in]

A pointer to an INF file context that specifies the line of text to be written to the text log. An INF file context for a line is obtained by calling the **SetupFind***Xxx***Line** functions. For information about INF files and an INF file context, see the information that is provided in the Platform SDK about using INF files, obtaining an INF file context, and the INFCONTEXT structure.

## Return value

None

## Remarks

**SetupWriteTextLogInfLine** writes a log entry in the following format:

*entry-prefix* *time-stamp* **inf:***indentation* *inf-line-text* **(***inf-file-name* **line** *line-number***)**

Where:

* The *entry-prefix* and *time-stamp* fields are the same as those described in [Format of a Text Log Section Body](https://learn.microsoft.com/windows-hardware/drivers/install/format-of-a-text-log-section-body).
* The *inf-line-text* field contains the text of the specified INF file line.
* The *inf-file-name* field contains the name of the INF file that contains the specified INF file line.
* The *line-number* field contains the line number of the specified line in the INF file.

The log token and flags that a caller supplies affect the operation of **SetupWriteTextLogInfLine** in the same manner as that described for [SetupWriteTextLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlog) and [SetupWriteTextLogError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlogerror). In addition, **SetupWriteTextLogInfLine** uses the [event category](https://learn.microsoft.com/windows-hardware/drivers/install/enabling-event-categories-for-a-text-log) TXTLOG_INF.

For general information about writing log entries in the SetupAPI text logs, see [SetupAPI Logging (Windows Vista)](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-logging--windows-vista-and-later-).

For more information about the operation of **SetupWriteTextLogInfLine**, see [Calling SetupWriteTextLogInfLine](https://learn.microsoft.com/windows-hardware/drivers/install/calling-setupwritetextloginfline).

For more information about the various types of log tokens, see [Log Tokens](https://learn.microsoft.com/windows-hardware/drivers/install/log-tokens).

For more information about using log tokens, see [Setting and Getting a Log Token for a Thread](https://learn.microsoft.com/windows-hardware/drivers/install/setting-and-getting-a-log-token-for-a-thread).

## See also

[SetupGetThreadLogToken](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetthreadlogtoken)

[SetupWriteTextLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlog)

[SetupWriteTextLogError](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupwritetextlogerror)