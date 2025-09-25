# IPortableDeviceConnector::Connect

## Description

The **Connect** method sends an asynchronous connection request to the MTP/Bluetooth device.

## Parameters

### `pCallback` [in, optional]

A pointer to a [IConnectionRequestCallback](https://learn.microsoft.com/windows/desktop/wpd_sdk/iconnectionrequestcallback) interface if the application wishes to be notified when the request is complete; otherwise, **NULL**. If multiple requests are being sent simultaneously using the same [IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector) object, a different instance of the callback object must be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method will queue a connect request and then return immediately. The connection request will result in a no-op if a device is already connected.

To be notified when the request is complete, applications should provide a pointer to the [IConnectionRequestCallback](https://learn.microsoft.com/windows/desktop/wpd_sdk/iconnectionrequestcallback) interface.

If a previously paired MTP/Bluetooth device is within range, applications can call this method to instantiate the Windows Portable Devices (WPD) class driver stack for that device, so that the device can be communicated to using the WPD API.

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)