# IMFSensorGroup::CreateMediaSource

## Description

Creates an [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) that virtualizes the sensor group. The term "device" in this context could refer to a physical device or a software media source. The source can represent a sensor group that actually contains multiple sensor devices, or it could contain only a single device, but still behaves as a sensor group.

## Parameters

### `ppSource` [out]

Receives a pointer to the created media source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)