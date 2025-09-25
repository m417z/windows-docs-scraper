# IVMRWindowlessControl9::SetBorderColor

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetBorderColor` method sets the border color to be used by the VMR.

## Parameters

### `Clr` [in]

Specifies the color as a **COLORREF** value.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The border color is used to fill any area of the destination rectangle that does not contain video. It is typically used in two situations:

* When the video straddles two monitors
* When the VMR is trying to maintain the aspect ratio of the movies by letter-boxing the video to fit within the specified destination rectangle. See **SetAspectRatioMode**.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRWindowlessControl9 Interface](https://learn.microsoft.com/previous-versions/ms787155(v=vs.85))

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)