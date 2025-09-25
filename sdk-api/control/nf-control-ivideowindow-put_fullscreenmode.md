# IVideoWindow::put_FullScreenMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_FullScreenMode` method enables or disables full-screen video rendering.

## Parameters

### `FullScreenMode` [in]

Boolean value that specifies whether to enable or disable full-screen mode. Must be one of the following values:

| Value | Description |
| --- | --- |
| OATRUE | Switch to full-screen mode. |
| OAFALSE | Disable full-screen mode. (Default.) |

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Filter does not support full-screen mode. |
| **S_FALSE** | Already in the requested mode. |
| **S_OK** | Success. |
| **VFW_E_NO_FULLSCREEN** | Could not find any filter that supports full-screen mode. |

## Remarks

Depending on the video renderer, the switch to full-screen mode may not be visible until the application runs or pauses the graph. In full-screen mode, if the user switches away from the application (for example, using ALT + TAB), the Filter Graph Manager sends an [EC_FULLSCREEN_LOST](https://learn.microsoft.com/windows/desktop/DirectShow/ec-fullscreen-lost) event.

The following remarks describe how the Filter Graph Manager implements full-screen mode. Application developers can probably ignore this information, but it may be useful if you are writing a custom video renderer.

When an application switches to full-screen mode, the Filter Graph Manager searches for a video renderer that will function most efficiently. In order of preference, these are:

1. Any video renderer in the filter graph that natively supports full-screen mode.
2. Any video renderer in the filter graph that can stretch the video to full-screen without a significant performance cost.
3. The [Full Screen Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/full-screen-renderer-filter) filter.
4. Any video renderer in the filter graph that supports **IVideoWindow**.

For the first option, the Filter Graph Manager calls [IVideoWindow::get_FullScreenMode](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_fullscreenmode) on every video renderer in the graph. Most renderers return E_NOTIMPL, indicating the filter does not natively support full-screen mode. If any renderer returns a value not equal to E_NOTIMPL, the Filter Graph Manager uses that one.

For the second option, the Filter Graph Manager calls [IVideoWindow::GetMaxIdealImageSize](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-getmaxidealimagesize) and **GetMinIdealImageSize** on every video renderer in the graph. If the size of the display falls within the filter's reported range, it indicates that the filter can stretch the video without a significant performance cost.

**Note** If the graph is stopped, the Filter Graph Manager pauses each renderer before calling these methods. This gives the renderer an opportunity to initialize any resources it needs, because many renderers cannot determine these values while they are stopped.

Except on older hardware, the second option will generally succeed. The third option is to use the Full Screen Renderer filter, adding it to the graph if necessary. The fourth option is simply to find the first renderer in the graph that supports **IVideoWindow**, and stretch the video regardless of performance.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_FullScreenMode](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_fullscreenmode)