# AM_LINE21_DRAWBGMODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the closed captioning text background mode.

## Constants

### `AM_L21_DRAWBGMODE_Opaque`

Opaque background.

### `AM_L21_DRAWBGMODE_Transparent`

Transparent background.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMLine21Decoder::GetDrawBackgroundMode](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getdrawbackgroundmode)

[IAMLine21Decoder::SetDrawBackgroundMode](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-setdrawbackgroundmode)