# IMFCaptureSource::AddEffect

## Description

Adds an effect to a capture stream.

## Parameters

### `dwSourceStreamIndex` [in]

The capture stream. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM****<br><br>0xFFFFFFFB | The first image stream. |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |

### `pUnknown` [in]

A pointer to one of the following:

* A Media Foundation transform (MFT) that exposes the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.
* An MFT activation object that exposes the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDMEDIATYPE** | No compatible media type could be found. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid. |

## Remarks

The effect must be implemented as a [Media Foundation Transform](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms) (MFT). The *pUnknown* parameter can point to an instance of the MFT, or to an activation object for the MFT. For more information, see [Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects).

The effect is applied to the stream before the data reaches the capture sinks.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)