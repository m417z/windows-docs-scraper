# IAMLine21Decoder::SetRedrawAlways

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRedrawAlways` method specifies whether the [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter redraws the entire output bitmap for each sample.

## Parameters

### `bOption`

Specifies one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | The filter always redraws the entire bitmap. |
| **FALSE** | The filter does not always redraw the entire bitmap. (Default) |

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

Generally, applications should not call this method. The downstream mixer or renderer filter should call this method with the value **TRUE** if it writes into the buffers that it receives from the [Line 21 Decoder](https://learn.microsoft.com/windows/desktop/DirectShow/line-21-decoder-filter) filter. Redrawing degrades performance and increases CPU load, because it negates any potential optimizations.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMLine21Decoder Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/il21dec/nn-il21dec-iamline21decoder)

[IAMLine21Decoder::GetRedrawAlways](https://learn.microsoft.com/windows/desktop/api/il21dec/nf-il21dec-iamline21decoder-getredrawalways)