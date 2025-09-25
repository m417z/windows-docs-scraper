# IMFSensorDevice::GetSensorDeviceMode

## Description

Gets a value that specifies the current sharing mode of the sensor device, which is either controller or shared.

## Parameters

### `peMode`

If the call succeeds, receives a member of the [MFSensorDeviceMode](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensordevicemode), specifying the current mode of the sendsor device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pDeviceId* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)