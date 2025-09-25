# IBasicVideo::SetSourcePosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSourcePosition` method sets the source rectangle.

## Parameters

### `Left` [in]

Specifies the x-coordinate, in pixels.

### `Top` [in]

Specifies the y-coordinate, in pixels.

### `Width` [in]

Specifies the width, in pixels.

### `Height` [in]

Specifies the height, in pixels.

## Return value

Returns an **HRESULT** value.

## Remarks

This method has the same effect as individually calling the [IBasicVideo::put_SourceLeft](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-put_sourceleft), [IBasicVideo::put_SourceTop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-put_sourcetop), [IBasicVideo::put_SourceWidth](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-put_sourcewidth), and [IBasicVideo::put_SourceHeight](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-put_sourceheight) methods.

Setting this coordinate does not affect the destination rectangle height.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)