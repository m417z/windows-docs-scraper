# IVideoWindow::put_BorderColor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_BorderColor` method sets the color that appears around the edges of the destination rectangle.

## Parameters

### `Color` [in]

The border color, specified as a **COLORREF** value.

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

If the destination rectangle is smaller than the client area of the video window, a border is exposed around the edges of the video. The default color is black. Use this method to override the default color. If a palette is in use, a nonsystem color is converted to its closest match.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo::SetDestinationPosition](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-setdestinationposition)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_BorderColor](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_bordercolor)