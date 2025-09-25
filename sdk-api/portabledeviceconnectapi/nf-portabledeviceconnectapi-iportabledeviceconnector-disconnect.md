# IPortableDeviceConnector::Disconnect

## Description

The **Disconnect** method sends an asynchronous disconnect request to the MTP/Bluetooth device.

## Parameters

### `pCallback` [in]

A pointer to an [IConnectionRequestCallback](https://learn.microsoft.com/windows/desktop/wpd_sdk/iconnectionrequestcallback) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method will queue a disconnect request and then return immediately.

To be notified when the request is complete, applications should provide a pointer to the [IConnectionRequestCallback](https://learn.microsoft.com/windows/desktop/wpd_sdk/iconnectionrequestcallback) interface. This will disconnect the MTP/Bluetooth link and remove the Windows Portable Devices (WPD) class driver stack for that device.

Once the disconnection completes, the WPD API will no longer enumerate this device.

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)