# IMFCaptureSource::GetStreamIndexFromFriendlyName

## Description

Gets the actual device stream index translated from a friendly stream name.

## Parameters

### `uifriendlyName` [in]

The friendly name. Can be one of the following:

* MF_CAPTURE_ENGINE_FIRST_SOURCE_AUDIO_STREAM
* MF_CAPTURE_ENGINE_FIRST_SOURCE_VIDEO_STREAM
* MF_CAPTURE_ENGINE_FIRST_SOURCE_PHOTO_STREAM
* MF_CAPTURE_ENGINE_PREFERRED_SOURCE_VIDEO_STREAM_FOR_RECORD
* MF_CAPTURE_ENGINE_PREFERRED_SOURCE_VIDEO_STREAM_FOR_PREVIEW
* MF_CAPTURE_ENGINE_FIRST_SOURCE_INDEPENDENT_PHOTO_STREAM

### `pdwActualStreamIndex` [out]

Receives the value of the stream index that corresponds to the friendly name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFCaptureSource](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesource)