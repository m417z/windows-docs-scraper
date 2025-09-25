# IMFSensorDevice::SetSensorDeviceMode

## Description

Sets a value that specifies the sharing mode of the sensor device to either controller or shared.

## Parameters

### `eMode` [in]

A member of the [MFSensorDeviceMode](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensordevicemode) enumeration specifying whether the device is in shared or controller mode.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)