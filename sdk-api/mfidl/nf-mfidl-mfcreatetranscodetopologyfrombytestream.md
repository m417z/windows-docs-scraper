# MFCreateTranscodeTopologyFromByteStream function

## Description

Creates a topology for transcoding to a byte stream.

## Parameters

### `pSrc` [in]

A pointer to the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface of a media source. The media source provides that source content for transcoding.

### `pOutputStream` [in]

A pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of a byte stream. The transcoded output will be written to this byte stream.

### `pProfile` [in]

A pointer to the [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) interface of a transcoding profile.

### `ppTranscodeTopo` [out]

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a partial topology that contains the media source, the encoder, and the media sink.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Session](https://learn.microsoft.com/windows/desktop/medfound/media-session)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)