## Description

Producers and categories have a hierarchical relationship--that is, categories belong to producers. This function fetches the available Category IDs and text representation of categories for a given diagnostic Producer Name.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `producerName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The name of the producer of interest.

### `hCategoryDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of categories and their descriptions that belong to the given producer.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description)** for documentation on how a category is defined.

## See also