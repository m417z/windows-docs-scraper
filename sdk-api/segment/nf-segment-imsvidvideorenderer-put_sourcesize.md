# IMSVidVideoRenderer::put_SourceSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_SourceSize** method specifies the type of clipping to apply to the video rectangle, if any.

## Parameters

### `NewSize` [in]

Specifies a member of the [SourceSizeList](https://learn.microsoft.com/windows/desktop/api/segment/ne-segment-sourcesizelist) enumeration.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_sourcesize)

[IMSVidVideoRenderer::put_ClippedSourceRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_clippedsourcerect)

[IMSVidVideoRenderer::put_OverScan](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_overscan)