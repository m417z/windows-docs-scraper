# IAMLine21Decoder::SetOutputFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOutputFormat` method sets the [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter's output format.

This method is currently not implemented.

## Parameters

### `lpbmi`

Pointer to a **BITMAPINFO** structure that describes the output format.

## Return value

Returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder)

[IAMLine21Decoder::GetOutputFormat](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getoutputformat)