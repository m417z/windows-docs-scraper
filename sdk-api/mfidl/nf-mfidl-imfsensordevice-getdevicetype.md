# IMFSensorDevice::GetDeviceType

## Description

Gets a value that specifies the type of sensor device represented by the object.

## Parameters

### `pType`

A value that specifies the type of sensor device represented by the object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pType* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)