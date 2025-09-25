# IMSVidVideoRenderer::put_MixerBitmap

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MixerBitmap** method specifies the static bitmap image, as an **IPictureDisp** type.

## Parameters

### `MixerPictureDisp` [in]

Specifies a pointer to the **IPictureDisp** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The VMR alpha-blends the static bitmap image onto the video image. For information about the **IPictureDisp** interface, see the Platform SDK documentation.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::SetupMixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-setupmixerbitmap)

[IMSVidVideoRenderer::get_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmap)

[IMSVidVideoRenderer::put_MixerBitmapOpacity](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmapopacity)

[IMSVidVideoRenderer::put_MixerBitmapPositionRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmappositionrect)

[Mixing an Image Onto the Video Window in C++](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mixing-an-image-onto-the-video-window-in-c-)