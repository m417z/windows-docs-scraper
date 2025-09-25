# IMSVidVideoRenderer::get_MixerBitmapOpacity

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MixerBitmapOpacity** method retrieves the opacity of the static bitmap image.

## Parameters

### `opacity` [out]

Receives the opacity, expressed as an integer from 0 (transparent) to 100 (opaque).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the static bitmap image is set, the VMR alpha-blends the bitmap onto the video image, using the opacity given in *pOpacity*.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmap)

[IMSVidVideoRenderer::put_MixerBitmapOpacity](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmapopacity)