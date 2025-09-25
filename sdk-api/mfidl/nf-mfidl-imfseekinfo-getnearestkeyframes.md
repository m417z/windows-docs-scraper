# IMFSeekInfo::GetNearestKeyFrames

## Description

For a particular seek position, gets the two nearest key frames.

## Parameters

### `pguidTimeFormat` [in]

A pointer to a GUID that specifies the time format. The time format defines the units for the other parameters of this method. If the value is **GUID_NULL**, the time format is 100-nanosecond units. Some media sources might support additional time format GUIDs.

### `pvarStartPosition` [in]

The seek position. The units for this parameter are specified by *pguidTimeFormat*.

### `pvarPreviousKeyFrame` [out]

Receives the position of the nearest key frame that appears earlier than *pvarStartPosition*. The units for this parameter are specified by *pguidTimeFormat*.

### `pvarNextKeyFrame` [out]

Receives the position of the nearest key frame that appears later than *pvarStartPosition*. The units for this parameter are specified by *pguidTimeFormat*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_UNSUPPORTED_TIME_FORMAT** | The time format specified in *pguidTimeFormat* is not supported. |

## Remarks

If an application seeks to a non–key frame, the decoder must start decoding from the previous key frame. This can increase latency, because several frames might get decoded before the requested frame is reached. To reduce latency, an application can call this method to find the two key frames that are closest to the desired time, and then seek to one of those key frames.

## See also

[IMFSeekInfo](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfseekinfo)