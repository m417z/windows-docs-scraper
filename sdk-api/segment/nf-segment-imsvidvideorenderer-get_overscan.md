# IMSVidVideoRenderer::get_OverScan

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_OverScan** method retrieves the amount of clipping to perform on all sides of the video frame, in order to cut off random video noise.

## Parameters

### `plPercent` [out]

Receives the amount to clip, in hundredths of a percent.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the current clipping mode is **sslClipByOverScan**, the VMR clips the video image by the amount given in the *plPercent* parameter. For more information, see [IMSVidVideoRenderer::put_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_sourcesize).

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::put_OverScan](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_overscan)