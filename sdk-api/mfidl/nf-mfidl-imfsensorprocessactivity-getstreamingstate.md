# IMFSensorProcessActivity::GetStreamingState

## Description

Gets a value indicating whether the sensor is currently streaming.

## Parameters

### `pfStreaming` [out]

Receives a value indicating whether the sensor is currently streaming.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pfStreaming* parameter is null. |

## See also

[IMFSensorProcessActivity](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprocessactivity)