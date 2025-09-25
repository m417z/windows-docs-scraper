## Description

Fetches information for all known tags under the specified locale and provides a handle, HDIAGNOSTIC_EVENT_TAG_DESCRIPTION, to the data. An example locale would be “en-US”. An example return value is a DIAGNOSTIC_EVENT_TAG_DESCRIPTION resource that contains the following data: tag: 11, name: “Device Connectivity and Configuration” and description: “Data that describes the connections and configuration of the devices connected to the service and the network, including device identifiers (e.g IP addresses) configuration, setting and performance”.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `locale`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The locale for the tag descriptions.

### `hTagDescription`

Type: **[HANDLE\*](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This output parameter is a pointer to the handle for the resource that contains the list of tag descriptions. The resource is of the form DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION and contains the tag name, description and the numeric tag value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more details about the tag description data type, see our [**DIAGNOSTIC_DATA_EVENT_TAG_DESCRIPTION**](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_data_event_tag_description).

## See also