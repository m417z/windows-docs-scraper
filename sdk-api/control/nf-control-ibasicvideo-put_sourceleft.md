# IBasicVideo::put_SourceLeft

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_SourceLeft` method sets the x-coordinate of the source rectangle.

## Parameters

### `SourceLeft` [in]

Specifies the x-coordinate, in pixels.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The video renderer's input pin is not connected. |

## Remarks

This method moves the entire source rectangle to the left or right. It does not change the width of the source rectangle. If the value of *SourceLeft* would place the right edge of the rectangle beyond the edge of the video frame, the method returns E_INVALIDARG. To crop the video, call **put_SourceWidth** to adjust the width, before calling `put_SourceLeft`. (Or call **SetSourcePosition** to set the entire source rectangle at once.)

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)