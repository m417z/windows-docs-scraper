# AM_LINE21_CCSTATE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the closed captioning state (on or off).

## Constants

### `AM_L21_CCSTATE_Off:0`

Closed captioning off.

### `AM_L21_CCSTATE_On`

Closed captioning on.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMLine21Decoder::GetServiceState](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getservicestate)

[IAMLine21Decoder::SetServiceState](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-setservicestate)