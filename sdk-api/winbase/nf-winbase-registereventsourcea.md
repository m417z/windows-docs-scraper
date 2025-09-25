# RegisterEventSourceA function

## Description

Retrieves a registered handle to the specified event log.

## Parameters

### `lpUNCServerName` [in]

The Universal Naming Convention (UNC) name of the remote server on which this operation is to be performed. If this parameter is **NULL**, the local computer is used.

### `lpSourceName` [in]

The name of the [event source](https://learn.microsoft.com/windows/desktop/EventLog/event-sources) whose handle is to be retrieved. The source name must be a subkey of a log under the **Eventlog** registry key.
Note that the **Security** log is for system use only.

**Note** This string must not contain characters prohibited in XML Attributes, with the exception of XML Escape sequences such as **&lt &gl**.

## Return value

If the function succeeds, the return value is a handle to the event log.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The function returns **ERROR_ACCESS_DENIED** if *lpSourceName* specifies the **Security** event log.

## Remarks

If the source name cannot be found, the event logging service uses the **Application** log. Although events will be reported , the events will not include descriptions because there are no message and category message files for looking up descriptions related to the event identifiers.

To close the handle to the event log, use the
[DeregisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deregistereventsource) function.

#### Examples

For an example, see
[Reporting an Event](https://learn.microsoft.com/windows/desktop/EventLog/reporting-an-event).

> [!NOTE]
> The winbase.h header defines RegisterEventSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeregisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deregistereventsource)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[Event Sources](https://learn.microsoft.com/windows/desktop/EventLog/event-sources)

[ReportEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-reporteventa)