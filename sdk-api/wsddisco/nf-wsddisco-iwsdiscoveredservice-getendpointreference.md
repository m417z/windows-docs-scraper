# IWSDiscoveredService::GetEndpointReference

## Description

Retrieves a WS-Addressing address referencing an endpoint of the remote device.

## Parameters

### `ppEndpointReference` [out]

A WS-Addressing address referencing an endpoint of the remote device. For details, see [WSD_ENDPOINT_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_endpoint_reference). Do not deallocate the output structure.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppEndPointReference* is **NULL**. |

## Remarks

The resulting pointer value is only valid for the lifetime of the [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) object.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)