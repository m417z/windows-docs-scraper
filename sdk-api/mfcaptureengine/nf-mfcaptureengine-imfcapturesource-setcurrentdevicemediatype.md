# IMFCaptureSource::SetCurrentDeviceMediaType

## Description

Sets the output format for a capture stream.

## Parameters

### `dwSourceStreamIndex` [in]

The capture stream to set. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM**<br><br>0xFFFFFFFB | The first image stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid. |

## Remarks

This method sets the native output type on the capture device. The device must support the specified format. To get the list of available formats, call [IMFCaptureSource::GetAvailableDeviceMediaType](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getavailabledevicemediatype).

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)