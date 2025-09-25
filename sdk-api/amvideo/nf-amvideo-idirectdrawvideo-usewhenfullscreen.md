# IDirectDrawVideo::UseWhenFullScreen

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UseWhenFullScreen` method determines whether DirectShow should change display mode when going to full-screen mode.

## Parameters

### `UseWhenFullScreen`

Value specifying whether to change the display mode. Set to OATRUE to cause the renderer to use DirectShow in full-screen mode; otherwise, set to OAFALSE.

## Return value

Returns an **HRESULT** value.

## Remarks

When asked to go to full-screen mode, DirectShow has a number of choices. The first choice is to determine if any filters in the graph can support full-screen playback directly; if one can, it will be asked to do so.

The second choice is to automatically add a special full-screen renderer to the filter graph that uses DirectDraw mode-changing services to play back the video. By changing display modes, the video effectively fills more (but not necessarily all) of the display. So, for example, if the current mode is 1024 x 768 pixels, a video might look relatively small, but when displayed in a 320 x 240 display mode it might look very presentable.

The third and final choice is to simply take any renderer supporting the [IVideoWindow](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow) interface and have its window stretched full-screen. This will typically offer lower performance than the second option (swapping in a full-screen DirectDraw-enabled renderer). If the *UseWhenFullScreen* parameter is set to On (OATRUE), the window will always be stretched full-screen for full-screen playback; if set to Off (the default), the filter graph manager is free to swap in the DirectDraw-enabled full-screen renderer.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)