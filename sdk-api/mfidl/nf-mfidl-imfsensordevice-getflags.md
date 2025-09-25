# IMFSensorDevice::GetFlags

## Description

Gets the flags set for the sensor device. This method is reserved for future use.

## Parameters

### `pFlags` [out]

The flags set for the sensor device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pDeviceId* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

This method is reserved for future use and should not be called.

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)