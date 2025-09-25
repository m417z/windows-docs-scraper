## Description

Fetches Diagnostic Data Events per privacy tag event distribution statistics based on the specified producer names.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `producerNames`

Type: **[PCWSTR\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
List of producer names to search for. A diagnostic data record that matches at least one of the producer names is included as a result in this search criteria. Use `nullptr` for this value to indicate no filter by producers.

### `producerNameCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of producer names in the list of producer names to search for. Use `0` for this value to indicate no filter by producers.

### `tagStats`

Type: **[DIAGNOSTIC_DATA_TAG_STATS\*\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_stats)**
This output parameter is a pointer to a list of DIAGNOSTIC_DATA_TAG_STATS items. Each item is a resource that contains information about a privacy tag and the number of events that have that tag.

### `statCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of items in the DIAGNOSTIC_DATA_TAG_STATS list.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See our [**privacy statement**](https://learn.microsoft.com/windows/privacy/windows-diagnostic-data) for information about diagnostic data privacy tags.
For more details about the tag description data type, see our [**DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description).

## See also