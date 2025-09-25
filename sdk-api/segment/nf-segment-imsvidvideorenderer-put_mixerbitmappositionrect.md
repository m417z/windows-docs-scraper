# IMSVidVideoRenderer::put_MixerBitmapPositionRect

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MixerBitmapPositionRect** method specifies the position of the static bitmap image, relative to the video window.

## Parameters

### `rDest` [in]

Pointer to an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface, specifying the rectangle.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the static bitmap image is set, the VMR alpha blends the bitmap onto the video image, using the specified position rectangle.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::SetupMixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-setupmixerbitmap)

[IMSVidVideoRenderer::get_MixerBitmapPositionRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmappositionrect)

[IMSVidVideoRenderer::put_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmap)