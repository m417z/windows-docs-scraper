# IMFSensorGroup::GetDefaultSensorDeviceIndex

## Description

Retrieves the index of the default device in the sensor group.

## Parameters

### `pdwIndex` [out]

If the call succeeds, *pdwIndex* receives the index of the default device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pdwIndex* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The term "device" in this context could refer to a physical device, a custom media source, or a frame provider.

If this [SetDefaultSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensorgroup-setdefaultsensordeviceindex) has not been called, the first device in the Sensor Group (i.e. index 0) will be returned.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)