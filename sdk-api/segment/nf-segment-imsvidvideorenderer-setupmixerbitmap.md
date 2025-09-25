# IMSVidVideoRenderer::SetupMixerBitmap

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetupMixerBitmap** method configures the Video Mixing Renderer (VMR) to display an alpha-blended bitmap on top of the video.

## Parameters

### `MixerPictureDisp` [in]

Pointer to an **IPictureDisp** interface that specifies the bitmap.

### `Opacity` [in]

Specifies the opacity of the bitmap, as an integer from 0 (transparent) to 100 (opaque).

### `rDest` [in]

Pointer to an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface that specifies the position of the bitmap, relative to the video window.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::put_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmap)

[IMSVidVideoRenderer::put_MixerBitmapOpacity](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmapopacity)

[IMSVidVideoRenderer::put_MixerBitmapPositionRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmappositionrect)