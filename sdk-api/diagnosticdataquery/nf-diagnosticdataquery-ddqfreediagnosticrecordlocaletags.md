## Description

Frees memory allocated for tag information referenced by HDIAGNOSTIC_EVENT_TAG_DESCRIPTION handle.

## Parameters

### `hTagDescription`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the resource that contains the tag descriptions being freed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more details about the tag description data type, see our [**DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description).

## See also