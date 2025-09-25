# IDirectDrawVideo::CanUseScanLine

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CanUseScanLine` method determines whether the renderer will check the current scan line when drawing.

## Parameters

### `UseScanLine`

Pointer to a value indicating whether the renderer will use scan line information. OATRUE indicates the renderer will check the current scan line when drawing; OAFALSE indicates it will not.

## Return value

Returns an **HRESULT** value.

## Remarks

For a description of the use of scan line detection in the DirectShow video renderer, see [IDirectDrawVideo::UseScanLine](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-idirectdrawvideo-usescanline).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)