# IAMLine21Decoder::SetBackgroundColor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetBackgroundColor` method sets the background color that the [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter uses for overlay. The default background color is magenta.

Generally, applications should not call this method. The background color must match the overlay color key, which is defined by the downstream rendering filter.

## Parameters

### `dwPhysColor`

Sets the background color as a pixel color value. The meaning of the pixel value is defined by the bit depth of the filter's current output format.

## Return value

Returns S_OK if successful, or an error code otherwise.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder)

[IAMLine21Decoder::GetBackgroundColor](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getbackgroundcolor)