# EvtClearLog function

## Description

Removes all events from the specified channel and writes them to the target log file.

## Parameters

### `Session` [in, optional]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** for local channels.

### `ChannelPath` [in]

The name of the channel to clear.

### `TargetFilePath` [in, optional]

The full path to the target log file that will receive the events. Set to **NULL** to clear the log file and not save the events.

### `Flags` [in]

Reserved. Must be zero.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

To copy events from a channel or log file, call the [EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog) function.

You must specify the absolute path to the target log file; you cannot use relative paths and environment variables to specifying the target log file. The path can be a Universal Naming Convention (UNC) path. You should use .evtx as the file name extension.

This function affects only the channel—if the channel uses autoBackup or fileMax, this function will not affect those backup files.

## See also

[EvtArchiveExportedLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtarchiveexportedlog)

[EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog)