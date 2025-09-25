# IPortableDeviceConnector::Cancel

## Description

The **Cancel** method cancels a pending request to connect or disconnect an MTP/Bluetooth device. The callback object is used to identify the request. This method returns immediately, and the request will be cancelled asynchronously.

## Parameters

### `pCallback` [in]

A pointer to an [IConnectionRequestCallback](https://learn.microsoft.com/windows/desktop/wpd_sdk/iconnectionrequestcallback) interface. This value cannot be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Either the *pCallback* parameter does not correspond to a pending connect or disconnect request, or this method has been already been called. |

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)