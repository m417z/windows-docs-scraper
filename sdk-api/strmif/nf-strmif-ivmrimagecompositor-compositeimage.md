# IVMRImageCompositor::CompositeImage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CompositeImage` method composites the current frames available in each input stream.

## Parameters

### `pD3DDevice` [in]

Pointer to the **IUnknown** interface of the Direct3D device. The compositor must cast this to a **LPDIRECT3DDEVICE7** type.

### `pddsRenderTarget` [in]

Specifies the DirectDraw surface that all drawing should be performed on.

### `pmtRenderTarget` [in]

Specifies the media type of the DirectDraw surface.

### `rtStart` [in]

Specifies the start time.

### `rtEnd` [in]

Specifies the end time.

### `dwClrBkGnd` [in]

Specifies the background color.

### `pVideoStreamInfo` [in]

Pointer to an array of video stream info objects.

### `cStreams` [in]

Specifies the number of streams to be mixed, which is equal to the size of the pVideoStreamInfo array.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRImageCompositor Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagecompositor)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)