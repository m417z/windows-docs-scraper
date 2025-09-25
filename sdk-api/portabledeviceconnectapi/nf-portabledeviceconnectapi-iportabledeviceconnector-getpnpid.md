# IPortableDeviceConnector::GetPnPID

## Description

The **GetPnPID** method retrieves the connector's Plug and Play (PnP) device identifier.

## Parameters

### `ppwszPnPID` [out]

The PnP device identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The identifier retrieved by this method corresponds to a handle to the MTP/Bluetooth Bus Enumerator device node that receives connect and disconnect IOCTL requests for a paired MTP/Bluetooth device. Applications can use this identifier with the SetupAPI functions to access the device node.

Once the application no longer needs the identifier specified by the *ppwszPnPID* parameter, it must call the **CoTaskMemAlloc** function to free the identifier.

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)