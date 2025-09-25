## Description

Fetches tag description at the specified index in the resource pointed to by the HDIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION resource.

## Parameters

### `hTagDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of tag descriptions.

### `index`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The index of the tag description to be fetched.

### `tagDescription`

Type: **[DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION\*](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description)**
This outpoint parameter is a pointer to the tag description that was fetched.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

## See also