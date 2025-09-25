# IAMLine21Decoder::SetDrawBackgroundMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDrawBackgroundMode` method specifies whether the [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter draws the captions on a transparent background or an opaque background. By default, the caption background is opaque.

## Parameters

### `Mode`

Specifies a member of the [AM_LINE21_DRAWBGMODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/ne-il21dec-am_line21_drawbgmode) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder::GetDrawBackgroundMode](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getdrawbackgroundmode)