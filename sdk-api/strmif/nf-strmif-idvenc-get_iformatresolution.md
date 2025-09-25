# IDVEnc::get_IFormatResolution

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_IFormatResolution** method retrieves the encoding resolution.

## Parameters

### `VideoFormat` [out]

Pointer to a variable that receives a member of the [DVENCODERVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_dvencodervideoformat) enumeration, specifying the video standard in use (NTSC or PAL).

### `DVFormat` [out]

Pointer to a variable that receives a member of the [DVENCODERFORMAT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_dvencoderformat) enumeration, specifying the digital video (DV) format.

### `Resolution` [out]

Pointer to a variable that receives a member of the [DVENCODERRESOLUTION](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_dvencoderresolution) enumeration, specifying the video resolution.

### `fDVInfo` [in]

Boolean value specifying whether to retrieve the [DVINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvinfo) structure that specifies the stream format. If **TRUE**, the stream format is returned in the *sDVInfo* parameter.

### `sDVInfo` [out]

Pointer to a variable that receives a **DVINFO** structure containing the stream format. If *fDVInfo* is **FALSE**, this parameter is ignored.

## Return value

Returns S_OK if successful. Otherwise, returns E_FAIL or another error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDVEnc Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvenc)