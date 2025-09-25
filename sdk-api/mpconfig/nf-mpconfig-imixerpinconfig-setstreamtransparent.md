# IMixerPinConfig::SetStreamTransparent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetStreamTransparent` method sets the stream to transparent.

## Parameters

### `bStreamTransparent` [in]

Value specifying the transparency of the stream. Pass in **TRUE** to indicate stream is transparent; **FALSE** to indicate not a transparent stream.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::GetStreamTransparent](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getstreamtransparent)