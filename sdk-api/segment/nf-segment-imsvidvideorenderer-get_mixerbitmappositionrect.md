# IMSVidVideoRenderer::get_MixerBitmapPositionRect

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MixerBitmapPositionRect** method retrieves the position of the static bitmap image, relative to the video window.

## Parameters

### `rDest` [out]

Receives an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the static bitmap image is set, the VMR alpha-blends the bitmap onto the video image, using the position rectangle given in *pprDest*.

The returned [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmap)

[IMSVidVideoRenderer::put_MixerBitmapPositionRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmappositionrect)