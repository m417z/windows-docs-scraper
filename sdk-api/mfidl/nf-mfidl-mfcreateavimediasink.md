# MFCreateAVIMediaSink function

## Description

Creates an Audio-Video Interleaved (AVI) Sink.

## Parameters

### `pIByteStream` [in]

Pointer to the byte stream that will be used to write the AVI file.

### `pVideoMediaType` [in]

Pointer to the media type of the video input stream

### `pAudioMediaType` [in, optional]

Pointer to the media type of the audio input stream

### `ppIMediaSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) Interface. The caller must release this interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)