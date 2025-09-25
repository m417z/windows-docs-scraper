# MFCreate3GPMediaSink function

## Description

Creates a media sink for authoring 3GP files.

## Parameters

### `pIByteStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The media sink writes the 3GP file to this byte stream. The byte stream must be writable and support seeking.

### `pVideoMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a video media type. This type specifies the format of the video stream.

This parameter can be **NULL**, but not if *pAudioMediaType* is **NULL**.

### `pAudioMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of an audio media type. This type specifies the format of the audio stream.

This parameter can be **NULL**, but not if *pVideoMediaType* is **NULL**.

### `ppIMediaSink` [out]

Receives a pointer to the 3GP media sink's [IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The 3GP media sink supports a maximum of one video stream and one audio stream. The initial stream formats are given in the *pVideoMediaType* and *pAudioMediaType* parameters. To create an MP4 file with one stream, set the other stream type to **NULL**. For example, to create an audio-only file, set *pVideoMediaType* to **NULL**.

The number of streams is fixed when you create the media sink. The sink does not support the [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) method.

To author MP4 files, use the [MFCreateMPEG4MediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatempeg4mediasink) function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)