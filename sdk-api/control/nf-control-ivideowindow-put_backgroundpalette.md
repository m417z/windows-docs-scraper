# IVideoWindow::put_BackgroundPalette

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_BackgroundPalette` method specifies whether the video window realizes its palette in the background.

## Parameters

### `BackgroundPalette` [in]

Specifies whether the video renderer realizes it palette in the background. Must be one of the following values:

| Value | Description |
| --- | --- |
| OATRUE | The video renderer realizes the palette in the background. |
| OAFALSE | The video renderer does not realize the palette in the background. (Default.) |

## Return value

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer filter is not connected. |

## Remarks

If *BackgroundPalette* is **OATRUE** and the video image requires a palette, the video renderer will realize that palette in the background. Any colors that the palette uses will change to their closest match in the display palette prior to drawing. This ensures that an application will not have its palette disturbed. However, it imposes severe performance penalties on the video.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoWindow Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ivideowindow)

[IVideoWindow::get_BackgroundPalette](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ivideowindow-get_backgroundpalette)