# IWSDDeviceProxy::GetEndpointProxy

## Description

Retrieves the endpoint proxy for the device.

## Parameters

### `ppProxy` [out]

An [IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy) interface that implements a device services messaging proxy for this device.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppProxy* is **NULL**. |

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)