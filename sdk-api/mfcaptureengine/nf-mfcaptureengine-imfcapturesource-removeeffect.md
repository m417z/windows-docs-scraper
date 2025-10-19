# IMFCaptureSource::RemoveEffect

## Description

Removes an effect from a capture stream.

## Parameters

### `dwSourceStreamIndex` [in]

The capture stream. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM**<br><br>0xFFFFFFFB | The first image stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pUnknown` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the effect object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | Invalid request. Possibly the specified effect could not be found. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid. |

## Remarks

This method removes an effect that was previously added using the [IMFCaptureSource::AddEffect](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-addeffect) method.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)