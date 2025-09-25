## Description

Fetches Diagnostic Data Producers available for a Diagnostic Data Query session.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `hProducerDescription`

Type: **[HANDLE\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the handle for the resource that contains the list of producers.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_PRODUCER_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_producer_description)** for documentation on how a producer is defined.

## See also