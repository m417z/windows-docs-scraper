# IDrawVideoImage::DrawVideoImageDraw

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface has been deprecated. New applications should not use it.

The `DrawVideoImageDraw` method draws the specified source rectangle to the specified destination rectangle in the specified GDI device context.

## Parameters

### `hdc` [in]

Specifies the device context.

### `lprcSrc` [in]

Pointer to a **RECT** structure that specifies the source rectangle, as a subrectangle of the current video frame.

### `lprcDst` [in]

Pointer to a **RECT** structure that specifies the destination rectangle in the device context.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDrawVideoImage Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idrawvideoimage)