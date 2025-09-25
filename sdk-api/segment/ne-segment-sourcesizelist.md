# SourceSizeList enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **SourceSizeList** enumeration is used to indicate how the VMR will clip the source video rectangle.

## Constants

### `sslFullSize:0`

Do not clip the source video rectangle.

### `sslClipByOverScan`

Clip the source video rectangle by the value specified in the last call to [IMSVidVideoRenderer::put_OverScan](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_overscan).

### `sslClipByClipRect`

Clip the source video rectangle by the value specified in the last call to [IMSVidVideoRenderer::put_ClippedSourceRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_clippedsourcerect)

## See also

[IMSVidVideoRenderer::get_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_sourcesize)

[IMSVidVideoRenderer::put_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_sourcesize)

[Video Control Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/video-control-enumerations)