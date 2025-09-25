# MFCreateWAVEMediaSink function

## Description

 Creates a WAVE archive sink. The WAVE archive sink takes
audio and writes it to an .wav file.

## Parameters

### `pTargetByteStream` [in]

 Pointer to the byte stream that will be used to write the .wav file.

### `pAudioMediaType` [in]

Pointer to the audio media type.

### `ppMediaSink` [out]

Receives a pointer to the [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release this interface.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)