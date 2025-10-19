# IMFCaptureSource::RemoveAllEffects

## Description

Removes all effects from a capture stream.

## Parameters

### `dwSourceStreamIndex` [in]

The capture stream. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM**<br><br>0xFFFFFFFB | The first image stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid. |

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)