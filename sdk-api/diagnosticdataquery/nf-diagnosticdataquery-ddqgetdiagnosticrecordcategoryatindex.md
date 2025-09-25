## Description

Fetches a diagnostic record category at the specified index in the resource pointed to bythe HDIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION handle.

## Parameters

### `hCategoryDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of categories and their descriptions

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The index of the category to be fetched.

### `categoryDescription`

Type: **[DIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description)**
This outpoint parameter is a pointer to the category and its description that was fetched.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

See **[DIAGNOSTIC_DATA_EVENT_CATEGORY_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_category_description)** for documentation on how a category is defined.

## See also