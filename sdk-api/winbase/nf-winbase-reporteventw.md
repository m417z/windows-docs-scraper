# ReportEventW function

## Description

Writes an entry at the end of the specified event log.

## Parameters

### `hEventLog` [in]

A handle to the event log. The
[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea) function returns this handle.

As of Windows XP with SP2, this parameter cannot be a handle to the **Security** log. To write an event to the **Security** log, use the [AuthzReportSecurityEvent](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzreportsecurityevent) function.

### `wType` [in]

The type of event to be logged. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **EVENTLOG_SUCCESS**<br><br>0x0000 | Information event |
| **EVENTLOG_AUDIT_FAILURE**<br><br>0x0010 | Failure Audit event |
| **EVENTLOG_AUDIT_SUCCESS**<br><br>0x0008 | Success Audit event |
| **EVENTLOG_ERROR_TYPE**<br><br>0x0001 | Error event |
| **EVENTLOG_INFORMATION_TYPE**<br><br>0x0004 | Information event |
| **EVENTLOG_WARNING_TYPE**<br><br>0x0002 | Warning event |

For more information about event types, see
[Event Types](https://learn.microsoft.com/windows/desktop/EventLog/event-types).

### `wCategory` [in]

The event category. This is source-specific information; the category can have any value. For more information, see
[Event Categories](https://learn.microsoft.com/windows/desktop/EventLog/event-categories).

### `dwEventID` [in]

The event identifier. The event identifier specifies the entry in the message file associated with the event source. For more information, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/EventLog/event-identifiers).

### `lpUserSid` [in]

A pointer to the current user's security identifier. This parameter can be **NULL** if the security identifier is not required.

### `wNumStrings` [in]

The number of insert strings in the array pointed to by the *lpStrings* parameter. A value of zero indicates that no strings are present.

### `dwDataSize` [in]

The number of bytes of event-specific raw (binary) data to write to the log. If this parameter is zero, no event-specific data is present.

### `lpStrings` [in]

A pointer to a buffer containing an array of null-terminated strings that are merged into the message before Event Viewer displays the string to the user. This parameter must be a valid pointer (or **NULL**), even if *wNumStrings* is zero. Each string is limited to 31,839 characters.

**Prior to Windows Vista:** Each string is limited to 32K characters.

### `lpRawData` [in]

A pointer to the buffer containing the binary data. This parameter must be a valid pointer (or **NULL**), even if the *dwDataSize* parameter is zero.

## Return value

If the function succeeds, the return value is nonzero, indicating that the entry was written to the log.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns one of the following extended error codes.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters is not valid.<br><br>This error is returned on Windows Server 2003 if the message data to be logged is too large. This error is returned by the RPC server on Windows Server 2003 if the *dwDataSize* parameter is larger than 261,991 (0x3ff67). |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory resources are available to complete the operation. |
| **RPC_S_INVALID_BOUND** | The array bounds are invalid. <br><br>This error is returned if the message data to be logged is too large. On Windows Vista and later, this error is returned if the *dwDataSize* parameter is larger than 61,440 (0xf000). |
| **RPC_X_BAD_STUB_DATA** | The stub received bad data.<br><br>This error is returned on Windows XP if the message data to be logged is too large. This error is returned by the RPC server on Windows XP, if the *dwDataSize* parameter is larger than 262,143 (0x3ffff). |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

This function is used to log an event. The entry is written to the end of the configured log for the source identified by the *hEventLog* parameter. The
**ReportEvent** function adds the time, the entry's length, and the offsets before storing the entry in the log. To enable the function to add the user name, you must supply the user's SID in the *lpUserSid* parameter.

There are different size limits on the size of the message data that can be logged depending on the version of Windows used by both the client where the application is run and the server where the message is logged. The server is determined by the *lpUNCServerName* parameter passed to the [RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea) function. Different errors are returned when the size limit is exceeded that depend on the version of Windows.

If the string that you log contains %*n*, where *n* is an integer value (for example, %1), the event viewer treats it as an insertion string. Because an IPv6 address can contain this character sequence, you must provide a format specifier (*!S!*) to log an event message that contains an IPv6 address. This specifier tells the formatting code to use the string literally and not perform any further expansions (for example, "my IPv6 address is: %1!S!").

#### Examples

For an example, see
[Reporting an Event](https://learn.microsoft.com/windows/desktop/EventLog/reporting-an-event).

> [!NOTE]
> The winbase.h header defines ReportEvent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ClearEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-cleareventloga)

[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog)

[Event Log File Format](https://learn.microsoft.com/windows/desktop/EventLog/event-log-file-format)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)

[ReadEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readeventloga)

[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea)