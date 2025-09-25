# IMFSensorProcessActivity::GetStreamingMode

## Description

Gets the streaming mode of the sensor process.

## Parameters

### `pMode` [out]

Receives a value from the MFSensorDeviceMode enumeration specifying the streaming mode of the sensor process.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pMode* parameter is null. |

## See also
[MFSensorDeviceMode](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfsensordevicemode)

[IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity)