# IMSVidVideoRenderer::get_MaxVidRect

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MaxVidRect** method retrieves the maximum ideal size of the video rectangle.

## Parameters

### `ppVidRect` [out]

Receives an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The maximum ideal image size is the maximum video size that can be displayed without significantly degrading performance or image quality.

The returned [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_MinVidRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_minvidrect)