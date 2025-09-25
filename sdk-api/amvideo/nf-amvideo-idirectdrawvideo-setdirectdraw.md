# IDirectDrawVideo::SetDirectDraw

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDirectDraw` method passes the **IDirectDraw** interface to a loaded driver.

## Parameters

### `pDirectDraw`

Pointer to the **IDirectDraw** interface to be passed.

## Return value

Returns an **HRESULT** value.

## Remarks

To have the renderer release a DirectDraw interface previously passed in through `SetDirectDraw`, an application can call `SetDirectDraw` and pass in **NULL**. However, the renderer will continue using that DirectDraw interface until it is disconnected. Therefore, calling `SetDirectDraw` with a **NULL** parameter does not make the renderer stop using it immediately.

This method was created because only one instance of **IDirectDraw** could be loaded per process in versions of DirectDraw prior to DirectX 7.0. If you are using DirectX 7.0 or later, you never need to call this method. If an application wanted to load **IDirectDraw** but allow the Video Renderer to also allocate surfaces, the application could open **IDirectDraw** itself and then pass the interface to the loaded driver through `IDirectDrawVideo::SetDirectDraw`. Alternatively, the application could let the renderer load DirectDraw and then obtain a reference-incremented interface to it through [IDirectDrawVideo::GetDirectDraw](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-idirectdrawvideo-getdirectdraw). Because DirectShow ships with the most recently shipped version of DirectDraw, however, this method is not required unless the application wants to change display modes itself and pass in a DirectDraw object, which the renderer can then use to allocate surfaces.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)