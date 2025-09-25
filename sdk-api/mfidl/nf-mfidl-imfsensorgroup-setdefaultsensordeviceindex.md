# IMFSensorGroup::SetDefaultSensorDeviceIndex

## Description

Configures one of the devices in the sensor group as the default device.

## Parameters

### `dwIndex`

0-based index of the device to be set as default. The index must be between 0 and the value returned by [GetSensorDeviceCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensorgroup-getsensordevicecount) - 1.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALID_INDEX** | the *dwIndex* parameter is not in the valid range. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The term "device" in this context could refer to a physical device, a custom media source, or a frame provider.

If this method is not called, the first device in the Sensor Group (i.e. the device with index 0) will be used.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)