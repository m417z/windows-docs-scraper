# IBasicVideo::GetCurrentImage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentImage` method retrieves the current image waiting at the renderer.

## Parameters

### `pBufferSize` [in, out]

Pointer to a variable that contains the size of the buffer that the caller is passing in. If *pDIBImage* is **NULL**, this parameter receives the required buffer size.

### `pDIBImage` [out]

Pointer to a buffer where the complete image will be stored in device-independent bitmap (DIB) format. Cast the pointer to a long pointer type.

## Return value

Returns an **HRESULT** value.

## Remarks

The [Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/video-renderer-filter) filter and the Video Mixing Renderer (VMR) implement this method differently.

### Video Renderer only:

This method fails if the renderer is using DirectDraw acceleration. Unfortunately, this depends on the end-user's hardware configuration, so in practice this method is not reliable.

Pause the Video Renderer before calling this method. Otherwise, the method returns VFW_E_NOT_PAUSED. Make sure that the pause operation has completed by calling [IMediaControl::GetState](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-getstate); if the pause operation has not completed, the **GetCurrentImage** method returns E_UNEXPECTED. Depending on what data the source filter has available, the video renderer is not guaranteed to service this request. If no image is available, it returns E_FAIL.

### Video Mixing Renderer only:

This method is reliable regardless of whether the VMR is using DirectDraw acceleration and regardless of the current graph state (running, stopped, or paused).

### Video Renderer and Video Mixing Renderer:

To obtain the required buffer size to hold the image, call this method with a **NULL** pointer in the *pDIBImage* parameter. The method returns the required buffer size in the *pBufferSize* parameter. Allocate a buffer of that size and call the method again, with *pDIBImage* pointing to the buffer. On the second call, use *pBufferSize* to specify the buffer size. If the buffer is too small to hold the complete image, the method returns E_OUTOFMEMORY.

If the method succeeds, the buffer is filled with the entire DIB image, including the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure, plus any palette entries and bit masks as defined in the Win32 [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure. The format of the image depends on the type provided by the source filter, and cannot be specified in advance.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)