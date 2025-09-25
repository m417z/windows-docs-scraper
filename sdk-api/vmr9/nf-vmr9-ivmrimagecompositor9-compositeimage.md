# IVMRImageCompositor9::CompositeImage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CompositeImage` method composites the current frames available in each input stream.

## Parameters

### `pD3DDevice` [in]

Pointer to the **IUnknown** interface of the Direct3D device object.

### `pddsRenderTarget` [in]

Specifies the Direct3D surface that all drawing should be performed on.

### `pmtRenderTarget` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that contains the media type of the target surface.

### `rtStart` [in]

Specifies the start time.

### `rtEnd` [in]

Specifies the end time.

### `dwClrBkGnd` [in]

Specifies the background color, as a **D3DCOLOR** type.

### `pVideoStreamInfo` [in]

Pointer to an array of [VMR9VideoStreamInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videostreaminfo) structures, which describe each video stream.

### `cStreams` [in]

Specifies the number of streams to mix, which is also the size of the *pVideoStreamInfo* array.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRImageCompositor9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagecompositor9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)