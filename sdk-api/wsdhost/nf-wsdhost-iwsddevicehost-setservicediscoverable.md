# IWSDDeviceHost::SetServiceDiscoverable

## Description

Controls whether or not the service is advertised
using WS-Discovery.

## Parameters

### `pszServiceId` [in]

The ID for the service.

### `fDiscoverable` [in]

**TRUE** if the service can be found
using WS-Discovery, **FALSE** if the service is not visible to WS-Discovery.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszServiceId* is **NULL**, the length in characters of *pszServiceId* exceeds WSD_MAX_TEXT_LENGTH (8192), or *pszServiceId* does not correspond to a registered service. |

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)