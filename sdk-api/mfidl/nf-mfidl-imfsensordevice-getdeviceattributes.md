# IMFSensorDevice::GetDeviceAttributes

## Description

Gets the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) for the sensor group.

## Parameters

### `ppAttributes` [out]

The [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface representing the internal attribute store of the sensor device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppAttributes* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor device has not been initialized. |

## Remarks

The object returned is a copy of the internal attribute store and so changes made to the returned attributes have no effect on the [IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice).

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)