# IDirectDrawVideo::GetDirectDraw

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDirectDraw` method retrieves the **IDirectDraw** interface.

## Parameters

### `ppDirectDraw`

Address of a pointer to the **IDirectDraw** interface.

## Return value

Returns an **HRESULT** value.

## Remarks

If an application wants to load DirectDraw but allow the renderer to also allocate surfaces, it can let the renderer load DirectDraw and then obtain a reference-incremented interface to it through this method. The interface returned should be released by the application when it is finished with it.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)