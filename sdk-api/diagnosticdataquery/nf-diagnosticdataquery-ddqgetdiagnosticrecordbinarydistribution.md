## Description

Fetches binary name and associated estimated total upload of Diagnostic Data Events volume in bytes for top N noisiest binaries based on total estimated upload size, where N is the value passed in for topNBinaries.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A handle to the current Diagnostic Data Query session.

### `producerNames`

Type: **[PCWSTR\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Pointer to the set of known producers names.

### `producerNameCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Number of producer names

### `topNBinaries`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of noisiest records to return

### `binaryStats`

Type: **[DIAGNOSTIC_DATA_EVENT_BINARY_STATS](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_binary_stats)**
This output parameter is the pointer to the list of top N noisiest DIAGNOSTIC_DATA_EVENT_BINARY_STATS items.

### `statCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The number of items in binaryStats.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also