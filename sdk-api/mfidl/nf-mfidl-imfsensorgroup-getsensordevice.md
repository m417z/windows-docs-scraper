# IMFSensorGroup::GetSensorDevice

## Description

Gets the [IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice) corresponding to a device in the sensor group.

## Parameters

### `dwIndex` [in]

The 0-based index of the device to be retrieved. The index must be between 0 and the value returned by [GetSensorDeviceCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensorgroup-getsensordevicecount) - 1.

### `ppDevice` [out]

If the call is successful, *ppDevice* will contain the retrieved sensor device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppDevice* parameter is null. |
| **MF_E_INVALID_INDEX** | the *dwIndex* parameter is not in the valid range. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The term "device" in this context could refer to a physical device, a custom media source, or a frame provider.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)