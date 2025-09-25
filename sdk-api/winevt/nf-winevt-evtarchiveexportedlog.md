# EvtArchiveExportedLog function

## Description

Adds localized strings to the events in the specified log file.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** for local channels.

### `LogFilePath` [in]

The full path to the exported log file that contains the events to localize.

### `Locale` [in]

The locale to use to localize the strings that the service adds to the events in the log file. If zero, the function uses the calling thread's locale. If the provider's resources does not contain the locale, the string is empty.

### `Flags` [in]

 Reserved. Must be zero.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

To consume an event from an exported log file, the provider needs to be available to provide the resources (message strings) for the event. You would call this function to include the localized resources with the event, so that you can consume the event when the provider is not available.

## See also

[EvtClearLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclearlog)

[EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog)