## Description

Fetches the number (size) of diagnostic record categories in the resource pointed by the HDIAGNOSTIC_EVENT_CATEGORY_DESCRIPTION handle.

## Parameters

### `hCategoryDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of categories and their descriptions.

### `categoryDescriptionCount`

Type: **[UINT32\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the number of categories in the diagnostic record category array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description)** for documentation on how a category is defined.

## See also