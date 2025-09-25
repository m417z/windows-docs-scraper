# IMSVidVideoRenderer::put__CustomCompositor

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put__CustomCompositor** method specifies a custom image compositor for the Video Mixing Renderer (VMR) to use.

## Parameters

### `Compositor` [in]

Pointer to the [IVMRImageCompositor](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagecompositor) interface of the image compositor.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Applications can provide their own compositors to perform custom image compositing. For more information, see [Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer).

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get__CustomCompositor](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get__customcompositor)

[IMSVidVideoRenderer::put__CustomCompositorClass](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put__customcompositorclass)