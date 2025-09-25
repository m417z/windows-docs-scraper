# IMSVidVideoRenderer::get_MixerBitmap

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MixerBitmap** method retrieves the static bitmap image, as an **IPictureDisp** type.

## Parameters

### `MixerPictureDisp` [out]

Receives an **IPictureDisp** interface pointer. The caller must release the interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **CO_E_NOTINITIALIZED** | No bitmap was set. |

## Remarks

If the static bitmap image is set, the VMR alpha-blends the bitmap onto the video image. For information about the **IPictureDisp** interface, see the Platform SDK documentation.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_MixerBitmapOpacity](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmapopacity)

[IMSVidVideoRenderer::get_MixerBitmapPositionRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmappositionrect)

[IMSVidVideoRenderer::put_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmap)

[Mixing an Image Onto the Video Window in C++](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mixing-an-image-onto-the-video-window-in-c-)