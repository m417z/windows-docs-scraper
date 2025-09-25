# IDirectDrawStreamSample::SetRect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Changes the clipping rectangle for a sample.

## Parameters

### `pRect` [in]

Pointer to a **RECT** structure that specifies the stream's new clipping rectangle.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **DDERR_INVALIDPIXELFORMAT** | The stream isn't compatible with the pixel format. |
| **DDERR_INVALIDRECT** | The specified rectangle is invalid. |
| **DDERR_INVALIDSURFACETYPE** | The stream isn't compatible with the surface. |
| **E_POINTER** | One of the pointers is invalid. |
| **MS_E_SAMPLEALLOC** | The stream format doesn't match the surface and samples are currently allocated to the stream. |
| **S_OK** | Success. |

## Remarks

Both parameters are optional; set either to **NULL** to avoid changing that value. If the surface format doesn't match the stream format, this method fails.

If the new rectangle's size isn't the same as the current rectangle, a call to this method will fail.

## See also

[IDirectDrawStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawstreamsample)