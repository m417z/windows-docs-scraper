# IMFSensorDevice::GetDeviceId

## Description

Gets the unique identifier for the device. This value is currently unused.

## Parameters

### `pDeviceId` [out]

The unique identifier for the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pDeviceId* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)