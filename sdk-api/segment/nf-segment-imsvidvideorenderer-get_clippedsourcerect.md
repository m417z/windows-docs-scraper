# IMSVidVideoRenderer::get_ClippedSourceRect

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_ClippedSourceRect** method retrieves the clipping rectangle on the video source.

## Parameters

### `pRect` [out]

Receives an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the current clipping mode is **sslClipByClipRect**, the VMR clips the video image to the video source rectangle, and stretches the clipped image to fill the Video Control's video window. For more information, see [IMSVidVideoRenderer::put_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_sourcesize).

The returned [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::put_ClippedSourceRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_clippedsourcerect)