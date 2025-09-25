# IDirectDrawVideo::UseScanLine

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UseScanLine` method determines whether the renderer should check the current scan line when drawing a video.

## Parameters

### `UseScanLine`

Long integer value that specifies whether or not to use the scan line information. Set to **OATRUE** to use scan line information or **OAFALSE** to ignore it.

## Return value

Returns E_INVALIDARG if the argument is invalid or S_OK otherwise.

## Remarks

If you blit an image to the video memory while the monitor's scan line is scanning over a visible portion of the screen, the complete image will be a composite of the old and new images. This composite is known as a torn video image. You can avoid torn images by waiting until the previous image is complete before blitting the new image. Some video cards can retrieve the scan line's current position; if this information is available, you can have DirectShow try to reduce tearing by waiting until the scan line is off-screen before blitting the new image. Note that checking the scan line location increases load on the processor and can reduce the amount of video frames delivered to the screen. If scan line information is available, DirectShow uses it by default. Set *UseScanLine* to OAFALSE if you want to save processing time at the expense of minor image degradation.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)