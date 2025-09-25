# IMFSensorGroup::GetSensorDeviceCount

## Description

Gets the number of devices that are virtualized by the sensor group.

## Parameters

### `pdwCount` [out]

The number of devices in the sensor group.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pdwCount* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The term "device" in this context could refer to a physical device, a custom media source, or a frame provider.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)