# MF_TRANSCODE_SINK_INFO structure

## Description

Contains information about the audio and video streams for the transcode sink activation object.

To get the information stored in this structure, call [IMFTranscodeSinkInfoProvider::GetSinkInfo](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-getsinkinfo).

## Members

### `dwVideoStreamID`

The stream identifier of the video stream.

### `pVideoMediaType`

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type for the video stream. This member can be **NULL**.

### `dwAudioStreamID`

The stream identifier of the audio stream.

### `pAudioMediaType`

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type for the audio stream. This member can be **NULL**.

## Remarks

The [IMFTranscodeSinkInfoProvider::GetSinkInfo](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-getsinkinfo) method assigns [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) pointers to the **pAudioMediaType** and **pVideoMediaType** members of this structure. The method might set either member to **NULL**. If either member is non-**NULL** after the method returns, the caller must release the **IMFMediaType** pointers.

## See also

[IMFTranscodeSinkInfoProvider::GetSinkInfo](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-getsinkinfo)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)