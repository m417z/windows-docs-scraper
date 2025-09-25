# IAMOverlayFX::SetOverlayFX

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetOverlayFX` method applies the specified effects to the overlay surface.

## Parameters

### `dwOverlayFX` [in]

Value specifying which effects to apply. The value must be a logical combination of flags from the [AMOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-amoverlayfx) enumeration, or the method returns E_INVALIDARG.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The DirectShow implementation may return one of the following values, or others not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |

## Remarks

The application must call this method while the filter graph is running. The effects are applied immediately.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMOverlayFX Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamoverlayfx)