# IDDrawExclModeVideo::SetDDrawObject

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDDrawObject` method sets the DirectDraw object to be used in subsequent drawing.

## Parameters

### `pDDrawObject` [in]

Pointer to the **IDirectDraw** interface on the object to use.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Argument is invalid. |
| **A DirectDraw error code** | A DirectDraw error is encountered when trying to set the specified surface on the Overlay Mixer. |

## Remarks

A game application can use this method to share its DirectDraw object with the [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter, so that the video can be drawn in a specified surface, as set in [IDDrawExclModeVideo::SetDDrawSurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iddrawexclmodevideo-setddrawsurface).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo)