# IAMWstDecoder::GetDecoderLevel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Applications use the `GetDecoderLevel` method to retrieve the WST decoder level. This method is not implemented and always returns AM_WST_LEVEL_1_5.

## Parameters

### `lpLevel` [out]

Receives a member of the [AM_WST_LEVEL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iwstdec/ne-iwstdec-am_wst_level) enumeration, indicating the decoder level.

## Return value

When the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMWstDecoder Interface](https://learn.microsoft.com/windows/desktop/api/iwstdec/nn-iwstdec-iamwstdecoder)