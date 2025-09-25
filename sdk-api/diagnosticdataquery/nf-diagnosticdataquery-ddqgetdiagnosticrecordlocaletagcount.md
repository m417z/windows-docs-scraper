## Description

Fetches the number (size) of tags in the resource pointed to by the HDIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION handle.

## Parameters

### `hTagDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the list of tag descriptions.

### `tagDescriptionCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is the number of tags in the list of tag descriptions.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more details about the tag description data type, see our [**DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description).
For details about what a privacy tag is, see our [**privacy statement**](https://learn.microsoft.com/windows/privacy/windows-diagnostic-data).

## See also