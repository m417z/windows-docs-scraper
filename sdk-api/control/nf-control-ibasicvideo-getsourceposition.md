# IBasicVideo::GetSourcePosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSourcePosition` method retrieves the position of the source rectangle.

## Parameters

### `pLeft` [out]

Pointer to a variable that receives the x-coordinate, in pixels.

### `pTop` [out]

Pointer to a variable that receives the y-coordinate, in pixels.

### `pWidth` [out]

Pointer to a variable that receives the width, in pixels.

### `pHeight` [out]

Pointer to a variable that receives the height, in pixels.

## Return value

Returns an **HRESULT** value.

## Remarks

This method has the same effect as individually calling the [IBasicVideo::get_SourceLeft](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-get_sourceleft), [IBasicVideo::get_SourceTop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-get_sourcetop), [IBasicVideo::get_SourceWidth](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-get_sourcewidth), and [IBasicVideo::get_SourceHeight](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicvideo-get_sourceheight) methods.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)