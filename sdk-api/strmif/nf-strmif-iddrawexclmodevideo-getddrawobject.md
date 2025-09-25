# IDDrawExclModeVideo::GetDDrawObject

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDDrawObject` method retrieves the DirectDraw object being used by the Overlay Mixer filter.

## Parameters

### `ppDDrawObject` [out]

Address of a pointer to the **IDirectDraw** interface that the Overlay Mixer is using.

### `pbUsingExternal` [out]

Pointer to a variable that receives a Boolean value. It receives the value **TRUE** if the Overlay Mixer is using a DirectDraw object specified by [IDDrawExclModeVideo::SetDDrawObject](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iddrawexclmodevideo-setddrawobject), or **FALSE** otherwise.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Argument is invalid. |
| **A DirectDraw error code** | A DirectDraw error is encountered when trying to set the specified surface on the Overlay Mixer. |

## Remarks

If the filter graph has not set a DirectDraw object and the Overlay Mixer has not yet allocated one, then *pDDrawObject* will be set to **NULL** and *pbUsingExternal* will be set to **FALSE**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo)