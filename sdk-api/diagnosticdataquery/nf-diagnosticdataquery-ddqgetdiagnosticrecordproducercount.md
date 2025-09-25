## Description

Fetches the number (size) of producers in the resource pointed to by the HDIAGNOSTIC_EVENT_PRODUCER_DESCRIPTION.

## Parameters

### `hProducerDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains list of producers.

### `producerDescriptionCount`

Type: **[UNINT32\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the number of producers in provided resource.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_PRODUCER_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_producer_description)** for documentation on how a producer is defined.

## See also