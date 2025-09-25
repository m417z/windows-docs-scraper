# IDDrawExclModeVideo::SetDDrawSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDDrawSurface` method specifies the DirectDraw surface to be used in subsequent drawing.

## Parameters

### `pDDrawSurface` [in]

Pointer to the **IDirectDrawSurface** interface on the surface to use.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

The current DirectShow implementation return values include the following.

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| E_INVALIDARG | Argument is invalid. |
| A DirectDraw error code | A DirectDraw error is encountered when trying to set the specified surface on the Overlay Mixer. |

## Remarks

A game application can use this to share its DirectDraw surface with the [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter so that the video can be drawn in a specified surface. This surface must be associated with the object specified in [IDDrawExclModeVideo::SetDDrawObject](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iddrawexclmodevideo-setddrawobject).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo)