# IMSVidVideoRenderer::get_UsingOverlay

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_UsingOverlay** method queries whether the Video Mixing Renderer (VMR) is using the hardware overlay.

## Parameters

### `UseOverlayVal` [out]

Receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The VMR is using the hardware overlay. |
| VARIANT_FALSE | The VMR is not using the hardware overlay. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::put_UsingOverlay](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_usingoverlay)