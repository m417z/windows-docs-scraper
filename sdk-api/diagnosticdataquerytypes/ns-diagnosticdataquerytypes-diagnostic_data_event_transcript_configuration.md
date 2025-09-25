## Description

Event transcript configuration details such as maximum storage size and hours of data history.

## Members

### `hoursOfHistoryToKeep`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Number of hours of event history to keep. When an event has been stored for longer than this amount of time, it will be dropped.

### `maxStoreMegabytes`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Maximum storage size (in megabytes) of event history to keep. When event store exceeds this size, events will be removed from the store starting with the oldest event.

### `requestedMaxStoreMegabytes`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The requested storage size (in megabytes) of event history to keep.

## Remarks

For more details on how configurations work, see [**Diagnostic Data Viewer overview**](https://learn.microsoft.com/windows/privacy/diagnostic-data-viewer-overview)

## See also