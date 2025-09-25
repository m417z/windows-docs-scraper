# IDirectDrawStreamSample::GetSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves pointers to the current sample's DirectDraw surface and associated clipping rectangle.

## Parameters

### `ppDirectDrawSurface` [out]

Address of a pointer to an **IDirectDrawSurface** interface that specifies the sample's new surface. Set this parameter to **NULL** if you don't want to specify a new surface.

### `pRect` [out]

Pointer to a **RECT** structure that will contain the current sample's clipping rectangle. Set this parameter to **NULL** if you don't want to retrieve the clipping rectangle.

## Return value

Returns an **HRESULT** value.

## Remarks

Both parameters are optional. All implementations of this interface must support **NULL** values as valid parameters. If you retrieve a surface pointer, this method increments its reference count, so you must release the reference.

## See also

[IDirectDrawStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawstreamsample)