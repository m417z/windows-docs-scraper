# IMSVidVideoRenderer::put_UsingOverlay

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_UsingOverlay** method specifies whether the Video Mixing Renderer will use the hardware overlay.

## Parameters

### `UseOverlayVal` [in]

Flag that specifies whether to use the hardware overlay. Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Use the hardware overlay. |
| VARIANT_FALSE | Do not use the hardware overlay. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_UsingOverlay](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_usingoverlay)