# EvtOpenLog function

## Description

Gets a handle to a channel or log file that you can then use to get information about the channel or log file.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to open a channel or log on the local computer.

### `Path` [in]

The name of the channel or the full path to the exported log file.

### `Flags` [in]

A flag that determines whether the *Path* parameter points to a log file or channel. For possible values, see the [EVT_OPEN_LOG_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_open_log_flags) enumeration.

## Return value

If successful, the function returns a handle to the file or channel; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

Relative paths and environment variables cannot be used when specifying a file. A Universal Naming Convention (UNC) path can be used to locate the file. Any relative path and environment variable expansion needs to be done prior to making API calls.

To get information about the channel or log file, call the [EvtGetLogInfo](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetloginfo) function.

## See also

[EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog)

[EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog)

[EvtGetLogInfo](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetloginfo)