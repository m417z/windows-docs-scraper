## Description

Gets event transcript configuration, such as maximum storage size hours of data history to keep.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `currentConfig`

Type: **[DIAGNOSTIC_DATA_EVENT_TRANSCRIPT_CONFIGURATION\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_transcript_configuration)**
This output parameter is a pointer to the resource that contains the event transcript configuration details.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also