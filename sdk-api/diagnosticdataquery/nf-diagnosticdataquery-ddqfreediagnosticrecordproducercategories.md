## Description

Frees memory allocated for set of categories and the text representation of the categories referenced by HDIAGNOSTIC_EVENT_CATEGORY_DESCRIPTION handle.

## Parameters

### `hCategoryDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the set of categories and their descriptions to be freed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more information about the data type DIAGNOSTIC_EVENT_CATEGORY_DESCRIPTION, see [**here**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description).

## See also