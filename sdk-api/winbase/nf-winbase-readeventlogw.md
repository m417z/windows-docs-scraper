# ReadEventLogW function

## Description

Reads the specified number of entries from the specified event log. The function can be used to read log entries in chronological or reverse chronological order.

## Parameters

### `hEventLog` [in]

A handle to the event log to be read. The
[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) function returns this handle.

### `dwReadFlags` [in]

Use the following flag values to indicate how to read the log file. This parameter must include one of the following values (the flags are mutually exclusive).

| Value | Meaning |
| --- | --- |
| **EVENTLOG_SEEK_READ**<br><br>0x0002 | Begin reading from the record specified in the *dwRecordOffset* parameter. <br><br>This option may not work with large log files if the function cannot determine the log file's size. For details, see Knowledge Base article, 177199. |
| **EVENTLOG_SEQUENTIAL_READ**<br><br>0x0001 | Read the records sequentially. <br><br>If this is the first read operation, the EVENTLOG_FORWARDS_READ EVENTLOG_BACKWARDS_READ flags determines which record is read first. |

You must specify one of the following flags to indicate the direction for successive read operations (the flags are mutually exclusive).

| Value | Meaning |
| --- | --- |
| **EVENTLOG_FORWARDS_READ**<br><br>0x0004 | The log is read in chronological order (oldest to newest). <br><br>The default. |
| **EVENTLOG_BACKWARDS_READ**<br><br>0x0008 | The log is read in reverse chronological order (newest to oldest). <br><br> |

### `dwRecordOffset` [in]

The record number of the log-entry at which the read operation should start. This parameter is ignored unless *dwReadFlags* includes the **EVENTLOG_SEEK_READ** flag.

### `lpBuffer` [out]

An application-allocated buffer that will receive one or more [EVENTLOGRECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-eventlogrecord) structures. This parameter cannot be **NULL**, even if the *nNumberOfBytesToRead* parameter is zero.

The maximum size of this buffer is 0x7ffff bytes.

### `nNumberOfBytesToRead` [in]

The size of the *lpBuffer* buffer, in bytes. This function will read as many log entries as will fit in the buffer; the function will not return partial entries.

### `pnBytesRead` [out]

A pointer to a variable that receives the number of bytes read by the function.

### `pnMinNumberOfBytesNeeded` [out]

A pointer to a variable that receives the required size of the *lpBuffer* buffer. This value is valid only this function returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INSUFFICIENT_BUFFER**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When this function returns successfully, the read position in the event log is adjusted by the number of records read.

**Note** The configured file name for this source may also be the configured file name for other sources (several sources can exist as subkeys under a single log). Therefore, this function may return events that were logged by more than one source.

#### Examples

For an example, see
[Querying for Event Information](https://learn.microsoft.com/windows/desktop/EventLog/querying-for-event-source-messages).

> [!NOTE]
> The winbase.h header defines ReadEventLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ClearEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-cleareventloga)

[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog)

[EVENTLOGRECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-eventlogrecord)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)

[ReportEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-reporteventa)