## Description

Sets event transcript configuration, such as maximum storage size and hours of data history. Note that setting the configuration will fail if the user is not elevated.

## Parameters

### `hSession`

A [HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) to the **Diagnostic Data Query** session.

### `desiredConfig`

A [DIAGNOSTIC_DATA_EVENT_TRANSCRIPT_CONFIGURATION\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_transcript_configuration) that points to the resource that contains the desired event transcript configuration.

## Return value

An [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) which returns `S_OK` on successful completion.

## Remarks

## See also