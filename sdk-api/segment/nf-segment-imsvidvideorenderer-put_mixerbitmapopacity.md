# IMSVidVideoRenderer::put_MixerBitmapOpacity

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MixerBitmapOpacity** method specifies the opacity of the static bitmap image.

## Parameters

### `opacity` [in]

Specifies the opacity as an integer from 0 (transparent) to 100 (opaque).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the static bitmap image is set, the VMR alpha blends the bitmap onto the video image, using the specified opacity.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::SetupMixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-setupmixerbitmap)

[IMSVidVideoRenderer::get_MixerBitmapOpacity](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmapopacity)

[IMSVidVideoRenderer::put_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmap)