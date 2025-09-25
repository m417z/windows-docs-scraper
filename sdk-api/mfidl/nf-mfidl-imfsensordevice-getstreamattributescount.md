# IMFSensorDevice::GetStreamAttributesCount

## Description

Gets the count of stream attribute stores for the sensor device. This number represents the number of total streams available for the device because every valid stream must have an attribute store that contains at least the stream ID and stream category.

## Parameters

### `eType` [in]

A member of the [MFSensorStreamType](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensorstreamtype) enumeration specifying whether the attribute store count is being requested for an input or output stream.

### `pdwCount` [out]

The number of stream attributes available for this sensor device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pdwCount* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The caller can use the number of stream attributes to indicate the number of streams provided by the sensor device.

**Note** Depending on the sharing mode in which the sensor device was activated, not all streams may be present during runtime. Streams marked as shared, i.e. with the [MF_DEVICESTREAM_FRAMESERVER_SHARED](https://learn.microsoft.com/windows/desktop/medfound/mf-devicestream-frameserver-shared) attribute set to non-zero value, and streams with pins with the category **PINNAME_VIDEO_PREVIEW** will be present in devices that are set to used shared mode. Put a device in shared mode by passing [MFSensorDeviceMode_Shared](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensordevicemode) into [SetSensorDeviceMode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensordevice-setsensordevicemode).
If no streams are marked as shared and no preview stream is available, the first capture stream, with the category **PINNAME_VIDEO_CAPTURE**, will be shared.

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)