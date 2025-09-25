# EvtExportLog function

## Description

Copies events from the specified channel or log file and writes them to the target log file.

## Parameters

### `Session` [in, optional]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** for local channels.

### `Path` [in]

The name of the channel or the full path to a log file that contains the events that you want to export. If the *Query* parameter contains an XPath query, you must specify the channel or log file. If the *Flags* parameter contains EvtExportLogFilePath, you must specify the log file. If the *Query* parameter contains a structured XML query, the channel or path that you specify here must match the channel or path in the query. If the *Flags* parameter contains EvtExportLogChannelPath, this parameter can be **NULL** if the query is a structured XML query that specifies the channel.

### `Query` [in]

A query that specifies the types of events that you want to export. You can specify an XPath 1.0 query or structured XML query. If your XPath contains more than 20 expressions, use a structured XML query. To export all events, set this parameter to **NULL** or "*".

### `TargetFilePath` [in]

The full path to the target log file that will receive the events. The target log file must not exist.

### `Flags` [in]

Flags that indicate whether the events come from a channel or log file. For possible values, see the [EVT_EXPORTLOG_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_exportlog_flags) enumeration.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

You can export events from multiple channels using a structured XML query (see [Consuming Events](https://learn.microsoft.com/windows/desktop/WES/consuming-events)); however, you cannot use this function to merge events from multiple log files. If the query result is empty, the service creates a file that contains header information but no events.

To remove events from a channel and write them to a target log file, call the [EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog) function. To include localized strings with the events in the log file, call the [EvtArchiveExportedLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtarchiveexportedlog) function.

You must specify the absolute path to the target log file; you cannot use relative paths and environment variables to specifying the target log file. The path can be a Universal Naming Convention (UNC) path. You should use .evtx as the file name extension.

This function affects only the specified channel or log file—if the channel uses autoBackup or fileMax, this function will not affect those backup files.

#### Examples

For an example that shows how to use this function, see [Saving Events to a Log File](https://learn.microsoft.com/windows/desktop/WES/saving-events-to-a-log-file).

## See also

[EvtArchiveExportedLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtarchiveexportedlog)

[EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog)