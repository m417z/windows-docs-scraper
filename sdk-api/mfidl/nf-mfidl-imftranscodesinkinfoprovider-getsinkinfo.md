# IMFTranscodeSinkInfoProvider::GetSinkInfo

## Description

Gets the media types for the audio and video streams specified in the transcode profile.

## Parameters

### `pSinkInfo` [out]

A pointer to an [MF_TRANSCODE_SINK_INFO](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mf_transcode_sink_info) structure.

If the method succeeds, the method assigns [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) pointers to the **pAudioMediaType** and **pVideoMediaType** members of this structure. The method might set either member to **NULL**. If either member is non-NULL after the method returns, the caller must release the **IMFMediaType** pointers.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this method, call [IMFTranscodeSinkInfoProvider::SetProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodesinkinfoprovider-setprofile) to set the transcode profile. The **GetSinkInfo** method uses the profile to create media types for the audio and video streams.

## See also

[IMFTranscodeProfile Interface](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[IMFTranscodeSinkInfoProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodesinkinfoprovider)