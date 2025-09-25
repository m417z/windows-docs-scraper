# IMFCaptureSource::GetAvailableDeviceMediaType

## Description

Gets a format that is supported by one of the capture streams.

## Parameters

### `dwSourceStreamIndex` [in]

The stream to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. To get the number of streams, call [IMFCaptureSource::GetDeviceStreamCount](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesource-getdevicestreamcount). |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM****<br><br>0xFFFFFFFB | The first image stream. |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |

### `dwMediaTypeIndex` [in]

The zero-based index of the media type to retrieve.

### `ppMediaType` [in]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwSourceStreamIndex* parameter is invalid. |
| **MF_E_NO_MORE_TYPES** | The *dwMediaTypeIndex* parameter is out of range. |

## Remarks

To enumerate all of the available formats on a stream, call this method in a loop while incrementing *dwMediaTypeIndex*, until the method returns **MF_E_NO_MORE_TYPES**.

Some cameras might support a range of frame rates. The minimum and maximum frame rates are stored in the [MF_MT_FRAME_RATE_RANGE_MIN](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-min) and [MF_MT_FRAME_RATE_RANGE_MAX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-frame-rate-range-max) attributes on the media type.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)