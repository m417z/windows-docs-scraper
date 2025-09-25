# MFCreateFMPEG4MediaSink function

## Description

Creates a media sink for authoring fragmented MP4 files.

## Parameters

### `pIByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The media sink writes the MP4 file to this byte stream. The byte stream must be writable and support seeking.

### `pVideoMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a video media type. This type specifies the format of the video stream.

This parameter can be **NULL**, but not if *pAudioMediaType* is **NULL**.

### `pAudioMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of an audio media type. This type specifies the format of the audio stream.

This parameter can be **NULL**, but not if *pVideoMediaType* is **NULL**.

### `ppIMediaSink` [out]

Receives a pointer to the MP4 media sink's [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)