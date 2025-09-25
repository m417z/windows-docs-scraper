# VfwCaptureDialogs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies a dialog box that might exist in a Video for Windows capture driver.

## Constants

### `VfwCaptureDialog_Source:0x1`

Video source dialog box.

### `VfwCaptureDialog_Format:0x2`

Video format dialog box.

### `VfwCaptureDialog_Display:0x4`

Video display dialog box.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVfwCaptureDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcapturedialogs)