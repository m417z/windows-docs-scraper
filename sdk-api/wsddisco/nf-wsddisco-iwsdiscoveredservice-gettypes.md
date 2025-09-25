# IWSDiscoveredService::GetTypes

## Description

Retrieves a list of WS-Discovery Types.

## Parameters

### `ppTypesList` [in]

List of WS-Discovery Types provided in the Hello, ProbeMatch, or ResolveMatch message sent by the remote device. For details, see [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list). Do not deallocate the output structure.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppTypesList* is **NULL**. |

## Remarks

The resulting pointer value is only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)