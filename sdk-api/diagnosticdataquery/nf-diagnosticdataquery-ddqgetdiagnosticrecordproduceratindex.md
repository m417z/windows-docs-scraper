## Description

Fetches the description of a producer at the specified index in the resource pointed to by the HDIAGNOSTIC_EVENT_PRODUCER_DESCRIPTION handle.

## Parameters

### `hProducerDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains set of producers.

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The index of the producer to fetch.

### `producerDescription`

Type: **[DIAGNOSTIC_DATA_EVENT_PRODUCER_DESCRIPTION\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_producer_description)**
This output parameter is the pointer to the resource that describes the fetched producer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_PRODUCER_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_producer_description)** for documentation on how a producer is defined.

## See also